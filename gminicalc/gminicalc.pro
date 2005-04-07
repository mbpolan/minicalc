SOURCES	+= main.cpp \
	mainwindow.cpp \
	calcbody.cpp \
	buttons.cpp
HEADERS	+= mainwindow.h \
	calcbody.h \
	buttons.h
unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}
TEMPLATE	=app
CONFIG	+= qt warn_on release
LANGUAGE	= C++
