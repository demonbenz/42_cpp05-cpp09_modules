#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define MAX_INT 2147483647

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <cctype>
#include <algorithm>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, double> bit;
public:
	BitcoinExchange();
	~BitcoinExchange();

	//function member
    BitcoinExchange & openAndReadCsvFile(const char * fileName, char delim);
    BitcoinExchange & openAndReadWallet(const char * fileName, char delim);

	void setKeyValue(const std::string & date, double number);
	double getCloseValue(const std::string & date)const;
	double getValue(const std::string & date)const;

	void 	checkIsNumber(const std::string & rawNumber)const;
	void	checkValidDate(const std::string & date) const;
	void	checkFormatValue(const double & number) const;
	void	printMap();

	std::string trim(const std::string & str);
};

#endif