#include "progressBar.h"

#include <QLayout>
#include <QProgressBar>
#include <QLabel>

struct ios::ProgressBar::ProgressBarData
{
	QLabel * name;
	QLabel * value;
	QLabel * unit;
	QProgressBar * progressBar;
	QHBoxLayout * layout;
};

ios::ProgressBar::ProgressBar(QWidget * _parent) :
	BaseWidget(_parent),
	data(new ProgressBarData)
{
	data->progressBar = new QProgressBar;
	data->progressBar->setValue(80);
	data->progressBar->setOrientation(Qt::Horizontal);
	data->progressBar->setAlignment(Qt::AlignCenter);

	data->name = new QLabel;
	data->value = new QLabel;
	data->unit = new QLabel;

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->name);
	data->layout->addWidget(data->value);
	data->layout->addWidget(data->unit);
	data->layout->addWidget(data->progressBar);
	data->layout->setMargin(0);
	
	setLayout(data->layout);
}

ios::ProgressBar::~ProgressBar()
{
	delete data;
}


void ios::ProgressBar::setText(const QString & _text) const
{
	data->name->setText(_text);
}

void ios::ProgressBar::setValue(double _value) const
{
	data->value->setText(QString::number(_value));
}

void ios::ProgressBar::setUnit(const QString & _unit) const
{
	data->unit->setText(_unit);
}