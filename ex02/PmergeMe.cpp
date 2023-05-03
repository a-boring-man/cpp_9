#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->vec = rhs.getVec();
		this->lst = rhs.getLst();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	PmergeMe::sort_vec(unsigned int minimum_size, vector<unsigned int> & vec) {
	if (vec.size() > minimum_size && vec.size() > 1)
	{
		vector<unsigned int> left(vec.begin(), vec.begin() + vec.size() / 2);
		vector<unsigned int> right(vec.begin() + vec.size() / 2, vec.end());
		cout << "left size : " << left.size() << "right size : " << right.size() << endl;
		sort_vec(minimum_size, left);
		sort_vec(minimum_size, right);
	}
	
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const vector<unsigned int> & PmergeMe::getVec() const {
	return vec;
}

const list<unsigned int> & PmergeMe::getLst() const {
	return lst;
}

/* ************************************************************************** */