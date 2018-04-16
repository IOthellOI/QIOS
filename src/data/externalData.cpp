#include "externalData.h"

#include <QString>

struct ExternalData::ExternalDataPrivate
{
	QString name;
	QString type;
	QString value;
	QString unit;
	QString min;
	QString max;
	int address;
};

ExternalData::ExternalData(QObject * _parent) :
	QObject(_parent),
	data(new ExternalDataPrivate)
{
	data->address = 0x0;
}

ExternalData::~ExternalData()
{
	delete data;
}

void ExternalData::setName(const QString & _name)
{
	data->name = _name;
}

QString ExternalData::name()
{
	return data->name;
}

void ExternalData::setType(const QString & _type)
{
	data->type = _type;
}

QString ExternalData::type()
{
	return data->type;
}

void ExternalData::setValue(const QString & _value)
{
	data->value = _value;
}

QString ExternalData::value()
{
	return data->value;
}

void ExternalData::setUnit(const QString & _unit)
{
	data->unit = _unit;
}

QString ExternalData::unit()
{
	return data->unit;
}

void ExternalData::setMinValue(const QString & _min)
{
	data->min = _min;
}

QString ExternalData::minValue()
{
	return data->min;
}

void ExternalData::setMaxValue(const QString & _max)
{
	data->max = _max;
}

QString ExternalData::maxValue()
{
	return data->max;
}

void ExternalData::setAddress(int _address)
{
	data->address = _address;
}

int ExternalData::address()
{
	return data->address;
}

void ExternalData::slotDataUpdate(const QString & _value)
{
	data->value = _value;
}

void ExternalData::slotDataUpdate(unsigned short _value)
{
	data->value = QString::number(_value);
	emit signalDataUpdate(_value);
}

void ExternalData::slotDataUpdate(int _value)
{
	data->value = QString::number(_value);
	emit signalDataUpdate(_value);
}

void ExternalData::slotDataUpdate(float _value)
{
	data->value = QString::number(_value);
	emit signalDataUpdate(_value);
}

void ExternalData::slotDataUpdate(double _value)
{
	data->value = QString::number(_value);
	emit signalDataUpdate(_value);
}
