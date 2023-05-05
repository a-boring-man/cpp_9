/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:53:43 by jrinna            #+#    #+#             */
/*   Updated: 2023/05/05 13:16:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{ (void)src;
}

BitcoinExchange::BitcoinExchange(const char * database) {
	ifstream file(database);
	if (!file.is_open())
	{
		//cerr << "the database couldn't be open, please check the file right or location" << endl;
		throw "error opening file";
	}
	else {
		this->build_map(file);
	}
	file.close();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
	rate_table.clear();
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i )
{
	(void)i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void BitcoinExchange::build_map(ifstream & file) {

	string line, tmp1, tmp2;
	if (file.good())
			std::getline(file, line);
	while (file.good())
	{
		std::getline(file, line);
		std::stringstream tmp_stream(line);
		//cerr << "buffer contain : ->" << line  << "<- ending here" << endl;
		getline(tmp_stream, tmp1, ',');
		//cerr << "tmp1 contain : ->" << tmp1  << "<- ending here" << endl;
		getline(tmp_stream, tmp2, ',');
		//cerr << "tmp2 contain : ->" << tmp2 << "<- ending here" << endl;
		if (!tmp1.empty())
			rate_table.insert(std::pair<string, double>(trim(tmp1), atof(tmp2.c_str())));
		//cerr << "buffer contain : ->" << line  << "<- ending here" << endl;	
	}
	// for (map<string, double>::iterator it = rate_table.begin(); it != rate_table.end(); it++) {
	// 		cerr << "->" << it->first << "<- : ->" << it->second << "<-" << endl;
	// }
	if (rate_table.size() == 0){
		throw "no data where found in the file/ folder";
	}
}

void	BitcoinExchange::display() const {
	for (map<string, double>::const_iterator it = rate_table.begin(); it != rate_table.end(); it++){
		//cerr << "->" << it->first << "<-" << endl;
	}
}

double	BitcoinExchange::get_the_value(const string & key) {
	map<string, double>::const_iterator it = rate_table.find(trim(key));
	if (it != rate_table.end())
		return it->second;
	if (rate_table.size() == 1) {
		return rate_table.begin()->second;
	}
	for (it = rate_table.begin(); it != rate_table.end(); it++) {
		int cmp = it->first.compare(trim(key));
		if (cmp > 0) {
			it--;
			return it->second;
		}
	}
	return rate_table.rbegin()->second;
}


const string &	BitcoinExchange::get_the_closest_key(const string & key) {
	map<string, double>::const_iterator it = rate_table.find(trim(key));
	if (it != rate_table.end())
		return it->first;
	if (rate_table.size() == 1) {
		return rate_table.begin()->first;
	}
	//cerr << "heu.... ->" << rate_table.begin()->first.compare(trim(key)) << "<-" << "key : ->" << key << "<-" << "begin : ->" << rate_table.begin()->first << "<-" << endl;
	if (rate_table.begin()->first.compare(trim(key)) > 0)
		return rate_table.begin()->first;
	for (it = rate_table.begin(); it != rate_table.end(); it++) {
		int cmp = it->first.compare(trim(key));
		//cout << "comparing" << it->first << endl;
		if (cmp > 0) {
			it--;
			return it->first;
		}
	}
	return rate_table.rbegin()->first;
}

string ltrim(const string & s) {
	size_t start = s.find_first_not_of(' ');
	return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string & s) {
	size_t end = s.find_last_not_of(' ');
	return (end == string::npos) ? "" : s.substr(0, end + 1);
}

const string trim(const string & s) {
	return rtrim(ltrim(s));
}

bool is_a_valid_double(const string & s) {
	// finit state table 0-9 and .,
	const int tbl[2][5] = {{1, 1, 3, 3, 3}, {2, 4, -1, -1, -1}};
	int cs = 0;

	for (size_t i = 0; cs > -1 && s.length() > i && s.at(i); i++)
	{
		if (s.at(i) >= '0' && s.at(i) <= '9')
			cs = tbl[0][cs];
		else if (s.at(i) == '.' || s.at(i) == ',')
			cs = tbl[1][cs];
		else
			cs = -1;
	}
	return cs == 1 || cs == 3 || cs == 4;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */