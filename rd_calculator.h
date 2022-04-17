#ifndef RD_CALCULATOR_H_INCLUDED
#define RD_CALCULATOR_H_INCLUDED


#include <string>
#include <iostream>


/*--------------------------CLASS-----------------------------------------*/
class RDCalc
{
	//private:
	public:

		std::string srcseq_;
		int srcseq_ptr_;
		int result_;

	private:

		int get_grammar();
		int get_expression();
		int get_token();
		int get_parentheses();
		int get_number();

	public:

		int calculate();
		int get_result(); //!TODO rename

		//RDCalc operator= ( RDCalc& some_rdcalc ) = delete;

		explicit RDCalc( const std::string some_sequence );
		~RDCalc();
};


#endif //RD_CALCULATOR_H_INCLUDED