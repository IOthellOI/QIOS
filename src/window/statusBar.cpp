#include "statusBar.h"

StatusBar::StatusBar(QFrame * _parent) :
	QFrame(_parent)
{
	setMinimumHeight(100);
	setMaximumHeight(100);
}

StatusBar::~StatusBar()
{
}
