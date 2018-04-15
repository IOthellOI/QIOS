#include "widgetFactory.h"
#include "pictureLabel.h"
#include "loginEdit.h"
#include "loginButton.h"
#include "textLabel.h"
#include "titleButton.h"
#include "controlButton.h"
#include "faultDisplay.h"
#include "computerTable.h"
#include "projectorControl.h"
#include "separatorLine.h"

#include <QPixmap>
#include <QImage>
#include <QPicture>

static QWidget * creatPictrueLabel(const QDomElement & element);
static QWidget * creatEmptyWidget(const QDomElement & element);
static QWidget * creatLoginEdit(const QDomElement & element);
static QWidget * creatLoginButton(const QDomElement & element);
static QWidget * creatTextLabel(const QDomElement & element);
static QWidget * creatTitleButton(const QDomElement & element);
static QWidget * creatControlButton(const QDomElement & element);
static QWidget * creatFaultDisplay(const QDomElement & element);
static QWidget * creatComputerTable(const QDomElement & element);
static QWidget * creatProjectorControl(const QDomElement & element);
static QWidget * creatSeparatorLine(const QDomElement & element);

QWidget * WidgetFactory::creat(const QDomElement & element)
{
	if (element.nodeName().toUpper() == "PICTURELABEL")
	{
		return creatPictrueLabel(element);
	}
	else if (element.nodeName().toUpper() == "EMPTYWIDGET")
	{
		return creatEmptyWidget(element);
	}
	else if (element.nodeName().toUpper() == "LOGINEDIT")
	{
		return creatLoginEdit(element);
	}
	else if (element.nodeName().toUpper() == "LOGINBUTTON")
	{
		return creatLoginButton(element);
	}
	else if (element.nodeName().toUpper() == "TEXTLABEL")
	{
		return creatTextLabel(element);
	}
	else if (element.nodeName().toUpper() == "TITLEBUTTON")
	{
		return creatTitleButton(element);
	}
	else if (element.nodeName().toUpper() == "CONTROLBUTTON")
	{
		return creatControlButton(element);
	}
	else if (element.nodeName().toUpper() == "FAULTDISPLAY")
	{
		return creatFaultDisplay(element);
	}
	else if (element.nodeName().toUpper() == "COMPUTERTABLE")
	{
		return creatComputerTable(element);
	}
	else if (element.nodeName().toUpper() == "PROJECTORCONTROL")
	{
		return creatProjectorControl(element);
	}
	else if (element.nodeName().toUpper() == "SEPARATORLINE")
	{
		return creatSeparatorLine(element);
	}
	else
	{
		return nullptr;
	}
}

QWidget * creatPictrueLabel(const QDomElement & element)
{
	PictureLabel * label = new PictureLabel;

	label->setFixedSize(QSize(element.attribute("width").toInt(), element.attribute("height").toInt()));

	QImage icon(element.attribute("icon"));
	icon = icon.scaled(label->size(), Qt::KeepAspectRatio);

	label->setPixmap(QPixmap::fromImage(icon));	

	return label;
}

QWidget * creatEmptyWidget(const QDomElement & element)
{
	QWidget * widget = new QWidget;
	if (element.hasAttribute("width"))
	{
		widget->setFixedWidth(element.attribute("width").toInt());
	}
	if (element.hasAttribute("height"))
	{
		widget->setMinimumHeight(element.attribute("height").toInt());
	}
	return widget;
}

QWidget * creatLoginEdit(const QDomElement & element)
{
	LoginEdit * edit = new LoginEdit;
	if (element.hasAttribute("icon"))
	{
		edit->setIcon(QPixmap(element.attribute("icon")));
	}
	if (element.hasAttribute("text"))
	{
		edit->setText(element.attribute("text"));
	}
	if (element.hasAttribute("type"))
	{
		edit->setMode(element.attribute("type"));
	}
	return edit;
}

QWidget * creatLoginButton(const QDomElement & element)
{
	LoginButton * button = new LoginButton;
	if (element.hasAttribute("text"))
	{
		button->setText(element.attribute("text"));
	}
	return button;
}

QWidget * creatTextLabel(const QDomElement & element)
{
	TextLabel * label = new TextLabel;
	label->setText(element.attribute("text"));
	label->setColor(element.attribute("color"));
	return label;
}

QWidget * creatTitleButton(const QDomElement & element)
{
	TitleButton * button = new TitleButton;
	if (element.hasAttribute("text"))
	{
		button->setText(element.attribute("text"));
	}
	return button;
}

QWidget * creatControlButton(const QDomElement & element)
{
	ControlButton * button = new ControlButton;
	if (element.hasAttribute("text"))
	{
		button->setText(element.attribute("text"));
	}
	if (element.hasAttribute("icon"))
	{
		button->setIcon(QIcon(element.attribute("icon")));
	}
	return button;
}

QWidget * creatFaultDisplay(const QDomElement & element)
{
	FaultDisplay * display = new FaultDisplay;
	return display;
}

QWidget * creatComputerTable(const QDomElement & element)
{
	ComputerTable * table = new ComputerTable;
	table->loadConfig(element.attribute("path"));
	return table;
}

QWidget * creatProjectorControl(const QDomElement & element)
{
	ProjectorControl * group = new ProjectorControl;
	return group;
}

QWidget * creatSeparatorLine(const QDomElement & element)
{
	SeparatorLine * label = new SeparatorLine;
	if (element.hasAttribute("width"))
	{
		label->setFixedWidth(element.attribute("width").toInt());
	}
	if (element.hasAttribute("height"))
	{
		label->setFixedHeight(element.attribute("height").toInt());
	}
	label->setColor(element.attribute("color"));
	return label;
}
