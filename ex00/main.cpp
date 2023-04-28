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
		ifstream file(av[1]);
		if (!file.is_open())
		{
			throw "can't open input file";
		}
		string line, tmp1, tmp2;
		std::getline(file, line);
		while (file.good())
		{
			std::getline(file, line);
			std::stringstream tmp_stream(line);
			cerr << "buffer contain : ->" << line  << "<- ending here" << endl;
			getline(tmp_stream, tmp1, '|');
			cerr << "tmp1 contain : ->" << tmp1  << "<- ending here" << endl;
			getline(tmp_stream, tmp2, ',');
			cerr << "tmp2 contain : ->" << tmp2 << "<- ending here" << endl;
			string date = data1.get_the_closest_key(tmp1);
			cout << trim(date) << " => " << trim(tmp2) << " = " << data1.get_the_value(date) * strtod(tmp2.c_str(), NULL) << endl;
			cerr << "buffer contain : ->" << line  << "<- ending here" << endl;	
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}