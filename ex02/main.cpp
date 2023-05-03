# include "PmergeMe.hpp"

int main () {
	PmergeMe me;
	vector<unsigned int> titi;
	titi.push_back(4);
	titi.push_back(7);
	titi.push_back(5);
	titi.push_back(6);
	titi.push_back(12342);
	titi.push_back(554);
	titi.push_back(65);
	titi.push_back(322);
	// titi.push_back(1);
	// titi.push_back(000);
	// titi.push_back(224434343);
	// titi.push_back(545);
	// titi.push_back(33);
	// titi.push_back(3);
	cout << "avant : " << endl;
	for (vector<unsigned int>::iterator it = titi.begin(); it != titi.end(); it++) {
		cout << *it << ", ";
	}
	me.sort_vec(1, titi);
	cout << "apres : " << endl;
	for (vector<unsigned int>::iterator it = titi.begin(); it != titi.end(); it++) {
		cout << *it << ", ";
	}
}