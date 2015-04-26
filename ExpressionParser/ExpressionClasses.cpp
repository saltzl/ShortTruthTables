#include "ExpressionClasses.h"

bool ShortTruthTables::Expression::setTruthValue(bool val){
	if(val && tval != ShortTruthTables::ASSIGNED_FALSE){
		tval = ShortTruthTables::ASSIGNED_TRUE;
	}else if(!val && tval != ShortTruthTables::ASSIGNED_TRUE){
		tval = ShortTruthTables::ASSIGNED_FALSE;
	}else{
		return false;
	}
	return true;
}

bool ShortTruthTables::NotOperator::isValid(){
	if(this->isUnassigned() || child->isUnassigned()) return true;
	if(this->isAssignedTrue()) return child->isAssignedFalse();
	else return child->isAssignedTrue();
}

bool ShortTruthTables::AndOperator::isValid(){
	if(left_child->isUnassigned() && right_child->isUnassigned()) return true;
	if(this->isUnassigned()) return true;
	if(this->isAssignedTrue() && (left_child->isAssignedTrue() && right_child->isAssignedTrue())) return true;
	if(this->isAssignedTrue() && left_child->isUnassigned() && right_child->isAssignedTrue()) return true;
	if(this->isAssignedTrue() && right_child->isUnassigned() && left_child->isAssignedTrue()) return true;
	if(this->isAssignedFalse() && (left_child->isAssignedFalse() || right_child->isAssignedFalse())) return true;

	return false;
}

bool ShortTruthTables::OrOperator::isValid(){
	if(this->isUnassigned()) return true;

	if(left_child->isUnassigned() || right_child->isUnassigned()) return true;

	if(this->isAssignedTrue() && (left_child->isAssignedTrue() || right_child->isAssignedTrue())) return true;
	if(this->isAssignedFalse() && (left_child->isAssignedFalse() && right_child->isAssignedFalse())) return true;

	return false;
}


bool ShortTruthTables::ConditionalOperator::isValid(){
	if(this->isUnassigned()|| left_child->isUnassigned() || right_child->isUnassigned()) return true;

	if(this->isAssignedTrue()){
		if(left_child->isAssignedTrue()){
			return right_child->isAssignedTrue();

		}else{ //assigned false
			return true;
		}
	}else{ // assigned false
		return left_child->isAssignedTrue() && right_child->isAssignedFalse();
	}
}

bool ShortTruthTables::BiConditionalOperator::isValid(){
	if(this->isUnassigned()|| left_child->isUnassigned() || right_child->isUnassigned()) return true;

	if(this->isAssignedTrue()){
		if(left_child->isAssignedTrue()) return right_child->isAssignedTrue();
		if(left_child->isAssignedFalse()) return right_child->isAssignedFalse();
	}

	if(this->isAssignedFalse()){
		if(left_child->isAssignedTrue()) return right_child->isAssignedFalse();
		if(left_child->isAssignedFalse()) return right_child->isAssignedTrue();
	}
}