#include "navigationPage.h"

#include <QLayout>

struct ios::NavigationPage::NavigationPageData
{
	QVBoxLayout * layout;
};

ios::NavigationPage::NavigationPage(QWidget * _parent) :
	BaseWidget(_parent),
	data(new NavigationPageData)
{
	data->layout = new QVBoxLayout;
	setLayout(data->layout);
}

ios::NavigationPage::~NavigationPage()
{
	delete data;
}

void ios::NavigationPage::loadConfig(const QString & _path) const
{

}
