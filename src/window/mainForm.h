//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   MainForm
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#ifndef MAINFORM_H
#define MAINFORM_H
#pragma once

#include <QWidget>

class MainForm : public  QWidget
{
	Q_OBJECT
public:
	explicit MainForm(QWidget * _parent = nullptr);
	virtual ~MainForm();
};

#endif // !MAINFORM_H

