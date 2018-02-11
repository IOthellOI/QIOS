#include "dataSlider.h"

#include <QLayout>
#include <QSlider>
#include <QLabel>

struct ios::DataSlider::DataSliderData
{
	QLabel * name;
	QLabel * value;
	QLabel * unit;
	QSlider * slider;
	QHBoxLayout * layout;
};

ios::DataSlider::DataSlider(QWidget * _parent) :
	BaseWidget(_parent),
	data(new DataSliderData)
{
	data->slider = new QSlider;
	data->slider->setOrientation(Qt::Horizontal);

	data->name = new QLabel;
	data->value = new QLabel;
	data->unit = new QLabel;

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->name);
	data->layout->addWidget(data->slider);
	data->layout->addWidget(data->value);
	data->layout->addWidget(data->unit);
	data->layout->setMargin(0);

	setLayout(data->layout);
	connect(data->slider, SIGNAL(valueChanged(int)), this, SLOT(slotSilde(int)));
}

ios::DataSlider::~DataSlider()
{
	delete data;
}

void ios::DataSlider::setText(const QString & _text) const
{
	data->name->setText(_text);
}

void ios::DataSlider::setValue(int _value) const
{
	data->value->setText(QString::number(_value));
}
	
void ios::DataSlider::setUnit(const QString & _unit) const
{
	data->unit->setText(_unit);
}

void ios::DataSlider::slotSilde(int _value)
{
	data->value->setText(QString::number(_value));
}