//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   TitleBar
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QFrame>

#pragma once
class StatusBar : public QFrame
{
	Q_OBJECT
public:
	explicit StatusBar(QFrame * _parent = nullptr);
	virtual ~StatusBar();

public:
	void loadConfig(const QString  & _path);

private:
	struct StatusBarPrivate;
	StatusBarPrivate * data;
};



#endif // !STATUSBAR_H

