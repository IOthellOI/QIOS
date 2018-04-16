#include "inputButton.h"

#include <QPushButton>
#include <QLabel>
#include <QLayout>

struct InputButton::InputButtonPrivate
{
	QPushButton * button;
	QLabel * name;
	QLabel * value;
	ExternalData * data;
};

InputButton::InputButton(QWidget * _parent) :
	QWidget(_parent),
	data(new InputButtonPrivate)
{
	setObjectName("InputButton");
	data->button = new QPushButton;
	data->button->setObjectName("InputButton");
	data->name = new QLabel("Undefined");
	data->name->setAlignment(Qt::AlignCenter);
	data->name->setObjectName("InputButton");
	data->value = new QLabel("Undefined");
	data->value->setAlignment(Qt::AlignCenter);
	data->value->setObjectName("InputButton");
	
	QVBoxLayout * layout = new QVBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(10);
	layout->setAlignment(Qt::AlignCenter);
	layout->addWidget(data->button);
	layout->addWidget(data->name);
	layout->addWidget(data->value);
}

InputButton::~InputButton()
{
	delete data;
}

void InputButton::setName(const QString & _name)
{
	data->name->setText(_name);
}

void InputButton::setData(ExternalData * _data)
{
	data->data = _data;
	data->value->setText(_data->value() + _data->unit());
}
