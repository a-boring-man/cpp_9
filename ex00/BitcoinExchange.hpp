/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:53:40 by jrinna            #+#    #+#             */
/*   Updated: 2023/04/26 14:56:13 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>

using std::map;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

class BitcoinExchange
{

	public:

		BitcoinExchange(const char * database);
		~BitcoinExchange();

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

	private:

		map<string, double>	rate_table;
		
		double get_the_value(const string & key);
		void build_map(ifstream & file);
	
		BitcoinExchange( BitcoinExchange const & src );
		BitcoinExchange();

};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );

#endif /* ************************************************* BITCOINEXCHANGE_H */