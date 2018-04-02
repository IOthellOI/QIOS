#pragma once
#ifndef LOGINEDIT_H
#define LOGINEDIT_H

#include <QWidget>


class LoginEdit : public QWidget
{
	Q_OBJECT
public:
	explicit LoginEdit(QWidget * _parent = nullptr);
	virtual ~LoginEdit();

public:
	void setIcon(const QPicture &_picture);
	void setText(const QString & _text);
	QString text();

private:
	struct LoginEditData;
	LoginEditData * data;
};

#endif // !LOGINEDIT_H
