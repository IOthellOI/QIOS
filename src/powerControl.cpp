#include "powerControl.h"

#include <QLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>

#pragma execution_character_set("utf-8")

struct ios::PowerControl::PowerControlData
{
	QGroupBox * box;
	QGridLayout * layout;
	QLabel * control;
	QLabel * connect;
	QPushButton * button;
};

ios::PowerControl::PowerControl(QWidget * _parent):
	BaseWidget(_parent),
	data(new PowerControlData)
{
	data->box = new QGroupBox;
	data->layout = new QGridLayout;

	data->control = new QLabel("可控");
	data->control->setAlignment(Qt::AlignCenter);
	data->control->setStyleSheet("background-color : rgb(255, 0, 0)");

	data->connect = new QLabel("接通");
	data->connect->setAlignment(Qt::AlignCenter);
	data->connect->setStyleSheet("background-color : rgb(255, 0, 0)");

	data->button = new QPushButton("电源控制开关");
	data->button->setCheckable(true);
	data->button->setFixedHeight(40);

	data->box->setLayout(data->layout);
	data->layout->addWidget(data->control, 0, 0, 1, 1);
	data->layout->addWidget(data->connect, 0, 1, 1, 1);
	data->layout->addWidget(data->button, 1, 0, 1, 2);

	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(data->box);

	setLayout(layout);
}

ios::PowerControl::~PowerControl()
{
	delete data;
}

void ios::PowerControl::setText(const QString & _text) const
{
	data->box->setTitle(_text);
}
