#include "dataEdit.h"

#include <QLabel>
#include <QDoubleSpinBox>
#include <QLayout>

struct DataEdit::DataEditPrivate
{
	QLabel * name;
	QDoubleSpinBox * edit;
	QLabel * unit;
};

DataEdit::DataEdit(QWidget * _parent) :
	QWidget(_parent),
	data(new DataEditPrivate)
{
	setObjectName("DataEdit");
	data->name = new QLabel("Undefined");
	data->name->setObjectName("DataEdit");
	data->edit = new QDoubleSpinBox;
	data->edit->setObjectName("DataEdit");
	data->edit->setDecimals(4);
	data->unit = new QLabel("Undefined");
	data->unit->setObjectName("DataEdit");
	
	QHBoxLayout * layout = new QHBoxLayout(this);
	layout->addWidget(data->name);
	layout->addWidget(data->edit);
	layout->addWidget(data->unit);
	layout->setMargin(0);
	layout->setAlignment(Qt::AlignCenter);
}

DataEdit::~DataEdit()
{
	delete data;
}

void DataEdit::setName(const QString & _name)
{
	data->name->setText(_name + ":");
}

void DataEdit::setData(ExternalData * _data)
{
	data->edit->setValue(_data->value().toDouble());
	data->edit->setRange(_data->minValue().toDouble(), _data->maxValue().toDouble());
	data->unit->setText(_data->unit());
}
