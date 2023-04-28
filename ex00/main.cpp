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
		struct tm tm;
		std::getline(file, line);
		while (file.good())
		{
			std::getline(file, line);
			if (line.find('|') == string::npos)
			{
				cout << "Invalide format, string doesn't contain the '|' character" << endl;
				continue;
			}
			std::stringstream tmp_stream(line);
			cerr << "buffer contain : ->" << line  << "<- ending here" << endl;
			getline(tmp_stream, tmp1, '|');
			cerr << "test ->" << trim(tmp1) << "<-" << endl;
			if (trim(tmp1).length() < 1)
			{
				cout << "Invalide format, string doesn't have character before '|', expected a date" << endl;
				continue;
			}
			cerr << "tmp1 contain : ->" << tmp1  << "<- ending here" << endl;
			string first_part_clean = trim(tmp1.substr(0, tmp1.length() - 1));
			cerr << "test trim clean string : ->" << first_part_clean <<  "<-"  << endl;
			if (!strptime(first_part_clean.c_str(), "%Y-%m-%d", &tm))
			{
				cout << "Invalid format, date are in a wrong format, expected format is : year-month-days" << endl;
				continue;
			}

			getline(tmp_stream, tmp2, '|');
			if (trim(tmp2).empty())
			{
				cout << "Invalide format, string doesn't have character after '|', expected a float" << endl;
				continue;
			}
			if (!is_a_valid_double(trim(tmp2)))
			{
				cout << "Invalide format, the right end side of the '|' character is not in a valide float format, expecting number from 0-9, '.', ',' only" << endl;
				continue;
			}
			double input_value = strtod(tmp2.c_str(), NULL);
			if (!(input_value >= 0 && input_value <= 1000))
			{
				cout.precision(17);
				cout << "Invalide format, the float must be between 0 and 1000 included, found : => " << input_value << endl;
				continue;
			}
			cerr << "tmp2 contain : ->" << tmp2 << "<- ending here" << endl;




			string date = data1.get_the_closest_key(tmp1);

			cout << trim(date) << " => " << trim(tmp2) << " = " << data1.get_the_value(date) * strtod(tmp2.c_str(), NULL) << endl;
			cerr << "buffer contain : ->" << line  << "<- ending here" << endl;
			tmp1.clear();
			tmp2.clear();
			first_part_clean.clear();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}