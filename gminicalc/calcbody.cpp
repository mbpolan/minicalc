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

#include <qlayout.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <sstream>

#include "buttons.h"
#include "calcbody.h"

// calcBody constructor
calcBody::calcBody(QWidget *parent, const char *name): QWidget(parent, name) {
    std::stringstream ss;
    grid=new QGridLayout(this, 6, 4);
    current_op=-1;
    
    // set spacing
    for (int i=0; i<grid->numRows(); i++)
	grid->addRowSpacing(i, 3);
    
    for (int i=0; i<grid->numCols(); i++)
	    grid->addColSpacing(i, 3);
    
    // the display on top
    lineEdit=new QLineEdit(this);
    lineEdit->setReadOnly(true);
    grid->addMultiCellWidget(lineEdit, 0, 0, 0, 3);
    
    // make the buttons used in the interface
    for (int i=0; i<10; i++) {
	ss << i;
	buttons.push_back(new calcNumberButton(ss.str().c_str(), this));
	connect(buttons[i], SIGNAL(clicked(int)), SLOT(addToDisplay(int)));
	ss.str("");
    }
    
    // operation buttons
    // FIXME: these are not supposed to be calcNumberButtons!
    buttons.push_back(new calcNumberButton(".", this));
    buttons.push_back(new calcNumberButton("+", this));
    buttons.push_back(new calcNumberButton("-", this));
    buttons.push_back(new calcNumberButton("*", this));
    buttons.push_back(new calcNumberButton("/", this));
    buttons.push_back(new calcNumberButton("=", this));
 
    // some variables
    int row=0;
    int col=0;
    int button=9;
    
    // add the buttons to the grid layout
    grid->addWidget(buttons[9], 1, 0);
    grid->addWidget(buttons[8], 1, 1);
    grid->addWidget(buttons[7], 1, 2);
    
    grid->addWidget(buttons[6], 2, 0);
    grid->addWidget(buttons[5], 2, 1);
    grid->addWidget(buttons[4], 2, 2);
    
    grid->addWidget(buttons[3], 3, 0);
    grid->addWidget(buttons[2], 3, 1);
    grid->addWidget(buttons[1], 3, 2);
    
    grid->addMultiCellWidget(buttons[0], 4, 4, 0, 1);
    
    // operational buttons
    grid->addWidget(buttons[10], 4, 2);
    grid->addWidget(buttons[11], 1, 3);
    grid->addWidget(buttons[12], 2, 3);
    grid->addWidget(buttons[13], 3, 3);
    grid->addWidget(buttons[14], 4, 3);
    
    grid->addMultiCellWidget(buttons[15], 5, 5, 0, 3);
    
};

// slot to add a number to the display
void calcBody::addToDisplay(int val) {
    std::stringstream ss;
    ss << val;
    
    lineEdit->setText(lineEdit->text()+ss.str());
    ss.str("");
};

// slot to set the current operation;
void calcBody::setOperation(int op) {
    current_op=op;
};
