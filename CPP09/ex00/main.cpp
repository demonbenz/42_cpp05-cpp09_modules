#include "BitcoinExchange.hpp"

int	openAndRead(const char* filename, char delim, std::map<std::string, double> & mp);
// int checkValidDate(std::string & date);

void printMap(std::map<std::string, double> & mp);

int main(int argc, char *argv[])
{
	std::map<std::string, double> Btc;
	std::map<std::string, double> Wallet;
	if(argc == 2)
	{
		if(openAndRead("data.csv", ',', Btc) == 1)
		{
			std::cout << "Error: could not open file." << std::endl;
			return (1);
		}
		if(openAndRead(argv[1], '|', Wallet) == 1)
		{
			std::cout << "Error: could not open file." << std::endl;
			return (1);
		}
		//printMap(Btc);
		//printMap(Wallet);
		// calculate data
		// output function display
	}
	else
	{
		std::cout << "Error: could not open file.(arguement != 1)" << std::endl;
		return 1;
	}
	return 0;
}


int	openAndRead(const char * filename, char delim, std::map<std::string, double> & mp)
{
	std::ifstream inF;
	std::string date;
	double 		number;
	inF.open(filename);
	std::string line;
	if (inF.is_open())
	{
		if (inF.fail())
		{
			return (1);
		}	
		getline(inF, line, '\n');
		while(true)
		{
			if(inF.eof())
				break;
			else
			{
				getline(inF, line, '\n');
				try{
				date = line.substr(0,line.find(delim));
				// checkValidDate(date);
				number =  std::strtod((line.substr(line.find(delim) + 1)).c_str(), NULL);
				}
				catch(std::exception & e)
				{
					std::cout << e.what() <<std::endl;
				}
				mp.insert(std::pair<std::string, double>(date, number));
			}
		}
		inF.close();
		return(0);
	}
	return(1);
}


void printMap(std::map<std::string, double> & mp)
{
	std::map<std::string, double>::iterator it = mp.begin();
	for ( ;it != mp.end(); it++)
	{
		std::cout << "key:-> " << it->first << " : value:-> " << it->second << std::endl;
	}
}
// int checkValidDate(std::string & date)
// {
// 	if (date)
// 		return (0);
// 	return (1);
// }