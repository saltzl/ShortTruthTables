#ifndef _ExpressionClasses_h
#define _ExpressionClasses_h

#include "../TruthValues.h"
#include <string>

class Expression{
protected:
	ShortTruthTables::TruthValue tval;
public:
	virtual void setTruthValue(bool val) = 0;
	bool isUnassigned(){
		return tval == ShortTruthTables::UNASSIGNED;
	}
	bool isAssignedTrue(){
		return tval == ShortTruthTables::ASSIGNED_TRUE;
	}
	//true if assignment succeeds (either prev unassigned or held same value)
	//false if there's a conflics
	bool setTruthValue(bool val);

};

class AtomicValue : public Expression{
private:
	std::string name;
public:
	AtomicValue(std::string in_name) : Expression() {
		this.name = in_name;
		tval = ShortTruthTables::UNASSIGNED;
	}
	std::string getName(){
		return this.name;
	}
};

//class does nothing, should never be instantiated
class Operator : public Expression{
public:
	virtual bool isValid() = 0;
};

class UnaryOperator : public Operator{
protected:
	Expression* child;

public:
	Expression* getChild(){return child;}
	bool isValid(){
		if(this.isUnassigned() || child.isUnassigned()) return true;
		if(this.isAssignedTrue()) return !child.isAssignedTrue();
		else return child.isAssignedTrue();
	}
};

class BinaryOperator : public Operator{
protected:
	Expression* left_child;
	Expression* right_child;
public:
	Expression* getLeft(){return left_child;}
	Expression* getRight(){return right_child;}
	virtual bool isValid() = 0;
};

class NotOperator : public UnaryOperator{
public:
	NotOperator(Expression* n_child) : UnaryOperator{
		child = n_child;
	}
	bool isValid();
};

class AndOperator : public BinaryOperator{
public:
	bool isValid();
};

class OrOperator : public BinaryOperator{

};

class ConditionalOperator : public BinaryOperator{

};

class BiConditionalOperator : public BinaryOperator{

};


#endif