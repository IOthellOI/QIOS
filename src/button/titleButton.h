#pragma once
#ifndef TITLEBUTTON_H
#define TITLEBUTTON_H

#include <QPushButton>

class TitleButton : public QPushButton
{
	Q_OBJECT
public:
	explicit TitleButton(QWidget * _parent = nullptr);
	virtual ~TitleButton();
};

#endif // !TITLEBUTTON_H

