//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   PictureLabel
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#pragma once
#ifndef PICTURELABEL_H
#define PICTURELABEL_H

#include <QLabel>

class PictureLabel : public QLabel
{
public:
	explicit PictureLabel(QWidget * _parent = nullptr);
	virtual ~PictureLabel();

};

#endif // !PICTURELABEL_H