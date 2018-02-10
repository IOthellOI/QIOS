#include "indicationLabel.h"

#include <QLayout>
#include <QLabel>

struct ios::IndicationLabel::IndicationLabelData
{
	QLabel * label;
	QHBoxLayout * layout;
};

ios::IndicationLabel::IndicationLabel(QWidget * _parent) :
	BaseWidget(_parent),
	data(new IndicationLabelData)
{
	data->label = new QLabel;
	QSizePolicy sizePolicy = data->label->sizePolicy();
	sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
	sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
	data->label->setSizePolicy(sizePolicy);
	data->label->setAlignment(Qt::AlignCenter);

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->label);
	data->layout->setContentsMargins(0, 0, 0, 0);
	data->layout->setMargin(0);

	setLayout(data->layout);
}


ios::IndicationLabel::~IndicationLabel()
{
	delete data;
}

void ios::IndicationLabel::setText(const QString & _text) const
{
	data->label->setText(_text);
}

void ios::IndicationLabel::setState(int _state) const
{
	switch (_state)
	{
	case 0:
		data->label->setStyleSheet("background-color : rgb(255, 0, 0)");
		break;
	case 1:
		data->label->setStyleSheet("background-color : rgb(0, 255, 0)");
		break;
	default:
		data->label->setStyleSheet("background-color : rgb(255, 255, 0)");
		break;
	}
}