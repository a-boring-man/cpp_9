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
		//cout << "left size : " << left.size() << "right size : " << right.size() << endl;
		sort_vec(minimum_size, left);
		sort_vec(minimum_size, right);
		merge_vec(left, right, vec);
	}
	insertion_sort_vec(vec);
}

void	PmergeMe::merge_vec(const vector<unsigned int> & left, const vector<unsigned int> & right, vector<unsigned int> & result) {
	vector<unsigned int>::const_iterator itl = left.begin();
	vector<unsigned int>::const_iterator itr = right.begin();
	vector<unsigned int>::iterator itresult = result.begin();
	while (itl != left.end() && itr != right.end())
	{
		if (*itl <= *itr) {
			*itresult = *itl;
			itl++;
		}
		else {
			*itresult = *itr;
			itr++;
		}
		itresult++;
	}
	while (itl != left.end()) {
		*itresult = *itl;
		itresult++;
		itl++;
	}
	while (itr != right.end()) {
		*itresult = *itr;
		itresult++;
		itr++;
	}
	// cout << "try ->" << endl;
	// for (vector<unsigned int>::iterator it = result.begin(); it != result.end(); it++) {
	// 	cout << *it << ", ";
	// }
	// cout << endl;
}

void 	PmergeMe::insertion_sort_vec(vector<unsigned int> & vec) {
	unsigned long size = vec.size();
	for (unsigned long i = 0; i < size; i++)
	{
		unsigned long j = i;
		while (j > 0 && vec[j - 1] > vec[i])
		{
			vec[j - 1] = vec[j - 1] ^ vec[i];
			vec[i] = vec[j - 1] ^ vec[i];
			vec[j - 1] = vec[j - 1] ^ vec[i];
		}
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