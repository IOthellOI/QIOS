#pragma once
#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

#include <QWidget>
#include <QDomDocument>

class WidgetFactory
{
public:
	WidgetFactory() = delete;
	~WidgetFactory() = delete;

public:
	static QWidget * creat(const QDomElement & element);

private:

};

#endif // !WIDGETFACTORY_H
