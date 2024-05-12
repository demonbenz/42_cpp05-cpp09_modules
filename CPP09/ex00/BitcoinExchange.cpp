#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

std::map<std::string, double> const & BitcoinExchange::getMap()const
{
	return this->_bit;
}

BitcoinExchange & BitcoinExchange::openAndReadCsvFile(const char * fileName, char delim)
{
	std::ifstream	inF;
	std::string		date;
	double 			number;
	std::string 	line;
	size_t			found;
	
	inF.open(fileName);
	if (inF.is_open())
	{	
		getline(inF, line);
		while(true)
		{
			if(inF.eof())
				break;
			else
			{
				getline(inF, line);
					if (line != "")
					{
						found = line.find(delim);
						if ((found == std::string::npos) && (line != ""))
							throw std::runtime_error("bad input. (,)");
						date = line.substr(0, found);
						date = trim(date);
						checkValidDate(date);
						number =  std::strtod((line.substr(found + 1)).c_str(), NULL);
						setKeyValue(date, number);
					}
			}
		}
		inF.close();
		return(*this);
	}
	else{
		throw std::runtime_error(" Could not open file.");
		return(*this);
	}
}

BitcoinExchange & BitcoinExchange::openAndReadWallet(const char * fileName, char delim)
{
	std::ifstream	inF;
	std::string		rawDate;
	std::string		date;
	std::string 	rawNumber;
	double 			number;
	std::string 	line;
	size_t			found;
	
	inF.open(fileName);
	if (inF.is_open())
	{	
		getline(inF, line);
		while(true)
		{
			if(inF.eof())
				break;
			else
			{
				getline(inF, line);
				try
				{
					if (line != "")
					{
						found = line.find(delim);
						rawDate = line.substr(0, found);
						date = trim(rawDate);
						//std::cout << "trimDate =" << date;
						checkValidDate(date);
						if (found == std::string::npos && (line != ""))
							throw std::runtime_error("bad input");
						rawNumber = line.substr(found + 1);
						checkIsNumber(rawNumber);	
						number =  std::strtod(rawNumber.c_str(), NULL);
						checkFormatValue(number);
						if (date != "")
						{
							std::cout << date << " => " << number << " = " 
							<< (number * getValue(date)) << std::endl;
						}
					}
				}
				catch(std::out_of_range & e)
				{
					std::cout << "Error: " << e.what() << std::endl;
				}
				catch(std::exception & e)
				{
					std::cout << "Error: " << e.what() << " => "<< date << std::endl;
				}
			}
		}
		inF.close();
		return(*this);
	}
	else{
		throw std::runtime_error(" Could not open file.");
		return(*this);
	}
}


void BitcoinExchange::printMap()
{
	std::map<std::string, double>::iterator it = _bit.begin();
	for ( ;it != _bit.end(); it++)
	{
		std::cout << "key:-> |" << it->first << "| : value:-> |" << it->second << "|" << std::endl;
	}
}

std::string BitcoinExchange::trim(const std::string & str)
{
	int start = 0;
	int end = str.length();

	while(start < end && std::isspace(str[start]))
	{
		++start;
	}
	
	while(end > start && std::isspace(str[end - 1]))
	{
		--end;
	}
	return (str.substr(start, end - start));
}

void BitcoinExchange::setKeyValue(const std::string & date, double number)
{
	_bit.insert(std::pair<std::string, double>(date, number));
}
double BitcoinExchange::getCloseValue(const std::string & date)const
{	
	
	std::map<std::string, double>::const_iterator it = _bit.lower_bound(date);
	if (it == _bit.end())
	{
		--it;
		return it->second ;
	}
	else if(it == _bit.begin())
	{
		return it->second ;
	}else 
	{
		std::map<std::string, double>::const_iterator previous = --it;
		return (date.compare(it->first) < date.compare(previous->first) ? it->second : previous->second) ;
	}
}

double BitcoinExchange::getValue(const std::string & date)const
{
	std::map<std::string , double>::const_iterator it = _bit.find(date);
	if(it != _bit.end())
	{
		return(it->second);
	}
	return(getCloseValue(date));
}

void 	BitcoinExchange::checkIsNumber(const std::string & rawNumber)const
{
	std::istringstream iss(rawNumber);
	double num;
	iss >> num;
	if(iss.fail())
		throw std::out_of_range("value is not number.");
}

void	BitcoinExchange::checkFormatValue(const double & number) const
{
	if (number > MAX_INT)
		throw std::out_of_range("too large a number.");
	if (number < 0)
		throw std::out_of_range("not a positive number.");
}

void	BitcoinExchange::checkValidDate(const std::string & date)const
{
	// checkFormatDate(date);
	if (date.size() != 10)
	{
		throw std::out_of_range("date format error.");
	}
	if (date[4] != '-' || date[7] != '-')
		throw std::out_of_range("date format error.");

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);
	char * end;
	
	int year = std::strtol(yearStr.c_str(),&end,10);
	if (*end != '\0' || year < 2009)
		throw std::runtime_error("bad input");

	int month = std::strtol(monthStr.c_str(),&end,10);
	if (*end != '\0' || month < 1 || month > 12)
		throw std::runtime_error("bad input");

	int day = std::strtol(dayStr.c_str(),&end,10);
	if (*end != '\0' || day < 1 || day > 31)
		throw std::runtime_error("bad input");
	
	// checkCalendarDate(date);
	int daysInMonth[] = {31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > daysInMonth[month - 1])
        throw std::runtime_error("bad input");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & rhs) 
{
	*this = rhs;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) 
{
	if (this == &rhs)
		return *this;
	this->_bit = rhs._bit;
	return *this;
}

std::ostream & operator<<( std::ostream & o, BitcoinExchange const & rhs)
{
	o << rhs.getMap();
	return o;
}

std::ostream & operator<<( std::ostream & o, std::map<std::string, double> const & rhs)
{
	std::map<std::string, double>::const_iterator it = rhs.begin();
	for (;it != rhs.end(); it++)
	{
		o << it->first << " => " << it->second << "\n";
	}
	return o;
}