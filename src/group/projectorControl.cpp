#include "projectorControl.h"

#include <QLabel>
#include <QCheckBox>

struct ProjectorControl::ProjectorControlPrivate
{
	QLabel * name;
	QLabel * state;
	QCheckBox * button;
};

ProjectorControl::ProjectorControl(QWidget * _parent) :
	QGroupBox(_parent),
	data(new ProjectorControlPrivate)
{
	setObjectName("ProjectorControl");

}

ProjectorControl::~ProjectorControl()
{
}
