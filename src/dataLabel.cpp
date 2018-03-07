#include "dataLabel.h"

#include <QLayout>
#include <QLabel>

struct ios::DataLabel::DataLabelData
{
	QLabel * name;
	QLabel * value;
	QLabel * unit;
	QHBoxLayout * layout;
};

ios::DataLabel::DataLabel(QWidget * _parent) :
	BaseWidget(_parent),
	data(new DataLabelData)
{
	data->name = new QLabel;
	data->value = new QLabel;
	data->value->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	data->unit = new QLabel;

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->name);
	data->layout->addWidget(data->value);
	data->layout->addWidget(data->unit);
	data->layout->setMargin(0);

	setLayout(data->layout);
}

ios::DataLabel::~DataLabel()
{
	delete data;
}

void ios::DataLabel::setText(const QString & _text) const
{
	data->name->setText(_text);
}

void ios::DataLabel::setValue(double _value) const
{
	data->value->setText(QString::number(_value));
}

void ios::DataLabel::setUnit(const QString & _unit) const
{
	data->unit->setText(_unit);
}
