#pragma once
#ifndef LOGINFORM_H

#include <QWidget>

class LoginForm : public QWidget
{
	Q_OBJECT
public:
	explicit LoginForm(QWidget * _parent = nullptr);
	virtual ~LoginForm();

public:
	void loadConfig(const QString & _path);

private slots:
	void slotLogin();

private:
	struct LoginFormPrivate;
	LoginFormPrivate * data;
};

#endif // !LOGINFORM_H

