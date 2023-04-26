#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	(void)av;
	if (ac != 2)
	{
		cout << "this program must take exactly one argument witch is the name of the input file that must be to the format : " << endl << endl << "date | value" << endl << endl << "where date is in a \"Year-Month-Day\" format and value must be either a float or a positive interger between 0 and 1000 included" << endl;
	}
	try
	{
		BitcoinExchange data1("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}