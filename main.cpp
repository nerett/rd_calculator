#include "rd_calculator.h"
//#include <iostream>
#include <string>

int main()
{
	std::string math_sequence;
	std::cin >> math_sequence;

	RDCalc calculator( math_sequence );
	cout << calculator.calculate() << endl;

	return 0;
}