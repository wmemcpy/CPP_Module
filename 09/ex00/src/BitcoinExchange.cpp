#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file(CSV_PATH);
	if (!file.good())
	{
		std::cout << "File does not exist" << std::endl;
		return;
	}

	std::string line;

	std::getline(file, line); // Skip header line

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string rate;

		std::getline(ss, date, ',');
		std::getline(ss, rate);

		_rates[date] = rate;
	}

	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	if (this != &other)
		*this = other;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other.get_rates();
	return *this;
}

bool BitcoinExchange::is_valid_date(const std::string &date) const
{
	std::stringstream ss(date);
	std::string year_str, month_str, day_str;

	std::getline(ss, year_str, '-');
	std::getline(ss, month_str, '-');
	std::getline(ss, day_str, ' ');

	for (std::string::size_type i = 0; i < year_str.length(); i++)
		if (year_str[i] < '0' || year_str[i] > '9')
			return false;
	for (std::string::size_type i = 0; i < month_str.length(); i++)
		if (month_str[i] < '0' || month_str[i] > '9')
			return false;
	for (std::string::size_type i = 0; i < day_str.length(); i++)
		if (day_str[i] < '0' || day_str[i] > '9')
			return false;

	int year = atoi(year_str.c_str());
	int month = atoi(month_str.c_str());
	int day = atoi(day_str.c_str());

	if (month < 1 || month > 12)
		return false;

	bool is_leap_year = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

	int days_in_month[] = {31, (is_leap_year ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (day < 1 || day > days_in_month[month - 1])
		return false;

	return true;
}

bool BitcoinExchange::is_valid_value(const std::string &value) const
{
	if (value.length() == 0)
		return false;

	if (value[0] == '-')
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}

	bool dot = false;
	for (std::string::size_type i = 0; i < value.length() && !std::isspace(value[i]); i++)
	{
		if (value[i] == '.')
		{
			if (dot)
			{
				std::cout << "Error: not a valid number." << std::endl;
				return false;
			}
			dot = true;
		}
		else if (value[i] < '0' || value[i] > '9')
		{
			std::cout << "Error: not a valid number." << std::endl;
			return false;
		}
	}

	float floatValue = atof(value.c_str());

	if (floatValue < 0 || floatValue > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

const std::map<std::string, std::string> BitcoinExchange::get_rates() const
{
	return _rates;
}

int BitcoinExchange::date_to_int(const std::string &date) const
{
	std::stringstream ss(date);
	std::string year_str, month_str, day_str;
	std::getline(ss, year_str, '-');
	std::getline(ss, month_str, '-');
	std::getline(ss, day_str, ',');

	int year = std::atoi(year_str.c_str());
	int month = std::atoi(month_str.c_str());
	int day = std::atoi(day_str.c_str());

	return year * 10000 + month * 100 + day;
}

const std::string BitcoinExchange::get_rate_key(const std::string &date) const
{
	std::string closest_date = "";
	int min_diff = std::numeric_limits<int>::max();
	int input_date_int = date_to_int(date);

	for (std::map<std::string, std::string>::const_iterator it = _rates.begin(); it != _rates.end(); ++it)
	{
		int current_date_int = date_to_int(it->first);
		int diff = input_date_int - current_date_int;

		if (diff >= 0 && diff < min_diff)
		{
			min_diff = diff;
			closest_date = it->first;
			// std::cout << closest_date << std::endl;
		}
	}

	return closest_date;
}
