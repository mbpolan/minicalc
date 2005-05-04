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
 // mainwindow.h: a toplevel window class

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/table.h>
#include <gtkmm/window.h>
#include <vector>
#include "buttons.h"

class mainWindow: public Gtk::Window {
	public:
		mainWindow(std::string caption);
		virtual ~mainWindow();
		
		// methods
		void setDisplayText(Glib::ustring text);
		Glib::ustring getDisplayText() const;
		
	private:
		// widgets
		Gtk::HBox *topHBox;
		Gtk::HBox *bottomHBox;
		
		Gtk::Table *rootTable;
		Gtk::Table *leftTable;
		Gtk::Table *rightTable;
		
		Gtk::Entry *display;
		
		std::vector<calcButton*> buttons; // vector of buttons
};

#endif
