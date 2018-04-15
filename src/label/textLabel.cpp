#include "textLabel.h"

TextLabel::TextLabel(QWidget * _parent) :
	QLabel(_parent)
{
	setObjectName("TextLabel");
	setAlignment(Qt::AlignCenter);
}

TextLabel::~TextLabel()
{
}

void TextLabel::setColor(const QString & _color)
{
	if (_color == "white")
	{
		setStyleSheet("color: " + _color);
	}
	else if (_color == "black")
	{
		setStyleSheet("color: " + _color);
	}
}
