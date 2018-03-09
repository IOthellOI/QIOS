#include "page.h"
#include "xmlRead.h"
#include "componentFactory.h"

#include <QLayout>
#include <QGroupBox>
#include <QVariant>

struct ios::Page::PageData
{
	QGridLayout * layout;
	QGroupBox * box;
};

ios::Page::Page(QWidget * _parent) :
	BaseWidget(_parent),
	data(new PageData)
{
	data->layout = new QGridLayout;
	data->box = new QGroupBox;
	data->box->setLayout(data->layout);

	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(data->box);

	setLayout(layout);
}

ios::Page::~Page()
{
	delete data;
}

void ios::Page::loadConfig(const QString & _path) const
{
	XmlRead xmlRead;
	if (!xmlRead.loadFile(_path))
	{
		return;
	}

	QDomElement root = xmlRead.rootElement();
	QString title = root.attribute("title", "Î´ÃüÃû");
	data->box->setTitle(title);
	
	QDomElement component = root.firstChildElement();
	QGroupBox * box = nullptr;
	QGridLayout * layout = nullptr;
	BaseWidget * widget = nullptr;
	while (!component.isNull())
	{
		box = new QGroupBox;
		box->setTitle(component.attribute("title"));

		layout = new QGridLayout;
		box->setLayout(layout);

		data->layout->addWidget(box, 
			component.attribute("row").toInt(), 
			component.attribute("column").toInt(), 
			component.attribute("rowSpan").toInt(),
			component.attribute("columnSpan").toInt());

		QDomElement element = component.firstChildElement();
		while (!element.isNull())
		{
			widget = ComponentFactory::create(element.attribute("type"));

			if (widget == nullptr)
			{
				element = element.nextSiblingElement();
				continue;
			}

			if (element.hasAttribute("width"))
			{
				widget->setFixedWidth(element.attribute("width").toInt());
			}	
			if (element.hasAttribute("height"))
			{
				widget->setFixedHeight(element.attribute("height").toInt());
			}
			if (element.hasAttribute("text"))
			{
				widget->setText(element.attribute("text"));
			}
			if (element.hasAttribute("group"))
			{
				widget->setGroup(element.attribute("group").toInt());
			}
			if (element.hasAttribute("unit"))
			{
				widget->setUnit(element.attribute("unit"));
			}
			if (element.hasAttribute("value"))
			{
				widget->setValue(element.attribute("value").toDouble());
			}
			if (element.hasAttribute("checked"))
			{
				widget->setChecked((QVariant(element.attribute("checked"))).toBool());
			}

			layout->addWidget(widget,
				element.attribute("row").toInt(),
				element.attribute("column").toInt(),
				element.attribute("rowSpan").toInt(),
				element.attribute("columnSpan").toInt());
			element = element.nextSiblingElement();
		}

		component = component.nextSiblingElement();
	}
}


