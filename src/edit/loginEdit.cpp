#include "loginEdit.h"

#include <QLabel>
#include <QLineEdit>
#include <QLayout>

struct LoginEdit::UserEditData
{
	QLabel * label;
	QLineEdit * edit;
};

LoginEdit::LoginEdit(QWidget * _parent) :
	QWidget(_parent),
	data(new UserEditData)
{
	QHBoxLayout * layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignCenter);

	data->label = new QLabel;
	data->label->setObjectName("LoginEdit");
	layout->addWidget(data->label);

	data->edit = new QLineEdit;
	data->edit->setObjectName("LoginEdit");
	layout->addWidget(data->edit);	 
}

LoginEdit::~LoginEdit()
{
	delete data;
}

void LoginEdit::setIcon(const QPixmap & _picture)
{
	QPixmap temp = _picture.scaled(data->label->size(), Qt::KeepAspectRatio);
	data->label->setScaledContents(true);
	data->label->setPixmap(temp);
}

void LoginEdit::setText(const QString & _text)
{
	data->edit->setPlaceholderText(_text);
}

QString LoginEdit::text()
{
	return data->edit->text();
}

void LoginEdit::setMode(const QString & _mode)
{
	if (_mode == "password")
	{
		data->edit->setEchoMode(QLineEdit::Password);
	}
}
