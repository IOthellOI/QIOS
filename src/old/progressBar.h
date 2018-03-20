//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   ProgressBar
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 11,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "baseWidget.h"

namespace ios
{
	class ProgressBar : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit ProgressBar(QWidget * _parent = nullptr);
		virtual ~ProgressBar();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setValue(double _value) const;
		virtual void setUnit(const QString & _unit) const;

	private:
		struct ProgressBarData;
		ProgressBarData * data;
	};
}

#endif // !PROGRESSBAR_H

