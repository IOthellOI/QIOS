#include "mainForm.h"
#include "titleBar.h"
#include "navigationBar.h"
#include "paginationBar.h"
#include "pageBar.h"
#include "statusBar.h"
#include "iniRead.h"

#include <QLayout>

MainForm::MainForm(QWidget * _parent) :
	QWidget(_parent)
{
	setObjectName("MainForm");

	setWindowFlags(Qt::FramelessWindowHint);

	TitleBar * titleBar = new TitleBar;
	titleBar->loadConfig("./data/window/titleBar.xml");
	NavigationBar * navigationBar = new NavigationBar;
	navigationBar->loadConfig("./data/window/navigationBar.xml");
	PaginationBar * paginationBar = new PaginationBar;
	paginationBar->loadConfig("./data/window/navigationBar.xml");
	PageBar * pageBar = new PageBar;
	StatusBar * statusBar = new StatusBar;

	QGridLayout * layout = new QGridLayout;
	layout->setMargin(0);
	layout->setSpacing(0);
	layout->addWidget(titleBar, 0, 0, 1, 3);
	layout->addWidget(navigationBar, 1, 0, 1, 1);
	layout->addWidget(paginationBar, 1, 1, 1, 1);
	layout->addWidget(pageBar, 1, 2, 1, 1);
	layout->addWidget(statusBar, 2, 0, 1, 3);

	setMinimumSize(IniRead::mainFormSize());
	setMaximumSize(IniRead::mainFormSize());

	setLayout(layout);
}

MainForm::~MainForm()
{
}
