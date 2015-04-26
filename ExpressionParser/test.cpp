#include <string>
#include <iostream>
#include "Parser.h"

int main(){
	std::string minor = "(iff (or (if A B) (if (not A) B)) B)";
	ShortTruthTables::ParsedExpression expr(minor);
	std::cout << expr.print() << std::endl;
}