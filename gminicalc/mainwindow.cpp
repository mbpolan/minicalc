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

#include <qaction.h>
#include <qapplication.h>
#include <qlayout.h>
#include <qpopupmenu.h>
#include <qpushbutton.h>
#include <qmenubar.h>
#include <sstream>

#include "mainwindow.h"

// mainWindow constructor
mainWindow::mainWindow(QWidget *parent, const char *name): QMainWindow(parent, name) {
    setCaption("Mini Calc");
    cBody=new calcBody(this);
    setCentralWidget(cBody);
    
};

// make the actions
// TODO: port this over to a newer version of Qt. (i am temporarily using 3.0 cause my linux box is messed up :P)
void mainWindow::makeActions() {
    exitAct=new QAction(tr("Quit"), tr("&Quit"), tr("Ctrl+Q"), this);
    connect(exitAct, SIGNAL(activated()), qApp, SLOT(quit()));

    aboutAct=new QAction(tr("About GMini-Calc"), tr("&About"), tr("Alt+H"), this);
    connect(aboutAct, SIGNAL(activated()), SLOT(displayAboutDialog()));
};

// create the menus and menu bars
void mainWindow::makeMenuBars() {
    menu=new QMenuBar(this);
    
    // file menu
    fileMenu=new QPopupMenu(this);
    exitAct->addTo(fileMenu);
    
    // help menu
    helpMenu=new QPopupMenu(this);
    aboutAct->addTo(helpMenu);
    
    // order of menus is: file, help
    menu->insertItem(tr("&File"), fileMenu);
    menu->insertItem(tr("&Help"), helpMenu);
};

// TODO: about dialog
void mainWindow::displayAboutDialog() {
    return;
};
