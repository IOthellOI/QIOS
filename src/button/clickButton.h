//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   ClickButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#pragma once
#ifndef CLICKBUTTON_H
#define CLICKBUTTON_H

#include <QWidget>

class ClickButton : public QWidget
{
	Q_OBJECT
public:
	explicit ClickButton(QWidget * _parent = nullptr);
	virtual ~ClickButton();

public:
	
};

#endif // !CLICKBUTTON_H