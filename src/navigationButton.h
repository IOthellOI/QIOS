//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   NavigationButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 9,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef NAVIGATIONBUTTON_H
#define NAVIGATIONBUTTON_H

#include "baseWidget.h"

namespace ios
{
	class NavigationButton : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit NavigationButton(QWidget * _parent = nullptr);
		virtual ~NavigationButton();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setIcon(const QIcon & _icon) const;

	signals:
		void signalClicked();

	public slots:
		void slotClicked(bool _clicked);

	private:
		struct NavigationButtonData;
		NavigationButtonData * data;
	};
}

#endif // !NAVIGATIONBUTTON_H