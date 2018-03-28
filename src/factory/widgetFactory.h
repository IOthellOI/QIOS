//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   WidgetFactory
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#pragma once
#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

#include <QWidget>
#include <QDomDocument>

class WidgetFactory
{
public:
	WidgetFactory() = delete;
	~WidgetFactory() = delete;

public:
	static QWidget * creat(const QDomElement & element);

private:

};

#endif // !WIDGETFACTORY_H
