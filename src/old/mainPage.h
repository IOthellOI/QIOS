//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   MainPage
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 1,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "baseWidget.h"

namespace ios
{
	class MainPage : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit MainPage(QWidget * _parent = nullptr);
		virtual ~MainPage();

	public:
		virtual void loadConfig(const QString & _path) const;

	public slots:
		void slotPageChanged(const QString & _page);

	private:
		struct MainPageData;
		MainPageData * data;
	};
}

#endif // !MAINPAGE_H


