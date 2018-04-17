#pragma once
#ifndef DATASLIDER_H
#define DATASLIDER_H

#include "dataPool.h"

#include <QWidget>

class DataSlider : public QWidget
{
	Q_OBJECT
public:
	explicit DataSlider(QWidget * _parent = nullptr);
	virtual ~DataSlider();

public:
	void setName(const QString & _name);
	void setData(ExternalData * _data);
	
public slots:
	void slotDataUpdate(int _value);

private:
	struct DataSliderPrivate;
	DataSliderPrivate * data;
};

#endif // !DATASLIDER_H