#include "statusBar.h"

StatusBar::StatusBar(QFrame * _parent) :
	QFrame(_parent)
{
	setObjectName("StatusBar");
	setMinimumHeight(100);
	setMaximumHeight(100);
}

StatusBar::~StatusBar()
{
}
