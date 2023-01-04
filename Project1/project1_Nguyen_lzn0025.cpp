/* FILE NAME: project1_Nguyen_lzn0025.cpp
 * AUTHOR: Long Nguyen
 * I mostly copied the project_hint, then following the instruction to finish the project.
 */

#include <iostream>
using namespace std;

int main() {
	
	// VARIABLE INITIALIZATION 
	float loan = -1;
	float interestRate = -1;
	float interestRateC;
	float monthlyPaid = 0;
	unsigned int currentMonth = 0; //make sure Month can't be negative
	float interestTotal = 0;
	
	
	// CURRENCY FORMATTING
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// USER INPUT 
	// NOTE: For valid input, the loan, interest, and monthly payment must 
	// be positive. The monthly payment must also be large enough to 
	// terminate the loan. 
	while (loan < 0) {
		cout << "\nLoan Amount: ";
		cin >> loan;
	}

	while (interestRate < 0) {
		cout << "Interest Rate (% per year): ";
		cin >> interestRate;
	}

	// GET PROPER INTEREST RATES FOR CALCULATIONS 
	interestRate /= 12;
	interestRateC = interestRate / 100;
	//Make sure regular payments are larger than any monthly interest
	while (monthlyPaid <= 0 || monthlyPaid <= loan * interestRateC) {
		cout << "Monthly Payments: ";
		cin >> monthlyPaid;
	}

	cout << endl;

	// AMORTIZATION TABLE
	cout << "*****************************************************************\n"
		<< "\tAmortization Table\n"
		<< "*****************************************************************\n"
		<< "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";


	// LOOP TO FILL TABLE 
	while (loan > 0) {
		if (currentMonth == 0) {
			cout << currentMonth++ << "\t$" << loan;
			if (loan < 1000) cout << "\t"; // Formatting MAGIC
			cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
		}
		else {
			if ((loan * (1 + interestRateC)) < monthlyPaid) {
				monthlyPaid = (loan * (1 + interestRateC));
			}
			else {
				float interestPaid = loan * interestRateC;
				float principal = monthlyPaid - interestPaid;
				loan -= principal;
				interestTotal += interestPaid;
				
				if (loan < 0) {
					principal += loan;
					monthlyPaid += loan;
					loan = 0;
				}

				cout << currentMonth++ << "\t$" << loan;
				
				if (loan < 1000) cout << "\t"; 
				cout << "\t$" << monthlyPaid << "\t"
					<< interestRateC * 100 << "\t$"
					<< interestPaid << "\t\t$"
					<< principal << "\n";
			}
		}
	}

	cout << "****************************************************************\n";
	cout << "\nIt takes " << --currentMonth << " months to pay off "
		<< "the loan.\n"
		<< "Total interest paid is: $" << interestTotal;
	cout << endl << endl;

	return 0;
}
