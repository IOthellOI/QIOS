//////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) 2018 IOThellOI
/// All rights reserved.
/// 
/// @brief   DataPool
/// @version 1.0
/// @author  Yang Wang
/// @date    Mar 20,2018
//////////////////////////////////////////////////
#pragma once
#ifndef DATAPOOL_H
#define DATAPOOL_H

#include <QObject>
#include <QMap>

#include "internalData.h"
#include "externalData.h"

class DataPool : public QObject
{
	Q_OBJECT
public:
	explicit DataPool(QObject * _parent = nullptr);
	virtual ~DataPool();

public:
	void loadConfig(const QString & _path);
	static const QMap<QString, InternalData *> * internalDataMap();
	static const QMap<QString, ExternalData *> * externalDataMap();

private:
	void loadInternalData(const QString & _path);
	void loadExternalData(const QString & _path);

private:
	struct DataPoolPrivate;
	static DataPoolPrivate * data;
};

#endif // !DATAPOOR_H