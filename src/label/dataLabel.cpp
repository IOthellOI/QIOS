#include "dataLabel.h"

#include <QLabel>
#include <QLayout>

struct DataLabel::DataLabelPrivate
{
	QLabel * name;
	QLabel * value;
};

DataLabel::DataLabel(QWidget * _parent) :
	QWidget(_parent),
	data(new DataLabelPrivate)
{
	setObjectName("DataLabel");	
	data->name = new QLabel("Undefined");
	data->name->setObjectName("DataLabel");
	data->value = new QLabel("Undefined");
	data->value->setObjectName("DataLabel");
	
	QHBoxLayout * layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(0);
	layout->addWidget(data->name);
	layout->addWidget(data->value);
}

DataLabel::~DataLabel()
{
	delete data;
}

void DataLabel::setName(const QString & _name)
{
	data->name->setText(_name);
}

void DataLabel::setData(ExternalData * _data)
{
	data->value->setText(_data->value() + _data->unit());
}
