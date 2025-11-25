#include "loan.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

// Refactor: Removing Hardcoded Values

/**
 * @brief Attempts to read a default interest rate from a configuration file.
 * @param filename The name of the configuration file (e.g., "config.txt").
 * @return The default interest rate as LoanValue, or 0.0L if reading fails.
 */
LoanValue read_default_interest_rate(const string &filename)
{
	ifstream cfg_file(filename);
	LoanValue default_rate = 0.0L;

	if (cfg_file.is_open())
	{
		string line;
		if (getline(cfg_file, line))
		{
			stringstream ss(line);
			string token;
			if (ss >> default_rate)
			{
			}
		}
		cfg_file.close();
		return default_rate;
	}
	return 0.0L;
}

int main()
{
	LoanValue loan_amount, interest_rate, number_of_years;
	LoanCalculator calculator;
	LoanValue default_rate = read_default_interest_rate("config.txt");
	if (default_rate > 0.0L)
	{
		cout << "Loaded default interest rate from config.txt: " << fixed << setprecision(2) << default_rate << "%" << endl;
	}
	cout << "\n((Loan Calculator))" << endl;
	cout << "Enter the loan amount: ";
	cin >> loan_amount;

	cout << "Enter the annual interest rate (e.g., 5.0). Default rate if valid config: " << default_rate << "% : ";
	cin >> interest_rate;
	if (interest_rate <= 0.0L && default_rate > 0.0L)
	{
		interest_rate = default_rate;
		cout << "Using default interest rate: " << fixed << setprecision(2) << interest_rate << "%" << endl;
	}

	cout << "Enter the number of years: ";
	cin >> number_of_years;

	cout << "\n----------------------" << endl;

	// Refactor: Input Validation Bug Fix applied here
	if (!calculator.validate_inputs(loan_amount, interest_rate, number_of_years))
	{
		cerr << "Calculation aborted due to invalid input." << endl;
		return 1;
	}
	LoanResults results = calculator.calculate(loan_amount, interest_rate, number_of_years);
	// Refactor: Consistent Output Formatting
	cout << fixed << setprecision(2);
	cout << "Principal Loan Amount: " << loan_amount << endl;
	cout << "Annual Interest Rate: " << interest_rate << "%" << endl;
	cout << "Loan Tenure (Years): " << number_of_years << endl;
	cout << "----------------------" << endl;
	cout << "Total amount to be paid: " << results.total_amount_paid << endl;
	cout << "Total interest paid: " << results.total_interest << endl;
	cout << "Monthly amount to be paid: " << results.monthly_amount << endl;

	return 0;
}