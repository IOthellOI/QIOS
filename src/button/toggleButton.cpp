#include "toggleButton.h"

#include <QLabel>
#include <QLayout>

struct ToggleButton::ToggleButtonPrivate
{
	SwitchButton * button;
	QLabel * name;
};

ToggleButton::ToggleButton(QWidget * _parent) :
	QWidget(_parent),
	data(new ToggleButtonPrivate)
{
	setObjectName("ToggleButton");
	data->button = new SwitchButton;
	data->button->setObjectName("ToggleButtonButton");
	
	data->name = new QLabel("Undefined");
	data->name->setObjectName("ToggleButtonName");

	QHBoxLayout * layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(10);
	layout->setAlignment(Qt::AlignCenter);
	layout->addWidget(data->button);
	layout->addWidget(data->name);
}

ToggleButton::~ToggleButton()
{
	delete data;
}

void ToggleButton::setName(const QString & _name)
{
	data->name->setText(_name);
}
