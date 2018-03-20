//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   ClickButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 8,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef ORDINARYBUTTON_H
#define ORDINARYBUTTON_H

#include "baseWidget.h"

namespace ios
{
	class ClickButton : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit ClickButton(QWidget * _parent = nullptr);
		virtual ~ClickButton();

	public:
		virtual void setText(const QString & _text) const;

	signals:
		void signalClicked();

	private:
		struct ClickButtonData;
		ClickButtonData * data;
	};
}

#endif // !ORDINARYBUTTON_H