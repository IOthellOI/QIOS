#pragma once
#ifndef DATALABEL_H
#define DATALABEL_H

#include "dataPool.h"

#include <QWidget>

class DataLabel : public QWidget
{
	Q_OBJECT
public:
	explicit DataLabel(QWidget * _parent = nullptr);
	virtual ~DataLabel();

public:
	void setName(const QString & _name);
	void setData(ExternalData * _data);

private:
	struct DataLabelPrivate;
	DataLabelPrivate * data;
};

#endif // !DATALABEL_H