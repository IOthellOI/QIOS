#pragma once
#ifndef USEREDIT_H
#define USEREDIT_H

#include <QWidget>

class UserEidt : public QWidget
{
	Q_OBJECT
public:
	explicit UserEidt(QWidget * _parent = nullptr);
	virtual ~UserEidt();

private:
	struct UserEditData;
	UserEditData * data;
};

#endif // !USEREDIT_H
