/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:53:43 by jrinna            #+#    #+#             */
/*   Updated: 2023/04/26 14:44:02 by jrinna           ###   ########lyon.fr   */
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

	string line, tmp;
	if (file.good())
			std::getline(file, line);
	while (file.good())
	{
		std::getline(file, line);
		std::stringstream tmp_stream(line);
		cerr << "buffer contain : ->" << line  << "<- ending here" << endl;
		getline(tmp_stream, tmp, ',');
		cerr << "tmp1 contain : ->" << tmp  << "<- ending here" << endl;
		getline(tmp_stream, tmp, ',');
		cerr << "tmp2 contain : ->" << tmp << "<- ending here" << endl;
		cerr << "buffer contain : ->" << line  << "<- ending here" << endl;	
	}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */