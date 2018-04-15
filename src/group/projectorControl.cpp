#include "projectorControl.h"
#include "switchButton.h"

#include <QLabel>

struct ProjectorControl::ProjectorControlPrivate
{
	QLabel * state;
	SwitchButton * button;
};

ProjectorControl::ProjectorControl(QWidget * _parent) :
	QGroupBox(_parent),
	data(new ProjectorControlPrivate)
{
	setObjectName("ProjectorControl");
	
	data->state = new QLabel;
	data->state->setObjectName("ProjectorControlState");

	data->button = new SwitchButton;
	data->button->setObjectName("ProjectorControlButton");

	
}

ProjectorControl::~ProjectorControl()
{
}
