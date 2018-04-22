#include "userManage.h"
#include "findEdit.h"
#include "xmlRead.h"

#include <cassert>
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>

struct UserManageItem
{
    QLabel type;
    QLabel army;
    QLabel name;
    QLabel password;
};

struct UserManage::UserManagePrivate
{
    QGridLayout * layout;
    FindEdit * find;
    QPushButton * instructor;
    QPushButton * student;
    QPushButton * totle;
    QTableWidget * table;
    QPushButton * add;
    QPushButton * edit;
    QPushButton * take;
};

UserManage::UserManage(QWidget * _parent)
    : QWidget(_parent),
      data(new UserManagePrivate)
{
    setObjectName("UserManage");

    data->find = new FindEdit;

    data->instructor = new QPushButton(QString::fromLocal8Bit("ֻ����Ա"));
    data->instructor->setObjectName("UserManageTableButton");
    data->student = new QPushButton(QString::fromLocal8Bit("ֻ��ѧԱ"));
    data->student->setObjectName("UserManageTableButton");
    data->totle = new QPushButton(QString::fromLocal8Bit("�鿴ȫ��"));
    data->totle->setObjectName("UserManageTableButton");

    data->table = new QTableWidget;
    data->table->setObjectName("UserManageTable");
    data->table->horizontalHeader()->setObjectName("UserManageTable");
    data->table->verticalHeader()->setVisible(false);
    data->table->horizontalHeader()->setSectionsClickable(false);
    data->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    data->table->horizontalHeader()->setStretchLastSection(true);
    data->table->setShowGrid(false);
    data->table->setAlternatingRowColors(true);
    data->table->setSelectionMode(QAbstractItemView::NoSelection);
    data->table->setFocusPolicy(Qt::NoFocus);

    data->add = new QPushButton(QString::fromLocal8Bit("�����û�"));
    data->add->setObjectName("UserManageTableButton");
    data->edit = new QPushButton(QString::fromLocal8Bit("�༭�û�"));
    data->edit->setObjectName("UserManageTableButton");
    data->take = new QPushButton(QString::fromLocal8Bit("ɾ���û�"));
    data->take->setObjectName("UserManageTableDeleteButton");

    data->layout = new QGridLayout(this);

    data->layout->addWidget(data->find, 0, 0, 1, 1);
    data->layout->addWidget(data->instructor, 0, 4, 1, 1);
    data->layout->addWidget(data->student, 0, 5, 1, 1);
    data->layout->addWidget(data->totle, 0, 6, 1, 1);
    data->layout->addWidget(data->table, 1, 0, 1, 7);
    data->layout->addWidget(data->add, 2, 4, 1, 1);
    data->layout->addWidget(data->edit, 2, 5, 1, 1);
    data->layout->addWidget(data->take, 2, 6, 1, 1);
}

UserManage::~UserManage()
{
    delete data;
}

void UserManage::loadConfig(const QString &_path)
{
    assert(!_path.isEmpty());
    XmlRead xmlRead;
    xmlRead.loadFile(_path);
    QDomElement root = xmlRead.rootElement();
    QDomElement element = root.firstChildElement();
    QDomElement node = element.firstChildElement();

    QStringList header;

    for (int i = 0; !node.isNull(); i++)
    {
        data->table->setColumnCount(i + 1);
        header << node.attribute("item");
        data->table->setColumnWidth(i, node.attribute("width").toInt());
        node = node.nextSiblingElement();
    }

    data->table->setHorizontalHeaderLabels(header);

    element = element.nextSiblingElement();
    node = element.firstChildElement();

    data->table->verticalHeader()->setDefaultSectionSize(element.attribute("height").toInt());

}
