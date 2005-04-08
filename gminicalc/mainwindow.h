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

#include <qmainwindow.h>
#include "calcbody.h"

class QAction;
class QPopupMenu;
class QMenuBar;

// the main window of the calculator where widgets are added
class mainWindow: public QMainWindow {
    Q_OBJECT
    public:
                mainWindow(QWidget *parent=0, const char *name=0);
		
	// various methods
	void makeActions();
	void makeMenuBars();
	
    public slots:
	void displayAboutDialog();
	
    private:
	calcBody *cBody; // main widget
	
	// menus
	QMenuBar *menu;
	QPopupMenu *fileMenu;
	QPopupMenu *helpMenu;
	
	// actions
	QAction *exitAct;
	QAction *aboutAct;
	
} ;
