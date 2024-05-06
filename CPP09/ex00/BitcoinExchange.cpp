#include "BitcoinExchange.hpp"


Bitcoin & Bitcoin::openAndReadCsvFile(const char * fileName, char delim)
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
						// std::cout << "key date =<" << date << ">";
						//checkValidDate(date);
						number =  std::strtod((line.substr(found + 1)).c_str(), NULL);
						// std::cout << ", value = <" << number << ">" << std::endl;	
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

Bitcoin & Bitcoin::openAndReadWallet(const char * fileName, char delim)
{
	std::ifstream	inF;
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
						if (found == std::string::npos && (line != ""))
							throw std::runtime_error("bad input => ");
						date = line.substr(0, found);
						date = trim(date);
						//std::cout << "trimDate =" << date;
						checkValidDate(date);
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
				catch(std::exception & e)
				{
					std::cout << "Error: " << e.what() <<std::endl;
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


void Bitcoin::printMap()
{
	std::map<std::string, double>::iterator it = bit.begin();
	for ( ;it != bit.end(); it++)
	{
		std::cout << "key:-> |" << it->first << "| : value:-> |" << it->second << "|" << std::endl;
	}
}

std::string& ltrim(std::string &str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return str;
}

std::string& rtrim(std::string &str) {
    str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
    return str;
}

std::string& trim(std::string &str) {
    return ltrim(rtrim(str));
}

void Bitcoin::setKeyValue(const std::string & date, double number)
{
	bit.insert(std::pair<std::string, double>(date, number));
}
double Bitcoin::getValue(const std::string & date)const
{	
	
	std::map<std::string, double>::const_iterator it = bit.lower_bound(date);
	if (it == bit.end())
	{
		--it;
		return it->second ;
	}
	else if(it == bit.begin())
	{
		return it->second ;
	}else 
	{
		std::map<std::string, double>::const_iterator previous = --it;
		return (date.compare(it->first) < date.compare(previous->first) ? it->second : previous->second) ;
	}
}

void 	Bitcoin::checkIsNumber(const std::string & rawNumber)const
{
	std::istringstream iss(rawNumber);
	double num;
	iss >> num;
	if(iss.fail())
		throw std::out_of_range("value is not number.");
}

void	Bitcoin::checkFormatValue(const double & number) const
{
	if (number > MAX_INT)
		throw std::out_of_range("too large a number.");
	if (number < 0)
		throw std::out_of_range("not a positive number.");
}

void	Bitcoin::checkValidDate(const std::string & date)const
{
	// checkFormatDate(date);
	if (date.size() != 10)
	{
		throw std::out_of_range("date format error.(size)");
	}
	if (date[4] != '-' || date[7] != '-')
		throw std::out_of_range("date format error.(-)");

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);
	char * end;
	
	int year = std::strtol(yearStr.c_str(),&end,10);
	if (*end != '\0' || year < 2009)
		throw std::out_of_range("date format error.(year)");

	int month = std::strtol(monthStr.c_str(),&end,10);
	if (*end != '\0' || month < 1 || month > 12)
		throw std::out_of_range("date format error.(month)");

	int day = std::strtol(dayStr.c_str(),&end,10);
	if (*end != '\0' || day < 1 || day > 31)
		throw std::out_of_range("date format error.(day)");
	
	// checkCalendarDate(date);
	int daysInMonth[] = {31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > daysInMonth[month - 1])
        throw std::out_of_range("date format error.(not in carlendar)");
}
