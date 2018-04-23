#pragma once
#ifndef DATABASETABLEMODEL_H
#define DATABASETABLEMODEL_H

#include <QObject>
#include <QSqlTableModel>

class DatabaseTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit DatabaseTableModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());

public:
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // DATABASETABLEMODEL_H
