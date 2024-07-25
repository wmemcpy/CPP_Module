#include "BitcoinExchange.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange be;
	std::string line;
	std::getline(inputFile, line); // Skip header line

	while (std::getline(inputFile, line))
	{
		if (line.empty())
			continue;
		std::stringstream ss(line);
		std::string date;
		std::string value;

		std::getline(ss, date, ' ');
		ss.seekg(date.length() + 3); // Skip ' | '
		std::getline(ss, value, ' ');

		// Check if date and value are valid
		if (!be.is_valid_date(date))
			std::cout << "Error: bad input => " << date << std::endl;
		else if (!be.is_valid_value(value))
			continue;
		else
		{
			// Convert value to float
			float rate_value = std::atof(be.get_rates().at(be.get_rate_key(date)).c_str());
			float value_float = std::atof(value.c_str());

			rate_value *= value_float;

			std::cout << date << " => " << value << " = " << rate_value << std::endl;
		}
	}

	inputFile.close();
	return 0;
}
