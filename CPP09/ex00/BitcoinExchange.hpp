#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

std::map<std::string, double> Btc;
std::map<std::string, double> Wallet;

class Bitcoin :public std::map<std::string, double>
{
private:
public:
	Bitcoin();
	~Bitcoin();
	//function member
};

#endif
