#include "projectorControl.h"
#include "switchButton.h"

#include <QLabel>
#include <QLayout>

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
	
	data->state = new QLabel(u8"Î´Æô¶¯");
	data->state->setAlignment(Qt::AlignCenter);
	data->state->setObjectName("ProjectorControl");

	data->button = new SwitchButton;

	QGridLayout * layout = new QGridLayout(this);
	layout->setMargin(5);
	layout->addWidget(data->state, 0, 0, 1, 2);
	layout->addWidget(data->button, 1, 1, 1, 1);
}

ProjectorControl::~ProjectorControl()
{
	delete data;
}

void ProjectorControl::setState(const QString & _state)
{
	data->state->setText(_state);
}
