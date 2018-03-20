//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   PowerControl
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 7,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef POWERCONTROL_H
#define POWERCONTROL_H

#include "baseWidget.h"

namespace ios
{
	class PowerControl : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit PowerControl(QWidget * _parent = nullptr);
		virtual ~PowerControl();

	public:
		virtual void setText(const QString & _text) const;

	private:
		struct PowerControlData;
		PowerControlData * data;
	};
}

#endif // !POWERCONTROL_H

