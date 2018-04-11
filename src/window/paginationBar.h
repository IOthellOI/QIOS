//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   PaginationBar
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#pragma once
#ifndef PAGINATIONBAR_H
#define PAGINATIONBAR_H

#include <QFrame>

class PaginationBar : public QFrame
{
	Q_OBJECT
public:
	explicit PaginationBar(QFrame * _parent = nullptr);
	virtual ~PaginationBar();

public:
	void loadConfig(const QString  & _path);

signals:
	void signalPaginationChange(const QString & _page);

private slots:
	void slotNavigationChange(const QString & _value);
	void slotPaginationChange();

private:
	struct PaginationBarPrivate;
	PaginationBarPrivate * data;
};

#endif // !NAVIGATIONBAR_H


