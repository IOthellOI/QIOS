#include "widgetFactory.h"
#include "dataPool.h"
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
#include "soundTable.h"
#include "inputButton.h"
#include "dataLabel.h"
#include "missionButton.h"
#include "dataSlider.h"
#include "toggleButton.h"
#include "textEdit.h"
#include "spinEdit.h"
#include "weaponButton.h"

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
static QWidget * creatSoundTable(const QDomElement & element);
static QWidget * creatInputButton(const QDomElement & element);
static QWidget * creatDataLabel(const QDomElement & element);
static QWidget * creatMissionButton(const QDomElement & element);
static QWidget * creatDataSlider(const QDomElement & element);
static QWidget * creatToggleButton(const QDomElement & element);
static QWidget * creatTextEdit(const QDomElement & element);
static QWidget * creatSpinEdit(const QDomElement & element);
static QWidget * creatWeaponButton(const QDomElement & element);

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
	else if (element.nodeName().toUpper() == "SOUNDTABLE")
	{
		return creatSoundTable(element);
	}
	else if (element.nodeName().toUpper() == "INPUTBUTTON")
	{
		return creatInputButton(element);
	}
	else if (element.nodeName().toUpper() == "DATALABEL")
	{
		return creatDataLabel(element);
	}
	else if (element.nodeName().toUpper() == "MISSIONBUTTON")
	{
		return creatMissionButton(element);
	}
	else if (element.nodeName().toUpper() == "DATASLIDER")
	{
		return creatDataSlider(element);
	}
	else if (element.nodeName().toUpper() == "TOGGLEBUTTON")
	{
		return creatToggleButton(element);
	}
	else if (element.nodeName().toUpper() == "TEXTEDIT")
	{
		return creatTextEdit(element);
	}
	else if (element.nodeName().toUpper() == "SPINEDIT")
	{
		return creatSpinEdit(element);
	}
	else if (element.nodeName().toUpper() == "WEAPONBUTTON")
	{
		return creatWeaponButton(element);
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
	if (element.hasAttribute("alignment"))
	{
		if (element.attribute("alignment") == "left")
		{
			label->setAlignment(Qt::AlignLeft);
		}		
		else if (element.attribute("alignment") == "center")
		{
			label->setAlignment(Qt::AlignCenter);
		}		
		else if (element.attribute("alignment") == "right")
		{
			label->setAlignment(Qt::AlignRight);
		}
	}
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

QWidget * creatSoundTable(const QDomElement & element)
{
	SoundTable * table = new SoundTable;
	table->loadConfig(element.attribute("path"));
	return table;
}

QWidget * creatInputButton(const QDomElement & element)
{
	InputButton * button = new InputButton;
	button->setName(element.attribute("name"));
	button->setData(DataPool::externalDataMap()->value(element.attribute("data")));
	return button;
}

QWidget * creatDataLabel(const QDomElement & element)
{
	DataLabel * label = new DataLabel;
	label->setName(element.attribute("name"));
	label->setData(DataPool::externalDataMap()->value(element.attribute("data")));
	return label;
}

QWidget * creatMissionButton(const QDomElement & element)
{
	MissionButton * button = new MissionButton;
	button->setText(element.attribute("name"));
	return button;
}

QWidget * creatDataSlider(const QDomElement & element)
{
	DataSlider * slider = new DataSlider;
	slider->setName(element.attribute("name"));
	slider->setData(DataPool::externalDataMap()->value(element.attribute("data")));
	return slider;
}

QWidget * creatToggleButton(const QDomElement & element)
{
	ToggleButton * button = new ToggleButton;
	button->setName(element.attribute("name"));
	return button;
}

QWidget * creatTextEdit(const QDomElement & element)
{
	TextEdit * edit = new TextEdit;
	edit->setPlaceholderText(element.attribute("text"));
	return edit;
}

QWidget * creatSpinEdit(const QDomElement & element)
{
	SpinEdit * edit = new SpinEdit;
	//edit->setRange(element.attribute("minValue").toInt(), element.attribute("maxValue").toInt());
	return edit;
}

QWidget * creatWeaponButton(const QDomElement & element)
{
	WeaponButton * button = new WeaponButton;
	button->setName(element.attribute("name"));
	button->setNumber(element.attribute("number").toInt());	
	return button;
}
