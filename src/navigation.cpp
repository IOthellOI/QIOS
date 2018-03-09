#include "navigation.h"
#include "xmlRead.h"
#include "componentFactory.h"
#include "navigationButton.h"

#include <QLayout>
#include <QVariant>

struct ios::Navigation::NavigationData
{
	QGridLayout * layout;
};

ios::Navigation::Navigation(QWidget * _parent) :
	BaseWidget(_parent),
	data(new NavigationData)
{
	setMaximumWidth(200);
	setMinimumWidth(200);
	data->layout = new QGridLayout;
	data->layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	data->layout->setSpacing(0);
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
	
	NavigationButton * navigationButton = nullptr;

	while (!element.isNull())
	{
		navigationButton = new NavigationButton;

		if (element.hasAttribute("name"))
		{
			navigationButton->setObjectName(element.attribute("name"));
		}
		if (element.hasAttribute("text"))
		{
			navigationButton->setText(element.attribute("text"));
		}
		if (element.hasAttribute("width"))
		{
			navigationButton->setFixedWidth(element.attribute("width").toInt());
		}
		if (element.hasAttribute("height"))
		{
			navigationButton->setFixedHeight(element.attribute("height").toInt());
		}
		if (element.hasAttribute("checked"))
		{
			QVariant value = element.attribute("checked");
			navigationButton->setChecked(value.toBool());
		}

		navigationButton->setBindPage(element.attribute("bindPage"));

		data->layout->addWidget(navigationButton,
			element.attribute("row").toInt(),
			element.attribute("column").toInt(),
			element.attribute("rowSpan").toInt(),
			element.attribute("columnSpan").toInt());

		connect(navigationButton, 
			SIGNAL(signalClicked(const QString &)),
			this, 
			SLOT(slotPageChanged(const QString &)));

		element = element.nextSiblingElement();
	}
}

void ios::Navigation::slotPageChanged(const QString & _page)
{
	emit signalPageChanged(_page);
}
