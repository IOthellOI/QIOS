#include "loginForm.h"
#include "xmlRead.h"
#include "widgetFactory.h"
#include "dataPool.h"
#include "windowForm.h"
#include "iniRead.h"
#include "database.h"

#include <QLayout>
#include <QFrame>
#include <cassert>
#include <QLabel>

struct LoginForm::LoginFormPrivate
{
	QVBoxLayout * layout;
};

LoginForm::LoginForm(QWidget * _parent) :
	QWidget(_parent),
	data(new LoginFormPrivate)
{
	setObjectName("LoginForm");
	setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);

	QFrame * frame = new QFrame(this);
	frame->setObjectName("LoginForm");

	data->layout = new QVBoxLayout;
	data->layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	data->layout->setMargin(0);

	QHBoxLayout * mainLayout = new QHBoxLayout;

	mainLayout->addStretch();
	mainLayout->addLayout(data->layout);
	mainLayout->addStretch();


	frame->setLayout(mainLayout);
	
	loadConfig("./data/window/loginForm.xml");
}

LoginForm::~LoginForm()
{

}

void LoginForm::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());

	XmlRead xmlRead;

	xmlRead.loadFile(_path);

	QDomElement root = xmlRead.rootElement();

	setWindowTitle(root.attribute("title"));

	QDomElement element = root.firstChildElement();

	QWidget * widget = nullptr;

	while (!element.isNull())
	{
		widget = WidgetFactory::creat(element);

		data->layout->addWidget(widget);

		element = element.nextSiblingElement();

		if (widget->objectName() == "LoginButton")
		{
			connect(widget, SIGNAL(clicked()), this, SLOT(slotLogin()));
		}
	}
}

void LoginForm::slotLogin()
{
	if (true)
	{
		DataPool d;

		IniRead i;

		Database b;

		WindowForm * w = new WindowForm;
		w->show();

		close();
	}
}
