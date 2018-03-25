//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   PaginationButton
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#pragma once
#ifndef PAGINATIONBUTTON_H
#define PAGINATIONBUTTON_H

#include <QToolButton>

class PaginationButton : public QToolButton
{
	Q_OBJECT
public:
	explicit PaginationButton(QWidget * _parent = nullptr);
	virtual ~PaginationButton();	
};


#endif // !PAGINATIONBUTTON_H
