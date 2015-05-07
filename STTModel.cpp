#include "STTModel.h"

void ShortTruthTables::STTModel::addPremise(std::string preorder){
	ParsedExpression* p = new ParsedExpression(preorder);
	p->setTruthValue(true);
	this->premises.push_back(p);
}

bool ShortTruthTables::STTModel::addConclusion(std::string preorder){
	bool retval;
	if(this->conclusion == NULL){
		retval = false;
	}else{
		retval = true;
	}
	ParsedExpression* p = new ParsedExpression(preorder);
	p->setTruthValue(false);
	this->conclusion = p;
	return retval;
}

bool ShortTruthTables::STTModel::assignTruthValue(int expNum, int pos_in_string, bool tval){
	if(expNum == -1){
		Expression* exp = this->conclusion->expressionAtPosition(pos_in_string);
		if(!exp->isUnassigned()) return false;
		exp->setTruthValue(tval);
	}
}

ShortTruthTables::ParsedExpression* ShortTruthTables::STTModel::getPremise(int i){
	if(i >= premises.size()) return NULL;
	return this->premises[i];
}
ShortTruthTables::ParsedExpression* ShortTruthTables::STTModel::getConclusion(){
	return this->conclusion;
}

ShortTruthTables::TruthValue ShortTruthTables::STTModel::valueOfExp(int expNum, int pos_in_string){
	ParsedExpression* e = this->getPremise(expNum);
	return e->expressionAtPosition(pos_in_string)->getTVal();
}

ShortTruthTables::STTModel::STTModel(){
	this->conclusion = NULL;
}