//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   MainWindow
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 28,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "baseWidget.h"

namespace ios
{
	class MainWindow : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit MainWindow(QWidget * parent = nullptr);
		virtual ~MainWindow();

		struct MainWindowData;
		MainWindowData * data;
	};
}
#endif // !MAINWINDOW_H
