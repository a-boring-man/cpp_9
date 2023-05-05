#include "BitcoinExchange.hpp"

bool check_date_is_correct(string & clean_date) {
	if (clean_date.length() != 10)
		return false;
	if (!(clean_date[4] == '-' && clean_date[7] == '-'))
		return false;
	return true;
}

bool first_part_check_is_ok(string first_half) {

	// create the usefull string and struct
	string trimed_first_half;
	struct tm tm;

	// clean the first part
	//cerr << "first half ->" << first_half << "<-" << endl;
	trimed_first_half = trim(first_half);
	//cerr << "test ->" << trimed_first_half << "<-" << endl;

	// test id the first half contain something other than the | caracter
	if (trimed_first_half.length() < 1)
	{
		cout << "Invalide format, string doesn't have character before '|', expected a date" << endl;
		return false;
	}

	// create the clean first part containing only the date
	// first_part_clean = trim(trimed_first_half.substr(0, first_half.length() - 1));
	// cerr << "test trim clean string : ->" << first_part_clean <<  "<-"  << endl;
	
	// check if the date is correct
	if (!(strptime(trimed_first_half.c_str(), "%Y-%m-%d", &tm) && check_date_is_correct(trimed_first_half)))
	{
		cout << "Invalid format, date are in a wrong format, expected format is : year-month-days with year > 1900 month and days must have 2 caracter" << endl;
		return false;
	}
	return true;
}

string return_first_part(string first_half) {

	//cerr << "j'ai : " << s << "returning ->" << trim(trim(first_half).substr(0, first_half.length() - 1)) << "<-" << endl;
	return trim(first_half);
}

bool second_part_check_is_ok(string second_half) {

	//create the data needed
	string trimed_second_half;

	//cerr << "second_half contain : ->" << second_half << "<- ending here" << endl;
	trimed_second_half = trim(second_half);
	//cerr << "trimed second_half contain : ->" << trimed_second_half << "<- ending here" << endl;

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
	double input_value = atof(second_half.c_str());

	// check if the double is in the correct boundary
	if (!(input_value >= 0 && input_value <= 1000))
	{
		cout.precision(17);
		cout << "Invalide format, the float must be between 0 and 1000 included, found : => " << input_value << endl;
		return false;
	}
	return true;
}

double return_second_half(string second_half) {
	//cerr << "second half ->" << second_half.c_str() << "<-" << endl;
	return atof(second_half.c_str());
}

int main(int ac, char **av) {

	// check if correct number of arguement
	if (ac != 2) {
		cout << "this program must take exactly one argument witch is the name of the input file that must be to the format : " << endl << endl << "date | value" << endl << endl << " where date is in a \"Year-Month-Day\" format and value must be either a float or a positive interger between 0 and 1000 included, ps the first line is ignore" << endl;
		return 1;
	}
	try
	{
		// get the data in the specified file
		BitcoinExchange data1("data.csv");
		data1.display();
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
			//cerr << "buffer contain : ->" << line  << "<- ending here" << endl;

			//if the line doesn't contain a | caractere
			if (line.find('|') == string::npos)
			{
				cout << "Invalide format, string doesn't contain the '|' character" << endl;
				continue;
			}

			// prepare a stream to split the line
			std::stringstream tmp_stream(line);
			//cerr << "buffer contain : ->" << line  << "<- ending here" << endl;
			// split the line into two part on the | caractere putting the first half in first_half
			string first_half;
			getline(tmp_stream, first_half, '|');
			//cerr << "first first_half ->" << first_half << "<-" << endl;
			string second_half;
			getline(tmp_stream, second_half, '|');
			//cerr << "first second_half ->" << second_half << "<-" << endl;

			if (!first_part_check_is_ok(first_half))
				continue;
			if (!second_part_check_is_ok(second_half))
				continue;

			//cerr << "return first half : ->" << return_first_part(first_half) << "<-" << endl;
			string date = data1.get_the_closest_key(return_first_part(first_half));

			if (tmp_stream.good())
				cout << "nice try but i can't accept other format than date | value and nothing else after" << endl;
			else if (date == "false")
				cout << "the bitcoin didn't existed back then sorry i can't say how much : " << return_second_half(second_half) << " was worth" << endl;
			else
				cout << trim(date) << " => " << return_second_half(second_half) << " = " << data1.get_the_value(date) * return_second_half(second_half) << endl;
		}
	}
	catch(char const* s)
	{
		cerr << s << endl;
	}
	
}
