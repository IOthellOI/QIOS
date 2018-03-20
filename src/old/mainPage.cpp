#include "mainPage.h"
#include "xmlRead.h"
#include "page.h"

#include <QStackedWidget>
#include <QLayout>

struct ios::MainPage::MainPageData
{
	QStackedWidget * page;
};

ios::MainPage::MainPage(QWidget * _parent):
	BaseWidget(_parent),
	data(new MainPageData)
{
	data->page = new QStackedWidget;
	QHBoxLayout * layout = new QHBoxLayout;
	layout->addWidget(data->page);
	setLayout(layout);
}

ios::MainPage::~MainPage()
{
	delete data;
}

void ios::MainPage::loadConfig(const QString & _path) const
{
	XmlRead xmlRead;
	if (!xmlRead.loadFile(_path))
	{
		return;
	}
	QDomElement root = xmlRead.rootElement();
	QDomElement element = root.firstChildElement();

	Page * page = nullptr;

	while (!element.isNull())
	{
		page = new Page;
		page->loadConfig(element.attribute("path"));

		page->setName(element.attribute("name"));

		data->page->addWidget(page);
		element = element.nextSiblingElement();
	}
}

void ios::MainPage::slotPageChanged(const QString & _page)
{
	for (size_t i = 0; i < data->page->count(); i++)
	{
		if (dynamic_cast<Page *>(data->page->widget(i))->name() == _page)
		{
			data->page->setCurrentIndex(i);
			break;
		}
	}
}