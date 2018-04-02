#include "loginEdit.h"

#include <QLabel>
#include <QLineEdit>
#include <QLayout>

struct LoginEdit::LoginEditData
{
	QLabel * label;
	QLineEdit * edit;
};

LoginEdit::LoginEdit(QWidget * _parent) :
	QWidget(_parent),
	data(new LoginEditData)
{
	QHBoxLayout * layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignCenter);

	data->label = new QLabel;
	data->label->setObjectName("LoginEdit");
	data->label->setFixedSize(50, 50);
	layout->addWidget(data->label);

	data->edit = new QLineEdit;
	data->edit->setObjectName("LoginEdit");
	data->edit->setFixedSize(250, 50);
	layout->addWidget(data->edit);
	 
}

LoginEdit::~LoginEdit()
{
	delete data;
}

void LoginEdit::setIcon(const QPicture & _picture)
{
	data->label->setPicture(_picture);
}

void LoginEdit::setText(const QString & _text)
{
	data->edit->setPlaceholderText(_text);
}

QString LoginEdit::text()
{
	return data->edit->text();
}
