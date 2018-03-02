#include "mainWindow.h"
#include "navigation.h"
#include "quickOperation.h"
#include "statusMonitor.h"
#include "mainPage.h"

#include <QLayout>

struct ios::MainWindow::MainWindowData
{
	Navigation * navigation;
	QuickOperation * quickOperation;
	StatusMonitor * statusMonitor;
	MainPage * mainPage;
};

ios::MainWindow::MainWindow(QWidget * _parent):
	BaseWidget(_parent),
	data(new MainWindowData)
{
	data->navigation = new Navigation;
	data->quickOperation = new QuickOperation;
	data->statusMonitor = new StatusMonitor;
	data->mainPage = new MainPage;

	data->navigation->loadConfig("./data/config/ui/navigation.xml");
	data->quickOperation->loadConfig("./data/config/ui/quickOperation.xml");
	data->statusMonitor->loadConfig("./data/config/ui/statusMonitor.xml");
	data->mainPage->loadConfig("./data/config/ui/mainPage.xml");

	QHBoxLayout * topLayout = new QHBoxLayout;
	QHBoxLayout * buttomLayout = new QHBoxLayout;
	QVBoxLayout * mainLayout = new QVBoxLayout;

	topLayout->setMargin(2);
	topLayout->setSpacing(2);
	buttomLayout->setMargin(2);
	buttomLayout->setSpacing(2);

	topLayout->addWidget(data->navigation);
	topLayout->addWidget(data->mainPage);
	buttomLayout->addWidget(data->quickOperation);
	buttomLayout->addWidget(data->statusMonitor);

	mainLayout->addLayout(topLayout);
	mainLayout->addLayout(buttomLayout);
	setLayout(mainLayout);

	setWindowFlags(Qt::FramelessWindowHint);
	setWindowState(Qt::WindowMaximized);

	connect(data->navigation,
		SIGNAL(signalPageChanged(const QString &)),
		data->mainPage,
		SLOT(slotPageChanged(const QString &)));
}

ios::MainWindow::~MainWindow()
{
	delete data;
}
