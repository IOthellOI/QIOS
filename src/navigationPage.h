//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   NavigationPage
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 12,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef NAVIGATIONPAGE_H
#define NAVIGATIONPAGE_H

#include "baseWidget.h"

namespace ios
{
	class NavigationPage : public BaseWidget
	{
	public:
		explicit NavigationPage(QWidget * _parent = nullptr);
		virtual ~NavigationPage();

	public:
		virtual void loadConfig(const QString & _path) const;

	public:
		struct NavigationPageData;
		NavigationPageData * data;
	};
}

#endif // !NAVIGATIONPAGE_H

