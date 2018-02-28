#include "mainWindow.h"
#include "navigation.h"
#include "quickOperation.h"

#include <QLayout>

struct ios::MainWindow::MainWindowData
{
	Navigation * navigation;
	QuickOperation * quickOperation;
};

ios::MainWindow::MainWindow(QWidget * _parent):
	BaseWidget(_parent),
	data(new MainWindowData)
{
	data->navigation = new Navigation;
	data->quickOperation = new QuickOperation;

	data->navigation->loadConfig("./data/config/ui/navigation.xml");
	data->quickOperation->loadConfig("./data/config/ui/quickOperation.xml");

	QHBoxLayout * topLayout = new QHBoxLayout;
	QHBoxLayout * buttomLayout = new QHBoxLayout;
	QVBoxLayout * mainLayout = new QVBoxLayout;

	topLayout->setMargin(2);
	topLayout->setSpacing(2);
	buttomLayout->setMargin(2);
	buttomLayout->setSpacing(2);

	topLayout->addWidget(data->navigation);
	buttomLayout->addWidget(data->quickOperation);

	mainLayout->addLayout(topLayout);
	mainLayout->addLayout(buttomLayout);
	setLayout(mainLayout);
}

ios::MainWindow::~MainWindow()
{
	delete data;
}
