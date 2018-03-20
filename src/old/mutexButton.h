//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   MutexButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 8,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef MUTEXBUTTON_H
#define MUTEXBUTTON_H

#include "baseWidget.h"

namespace ios
{
	class MutexButton : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit MutexButton(QWidget * _parent = nullptr);
		virtual ~MutexButton();

	public:
		virtual void setText(const QString & _text) const;
		virtual void setChecked(bool _checked) const;
		virtual void setGroup(int _group) const;

	signals:
		void signalClicked();

	public slots:
		void slotClicked(bool _clicked);

	private:
		struct MutexButtonData;
		MutexButtonData * data;
	};
}

#endif // !MUTEXBUTTON_H