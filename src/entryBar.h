//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   DataSlider
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 11,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef ENTRYBAR_H
#define ENTRYBAR_H

#include "baseWidget.h"

namespace ios
{
	class EntryBar : public BaseWidget
	{
	public:
		explicit EntryBar(QWidget * _parent = nullptr);
		virtual ~EntryBar();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setValue(double _value) const;
		virtual void setUnit(const QString & _unit) const;
		
	private:
		struct EntryBarData;
		EntryBarData * data;
	};
}

#endif // ENTRYBAR_H

