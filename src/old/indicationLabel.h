//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   IndicationLabel
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 10,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef INDICATIONLABEL_H
#define INDICATIONLABEL_H

#include "baseWidget.h"

namespace ios
{
	class IndicationLabel : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit IndicationLabel(QWidget * _parent = nullptr);
		virtual ~IndicationLabel();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setState(int _state) const;

	private:
		struct IndicationLabelData;
		IndicationLabelData * data;
	};

}
#endif // !INDICATIONLABEL_H