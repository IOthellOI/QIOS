#pragma once
#ifndef USEREDIT_H
#define USEREDIT_H

#include <QWidget>


class UserEdit : public QWidget
{
	Q_OBJECT
public:
	explicit UserEdit(QWidget * _parent = nullptr);
	virtual ~UserEdit();

public:
	void setIcon(const QPicture &_picture);
	void setText(const QString & _text);
	const QString & text();

private:
	struct UserEditData;
	UserEditData * data;
};

#endif // !USEREDIT_H
