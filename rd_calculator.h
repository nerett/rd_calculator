#ifndef RD_CALCULATOR_H_INCLUDED
#define RD_CALCULATOR_H_INCLUDED


#include <string>


class RDCalc
{
	private:

		std::string src_sequence_;
		int result_;

	private:

		int get_grammar();
		int get_expression();
		int get_T(); //cringe...
		int get_P(); //cringe...
		int get_number();

	public:

		int calculate();
		int get_result(); //!TODO rename

		//RDCalc operator= ( RDCalc& some_rdcalc ) = delete;

		explicit RDCalc( std::string some_sequence );
		~RDCalc();
};


#endif //RD_CALCULATOR_H_INCLUDED