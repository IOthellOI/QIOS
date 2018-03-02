//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   Navigation
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 12,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "baseWidget.h"

namespace ios
{
	class Navigation : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit Navigation(QWidget * _parent = nullptr);
		virtual ~Navigation();

	public:
		virtual void loadConfig(const QString & _path) const;
		
	signals:
		void signalPageChanged(const QString & _page);

	public slots:
		void slotPageChanged(const QString & _page);

	public:
		struct NavigationData;
		NavigationData * data;
	};
}

#endif // !NAVIGATION_H

