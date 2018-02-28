#include "navigation.h"
#include "xmlRead.h"
#include "componentFactory.h"

#include <QLayout>

struct ios::Navigation::NavigationData
{
	QGridLayout * layout;
};

ios::Navigation::Navigation(QWidget * _parent) :
	BaseWidget(_parent),
	data(new NavigationData)
{
	//setMaximumWidth(350);
	//setMinimumWidth(350);
	data->layout = new QGridLayout;
	data->layout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	setLayout(data->layout);
}

ios::Navigation::~Navigation()
{
	delete data;
}

void ios::Navigation::loadConfig(const QString & _path) const
{
	XmlRead xmlRead;
	if (!xmlRead.loadFile(_path))
	{
		return;
	}

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();
	
	BaseWidget * widget = nullptr;

	while (!element.isNull())
	{
		widget = ComponentFactory::create(element.attribute("type", "NavigationButton"));

		if (element.hasAttribute("name"))
		{
			widget->setObjectName(element.attribute("name"));
		}
		if (element.hasAttribute("text"))
		{
			widget->setText(element.attribute("text"));
		}
		if (element.hasAttribute("width"))
		{
			widget->setFixedWidth(element.attribute("width").toInt());
		}
		if (element.hasAttribute("height"))
		{
			widget->setFixedHeight(element.attribute("height").toInt());
		}

		int row = element.attribute("row").toInt();
		int column = element.attribute("column").toInt();
		int rowSpan = element.attribute("rowSpan").toInt();
		int columnSpan = element.attribute("columnSpan").toInt();
		data->layout->addWidget(widget, row, column, rowSpan, columnSpan);

		element = element.nextSiblingElement();
	}
}
