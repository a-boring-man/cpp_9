# include "PmergeMe.hpp"

bool is_in_charset(const char c, const char*set) {
	for (int i = 0; set[i]; i++) {
		if (set[i] == c)
			return true;
	}
	return false;
}

bool is_correct_charset(const char*av, const char*set) {
	for (int i = 0; av[i]; i++) {
		if (!is_in_charset(av[i], set))
			return false;
	}
	return true;
}

int main (int ac, char **av) {

	PmergeMe me;

	if (ac <= 1)
	{
		cout << "the program must have at least one argument" << endl;
		return 1;
	}

	// parsing
	cout << "beginning of parsing" << endl;
	clock_t	start, end;
	double cpu_time_used;
	start = clock();
	for (int i = 1; i < ac; i++)
	{
		if (!is_correct_charset(av[i], "0123456789"))
		{
			cout << "one argument isn't a positif interger" << endl;
			return 1;
		}
		if (is_correct_charset(av[i], "0123456789"))
			me.add(std::atoi(av[i]));
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "time passing parsing : " << cpu_time_used << " second without even trying" << endl << endl;

	// display before sort
	cout << "before sorting vec : ->";
	for (vector<unsigned int>::const_iterator it = me.getVec().begin(); it != me.getVec().end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;
	cout << "before sorting list : ->";
	for (list<unsigned int>::const_iterator it = me.getLst().begin(); it != me.getLst().end(); it++) {
		cout << *it << ", ";
	}
	cout << endl << endl;

	// vec
	cout << "sorting vec ..." << endl;
	start = clock();
	me.sort_vec(1, me.get_modif_vec());
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "after sorting vec : ->";
	for (vector<unsigned int>::const_iterator it = me.getVec().begin(); it != me.getVec().end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;
	cout << "sorting done in : " << cpu_time_used << " second, without even trying" << endl << endl;

	// list
	cout << "sorting lst ..." << endl;
	start = clock();
	me.sort_list(1, me.get_modif_lst());
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "after sorting list : ->";
	for (list<unsigned int>::const_iterator it = me.getLst().begin(); it != me.getLst().end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;
	cout << "sort in : " << cpu_time_used << " second, while running multiple firefox tab" << endl << endl;
}