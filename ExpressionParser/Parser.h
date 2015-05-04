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
	std::map<int, Expression*> stringPlace;
	Expression* recursiveParser(std::string::iterator &curr_pos, const std::string::iterator &end);
	Expression* parser(std::string& input);
	std::string inOrderExp;
	void left_to_right_map();

public:
	ParsedExpression(std::string exp);
	std::string getInOrderExp(){ return inOrderExp;}
	Expression* expressionAtPosition(int i){
		std::map<int, Expression*>::iterator temp = stringPlace.find(i);
		if(temp == stringPlace.end()){
			return NULL;
		}
		return temp->second;
	}
};	

}// end namespace ShortTruthTables
#endif