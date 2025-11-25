#include "loan.hpp"
#include <cmath>
using namespace std;

LoanResults LoanCalculator::calculate(LoanValue amount, LoanValue rate, LoanValue years) {
    LoanResults results;

    LoanValue total_interest_calculated = amount * (rate / 100.0L) * years;
    
    results.total_amount_paid = amount + total_interest_calculated;
    results.total_interest = total_interest_calculated;
    LoanValue total_months = years * 12.0L;
    
    if (total_months > 0.0L) {
        results.monthly_amount = results.total_amount_paid / total_months;
    } else {
        results.monthly_amount = 0.0L;
    }

    return results;
}

bool LoanCalculator::validate_inputs(LoanValue amount, LoanValue rate, LoanValue years) {
    if (amount <= 0.0L) {
        cerr << "Error: Loan amount must be greater than zero." << endl;
        return false;
    }
    if (rate <= 0.0L) {
        cerr << "Error: Interest rate must be greater than zero." << endl;
        return false;
    }
    if (years <= 0.0L) {
        cerr << "Error: Number of years must be greater than zero." << endl;
        return false;
    }
    return true;
}