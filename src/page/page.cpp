#include "page.h"
#include "xmlRead.h"
#include "componentBox.h"
#include "widgetFactory.h"

#include <QLayout>
#include <cassert>

struct Page::PagePrivate
{
	QGridLayout * layout;
	QString * name;
};

Page::Page(QWidget * _parent):
	QWidget(_parent),
	data(new PagePrivate)
{
	setObjectName("Page");
	data->layout = new QGridLayout(this);
	data->layout->setMargin(0);
	data->layout->setSpacing(9);

	data->name = new QString;
}

Page::~Page()
{
	delete data;
}

void Page::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	ComponentBox * box = nullptr;

	QWidget * widget = nullptr;

	while (!element.isNull())
	{
		box = new ComponentBox;

		box->setTitle(QString("    ") + element.attribute("title"));
		if (element.hasAttribute("min-width"))
		{
			box->setMinimumWidth(element.attribute("min-width").toInt());
		}
		if (element.hasAttribute("min-height"))
		{
			box->setMinimumHeight(element.attribute("min-height").toInt());
		}
		if (element.hasAttribute("max-width"))
		{
			box->setMaximumWidth(element.attribute("max-width").toInt());
		}
		if (element.hasAttribute("max-height"))
		{
			box->setMaximumHeight(element.attribute("max-height").toInt());
		}
		if (element.hasAttribute("spacing"))
		{
			box->setSpacing(element.attribute("spacing").toInt());
		}
		if (element.hasAttribute("alignment"))
		{
			box->setAlignmnet(element.attribute("alignment"));
		}

		data->layout->addWidget(box,
			element.attribute("row").toInt(), element.attribute("column").toInt(),
			element.attribute("rowSpan").toInt(), element.attribute("columnSpan").toInt());

		QDomElement node = element.firstChildElement();

		while (!node.isNull())
		{
			widget = WidgetFactory::creat(node);

			box->addWidget(widget,
				node.attribute("row").toInt(), node.attribute("column").toInt(), 
				node.attribute("rowSpan").toInt(), node.attribute("columnSpan").toInt());

			node = node.nextSiblingElement();
		}

		element = element.nextSiblingElement();
	}
}

void Page::setName(const QString & _name)
{
	*data->name = _name;
}

QString Page::name()
{
	return *data->name;
}
