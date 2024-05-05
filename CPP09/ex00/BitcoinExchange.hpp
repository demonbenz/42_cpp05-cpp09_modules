#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <cctype>
#include <algorithm>

std::string& ltrim(std::string &str);
std::string& rtrim(std::string &str);
std::string& trim(std::string &str);

class Bitcoin /* :public std::map<std::string, double>*/
{
private:
	std::map<std::string, double> bit;
public:
	//Bitcoin();
	//~Bitcoin();
	//function member

    Bitcoin & openAndReadCsvFile(const char * fileName, char delim);
    Bitcoin & openAndReadWallet(const char * fileName, char delim);

	void setKeyValue(const std::string & date, double number);
	double getValue(const std::string & date)const;

	void printMap();
};

#endif
