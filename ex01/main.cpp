#include "RPN.hpp"

int main(int ac, char **av) {

	if (ac != 2){
		cout << "the program must have one and only one argument" << endl;
		return 1;
	}
	RPN rpn;
	try
	{
		rpn.calculate(string(av[1]));
	}
	catch(char const* s)
	{
		cout << "ERROR" << endl;
		cout << s << endl;
		return 1;
	}
	cout << rpn.getResult() << endl;
}