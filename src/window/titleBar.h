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
#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QFrame>

class TitleBar : public QFrame
{
	Q_OBJECT
public:
	explicit TitleBar(QFrame * _parent = nullptr);
	virtual ~TitleBar();

public:
	void loadConfig(const QString & _path);

private:
	struct TitleBarPrivate;
	TitleBarPrivate * data;
};

#endif // !TITLEBAR_H


