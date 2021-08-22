#include <iostream>
#include <iomanip>

using namespace std;

void userInput(double &initialInvestment, double &monthlyDeposit, double &annualInterest, double &numOfMonths, double &numOfYears, double &yearEndInterest, double &yearEndBalance) {
	//Get user input
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $";
	cin >> initialInvestment;
	cout << endl << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	cout << endl << "Annual Interest: %";
	cin >> annualInterest;
	cout << endl << "Number of years: ";
	cin >> numOfYears;
	numOfMonths = numOfYears * 12;

	yearEndBalance = initialInvestment;
}

void displayBalanceWithoutDeposits(double &annualInterest, double &numOfYears, double &yearEndInterest, double &yearEndBalance) {
	cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 1; i <= numOfYears; ++i) {
		yearEndInterest += yearEndBalance * ((annualInterest / 100));
		yearEndBalance += yearEndInterest;
		cout << i << "\t\t$" << fixed << setprecision(2) << yearEndBalance << "\t\t\t$" << yearEndInterest << endl;
	}
}

void displayBalanceWithDeposits(double &monthlyDeposit, double &annualInterest, double &numOfYears, double &yearEndInterest, double &yearEndBalance) {
	cout << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	for (int i = 1; i <= numOfYears; ++i) {
		for (int j = 1; j <= 12; ++j) {
			yearEndInterest += (yearEndBalance + monthlyDeposit) * ((annualInterest / 100) / 12);
			yearEndBalance += monthlyDeposit + yearEndInterest;

		}
		cout << i << "\t\t$" << fixed << setprecision(2) << yearEndBalance << "\t\t\t$" << yearEndInterest << endl;

	}
}

int main() {
	// Declare Variables

	double initialInvestment = 0.00;
	double monthlyDeposit = 0.00;
	double annualInterest = 0.00;
	double numOfYears = 0.00;
	double numOfMonths = 0.00;
	double monthlyInterest = 0.00;
	double yearEndBalance = 0.00;
	double yearEndInterest = 0.00;
	double closingBalance = 0.00;

	userInput(initialInvestment, monthlyDeposit, annualInterest, numOfMonths, numOfYears, yearEndInterest, yearEndBalance);

	displayBalanceWithoutDeposits(annualInterest, numOfYears, yearEndInterest, yearEndBalance);

	displayBalanceWithDeposits(monthlyDeposit, annualInterest, numOfYears, yearEndInterest, yearEndBalance);







	return 0;
}	