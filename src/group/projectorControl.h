#pragma once
#ifndef PROJECTORCONTROL_H
#define PROJECTORCONTROL_H

#include <QGroupBox>

class ProjectorControl : public QGroupBox
{
	Q_OBJECT
public:
	explicit ProjectorControl(QWidget * _parent = nullptr);
	~ProjectorControl();

public:
	void setState(const QString & _state);

private:
	struct ProjectorControlPrivate;
	ProjectorControlPrivate * data;
};

#endif // !PROJECTORCONTROL_H



