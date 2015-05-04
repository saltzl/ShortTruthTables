#include <string>
#include <iostream>
#include "Parser.h"

int main(){
	std::string minor = "(iff (or (if A B) (if (not A) B)) B)";
	ShortTruthTables::ParsedExpression expr(minor);
	std::cout << expr.getInOrderExp() << std::endl;
	ShortTruthTables::Expression* first_conditional = expr.expressionAtPosition(5);
	if(first_conditional == NULL){
		std::cout << "not at position" << std::endl;
	}else{
		std::cout << first_conditional->print() << std::endl;
	}
}