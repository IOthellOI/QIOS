#pragma once
#ifndef USEREDITFORM_H
#define USEREDITFORM_H

#include <QWidget>

class UserEditForm : public QWidget
{
    Q_OBJECT
public:
    explicit UserEditForm(QStringList * list = nullptr, QWidget *parent = nullptr);

signals:
    void signalUserEdit(QStringList list);

public slots:
    void slotOkbuttonClicked();

private:
    struct UserEditFormPrivate;
    UserEditFormPrivate * data;
};

#endif // USEREDITFORM_H
