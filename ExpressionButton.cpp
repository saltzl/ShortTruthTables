#include "ExpressionButton.h"
#include <gtkmm.h>
#include <iostream>

//randomly chosen numbers, no special meanings
#define TRUE_RESPONSE 12
#define FALSE_RESPONSE 13

void ExpressionButton::on_clicked(){
	Gtk::Dialog *tf_dialog = new Gtk::Dialog("True or False");
	tf_dialog->add_button("True", TRUE_RESPONSE);
	tf_dialog->add_button("False", FALSE_RESPONSE);
	int response = tf_dialog->run();
	std::cout << response << std::endl;

	tf_dialog->hide();
	delete tf_dialog;
	Gtk::Button::on_clicked();
}