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
// buttons.h: buttons used in the calculator

#ifndef BUTTONS_H
#define BUTTONS_H

#include <gtkmm/button.h>
#include <iostream>

// abstract button class
class calcButton: public Gtk::Button {
	public:
		calcButton(std::string label);
		virtual ~calcButton() {};
		
	protected:
};

// a button that stores a numeric value
class valueButton: public calcButton {
	public:
		valueButton(std::string label, std::string val);
		
		// methods
		int getVal() const {return atoi(value.c_str());}
		
		// signals
		sigc::signal<int> signal_clicked();
		
	protected:
		std::string value;
};

#endif
