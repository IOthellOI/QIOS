//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   ToggleButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 8,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef TOGGLEBUTTON_H
#define TOGGLEBUTTON_H

#include "baseWidget.h"

namespace ios
{
	class ToggleButton : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit ToggleButton(QWidget * _parent = nullptr);
		virtual ~ToggleButton();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setChecked(bool _checked) const;

	signals:
		void signalClicked(bool _clicked);

	public slots:
		void slotClicked(bool _clicked);

	private:
		struct ToggleButtonData;
		ToggleButtonData * data;
	};
}

#endif // !ORDINARYBUTTON_H