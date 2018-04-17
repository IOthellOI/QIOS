#pragma once
#ifndef TOGGLEBUTTON_H
#define TOGGLEBUTTON_H

#include "switchButton.h"

class ToggleButton : public QWidget
{
public:
	explicit ToggleButton(QWidget * _parent = nullptr);
	virtual ~ToggleButton();

public:
	void setName(const QString & _name);

private:
	struct ToggleButtonPrivate;
	ToggleButtonPrivate * data;
};

#endif // !TOGGLEBUTTON_H