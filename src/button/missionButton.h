#pragma once
#ifndef MISSIONBUTTON_H
#define MISSIONBUTTON_H

#include <QPushButton>

class MissionButton : public QPushButton
{
	Q_OBJECT
public:
	explicit MissionButton(QWidget * _parent = nullptr);
	virtual ~MissionButton();
};

#endif // MISSIONBUTTON_H
