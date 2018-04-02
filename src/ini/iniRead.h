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
#include <QSize>

class IniRead : public QObject
{
	Q_OBJECT
public:
	explicit IniRead(QObject * _prent = nullptr);
	virtual ~IniRead();

public:
	void loadIni(const QString & _path);
	static QSize mainFormSize();

	struct IniReadPrivate;
	static IniReadPrivate * data;
};

#endif // !INIREAD_H