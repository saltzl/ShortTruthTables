#include <gtkmm.h>
#include <iostream>
#include <cstdlib>
#include "STTPremiseDialogView.h"
#include "STTModel.h"
#include "STTConcDialogView.h"


Glib::RefPtr<Gtk::Builder> refBuilder;
Glib::RefPtr<Gtk::Application> app;
Gtk::Window* mainWindow = 0;
Gtk::Button* premiseButton;
Gtk::Button* conclusionButton;



int main (int argc, char **argv)
{
  ShortTruthTables::STTModel* model = new ShortTruthTables::STTModel();
  app = Gtk::Application::create(argc, argv, "com.rpi.saltzl.stt");

  //Load the GtkBuilder file and instantiate its widgets:
  refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("interface_prototype.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return 1;
  }

  //Get the GtkBuilder-instantiated Dialog:
  refBuilder->get_widget("mainWindow", mainWindow);
  PremDialog premView(refBuilder, model, mainWindow);
  ConcDialog concView(refBuilder,model,mainWindow);
  if(mainWindow)
  {
    // mainWindow->set_default_size(800,600);
    refBuilder->get_widget("premButton", premiseButton);
    premiseButton->signal_clicked().connect( sigc::mem_fun(premView, &PremDialog::show) );

    refBuilder->get_widget("concButton", conclusionButton);
    conclusionButton->signal_clicked().connect( sigc::mem_fun(concView, &ConcDialog::show) );


    app->run(*mainWindow);
  }

  delete mainWindow;

  return 0;
}