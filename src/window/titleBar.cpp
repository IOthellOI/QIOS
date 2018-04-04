#include "titleBar.h"
#include "widgetFactory.h"
#include "xmlRead.h"

#include <QLayout>
#include <cassert>

struct TitleBar::TitleBarPrivate
{
	QHBoxLayout * layout;
};

TitleBar::TitleBar(QFrame * _parent) :
	QFrame(_parent),
	data(new TitleBarPrivate)
{
	setObjectName("TitleBar");
	
	data->layout = new QHBoxLayout;
	data->layout->setMargin(0);
	data->layout->setSpacing(0);


	setLayout(data->layout);

}

TitleBar::~TitleBar()
{
	delete data;
}

void TitleBar::loadConfig(const QString & _path)
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
