#pragma once
#ifndef LOGINBUTTON_H
#define LOGINBUTTON_H

#include <QPushButton>

class LoginButton : public QPushButton
{
	Q_OBJECT
public:
	explicit LoginButton(QWidget * _parent = nullptr);
	virtual ~LoginButton();

};

#endif // !LOGINBUTTON_H