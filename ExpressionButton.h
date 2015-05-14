#ifndef ExpressionButton_h_
#define ExpressionButton_h_ 

#include <gtkmm.h>
#include "ExpressionParser/ExpressionClasses.h"


class ExpressionButton : public Gtk::Button{
private:
	ShortTruthTables::Expression* exp;
	Gtk::Grid* m_parent;
public:
	ExpressionButton(ShortTruthTables::Expression* e, Gtk::Grid* parent){
		this->exp = e;
		this->set_label(e->getExpChar());
		this->m_parent = parent;
	}
	ShortTruthTables::Expression* exp_for_button(){
		return this->exp;
	}
	void on_clicked();
};

#endif
