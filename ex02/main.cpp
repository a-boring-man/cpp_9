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
	for (int i = 1; i < ac; i++)
	{
		if (!is_correct_charset(av[i], "0123456789"))
		{
			cout << "one argument isn't a positif interger" << endl;
		}
		if (is_correct_charset(av[i], "0123456789"))
			me.add(std::atoi(av[i]));
	}
	
	// vector<unsigned int> titi;
	// list<unsigned int> toto;
	// titi.push_back(4);
	// titi.push_back(7);
	// titi.push_back(5);
	// titi.push_back(6);
	// titi.push_back(12342);
	// titi.push_back(554);
	// titi.push_back(65);
	// titi.push_back(322);
	// titi.push_back(1);
	// titi.push_back(000);
	// titi.push_back(224434343);
	// titi.push_back(545);
	// titi.push_back(33);
	// titi.push_back(3);
	// toto.push_back(4);
	// toto.push_back(7);
	// toto.push_back(5);
	// toto.push_back(6);
	// toto.push_back(12342);
	// toto.push_back(554);
	// toto.push_back(65);
	// toto.push_back(322);
	// toto.push_back(1);
	// toto.push_back(000);
	// toto.push_back(224434343);
	// toto.push_back(545);
	// toto.push_back(33);
	// toto.push_back(3);
	// cout << "avant : " << endl;
	// for (vector<unsigned int>::iterator it = titi.begin(); it != titi.end(); it++) {
	// 	cout << *it << ", ";
	// }
	// cout << "avant : " << endl;
	// for (list<unsigned int>::iterator it = toto.begin(); it != toto.end(); it++) {
	// 	cout << *it << ", ";
	// }
	// me.sort_vec(1, titi);
	// me.sort_list(1, toto);
	// cout << "apres : " << endl;
	// for (vector<unsigned int>::iterator it = titi.begin(); it != titi.end(); it++) {
	// 	cout << *it << ", ";
	// }
	// cout << "apres : " << endl;
	// for (list<unsigned int>::iterator it = toto.begin(); it != toto.end(); it++) {
	// 	cout << *it << ", ";
	// }
}