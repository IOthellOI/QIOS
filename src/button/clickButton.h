//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   ClickButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 19,2018
//////////////////////////////////////////////////
#pragma once
#ifndef CLICKBUTTON_H
#define CLICKBUTTON_H

#include <QPushButton>

class ClickButton : public QPushButton
{
	Q_OBJECT
public:
	explicit ClickButton(QWidget * _parent = nullptr);
	virtual ~ClickButton();
	
protected:
	virtual void mousePressEvent(QMouseEvent * _event);	
};

#endif // !CLICKBUTTON_H