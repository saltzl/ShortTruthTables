#ifndef PARSER_H_
#define PARSER_H_ 
#include "ExpressionClasses.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>

namespace ShortTruthTables{

class ParsedExpression{

private:
	Expression* topLevelExpression;
	std::map<char, std::vector<Expression*> > constant_uses;
	
	Expression* recursiveParser(std::string::iterator &curr_pos, const std::string::iterator &end);
	Expression* parser(std::string& input);

public:
	ParsedExpression(std::string exp);
	std::string print(){
		return topLevelExpression->print();
	}
};	

}// end namespace ShortTruthTables
#endif