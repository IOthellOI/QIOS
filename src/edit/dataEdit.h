#pragma once
#ifndef DATAEDIT_H
#define DATAEDIT_H

#include "dataPool.h"

#include <QWidget>

class DataEdit : public QWidget
{
	Q_OBJECT
public:
	explicit DataEdit(QWidget * _parent = nullptr);
	virtual ~DataEdit();

public:
	void setName(const QString & _name);
	void setData(ExternalData * _data);

private:
	struct DataEditPrivate;
	DataEditPrivate * data;
};

#endif // !DATAEDIT_H