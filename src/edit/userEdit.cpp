#include "userEdit.h"

#include <QLabel>
#include <QLineEdit>
#include <QLayout>

struct UserEdit::UserEditData
{
	QLabel * label;
	QLineEdit * edit;
};

UserEdit::UserEdit(QWidget * _parent) :
	QWidget(_parent),
	data(new UserEditData)
{
	QHBoxLayout * layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignCenter);

	data->label = new QLabel;
	data->label->setObjectName("UserEdit");
	data->label->setFixedSize(50, 50);
	layout->addWidget(data->label);

	data->edit = new QLineEdit;
	data->edit->setObjectName("UserEdit");
	data->edit->setFixedSize(250, 50);
	layout->addWidget(data->edit);
	 
}

UserEdit::~UserEdit()
{
	delete data;
}

void UserEdit::setIcon(const QPicture & _picture)
{
	data->label->setPicture(_picture);
}

void UserEdit::setText(const QString & _text)
{
	data->edit->setPlaceholderText(_text);
}

const QString & UserEdit::text()
{
	return data->edit->text();
}
