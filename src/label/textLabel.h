#pragma once
#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include <QLabel>

class TextLabel : public QLabel
{
	Q_OBJECT
public:
	explicit TextLabel(QWidget * _parent = nullptr);
	virtual ~TextLabel();

public:
	void setColor(const QString & _color);

protected:
};

#endif // !TEXTLABEL_H