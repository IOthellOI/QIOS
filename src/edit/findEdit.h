#pragma once
#ifndef FINDEDIT_H
#define FINDEDIT_H

#include <QLineEdit>

class FindEdit : public QLineEdit
{
    Q_OBJECT
public:
    FindEdit(QWidget * _parent = nullptr);
    ~FindEdit();

private slots:
    void slotClicked();

signals:
    void signalClicked();
};

#endif // FINDEDIT_H
