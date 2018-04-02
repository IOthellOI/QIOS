#include "loginForm.h"
#include "xmlRead.h"
#include "widgetFactory.h"

#include <QLayout>
#include <QFrame>
#include <cassert>

struct LoginForm::LoginFormPrivate
{
	QVBoxLayout * layout;
};

LoginForm::LoginForm(QWidget * _parent) :
	QWidget(_parent),
	data(new LoginFormPrivate)
{	
	QFrame * frame = new QFrame(this);
	frame->setObjectName("LoginForm");
	
	setWindowFlags(Qt::FramelessWindowHint);

	data->layout = new QVBoxLayout;

	frame->setLayout(data->layout);	
}

LoginForm::~LoginForm()
{
	delete data;
}

void LoginForm::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	QDomElement element = root.firstChildElement();

	QWidget * widget = nullptr;

	while (!element.isNull())
	{
		widget = WidgetFactory::creat(element);

		data->layout->addWidget(widget);

		element = element.nextSiblingElement();
	}
}
