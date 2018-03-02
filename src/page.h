//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   Page
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 1,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef PAGE_H
#define PAGE_H

#include "baseWidget.h"

namespace ios
{
	class Page : public BaseWidget
	{
	public:
		explicit Page(QWidget * _parent = nullptr);
		virtual ~Page();

	public:
		virtual void loadConfig(const QString & _path) const;

	private:
		struct PageData;
		PageData * data;
	};
}

#endif // !PAGE_H
