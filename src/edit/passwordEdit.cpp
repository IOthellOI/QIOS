#include "passwordEdit.h"

#include <QLabel>
#include <QLineEdit>
#include <QLayout>

struct PasswordEdit::PasswordEditData
{
	QLabel * label;
	QLineEdit * edit;
};

PasswordEdit::PasswordEdit(QWidget * _parent) :
	QWidget(_parent),
	data(new PasswordEditData)
{
	QHBoxLayout * layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignCenter);

	data->label = new QLabel;
	data->label->setObjectName("PasswordEdit");
	data->label->setFixedSize(50, 50);
	layout->addWidget(data->label);

	data->edit = new QLineEdit;
	data->edit->setObjectName("PasswordEdit");
	data->edit->setFixedSize(250, 50);
	layout->addWidget(data->edit);
	 
}

PasswordEdit::~PasswordEdit()
{
	delete data;
}

void PasswordEdit::setIcon(const QPicture & _picture)
{
	data->label->setPicture(_picture);
}

void PasswordEdit::setText(const QString & _text)
{
	data->edit->setPlaceholderText(_text);
}

QString PasswordEdit::text()
{
	return data->edit->text();
}
