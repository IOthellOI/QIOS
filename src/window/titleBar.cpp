#include "titleBar.h"

TitleBar::TitleBar(QFrame * _parent) :
	QFrame(_parent)
{
	setObjectName("TitleBar");
	setMaximumHeight(50);
	setMinimumHeight(50);
}

TitleBar::~TitleBar()
{
	
}
