//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   TextLabel
/// @version 1.0
/// @author  Yang Wang
/// @date    Feb 9,2018
/// @web     http://iothelloi.sxl.cn/
/// @git     https://github.com/iothelloi/
//////////////////////////////////////////////////
#pragma once
#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include "baseWidget.h"

namespace ios
{
	class TextLabel : public BaseWidget
	{
		Q_OBJECT
	public:
		explicit TextLabel(QWidget * _parent = nullptr);
		virtual ~TextLabel();

	public:
		virtual void setText(const QString & _text) const;

	private:
		struct TextLabelData;
		TextLabelData * data;
	};
}

#endif // !TEXTLABEL_H 