#include "gtest/gtest.h"
#include "../src/loan.hpp" // Adjust path based on your 'test' folder location
#include <cmath>
#include <iostream>

using namespace std;

// Fixture class for setting up LoanCalculator objects
class LoanTest : public ::testing::Test {
protected:
    LoanCalculator calculator;

    // Helper function for expected simple interest calculation
    LoanResults expected_simple_calc(LoanValue amount, LoanValue rate, LoanValue years) {
        LoanResults expected;
        LoanValue interest = amount * (rate / 100.0L) * years;
        expected.total_interest = interest;
        expected.total_amount_paid = amount + interest;
        expected.monthly_amount = expected.total_amount_paid / (years * 12.0L);
        return expected;
    }
};

// Test 1: Normal EMI Calculation
TEST_F(LoanTest, NormalEMICalculation) {
    // Principal: 10,000, Rate: 10%, Years: 1
    LoanValue amount = 10000.0L;
    LoanValue rate = 10.0L;
    LoanValue years = 1.0L;

    LoanResults results = calculator.calculate(amount, rate, years);
    LoanResults expected = expected_simple_calc(amount, rate, years);

    // Assert that the results match the expected values within a small tolerance (1e-4)
    ASSERT_NEAR(expected.total_amount_paid, results.total_amount_paid, 1e-4L);
    ASSERT_NEAR(expected.total_interest, results.total_interest, 1e-4L);
    ASSERT_NEAR(expected.monthly_amount, results.monthly_amount, 1e-4L);
}

// Test 2: Invalid Input Handling
TEST_F(LoanTest, InvalidInputHandling) {
    // Test case 1: Negative loan amount
    ASSERT_FALSE(calculator.validate_inputs(-10000.0L, 5.0L, 1.0L)) << "Should fail for negative amount.";

    // Test case 2: Zero interest rate
    ASSERT_FALSE(calculator.validate_inputs(10000.0L, 0.0L, 1.0L)) << "Should fail for zero rate.";

    // Test case 3: Negative tenure
    ASSERT_FALSE(calculator.validate_inputs(10000.0L, 5.0L, -10.0L)) << "Should fail for negative years.";

    // Test case 4: All valid (control test)
    ASSERT_TRUE(calculator.validate_inputs(1.0L, 1.0L, 1.0L)) << "Should pass for positive inputs.";
}

// Test 3: Large Tenure Calculations Without Overflow
TEST_F(LoanTest, LargeTenureCalculation) {
    // Set a very large tenure (1 million years) to test long double resilience
    LoanValue large_years = 1000000.0L; 
    LoanValue amount = 500000.0L;
    LoanValue rate = 8.0L;

    LoanResults results = calculator.calculate(amount, rate, large_years);
    
    // Check for calculated values against expected large values
    LoanResults expected = expected_simple_calc(amount, rate, large_years);

    // Check 1: Ensure the result is a finite, calculated number (no overflow to infinity/NaN)
    ASSERT_TRUE(isfinite(results.total_amount_paid)) << "Calculation resulted in non-finite value (possible overflow).";
    
    // Check 2: The total amount should be a large positive number
    ASSERT_GT(results.total_amount_paid, amount) << "Total paid should be greater than principal for positive interest.";
    
    // Check 3: Final assertion against expected value
    ASSERT_NEAR(expected.total_amount_paid, results.total_amount_paid, 1e-4L);
}

int main(int argc, char **argv) {
    cout << "24P-3000 PIR AHMED SHAH" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}