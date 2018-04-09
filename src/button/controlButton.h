#pragma once
#ifndef CONTROLBUTTON_H
#define CONTROLBUTTON_H

#include <QWidget>

class ControlButton : public QWidget
{
	Q_OBJECT
public:
	explicit ControlButton(QWidget * _parent = nullptr);
	virtual ~ControlButton();

public:
	void setText(const QString & _text);
	void setIcon(const QIcon & _icon);

private:
	struct ControlButtonPrivate;
	ControlButtonPrivate * data;
};

#endif // !CONTROLBUTTON_H