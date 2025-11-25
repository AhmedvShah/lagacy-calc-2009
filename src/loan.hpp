#ifndef LOAN_HPP
#define LOAN_HPP

#include <string>
#include <iostream>

// Refactor: Overflow/Precision Fix
using LoanValue = long double; 

/**
 * @brief Represents the results of a loan calculation.
 */
struct LoanResults {
    LoanValue total_amount_paid = 0.0L;
    LoanValue total_interest = 0.0L;
    LoanValue monthly_amount = 0.0L;
};

/**
 * @brief Class to handle loan calculations and validation.
 */
class LoanCalculator {
public:
    /**
     * @brief Calculates the loan details using a simple interest model.
     * @param amount The principal loan amount.
     * @param rate The annual interest rate (e.g., 5.0 for 5%).
     * @param years The loan tenure in years.
     * @return LoanResults structure containing the total, interest, and monthly amounts.
     */
    LoanResults calculate(LoanValue amount, LoanValue rate, LoanValue years);

    /**
     * @brief Validates input values.
     * @param amount Loan principal.
     * @param rate Interest rate.
     * @param years Number of years.
     * @return true if all values are valid (i.e., greater than zero), false otherwise.
     */
    bool validate_inputs(LoanValue amount, LoanValue rate, LoanValue years);
};

#endif // LOAN_HPP