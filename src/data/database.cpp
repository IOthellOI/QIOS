#include "database.h"
#include "iniRead.h"
#include "databaseTableModel.h"

#include <QMessageBox>

struct Database::DatabasePrivate
{
	QSqlDatabase * db;
    DatabaseTableModel * user;
};

Database::DatabasePrivate * Database::data = new Database::DatabasePrivate;

Database::Database(QObject * _parent):
    QObject(_parent)
{
    data->db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));

	QStringList message = IniRead::dabaBaseMessage();
    //data->db->setHostName(message.at(0));
    //data->db->setPort(message.at(1).toInt());
    data->db->setDatabaseName("data.db");
    //data->db->setUserName(message.at(3));
    //data->db->setPassword(message.at(4));

	if (!data->db->open()) {
		QMessageBox::critical(0, u8"数据库错误",
			u8"无法连接数据库.", QMessageBox::Cancel);
	}

    data->user = new DatabaseTableModel(this);
    data->user->setTable("user");
    data->user->select();
}

Database::~Database()
{

}

QSqlTableModel *Database::userDatabase()
{
    return data->user;
}

void Database::close()
{
    data->db->close();
}
