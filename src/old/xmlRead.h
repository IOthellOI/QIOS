//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   BaseWidget
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 8,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef XMLREAD_H
#define XMLREAD_H

#include <QObject>
#include <QDomDocument>

namespace ios
{
	class XmlRead : public QObject
	{
	public:
		explicit XmlRead();
		virtual ~XmlRead();

	public:
		bool loadFile(const QString & _path);
		QDomElement rootElement();

	private:
		struct XmlReadData;
		XmlReadData * data;
	};
}

#endif // !XMLREAD_H
