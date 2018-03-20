#include "quickOperation.h"
#include "xmlRead.h"
#include "componentFactory.h"

#include <QLayout>

struct ios::QuickOperation::QuickOperationData
{
	QGridLayout * layout;
};

ios::QuickOperation::QuickOperation(QWidget * _parent):
	BaseWidget(_parent),
	data(new QuickOperationData)
{
	//setMaximumWidth(800);
	//setMinimumWidth(800);
	setMaximumHeight(200);
	setMinimumHeight(200);

	data->layout = new QGridLayout;
	data->layout->setSpacing(10);
	data->layout->setMargin(0);
	data->layout->setAlignment(Qt::AlignCenter);

	setLayout(data->layout);
}

ios::QuickOperation::~QuickOperation()
{
	delete data;
}

void ios::QuickOperation::loadConfig(const QString & _path)
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
		widget = ComponentFactory::create(element.attribute("type", "ClickButton"));

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
