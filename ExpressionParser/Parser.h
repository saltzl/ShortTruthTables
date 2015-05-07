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
	std::vector<Expression*> inOrder;
	std::map<int, Expression*> stringPlace;
	Expression* recursiveParser(std::string::iterator &curr_pos, const std::string::iterator &end);
	Expression* parser(std::string& input);
	std::string preOrder;
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
	Expression* getNthExpression(int i ){
		if(i > inOrder.size()){
			return NULL;
		}
		return inOrder[i];
	}
	std::string getPreorder(){
		return this->preOrder;
	}
	int getNumExpressions(){
		return inOrder.size();
	}
	void setTruthValue(bool tval){
		topLevelExpression->setTruthValue(tval);
	}
};	

}// end namespace ShortTruthTables
#endif