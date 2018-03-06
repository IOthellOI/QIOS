//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   DataButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 5,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef DATABUTTON_H
#define DATABUTTON_H

#include "baseWidget.h"

namespace ios
{
	class DataButton : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit DataButton(QWidget * _parent = nullptr);
		virtual ~DataButton();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setValue(int _value) const;
		virtual void setValue(double _value) const;
		virtual void setUnit(const QString & _unit) const;

	signals:

	public slots:
		void slotClicked();
		void slotValueChanged(const QString & _text);

	private:
		struct DataButtonData;
		DataButtonData * data;
	};
}

#endif // !DATABUTTON_H

