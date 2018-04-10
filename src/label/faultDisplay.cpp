#include "faultDisplay.h"

BaseDisplay::BaseDisplay(QWidget * _parent) :
	QListWidget(_parent)
{
	setWrapping(true);
}

BaseDisplay::~BaseDisplay()
{
}

FaultDisplay::FaultDisplay(QWidget * _parent)
{
	setObjectName("FaultDisplay");
}

FaultDisplay::~FaultDisplay()
{
}
