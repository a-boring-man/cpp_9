#include "BitcoinExchange.hpp"

bool first_part_check_is_ok(std::stringstream & s) {

	// create the usefull string and struct
	string first_half;
	string trimed_first_half;
	string first_part_clean;
	struct tm tm;

	// split the line into two part on the | caractere putting the first half in first_half
	getline(s, first_half, '|');

	// clean the first part
	trimed_first_half = trim(first_half);
	cerr << "test ->" << trimed_first_half << "<-" << endl;

	// test id the first half contain something other than the | caracter
	if (trimed_first_half.length() < 1)
	{
		cout << "Invalide format, string doesn't have character before '|', expected a date" << endl;
		return false;
	}

	// create the clean first part containing only the date
	first_part_clean = trim(trimed_first_half.substr(0, first_half.length() - 1));
	cerr << "test trim clean string : ->" << first_part_clean <<  "<-"  << endl;
	
	// check if the date is correct
	if (!strptime(first_part_clean.c_str(), "%Y-%m-%d", &tm))
	{
		cout << "Invalid format, date are in a wrong format, expected format is : year-month-days" << endl;
		return false;
	}
	return true;
}

string return_first_part(std::stringstream & s) {

	string first_half;
	string first_part_clean;
	getline(s, first_half, '|');
	cerr << "returning ->" << trim(trim(first_half).substr(0, first_half.length() - 1)) << "<-" << endl;
	return trim(trim(first_half).substr(0, first_half.length() - 1));
}

bool second_part_check_is_ok(std::stringstream & s) {

	//create the data needed
	string second_half;
	string trimed_second_half;

	// get the second half of the string
	getline(s, second_half, '|');
	cerr << "second_half contain : ->" << second_half << "<- ending here" << endl;
	trimed_second_half = trim(second_half);
	cerr << "trimed second_half contain : ->" << trimed_second_half << "<- ending here" << endl;

	// check if the second half contain something
	if (trimed_second_half.empty())
	{
		cout << "Invalide format, string doesn't have character after '|', expected a float" << endl;
		return false;
	}

	// check if the contain of the second half is a correct format for the expected float
	if (!is_a_valid_double(trimed_second_half))
	{
		cout << "Invalide format, the right end side of the '|' character is not in a valide float format, expecting number from 0-9, '.', ',' only" << endl;
		return false;
	}

	// convert the string into a double
	double input_value = strtod(second_half.c_str(), NULL);

	// check if the double is in the correct boundary
	if (!(input_value >= 0 && input_value <= 1000))
	{
		cout.precision(17);
		cout << "Invalide format, the float must be between 0 and 1000 included, found : => " << input_value << endl;
		return false;
	}
	return true;
}

double return_second_half(std::stringstream & s) {
	string second_half;
	getline(s, second_half, '|');
	return strtod(second_half.c_str(), NULL);
}

int main(int ac, char **av) {

	// check if correct number of arguement
	if (ac != 2) {
		cout << "this program must take exactly one argument witch is the name of the input file that must be to the format : " << endl << endl << "date | value" << endl << endl << " where date is in a \"Year-Month-Day\" format and value must be either a float or a positive interger between 0 and 1000 included, ps the first line is ignore" << endl;
	}
	try
	{
		// get the data in the specified file
		BitcoinExchange data1("data.csv");

		// try to open the input file
		ifstream file(av[1]);
		if (!file.is_open()) {
			throw "can't open input file";
		}

		// init usefull data
		string line;

		//skip the first line of the file
		std::getline(file, line);

		// as long as the file contain something
		while (file.good())
		{
			// get the line
			std::getline(file, line);
			cerr << "buffer contain : ->" << line  << "<- ending here" << endl;

			//if the line doesn't contain a | caractere
			if (line.find('|') == string::npos)
			{
				cout << "Invalide format, string doesn't contain the '|' character" << endl;
				continue;
			}

			// prepare a stream to split the line
			std::stringstream tmp_stream(line);
			cerr << "buffer contain : ->" << line  << "<- ending here" << endl;

			if (!first_part_check_is_ok(tmp_stream))
				continue;
			if (!second_part_check_is_ok(tmp_stream))
				continue;

			string date = data1.get_the_closest_key(return_first_part(tmp_stream));

			cout << trim(date) << " => " << return_second_half(tmp_stream) << " = " << data1.get_the_value(date) * return_second_half(tmp_stream) << endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
