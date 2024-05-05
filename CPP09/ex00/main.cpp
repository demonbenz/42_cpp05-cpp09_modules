#include "BitcoinExchange.hpp"

// int checkValidDate(std::string & date);

int main(int argc, char *argv[])
{
	Bitcoin btc;
	//Bitcoin wallet;

	if(argc != 2)
	{
		std::cout << "Error : Could not open file.(arguement != 1)" << std::endl;
		return 1;
	}
	else
	{
		try
		{
			btc.openAndReadCsvFile("data.csv", ',');
			btc.openAndReadWallet(argv[1], '|');
		}
		catch(std::exception & e)
		{
			std::cout << "Error :" << e.what() << std::endl;
			return (1);
		}
		//btc.printMap();
	}
	return 0;
}
