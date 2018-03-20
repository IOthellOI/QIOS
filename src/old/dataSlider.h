//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   DataSlider
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 10,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef DATASLIDER_H
#define DATASLIDER_H

#include "baseWidget.h"

namespace ios
{
	class DataSlider : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit DataSlider(QWidget * _parent = nullptr);
		virtual ~DataSlider();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setValue(int _value) const;
		virtual void setUnit(const QString & _unit) const;

	public slots:
		void slotSilde(int _value);

	private:
		struct DataSliderData;
		DataSliderData * data;
	};
}

#endif // !DATASLIDER_H