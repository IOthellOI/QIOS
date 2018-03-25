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
#pragma once
#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include <QFrame>

class NavigationBar : public QFrame
{
	Q_OBJECT
public:
	explicit NavigationBar(QFrame * _parent = nullptr);
	virtual ~NavigationBar();

public:
	void loadConfig(const QString  & _path);

private:
	struct NavigationBarPrivate;
	NavigationBarPrivate * data;
};

#endif // !NAVIGATIONBAR_H


