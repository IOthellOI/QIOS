#pragma once
#ifndef NAVIGATIONBUTTON_H
#define NAVIGATIONBUTTON_H

#include <QToolButton>

class NavigationButton : public QToolButton
{
	Q_OBJECT
public:
	explicit NavigationButton(QWidget * _parent = nullptr);
	virtual ~NavigationButton();

public:
	virtual void setIcon(const QIcon & _icon);

protected:
	bool eventFilter(QObject * _object, QEvent * _event);

private:
	struct NavigationButtonPrivate;
	NavigationButtonPrivate * data;
};


#endif // !NAVIGATIONBUTTON_H
