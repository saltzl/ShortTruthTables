#include "ExpressionClasses.h"

bool Expression::setTruthValue(bool val){
	if(val && tval != ShortTruthTables::ASSIGNED_FALSE){
		tval = ShortTruthTables::ASSIGNED_TRUE;
	}else if(!val && tval != ShortTruthTables::ASSIGNED_TRUE){
		tval = ShortTruthTables::ASSIGNED_FALSE;
	}else{
		return false;
	}
	return true;
}
