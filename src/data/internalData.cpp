#include "internalData.h"

#include <QString>

struct InternalData::InternalDataPrivate
{
	QString * name;
	QString * type;
	QString * value;
};

InternalData::InternalData(QObject * _parent) :
	QObject(_parent),
	data(new InternalDataPrivate)
{
	data->name = new QString;
	data->type = new QString;
	data->value = new QString;
}

InternalData::~InternalData()
{
	
}

void InternalData::setName(const QString & _name)
{
	*data->name = _name;
}

const QString & InternalData::name()
{
	return *data->name;
}

void InternalData::setType(const QString & _type)
{
	*data->type = _type;
}

const QString & InternalData::type()
{
	return *data->type;
}

void InternalData::setValue(const QString & _value)
{
	*data->value = _value;
}

const QString & InternalData::value()
{
	return *data->value;
}

void InternalData::slotDataUpdate(const QString & _value)
{
	*data->value = _value;
	emit signalDataUpdata(_value);
}
