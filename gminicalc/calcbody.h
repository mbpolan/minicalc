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

#include <qwidget.h>
#include <vector>

// define some operations
#define OP_ADD 0
#define OP_SUBTR 1
#define OP_MULTI 2
#define OP_DIV 3

class QGridLayout;
class QPushButton;
class QLineEdit;
class calcNumberButton;

// the main interface of the calculator
class calcBody: public QWidget {
    Q_OBJECT
    public:
                calcBody(QWidget *parent, const char *name=0);
		
    public slots:
	    void addToDisplay(int);
                    void setOperation(int);
	
    private:
	QGridLayout *grid;
	
	QLineEdit *lineEdit;
	
	std::vector<calcNumberButton*> buttons;
	
	// current operation
	int current_op;
};
