//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   InternalData
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#pragma once
#ifndef INTERNALDATA_H
#define INTERNALDATA_H

#include <QObject>

class InternalData : public QObject
{
	Q_OBJECT
public:
	explicit InternalData(QObject * _parent = nullptr);
	~InternalData();

public:
	void setName(const QString & _name);
	QString name();
	void setType(const QString & _type);
	QString type();
	void setValue(const QString & _value);
	QString value();

signals:
	void signalDataUpdate(const QString & _value);

public slots:
	void slotDataUpdate(const QString & _value);

private:
	struct InternalDataPrivate;
	InternalDataPrivate * data;
};

#endif // !INTERNALDATA_H