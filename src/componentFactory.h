//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   ClickButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 12,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "baseWidget.h"

namespace ios
{
	class ComponentFactory : public QObject
	{
	public:
		explicit ComponentFactory() = delete;

	public:
		static BaseWidget * create(const QString & _type);
	};
}

#endif // !COMPONENTFACTORY_H
