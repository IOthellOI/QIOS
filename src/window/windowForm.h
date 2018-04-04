//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   WindowForm
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#ifndef WINDOWFORM_H
#define WINDOWFORM_H
#pragma once

#include <QWidget>

class WindowForm : public  QWidget
{
	Q_OBJECT
public:
	explicit WindowForm(QWidget * _parent = nullptr);
	virtual ~WindowForm();
};

#endif // !WINDOWFORM_H

