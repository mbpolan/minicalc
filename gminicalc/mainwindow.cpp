/***************************************************************************
 *   Copyright (C) 2005 by KanadaKid                                       *
 *   kanadakid@gmail.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 // mainwindow.cpp: implementations of mainWindow class

#include <iostream>
#include <sstream>  
 
#include "mainwindow.h"

// constants
const int leftTableRows=3;
const int leftTableCols=3;

//=========================================================================//
// start mainWindow class implementations
//=========================================================================//

// constructor
mainWindow::mainWindow(std::string caption): Gtk::Window() {
	set_title((Glib::ustring)caption);
	
	// set up the root table layout
	rootTable=new Gtk::Table(5, 2, false);
	
	// create the hbox that will hold the menu bar
	menuHBox=new Gtk::HBox;
	menuBar=new Gtk::MenuBar;
	
	menuHBox->pack_start(*menuBar, true, true);
	menuBar->show();
	
	// create some menu items
	menuItems.push_back(new Gtk::MenuItem("File"));
	menuBar->insert((*menuItems[0]), 0);
	
	// show all menu items
	for (int i=0; i<menuItems.size(); i++)
		menuItems[i]->show();
		
	// create sub menus
	subMenus.push_back(new Gtk::Menu);
	
	// and populate them with items
	subMenuItems.push_back(new Gtk::MenuItem("Quit"));
	//subMenuItems[0]->signal_activate().connect(sigc::mem_fun(*this, slot_kill()));
	
	// add the sub menus to root items
	menuItems[0]->set_submenu((*subMenus[0])); // file menu
	
	// add items to the sub menus
	subMenus[0]->insert((*subMenuItems[0]), 0); // 'quit' action
	
	// show all allocated widgets up to this point
	for (int i=0; i<subMenus.size(); i++)
		subMenus[i]->show();
	
	for (int i=0; i<subMenuItems.size(); i++)
		subMenuItems[i]->show();
	
	// start implementing the left side (buttons)
	leftTable=new Gtk::Table(leftTableRows, leftTableCols, false);
	
	// make the buttons first
	std::stringstream ss;
	for (int i=0; i<10; i++) {
		ss << i;
		buttons.push_back(new valueButton(ss.str(), ss.str()));
		ss.str("");
		
		// connect this signal
		((valueButton*) buttons[i])->signal_clicked_id.connect(sigc::mem_fun(*this, &mainWindow::valueButtonClicked));
	}
	
	// make the top table with the display
	display=new Gtk::Entry;
	
	topHBox=new Gtk::HBox;
	topHBox->pack_start(*display, true, true);
	display->show();
	
	// now we add the value buttons to the left table
	int c=1;
	for (int i=0; i<leftTableRows; i++) {
		for (int j=0; j<leftTableCols; j++) {
			if (buttons[c])
				leftTable->attach((*buttons[c]), j, j+1, i, i+1);
			
			c+=1;
		}
	}
	
	// make the other buttons
	/*
	buttons.push_back(new operationButton("+"));
	buttons.push_back(new operationButton("-"));
	buttons.push_back(new operationButton("x"));
	buttons.push_back(new operationButton("/"));
	buttons.push_back(new operationButton("="));*/
	
	// show the buttons
	for (int i=0; i<buttons.size(); i++)
		buttons[i]->show();
	
	// assemble the bottom table
	bottomHBox=new Gtk::HBox;
	bottomHBox->pack_start(*buttons[0], true, true);
	
	// attach the tables
	rootTable->attach(*menuHBox, 0, 1, 0, 1);
	rootTable->attach(*topHBox, 0, 1, 1, 2);
	rootTable->attach(*leftTable, 0, 1, 2, 3);
	rootTable->attach(*bottomHBox, 0, 1, 3, 4);
	
	// add the tables and show them
	add(*rootTable);
	rootTable->show();
	
	menuHBox->show();
	topHBox->show();
	leftTable->show();
	bottomHBox->show();
};

// destructor
mainWindow::~mainWindow() {
	// free memory allocated for containers
	delete rootTable;
	delete leftTable;
	// delete rightTable;
	delete menuHBox;
	delete topHBox;
	delete bottomHBox;
	
	// delete the display
	delete display;
	
	// and delete all the buttons
	for (int i=0; i<buttons.size(); i++)
		delete buttons[i];
	
	// delete sub menus
	for (int i=0; i<subMenus.size(); i++)
		delete subMenus[i];
	
	// delete the menu bar
	delete menuBar;
};

void mainWindow::valueButtonClicked(int id) {
	// int to std::string
	std::stringstream ss;
	ss << id;
	
	// get current text
	Glib::ustring text=display->get_text();
	text+=ss.str(); // merge them
	display->set_text(text);
};
