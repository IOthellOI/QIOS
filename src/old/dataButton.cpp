#include "dataButton.h"
#include "inputPage.h"

#include <QLayout>
#include <QPushButton>
#include <QLabel>


struct ios::DataButton::DataButtonData
{
	QVBoxLayout * layout;
	QPushButton * button;
	QLabel * label;
	QString * unit;
};

ios::DataButton::DataButton(QWidget * _parent):
	BaseWidget(_parent),
	data(new DataButtonData)
{
	data->layout = new QVBoxLayout;
	data->layout->setMargin(0);

	data->button = new QPushButton;
	QSizePolicy sizePolicy = data->button->sizePolicy();
	sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
	sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
	data->button->setSizePolicy(sizePolicy);
	connect(data->button, SIGNAL(clicked()), this, SLOT(slotClicked()));

	data->label = new QLabel("0");
	data->label->setFixedHeight(10);
	data->label->setAlignment(Qt::AlignCenter);
	
	data->layout->addWidget(data->button);
	data->layout->addWidget(data->label);

	setLayout(data->layout);

	data->unit = new QString;
}

ios::DataButton::~DataButton()
{
	delete data;
}

void ios::DataButton::setText(const QString & _text) const
{
	data->button->setText(_text);
}

void ios::DataButton::setValue(int _value) const
{
	data->label->setText(QString::number(_value) + data->unit);
}

void ios::DataButton::setValue(double _value) const
{
	data->label->setText(QString::number(_value) + data->unit);
}

void ios::DataButton::setUnit(const QString & _unit) const
{
	*data->unit = _unit;
}


void ios::DataButton::slotClicked()
{
	InputPage * inputPage = new InputPage;
	inputPage->setWindowModality(Qt::ApplicationModal);
	inputPage->show();
	connect(inputPage, SIGNAL(signalExcuteClicked(const QString &)), this, SLOT(slotValueChanged(const QString &)));
}

void ios::DataButton::slotValueChanged(const QString & _text)
{
	data->label->setText(_text);
}