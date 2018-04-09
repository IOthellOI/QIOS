#include "statusBar.h"
#include "xmlRead.h"
#include "widgetFactory.h"

#include <QLayout>
#include <cassert>

struct StatusBar::StatusBarPrivate
{
	QHBoxLayout * layout;
};

StatusBar::StatusBar(QFrame * _parent) :
	QFrame(_parent),
	data(new StatusBarPrivate)
{
	setObjectName("StatusBar");
	setMinimumHeight(100);
	setMaximumHeight(100);

	data->layout = new QHBoxLayout(this);
	data->layout->setMargin(0);
	data->layout->setSpacing(0);
}

StatusBar::~StatusBar()
{

}

void StatusBar::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	QHBoxLayout * layout = nullptr;

	QWidget * widget = nullptr;

	while (!element.isNull())
	{
		if (element.tagName() == "layout")
		{
			layout = new QHBoxLayout;

			if (element.attribute("alignment") == "left")
			{
				layout->setAlignment(Qt::AlignLeft | Qt::AlignHCenter);
			}
			else if (element.attribute("alignment") == "right")
			{
				layout->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
			}
			else if (element.attribute("alignment") == "center")
			{
				layout->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
			}
			data->layout->addLayout(layout);

			QDomElement node = element.firstChildElement();

			while (!node.isNull())
			{
				widget = WidgetFactory::creat(node);

				layout->addWidget(widget);

				node = node.nextSiblingElement();
			}

			element = element.nextSiblingElement();
		}
		else
		{
			data->layout->addStretch();
			element = element.nextSiblingElement();
		}
	}
}