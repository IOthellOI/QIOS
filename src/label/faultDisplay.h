#pragma once
#ifndef FAULTDISPLAY_H
#define FAULTDISPLAY_H

#include <QListWidget>

class BaseDisplay : public QListWidget
{
	Q_OBJECT
public:
	explicit BaseDisplay(QWidget * _parent = nullptr);
	virtual ~BaseDisplay();
};

class FaultDisplay : public BaseDisplay
{
	Q_OBJECT
public:
	explicit FaultDisplay(QWidget * _parent = nullptr);
	~FaultDisplay();
	
};


#endif // !FAULTDISPLAY_H

