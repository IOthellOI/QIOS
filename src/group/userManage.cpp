#include "userManage.h"
#include "findEdit.h"
#include "xmlRead.h"
#include "database.h"
#include "userEditForm.h"

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
    QTableView * table;
    QPushButton * add;
    QPushButton * edit;
    QPushButton * take;
    QSqlTableModel * model;
};

UserManage::UserManage(QWidget * _parent)
    : QWidget(_parent),
      data(new UserManagePrivate)
{
    setObjectName("UserManage");

    data->find = new FindEdit;

    data->instructor = new QPushButton(QString::fromLocal8Bit("只看教员"));
    data->instructor->setObjectName("UserManageTableButton");
    data->student = new QPushButton(QString::fromLocal8Bit("只看学员"));
    data->student->setObjectName("UserManageTableButton");
    data->totle = new QPushButton(QString::fromLocal8Bit("查看全部"));
    data->totle->setObjectName("UserManageTableButton");

    data->table = new QTableView;
    data->table->setObjectName("UserManageTable");
    data->table->horizontalHeader()->setObjectName("UserManageTable");
    data->table->verticalHeader()->setVisible(false);
    data->table->horizontalHeader()->setSectionsClickable(false);
    data->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    data->table->horizontalHeader()->setStretchLastSection(true);
    data->table->setShowGrid(false);
    data->table->setAlternatingRowColors(true);
    data->table->setSelectionMode(QAbstractItemView::SingleSelection);
    data->table->setSelectionBehavior(QAbstractItemView::SelectRows);
    //data->table->setFocusPolicy(Qt::NoFocus);

    data->add = new QPushButton(QString::fromLocal8Bit("增加用户"));
    data->add->setObjectName("UserManageTableButton");
    data->edit = new QPushButton(QString::fromLocal8Bit("编辑用户"));
    data->edit->setObjectName("UserManageTableButton");
    data->take = new QPushButton(QString::fromLocal8Bit("删除用户"));
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

    connect(data->instructor, SIGNAL(clicked()), this, SLOT(slotInstructorSelected()));
    connect(data->student, SIGNAL(clicked()), this, SLOT(slotStudentSelected()));
    connect(data->totle, SIGNAL(clicked()), this, SLOT(slotTotalSelected()));
    connect(data->add, SIGNAL(clicked()), this, SLOT(slotAddSelected()));
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

    data->model = Database::userDatabase();

    data->table->setModel(data->model);

    for (int i = 0; !node.isNull(); i++)
    {
        data->model->setHeaderData(i, Qt::Horizontal, node.attribute("item"));
        data->table->setColumnWidth(i, node.attribute("width").toInt());
        node = node.nextSiblingElement();
    }

    element = element.nextSiblingElement();
    node = element.firstChildElement();

    data->table->verticalHeader()->setDefaultSectionSize(element.attribute("height").toInt());
}

void UserManage::slotInstructorSelected()
{
    data->model->setFilter(QString("type = '%1'").arg(QString::fromLocal8Bit("教员")));
    data->model->select();
}

void UserManage::slotStudentSelected()
{
    data->model->setFilter(QString("type = '%1'").arg(QString::fromLocal8Bit("学员")));
    data->model->select();
}

void UserManage::slotTotalSelected()
{
    data->model->setFilter("");
    data->model->select();
}

void UserManage::slotAddSelected()
{
    UserEditForm * form = new UserEditForm;
    form->setWindowTitle(QString::fromLocal8Bit("增加用户"));
    form->show();
    connect(form, SIGNAL(signalUserEdit(QStringList)), this, SLOT(slotAddUser(QStringList)));
}

void UserManage::slotAddUser(QStringList _list)
{

}
