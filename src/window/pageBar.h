//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   PageBar
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#pragma once
#ifndef PAGEBAR_H
#define PAGEBAR_H

#include <QFrame>

class PageBar : public QFrame
{
	Q_OBJECT
public:
	explicit PageBar(QFrame * _parent = nullptr);
	virtual ~PageBar();
};

#endif // !PAGEBAR_H

