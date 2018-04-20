#include "windowForm.h"
#include "titleBar.h"
#include "navigationBar.h"
#include "paginationBar.h"
#include "pageBar.h"
#include "statusBar.h"
#include "iniRead.h"
#include "dataPool.h"
#include "database.h"

#include <QLayout>

struct WindowForm::WindowFormPrivate
{
    DataPool * pool;
    IniRead * ini;
    Database * base;
};

WindowForm::WindowForm(QWidget * _parent) :
    QWidget(_parent),
    data(new WindowFormPrivate)
{
    setObjectName("WindowForm");
    setWindowFlags(Qt::FramelessWindowHint);

    data->pool = new DataPool;
    data->pool->loadConfig("./data/data/dataPool.xml");
    data->ini = new IniRead;
    data->ini->loadIni("./data/config.ini");
    data->base = new Database;

	TitleBar * titleBar = new TitleBar;
	titleBar->loadConfig("./data/window/titleBar.xml");
	NavigationBar * navigationBar = new NavigationBar;
	navigationBar->loadConfig("./data/window/navigationBar.xml");
	PaginationBar * paginationBar = new PaginationBar;
	paginationBar->loadConfig("./data/window/navigationBar.xml");
	PageBar * pageBar = new PageBar;
	pageBar->loadConfig("./data/window/pageBar.xml");
	StatusBar * statusBar = new StatusBar;
	statusBar->loadConfig("./data/window/statusBar.xml");

	QGridLayout * layout = new QGridLayout;
	layout->setMargin(0);
	layout->setSpacing(0);
	layout->addWidget(titleBar, 0, 0, 1, 3);
	layout->addWidget(navigationBar, 1, 0, 1, 1);
	layout->addWidget(paginationBar, 1, 1, 1, 1);
	layout->addWidget(pageBar, 1, 2, 1, 1);
	layout->addWidget(statusBar, 2, 0, 1, 3);

	setMinimumSize(IniRead::windowFormSize());
	setMaximumSize(IniRead::windowFormSize());

    connect(DataPool::internalDataMap()->value("titleCommand"), SIGNAL(signalDataUpdate(QString)), this, SLOT(slotTitleConmmond(QString)));

	setLayout(layout);
}

WindowForm::~WindowForm()
{
}

void WindowForm::slotTitleConmmond(const QString &_text)
{
    if(_text == "close")
    {
        close();
    }
    else if(_text == "minimize")
    {
        showMinimized();
    }
}
