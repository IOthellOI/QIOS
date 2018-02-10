#include "dataSlider.h"

#include <QLayout>
#include <QSlider>

struct ios::DataSlider::DataSliderData
{
	QSlider * slider;
	QHBoxLayout * layout;
};

ios::DataSlider::DataSlider(QWidget * _parent) :
	BaseWidget(_parent),
	data(new DataSliderData)
{
	data->slider = new QSlider;
	QSizePolicy sizePolicy = data->slider->sizePolicy();
	sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
	sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
	data->slider->setSizePolicy(sizePolicy);

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->slider);
	data->layout->setContentsMargins(0, 0, 0, 0);
	data->layout->setMargin(0);

	setLayout(data->layout);
}

ios::DataSlider::~DataSlider()
{
	delete data;
}
