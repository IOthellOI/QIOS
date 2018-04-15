#pragma once
#ifndef SEPARATORLINE_H
#define SEPARATORLINE_H

#include <QLabel>

class SeparatorLine : public QLabel
{
public:
	explicit SeparatorLine(QWidget * _parent = nullptr);
	virtual ~SeparatorLine();

public:
	void setColor(const QString & _color);
};

#endif // !SEPARATORLINE_H