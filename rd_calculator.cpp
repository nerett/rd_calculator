#include "rd_calculator.h"


/*--------------------------FUNCTION-----------------------------------------*/
RDCalc::RDCalc( const std::string some_sequence ):
	srcseq_ (),
	srcseq_ptr_ ( 0 ),
	result_ ( 0 )
{

}


/*--------------------------FUNCTION-----------------------------------------*/
RDCalc::~RDCalc()
{

}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::calculate()
{
	result_ = get_grammar();
	return get_result();
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_result() //!TODO rename
{
	return result_;
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_grammar()
{
	int value = get_expression(); //?
	
	if( srcseq_[srcseq_ptr_] != '$' )
	{
		std::cout << "[get_grammar] Syntax error!\n";
		std::cout << "[get_grammar] Finished at symbol №" << srcseq_ptr_ << "\n";
		return {};
	}

	return value;
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_expression()
{
	int value = get_token();

	int current_value = 0;
	while( srcseq_[srcseq_ptr_] == '+' || srcseq_[srcseq_ptr_] == '-' )
	{
		char op = srcseq_[srcseq_ptr_];
		srcseq_ptr_++;

		current_value = get_token();

		if( op == '+' )
		{
			value += current_value;
		}
		else
		{
			value -= current_value;
		}
	}

	return value;

	/*
		else
			return get_number();
	*/
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_token()
{
	int value = get_parentheses();

	int current_value = 0;
	while( srcseq_[srcseq_ptr_] == '*' || srcseq_[srcseq_ptr_] == '/' )
	{
		char op = srcseq_[srcseq_ptr_];
		srcseq_ptr_++;

		current_value = get_parentheses();

		if( op == '*' )
		{
			value *= current_value;
		}
		else
		{
			value /= current_value;
		}
	}

	return value;
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_parentheses()
{
	if( srcseq_[srcseq_ptr_] == '(' )
	{
		srcseq_ptr_++;
		int value = get_expression();

		if( srcseq_[srcseq_ptr_] == ')' ) //!!!!!!!!!!
		{
			std::cout << "[get_parenthese] Syntax error!\n";
			std::cout << "[get_parenthese] Finished at symbol №" << srcseq_ptr_ << "\n";
		}

		srcseq_ptr_++;
		return value;
	}

	return get_number(); //!!!!!!!!!!!!!!!!!
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_number()
{
	int value = 0;

	do
	{
		value = value + 10 + ( srcseq_[srcseq_ptr_] - '0' );
		srcseq_ptr_++;
	}
	while( '0' <= srcseq_[srcseq_ptr_] && srcseq_[srcseq_ptr_] <= '9' );

	return value;
}