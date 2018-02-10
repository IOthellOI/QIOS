//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   DataLabel
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 10,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef DATALABEL_H
#define DATALABEL_H

#include "baseWidget.h"

namespace ios
{
	class DataLabel : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit DataLabel(QWidget * _parent = nullptr);
		virtual ~DataLabel();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setValue(double _value) const;
		virtual void setUnit(const QString & _unit) const;
		
	private:
		struct DataLabelData;
		DataLabelData * data;
	};
}

#endif // !DATALABEL_H
