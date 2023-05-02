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
		if (is_in_charset(s[i], "+-/*"))
			result++;
	}
	return result;
}

int		RPN::count_nbr(const string & s) const {
	int size = s.length();
	int result = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] >= '0' && s[i] <= '9')
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
		if (!is_in_charset(s[i], "0123456789-+*/ "))
			return false;
	}
	int nbr_signe = count_signe(s);
	int nbr_nbr = count_nbr(s);
	return (nbr_nbr - nbr_signe == 1);
}

void	RPN::calculate(const string & s) {
	if (!is_valide(s))
		throw "invalid format";
	int size = s.length();
	for (int i = 0; i < size; i++) {
		double result = 0, elm1 = 0, elm2 = 0;
		if (s[i] == ' ')
			continue;
		else if (is_in_charset(s[i], "+-*/") && order.size() <= 1)
			throw "logical error operator without enough operant";
		else if (s[i] == '*') {
			elm1 = order.top();
			order.pop();
			elm2 = order.top();
			order.pop();
			result = elm2 * elm1;
			order.push(result);
		}
		else if (s[i] == '+') {
			elm1 = order.top();
			order.pop();
			elm2 = order.top();
			order.pop();
			result = elm2 + elm1;
			order.push(result);
		}
		else if (s[i] == '-') {
			elm1 = order.top();
			order.pop();
			elm2 = order.top();
			order.pop();
			result = elm2 - elm1;
			order.push(result);
		}
		else if (s[i] == '/') {
			elm1 = order.top();
			order.pop();
			elm2 = order.top();
			order.pop();
			if (elm1 < 0.000001 && elm1 > -0.000001)
				throw "division by zero or near zero happening";
			result = elm2 / elm1;
			order.push(result);
		}
		else if (is_in_charset(s[i], "0123456789"))
			order.push(s[i] - '0');
		cerr << "inter resolut = " << result << endl;
	}
	if (order.size() == 1)
		result = order.top();
	cerr << result << endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

double	RPN::getResult() const {
	return result;
}


/* ************************************************************************** */