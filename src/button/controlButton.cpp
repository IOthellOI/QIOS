#include "controlButton.h"

#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QButtonGroup>

struct ControlButton::ControlButtonPrivate
{
	QPushButton * button;
	QLabel * label;
	static QButtonGroup * group;
};

QButtonGroup * ControlButton::ControlButtonPrivate::group = new QButtonGroup;

ControlButton::ControlButton(QWidget * _parent) :
	QWidget(_parent),
	data(new ControlButtonPrivate)
{
	data->button = new QPushButton;
	data->button->setObjectName("ControlButton");
	data->button->setCheckable(true);
	data->group->addButton(data->button);
	data->label = new QLabel;
	data->label->setObjectName("ControlButton");
	data->label->setAlignment(Qt::AlignCenter);

	QVBoxLayout * layout = new QVBoxLayout(this);
	layout->setMargin(0);
	layout->addWidget(data->button);
	layout->addWidget(data->label);
	layout->setAlignment(Qt::AlignCenter);
}

ControlButton::~ControlButton()
{
}

void ControlButton::setText(const QString & _text)
{
	data->label->setText(_text);
}

void ControlButton::setIcon(const QIcon & _icon)
{
	data->button->setIcon(_icon);
}
