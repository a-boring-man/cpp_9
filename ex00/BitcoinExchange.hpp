/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:53:40 by jrinna            #+#    #+#             */
/*   Updated: 2023/04/26 14:39:23 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>

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

		BitcoinExchange( BitcoinExchange const & src );
		BitcoinExchange();
		void build_map(ifstream & file);
		map<string, float>	rate_table;

};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );

#endif /* ************************************************* BITCOINEXCHANGE_H */