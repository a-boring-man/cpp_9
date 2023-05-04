#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <cstdlib>
# include <time.h>

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::list;
using std::advance;

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		const vector<unsigned int> & getVec() const;
		const list<unsigned int> & getLst() const;
		vector<unsigned int> & get_modif_vec();
		list<unsigned int> & get_modif_lst();

		void	sort_vec(unsigned int minimum_size, vector<unsigned int> & vec);
		void	sort_list(unsigned int minimum_size, list<unsigned int> & lst);
		void	add(unsigned int i);

	private:

		vector<unsigned int>	vec;
		list<unsigned int>		lst;

		void	insertion_sort_vec(vector<unsigned int> & vec);
		void	insertion_sort_lst(list<unsigned int> & lst);
		void	merge_vec(const vector<unsigned int> & left, const vector<unsigned int> & right, vector<unsigned int> & result);
		void	merge_list(const list<unsigned int> & left, const list<unsigned int> & right, list<unsigned int> & result);
};

#endif /* ******************************************************** PMERGEME_H */