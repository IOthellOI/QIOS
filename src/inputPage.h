//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   InputPage
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 5,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef INPUTPAGE_H
#define INPUTPAGE_H

#include "baseWidget.h"

#include <QPushButton>

namespace ios
{
	class InputPage : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit InputPage(QWidget * _parent = nullptr);
		virtual ~InputPage();

	signals:
		void signalExcuteClicked(const QString & _text);

	public slots:
		void slotDigitClicked();
		void slotPointClicked();
		void slotMinusClicked();
		void slotBackClicked();
		void slotClearClicked();
		void slotCancelClicked();
		void slotExcuteClicked();

	private:
		struct InputPageData;
		InputPageData * data;
	};
}

#endif // !INPUTPAGE_H

