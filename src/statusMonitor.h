//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   StatusMonitor
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 28,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef STATUSMONITOR_H
#define STATUSMONITOR_H

#include "baseWidget.h"

namespace ios
{
	class StatusMonitor : public BaseWidget
	{
	public:
		Q_OBJECT
		explicit StatusMonitor(QWidget * _parent = nullptr);
		virtual ~StatusMonitor();

	private:
		struct StatusMonitorData;
		StatusMonitorData * data;
	};
}

#endif // !STATUSMONITOR_H



