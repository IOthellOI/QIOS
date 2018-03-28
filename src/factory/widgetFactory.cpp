#include "widgetFactory.h"
#include "pictureLabel.h"

#include <QPixmap>
#include <QImage>

static QWidget * creatPictrueLabel(const QDomElement & element);
static QWidget * creatEmptyWidget(const QDomElement & element);

QWidget * WidgetFactory::creat(const QDomElement & element)
{
	if (element.nodeName().toUpper() == "PICTURELABEL")
	{
		return creatPictrueLabel(element);
	}
	else if (element.nodeName().toUpper() == "EMPTYWIDGET")
	{
		return creatPictrueLabel(element);
	}
	else
	{
		return nullptr;
	}
}

static QWidget * creatPictrueLabel(const QDomElement & element)
{
	PictureLabel * label = new PictureLabel;

	label->setFixedSize(QSize(element.attribute("width").toInt(), element.attribute("height").toInt()));

	QImage icon(element.attribute("icon"));
	icon = icon.scaled(label->size(), Qt::KeepAspectRatio);

	label->setPixmap(QPixmap::fromImage(icon));	

	return label;
}

static QWidget * creatEmptyWidget(const QDomElement & element)
{
	QWidget * widget = new QWidget;
	if (element.hasAttribute("width"))
	{
		widget->setFixedWidth(element.attribute("width").toInt());
	}
	if (element.hasAttribute("height"))
	{
		widget->setFixedWidth(element.attribute("height").toInt());
	}
	return widget;
}