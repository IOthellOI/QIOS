#include "loginForm.h"

struct LoginForm::LoginFormPrivate
{

};

LoginForm::LoginForm(QWidget * _parent) :
	QWidget(_parent),
	data(new LoginFormPrivate)
{
	
}

LoginForm::~LoginForm()
{

}
