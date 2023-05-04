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

void	PmergeMe::sort_list(unsigned int minimum_size, list<unsigned int> & lst) {
	unsigned long size = lst.size();
	if (size > minimum_size && size > 1)
	{
		list<unsigned int>::iterator middle_it = lst.begin();
		advance(middle_it, size / 2);
		
		list<unsigned int> left(lst.begin(), middle_it);
		list<unsigned int> right(middle_it, lst.end());
		//cout << "left size : " << left.size() << "right size : " << right.size() << endl;
		sort_list(minimum_size, left);
		sort_list(minimum_size, right);
		merge_list(left, right, lst);
	}
	insertion_sort_lst(lst);
}

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

void	PmergeMe::merge_list(const list<unsigned int> & left, const list<unsigned int> & right, list<unsigned int> & result) {
	list<unsigned int>::const_iterator itl = left.begin();
	list<unsigned int>::const_iterator itr = right.begin();
	list<unsigned int>::iterator itresult = result.begin();
	while (itl != left.end() && itr != right.end())
	{
		if (*itl <= *itr) {
			*itresult = *itl;
			advance(itl, 1);
		}
		else {
			*itresult = *itr;
			advance(itr, 1);
		}
		itresult++;
	}
	while (itl != left.end()) {
		*itresult = *itl;
		advance(itresult, 1);
		advance(itl, 1);
	}
	while (itr != right.end()) {
		*itresult = *itr;
		advance(itresult, 1);
		advance(itr, 1);
	}
	//cout << "try ->" << endl;
	// for (list<unsigned int>::iterator it = result.begin(); it != result.end(); it++) {
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

void	PmergeMe::insertion_sort_lst(list<unsigned int> & lst) {
	list<unsigned int>::iterator end = lst.end();
	list<unsigned int>::iterator begin = lst.begin();
	for (list<unsigned int>::iterator it = begin; it != end; it++) {
		list<unsigned int>::iterator before = it;
		while (before-- != begin && *before > *it)
		{
			*before = *before ^ *it;
			*it = *before ^ *it;
			*before = *before ^ *it;
		}
	}
}

void	PmergeMe::add(unsigned int i) {
	vec.push_back(i);
	lst.push_back(i);
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

vector<unsigned int> & PmergeMe::get_modif_vec() {
	return vec;
}

list<unsigned int> & PmergeMe::get_modif_lst() {
	return lst;
}

/* ************************************************************************** */