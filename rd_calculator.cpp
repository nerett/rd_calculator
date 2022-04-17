#include "rd_calculator.h"


/*--------------------------FUNCTION-----------------------------------------*/
RDCalc::RDCalc( const std::string some_sequence ):
	srcseq_ ( some_sequence ),
	srcseq_ptr_ ( 0 ),
	result_ ( 0 )
{
	std::cerr << "[RDCalc]\n";
}


/*--------------------------FUNCTION-----------------------------------------*/
RDCalc::~RDCalc()
{
	std::cerr << "[~RDCalc]\n";
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::calculate()
{
	std::cerr << "[calculate]\n";
	std::cerr << "Calculating " << srcseq_ << std::endl;
	result_ = get_grammar();
	return get_result();
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_result() //!TODO rename
{
	std::cerr << "[get_result]\n";
	return result_;
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_grammar()
{
	std::cerr << "[get_grammar]\n";

	int value = get_expression(); //?
	
	if( srcseq_[srcseq_ptr_] != '$' )
	{
		std::cout << "[get_grammar] Syntax error!\n";
		std::cout << "[get_grammar] Finished at symbol №" << srcseq_ptr_ << "\n";
		return {};
	}

	std::cerr << "[get_grammar] returning " << value << "\n";
	return value;
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_expression()
{
	std::cerr << "[get_expression]\n";

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

	std::cerr << "[get_expression] returning " << value << "\n";
	return value;

	/*
		else
			return get_number();
	*/
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_token()
{
	std::cerr << "[get_token]\n";

	int value = get_parentheses();

	int current_value = 0;
	while( srcseq_[srcseq_ptr_] == '*' || srcseq_[srcseq_ptr_] == '/' )
	{
		std::cerr << "[get_token] while iteration\n";

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

	std::cerr << "[get_token] returning " << value << "\n";
	return value;
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_parentheses()
{
	std::cerr << "[get_parentheses]\n";

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

		std::cerr << "[get_parentheses] returning " << value << "\n";
		return value;
	}

	int value = get_number(); //костыль
	std::cerr << "[get_parentheses] returning " << value << "\n";
	return value;
	//return get_number(); //!!!!!!!!!!!!!!!!!
}


/*--------------------------FUNCTION-----------------------------------------*/
int RDCalc::get_number()
{
	std::cerr << "[get_number]\n";

	int value = 0;

	do
	{
		std::cerr << "[get_number] do-while iteration\n";

		std::cerr << "[get_number] symbol = " << srcseq_[srcseq_ptr_] << "\n";
		std::cerr << "[get_number] symbolcode = " << srcseq_[srcseq_ptr_] - '0' << "\n";

		value = value * 10 + ( srcseq_[srcseq_ptr_] - '0' );
		//value = value + 10 + ( srcseq_[srcseq_ptr_] );

		std::cerr << "[get_number] value = " << value << "\n";

		srcseq_ptr_++;
	}
	while( '0' <= srcseq_[srcseq_ptr_] && srcseq_[srcseq_ptr_] <= '9' );

	std::cerr << "[get_number] returning " << value << "\n";
	return value;
}