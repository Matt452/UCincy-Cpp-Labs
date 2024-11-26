#include <iostream>
int main() {
	//Inputs
	int firstYear{};
	std::cout << "Enter the first year: ";
	std::cin >> firstYear;
	int firstPatients{};
	std::cout << "Enter the number of patients we saw that year: ";
	std::cin >> firstPatients;
	int secondYear{};
	std::cout << "Enter the second year: ";
	std::cin >> secondYear;
	int secondPatients{};
	std::cout << "Enter the number of patients we saw that year: ";
	//Calculations
	std::cin >> secondPatients;
	int diffPatients{};
	double diffPatientsP{};
	diffPatients = secondPatients - firstPatients;
	diffPatientsP = (diffPatients * 100.00) / firstPatients;
	double charityYear1, charityYear2;
	charityYear1 = 1071.87 * firstPatients;
	charityYear2 = 1071.87 * secondPatients;
	//Outputs
	std::cout << "In year " << firstYear << ", our hospital issued " << charityYear1 << " dollars of charity charges.\n";
	std::cout << "In year " << secondYear << ", our hospital issued " << charityYear2 << " dollars of charity charges.\n";
	std::cout << "Between " << firstYear << " and " << secondYear << ", there was a " << diffPatientsP << "% increase in patients seen at our hospital.\n";

	return 0;

}
