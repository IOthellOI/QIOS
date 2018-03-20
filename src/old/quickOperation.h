//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   QuickOperation
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 28,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef QUICKOPERATION_H
#define QUICKOPERATION_H

#include "baseWidget.h"

namespace ios
{
	class QuickOperation : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit QuickOperation(QWidget * _parent = nullptr);
		virtual ~QuickOperation();
		
	public:
		virtual void loadConfig(const QString & _path);

	private:
		struct QuickOperationData;
		QuickOperationData * data;
	};
}

#endif // !QUICKOPERATION_H

