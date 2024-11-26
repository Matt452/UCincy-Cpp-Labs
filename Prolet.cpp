#include <iostream>
#include <string>

int get_int();
double calculate_per_capita_gdp_estimate(int quarters_from_epoch);
std::string format_money(double money);
std::string quarter_to_ordinal(int quarter);

int main() {
	double epoch{};
	double zeroY{};
	double year{};
	double quarter{};
	double Tquarters{};
	std::string strQuarter{};

	// Inputs
	std::cout << "Please enter the year for the calculation: ";
	std::cin >> year;
	std::cout << "Please enter the quarter for the calculation: ";
	std::cin >> quarter;
	if (quarter == 1)
		strQuarter = "first";
	else if (quarter == 2)
		strQuarter = "second";
	else if (quarter == 3)
		strQuarter = "third";
	else if (quarter == 4)
		strQuarter = "fourth";

	// Calculations
	epoch = 1977 * 4;
	zeroY = year * 4 + (quarter - 1);
	Tquarters = zeroY - epoch;

	// Calculate GDP per capita
	double per_capita_gdp_estimate = calculate_per_capita_gdp_estimate(Tquarters);

	// Output
	std::cout << "In the " << strQuarter << " quarter of " << year << ", the projected contribution to GDP per working-age person is $" << format_money(per_capita_gdp_estimate) << ".\n";

	return 0;
}