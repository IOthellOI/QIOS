#pragma once
#ifndef FAULTDISPLAY_H
#define FAULTDISPLAY_H

#include <QListWidget>

class BaseDisplay : public QListWidget
{
public:
	explicit BaseDisplay(QWidget * _parent = nullptr);
	virtual ~BaseDisplay();
};

class FaultDisplay : public BaseDisplay
{
public:
	explicit FaultDisplay(QWidget * _parent = nullptr);
	~FaultDisplay();
	
};


#endif // !FAULTDISPLAY_H

