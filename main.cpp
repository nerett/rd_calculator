#include "rd_calculator.h"
#include <iostream>
#include <string>

int main()
{
	std::string math_sequence;
	std::cin >> math_sequence;
	//std::cin.ignore();

	RDCalc calculator( math_sequence );
	for( int i = 0; i < calculator.srcseq_.size(); i++ )
	{
		std::cerr << calculator.srcseq_[i] << " ";
	}
	std::cerr <<"\n";

	std::cout << calculator.calculate() << std::endl;

	for( int i = 0; i < calculator.srcseq_.size(); i++ )
	{
		std::cerr << calculator.srcseq_[i] << " ";
	}
	std::cerr <<"\n";

	return 0;
}