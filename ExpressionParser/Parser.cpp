#include "Parser.h"
#include "ExpressionClasses.h"
#include <ctype.h>
#include <cassert>
#include <iostream>

class Expression;
//(OP (OP CONST) CONST)
//format:
//input (OP (OP CONST CONST) CONST) || CONST
ShortTruthTables::Expression* ShortTruthTables::ParsedExpression::recursiveParser(std::string::iterator &curr_pos, const std::string::iterator &end){
	if(*curr_pos == '('){
		std::string::iterator temp = curr_pos;
		temp++;
		std::string next_word(temp, temp+3);
		ShortTruthTables::Expression* resultOperation;
		if(next_word == "not"){
			curr_pos += 5;
			ShortTruthTables::Expression* child = recursiveParser(curr_pos, end);
			resultOperation = new ShortTruthTables::NotOperator(child);
			assert(*curr_pos == ')');
			curr_pos++;
			if(*curr_pos == ' '){
				curr_pos++;
			}
			return resultOperation;
		}else if(next_word == "or "){
			curr_pos += 4;
			ShortTruthTables::Expression* left = recursiveParser(curr_pos, end);
			ShortTruthTables::Expression* right = recursiveParser(curr_pos, end);
			resultOperation = new ShortTruthTables::OrOperator(left,right);
			assert(*curr_pos == ')');
			curr_pos++;
			if(*curr_pos == ' '){
				curr_pos++;
			}
			return resultOperation;
		}else if(next_word == "and"){
			curr_pos += 5;
			ShortTruthTables::Expression* left = recursiveParser(curr_pos, end);
			ShortTruthTables::Expression* right = recursiveParser(curr_pos, end);
			resultOperation = new ShortTruthTables::AndOperator(left,right);
			assert(*curr_pos == ')');
			curr_pos++;
			if(*curr_pos == ' '){
				curr_pos++;
			}
			return resultOperation;
		}else if(next_word == "if "){
			curr_pos += 4;
			ShortTruthTables::Expression* left = recursiveParser(curr_pos, end);
			ShortTruthTables::Expression* right = recursiveParser(curr_pos, end);
			resultOperation = new ShortTruthTables::ConditionalOperator(left,right);
			assert(*curr_pos == ')');
			curr_pos++;
			if(*curr_pos == ' '){
				curr_pos++;
			}
			return resultOperation;
		}else if(next_word == "iff"){
			curr_pos += 5;
			ShortTruthTables::Expression* left = recursiveParser(curr_pos, end);
			ShortTruthTables::Expression* right = recursiveParser(curr_pos, end);
			resultOperation = new ShortTruthTables::BiConditionalOperator(left,right);
			assert(*curr_pos == ')');
			curr_pos++;
			if(*curr_pos == ' '){
				curr_pos++;
			}
			return resultOperation;
		}else{
			std::cerr << "Unrecognized Operation" << std::endl;
		}

	}else if(isalpha(*curr_pos) && isupper(*curr_pos)){
		ShortTruthTables::Expression* constant = new ShortTruthTables::AtomicValue(*curr_pos);
		curr_pos++;
		if(curr_pos == end){
			return constant;
		}else if(*curr_pos == ')'){
			return constant;
		}else if(*curr_pos == ' '){
			curr_pos++;
			return constant;
		}
	}
}


ShortTruthTables::Expression* ShortTruthTables::ParsedExpression::parser(std::string& input){
	std::string::iterator temp = input.begin();
	recursiveParser(temp, input.end());
}

ShortTruthTables::ParsedExpression::ParsedExpression(std::string exp){
	this->topLevelExpression = this->parser(exp);
}