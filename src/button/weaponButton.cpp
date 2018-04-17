#include "weaponButton.h"

#include <QPushButton>
#include <QLabel>
#include <QLayout>

struct WeaponButton::WeaponButtonPrivate
{
	QPushButton * button;
	QLabel * name;
};

WeaponButton::WeaponButton(QWidget * _parent) :
	QWidget(_parent),
	data(new WeaponButtonPrivate)
{
	setObjectName("WeaponButton");
	data->button = new QPushButton;
	data->button->setObjectName("WeaponButton");
	data->name = new QLabel("Undefined");
	data->name->setObjectName("WeaponButton");
	data->name->setAlignment(Qt::AlignCenter);
	QVBoxLayout * layout = new QVBoxLayout(this);
	layout->addWidget(data->button);
	layout->addWidget(data->name);
	layout->setSpacing(5);
	layout->setAlignment(Qt::AlignCenter);
}

WeaponButton::~WeaponButton()
{
	delete data;
}

void WeaponButton::setName(const QString & _name)
{
	data->name->setText(_name);
}

void WeaponButton::setNumber(int _number)
{
	data->button->setText(QString::number(_number));
}
