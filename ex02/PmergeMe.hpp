#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::list;

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		const vector<unsigned int> & getVec() const;
		const list<unsigned int> & getLst() const;

		void	sort_vec(unsigned int minimum_size, vector<unsigned int> & vec);
		void	sort_list(unsigned int minimum_size);

	private:

		vector<unsigned int>	vec;
		list<unsigned int>		lst;

		void	insertion_sort_vec(vector<unsigned int> & vec);
};

#endif /* ******************************************************** PMERGEME_H */