#pragma once
#ifndef PASSWORDEDIT_H
#define PASSWORDEDIT_H

#include <QWidget>


class PasswordEdit : public QWidget
{
	Q_OBJECT
public:
	explicit PasswordEdit(QWidget * _parent = nullptr);
	virtual ~PasswordEdit();

public:
	void setIcon(const QPicture &_picture);
	void setText(const QString & _text);
	const QString & text();

private:
	struct PasswordEditData;
	PasswordEditData * data;
};

#endif // !PASSWORDEDIT_H
