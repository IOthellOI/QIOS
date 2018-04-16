#include "internalData.h"

#include <QString>

struct InternalData::InternalDataPrivate
{
	QString name;
	QString type;
	QString value;
};

InternalData::InternalData(QObject * _parent) :
	QObject(_parent),
	data(new InternalDataPrivate)
{
}

InternalData::~InternalData()
{
	deletea data;
}

void InternalData::setName(const QString & _name)
{
	data->name = _name;
}

QString InternalData::name()
{
	return data->name;
}

void InternalData::setType(const QString & _type)
{
	data->type = _type;
}

QString InternalData::type()
{
	return data->type;
}

void InternalData::setValue(const QString & _value)
{
	data->value = _value;
}

QString InternalData::value()
{
	return data->value;
}

void InternalData::slotDataUpdate(const QString & _value)
{
	data->value = _value;
	emit signalDataUpdate(_value);
}
