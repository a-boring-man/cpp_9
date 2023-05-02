#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cstdlib>

using std::stack;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::atof;

class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

		double			getResult() const;
		void		calculate(const string & s);

	private:

		bool		is_valide(const string & s) const;
		bool		is_in_charset(char c, const string & charset) const;
		int			count_signe(const string & s) const;
		int			count_nbr(const string & s) const;
		stack<double> order;
		double		result;

};

#endif /* ************************************************************* RPN_H */