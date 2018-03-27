//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   IniRead
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#pragma once
#ifndef INIREAD_H
#define INIREAD_H

#include <QObject>

class IniRead : public QObject
{
	Q_OBJECT
public:
	explicit IniRead(QObject * _prent = nullptr);
	virtual ~IniRead();

	struct IniReadPrivate;
	IniReadPrivate * data;
};

#endif // !INIREAD_H