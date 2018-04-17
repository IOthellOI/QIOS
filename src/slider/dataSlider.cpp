#include "dataSlider.h"

#include <QLabel>
#include <QSlider>
#include <QLayout>

struct DataSlider::DataSliderPrivate
{
	QLabel * name;
	QLabel * value;
	QSlider * slider;
};

DataSlider::DataSlider(QWidget * _parent) :
	QWidget(_parent),
	data(new DataSliderPrivate)
{
	setObjectName("DataSlider");
	data->name = new QLabel("Undefined");
	data->name->setObjectName("DataSlider");
	data->value = new QLabel("Undefined");
	data->value->setObjectName("DataSlider");
	data->slider = new QSlider;
	data->slider->setOrientation(Qt::Horizontal);
	data->slider->setObjectName("DataSlider");

	QHBoxLayout * layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(10);
	layout->setAlignment(Qt::AlignCenter);
	layout->addWidget(data->name);
	layout->addWidget(data->slider);
	layout->addWidget(data->value);
}

DataSlider::~DataSlider()
{
	delete data;
}

void DataSlider::setName(const QString & _name)
{
	data->name->setText(_name + ":");
}

void DataSlider::setData(ExternalData * _data)
{
	data->slider->setRange(_data->minValue().toInt(), _data->maxValue().toInt());
	data->slider->setValue(_data->value().toInt());
	data->slider->setPageStep((_data->minValue().toInt() - _data->maxValue().toInt()) / 10);
	data->value->setText(_data->value() + _data->unit());

	connect(data->slider, SIGNAL(valueChanged(int)), _data, SLOT(slotDataUpdate(int)));
	connect(_data, SIGNAL(signalDataUpdate(int)), this, SLOT(slotDataUpdate(int)));
}

void DataSlider::slotDataUpdate(int _value)
{
	data->value->setText(QString::number(_value)
		+ dynamic_cast<ExternalData *>(sender())->unit());
}
