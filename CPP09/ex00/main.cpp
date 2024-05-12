#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange btc;

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
			std::cout << "Error: " << e.what() << std::endl;
			return (1);
		}
		//btc.printMap();
		//std::cout << btc.getMap();
	}
	return 0;
}
