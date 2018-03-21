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
#ifndef XMLREAD_H
#define XMLREAD_H

#include <QObject>
#include <QDomDocument>

namespace xml
{
	class XmlRead : public QObject
	{
		Q_OBJECT
	public:
		explicit XmlRead();
		virtual ~XmlRead();

	public:
		void loadFile(const QString & _path);
		QDomElement rootElement();

	private:
		struct XmlReadPrivate;
		XmlReadPrivate * data;
	};
}

#endif // !XMLREAD_H
