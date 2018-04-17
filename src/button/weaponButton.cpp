#include "weaponButton.h"

#include <QPushButton>
#include <QLabel>
#include <QLayout>

WeaponButton::WeaponButton(QWidget * _parent) :
	QWidget(_parent)
{
	setObjectName("WeaponButton");
}

WeaponButton::~WeaponButton()
{
	
}