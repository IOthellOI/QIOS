#include "pageBar.h"
#include "xmlRead.h"
#include "page.h"
#include "dataPool.h"

#include <QStackedWidget>
#include <QLayout>
#include <cassert>

struct PageBar::PageBarPrivate
{
	QStackedWidget * group;
};

PageBar::PageBar(QFrame * _parent) :
	QFrame(_parent),
	data(new PageBarPrivate)
{
	setObjectName("PageBar");

	data->group = new QStackedWidget;

	QHBoxLayout * layout = new QHBoxLayout(this);

	layout->addWidget(data->group);
}

PageBar::~PageBar()
{
	
}

void PageBar::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	connect(DataPool::internalDataMap()->value(root.attribute("pageData")),
		SIGNAL(signalDataUpdata(const QString &)),
		this,
		SLOT(slotPageChange(const QString &)));

	QDomElement element = root.firstChildElement();

	Page * page = nullptr;

	while (!element.isNull())
	{
		page = new Page;
		page->setName(element.attribute("name"));
		page->loadConfig(element.attribute("path"));
		data->group->addWidget(page);

		element = element.nextSiblingElement();
	}
}

void PageBar::slotPageChange(const QString & _page)
{
	for (size_t i = 0; i < data->group->count(); i++)
	{
		if (dynamic_cast<Page *>(data->group->widget(i))->name() == _page)
		{
			data->group->setCurrentIndex(i);
			break;
		}
	}
}
