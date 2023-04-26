/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:53:43 by jrinna            #+#    #+#             */
/*   Updated: 2023/04/26 15:49:39 by jrinna           ###   ########lyon.fr   */
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
		cerr << "the database couldn't be open, please check the file right or location" << endl;
		throw -1;
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
		cerr << "buffer contain : ->" << line  << "<- ending here" << endl;
		getline(tmp_stream, tmp1, ',');
		cerr << "tmp1 contain : ->" << tmp1  << "<- ending here" << endl;
		getline(tmp_stream, tmp2, ',');
		cerr << "tmp2 contain : ->" << tmp2 << "<- ending here" << endl;
		rate_table.insert(std::pair<string, double>(tmp1, strtod(tmp2.c_str(), NULL)));
		cerr << "buffer contain : ->" << line  << "<- ending here" << endl;	
	}
	for (map<string, double>::iterator it = rate_table.begin(); it != rate_table.end(); it++) {
		cerr << "->" << it->first << "<- : ->" << it->second << "<-" << endl;
	}
}

double	BitcoinExchange::get_the_value(const string & key) {
	map<string, double>::const_iterator it = rate_table.find(key);
	if (it != rate_table.end())
		return it->second;
	if (rate_table.size() == 1) {
		return rate_table[0];
	}
	for (it = rate_table.begin(); it != rate_table.end(); it++) {
		int cmp = it->first.compare(key);
		if (cmp > 0) {
			it--;
			return it->second;
		}
	}
	return rate_table.rbegin()->second;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */