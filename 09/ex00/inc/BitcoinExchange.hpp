#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstring>

#define CSV_PATH "data.csv"

class BitcoinExchange
{
private:
	std::map<std::string, std::string> _rates;

public:
	// Orthodox Canonical Form
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &other);

	// Methods
	bool is_valid_date(const std::string &date) const;
	bool is_valid_value(const std::string &value) const;

	// Getters
	const std::map<std::string, std::string> get_rates() const;
	const std::string get_rate_key(const std::string &date) const;

	int date_to_int(const std::string &date) const;
};
