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
	rootTable=new Gtk::Table(4, 2, false);
	
	// start implementing the left side (buttons)
	leftTable=new Gtk::Table(leftTableRows, leftTableCols, false);
	
	// make the buttons first
	std::stringstream ss;
	for (int i=0; i<10; i++) {
		ss << i;
		buttons.push_back(new valueButton(ss.str(), ss.str()));
		ss.str("");
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
	rootTable->attach(*topHBox, 0, 1, 0, 1);
	rootTable->attach(*leftTable, 0, 1, 1, 2);
	rootTable->attach(*bottomHBox, 0, 1, 2, 3);
	
	// add the tables and show them
	add(*rootTable);
	rootTable->show();
	
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
	delete topHBox;
	delete bottomHBox;
	
	// delete the display
	delete display;
	
	// and delete all the buttons
	for (int i=0; i<buttons.size(); i++)
		delete buttons[i];
};
