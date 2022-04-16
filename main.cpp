#include "rd_calculator.h"
#include <iostream>
#include <string>

int main()
{
	std::string math_sequence;
	std::cin >> math_sequence;

	RDCalc calculator( math_sequence );
	std::cout << calculator.calculate() << std::endl;

	return 0;
}