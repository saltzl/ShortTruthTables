#ifndef _STTModel_h
#define _STTModel_h

#include "ExpressionParser/ExpressionClasses.h"
#include "ExpressionParser/Parser.h"
#include "TruthValue.h"
#include <vector>
#include <string>

namespace ShortTruthTables{

class STTModel
{
private:
	std::vector<ParsedExpression*> premises;
	ParsedExpression* conclusion;
public:
	STTModel();
	~STTModel();
	void addPremise(std::string preorder);
	//true if overwrote previous conclusion
	bool addConclusion(std::string preorder);

	//arguments: expNum: -1 if conclusion, 0...n-1 if premise where n is num of premises
	//pos in string : see documentation of exp at position
	//tval true or false
	//returns: bool: true if succesfull, false if exp already had a value or didn't exist.
	bool assignTruthValue(int expNum, int pos_in_string, bool tval);
	ParsedExpression* getPremise(int i);
	ParsedExpression* getConclusion();
	TruthValue valueOfExp(int expNum, int pos_in_string);

};

}//end namespace

#endif