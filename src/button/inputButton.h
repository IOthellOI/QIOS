#pragma once
#ifndef INPUTBUTTON_H
#define INPUTBUTTON_H

#include "dataPool.h"

#include <QWidget>

class InputButton : public QWidget
{
	Q_OBJECT
public:
	explicit InputButton(QWidget * _parent = nullptr);
	virtual ~InputButton();

public:
	void setName(const QString & _name);
	void setData(ExternalData * _data);

private:
	struct InputButtonPrivate;
	InputButtonPrivate * data;
};

#endif // !INPUTBUTTON_H