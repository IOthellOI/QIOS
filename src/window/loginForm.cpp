#include "loginForm.h"

#include <QLayout>
#include <QFrame>

struct LoginForm::LoginFormPrivate
{
	QGridLayout * layout;
};

LoginForm::LoginForm(QWidget * _parent) :
	QWidget(_parent),
	data(new LoginFormPrivate)
{
	QFrame * frame = new QFrame(this);
	data->layout = new QGridLayout;

	frame->setLayout(data->layout);
	
	
}

LoginForm::~LoginForm()
{

}
