#include "database.h"
#include "iniRead.h"

//#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>

struct Database::DatabasePrivate
{
	QSqlDatabase * db;
};

Database::Database(QObject * _parent):
	QObject(_parent),
	data(new DatabasePrivate)
{
	data->db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL"));

	QStringList message = IniRead::dabaBaseMessage();
	data->db->setHostName(message.at(0));
	data->db->setPort(message.at(1).toInt());
	data->db->setDatabaseName(message.at(2));
	data->db->setUserName(message.at(3));
	data->db->setPassword(message.at(4));

	if (!data->db->open()) {
		QMessageBox::critical(0, u8"数据库错误",
			u8"无法连接数据库.", QMessageBox::Cancel);
	}
}

Database::~Database()
{

}
