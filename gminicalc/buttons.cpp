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

#include "buttons.h"

// button constructor
calcNumberButton::calcNumberButton(const char *label, QWidget *parent, const char *name): 
	QPushButton(label, parent, name) {
    name=label; // label
  
    // also connect a parser slot when this button is clicked
    connect(this, SIGNAL(clicked()), SLOT(parseClick()));
};

// slot to parse a click and emit the label as an int
void calcNumberButton::parseClick() {
    int val=atoi(this->text().ascii());
    emit clicked(val);
};
