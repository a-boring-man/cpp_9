#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() : result(0)
{
}

RPN::RPN( const RPN & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
		this->result = rhs.getResult();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int		RPN::count_signe(const string & s) const {
	int size = s.length();
	int result = 0;
	for (int i = 0; i < size; i++) {
		if (is_in_charset(s.c_str()[i], "+-/*"))
			result++;
	}
	return result;
}

int		RPN::count_nbr(const string & s) const {
	int size = s.length();
	int result = 0;
	for (int i = 0; i < size; i++) {
		if (s.c_str()[i] >= '0' && s.c_str()[i] <= '9')
			result++;
	}
	return result;
}

bool	RPN::is_in_charset(char c, const string & charset) const {
	int size = charset.length();
	for (int i = 0; i < size; i++)
		if (c == charset.c_str()[i])
			return true;
	return false;
}

bool	RPN::is_valide(const string & s) const {
	int size = s.length();
	for (int i = 0; i < size; i++) {
		if (!is_in_charset(s.c_str()[i], "0123456789-+*/ "))
			return false;
	}
	int nbr_signe = count_signe(s);
	int nbr_nbr = count_nbr(s);
	return (nbr_nbr - nbr_signe == 1);
}

void	RPN::calculate(const string & s) {
	if (!is_valide(s))
		throw "invalid format";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	RPN::getResult() const {
	return result;
}


/* ************************************************************************** */