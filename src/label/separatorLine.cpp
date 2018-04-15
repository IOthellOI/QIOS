#include "separatorLine.h"

SeparatorLine::SeparatorLine(QWidget * _parent) :
	QLabel(_parent)
{
	setObjectName("SeparatorLine");
}

SeparatorLine::~SeparatorLine()
{
}

void SeparatorLine::setColor(const QString & _color)
{
	setStyleSheet("background-color: " + _color);
}
