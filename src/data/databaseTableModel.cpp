#include "databaseTableModel.h"

DatabaseTableModel::DatabaseTableModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{

}

QVariant DatabaseTableModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);
    if(role ==  Qt::TextAlignmentRole)
    {
        value   =   (Qt::AlignCenter);
        return value;
    }
    return value;
}
