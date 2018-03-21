#include "windowForm.h"
#include "titleBar.h"
#include "navigationBar.h"
#include "pageBar.h"
#include "statusBar.h"

#include <QLayout>

WindowForm::WindowForm(QWidget * _parent) :
	QWidget(_parent)
{
	setFixedHeight(1080);
	setFixedWidth(1920); 
	setWindowFlags(Qt::FramelessWindowHint);

	TitleBar * titleBar = new TitleBar;
	NavigationBar * navigationBar = new NavigationBar;
	PageBar * pageBar = new PageBar;
	StatusBar * statusBar = new StatusBar;

	QGridLayout * layout = new QGridLayout;
	layout->setMargin(0);
	layout->setSpacing(0);
	layout->addWidget(titleBar, 0, 0, 1, 2);
	layout->addWidget(navigationBar, 1, 0, 1, 1);
	layout->addWidget(pageBar, 1, 1, 1, 1);
	layout->addWidget(statusBar, 2, 0, 1, 2);

	setLayout(layout);
}

WindowForm::~WindowForm()
{
}
