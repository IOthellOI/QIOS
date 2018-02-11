#include "entryBar.h"

#include <QLayout>
#include <QLabel>
#include <QSpinBox>

struct ios::EntryBar::EntryBarData
{
	QLabel * name;
	QLabel * unit;
	QDoubleSpinBox * spinBox;
	QHBoxLayout * layout;
};

ios::EntryBar::EntryBar(QWidget * _parent) :
	BaseWidget(_parent),
	data(new EntryBarData)
{
	data->name = new QLabel;
	data->unit = new QLabel;
	data->spinBox = new QDoubleSpinBox;

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->name);
	data->layout->addWidget(data->spinBox);
	data->layout->addWidget(data->unit);
	data->layout->setMargin(0);

	setLayout(data->layout);
}

ios::EntryBar::~EntryBar()
{
	delete data;
}

void ios::EntryBar::setText(const QString & _text) const
{
	data->name->setText(_text);
}

void ios::EntryBar::setValue(double _value) const
{
	data->spinBox->setValue(_value);
}

void ios::EntryBar::setUnit(const QString & _unit) const
{
	data->unit->setText(_unit);
}
