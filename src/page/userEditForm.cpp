#include "userEditForm.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QLayout>

struct UserEditForm::UserEditFormPrivate
{
    QComboBox * box;
    QLineEdit * name;
    QLineEdit * army;
    QLineEdit * password;
    QGridLayout * layout;
    QPushButton * ok;
    QPushButton * cancel;
};

UserEditForm::UserEditForm(QStringList *list, QWidget *parent)
    : QWidget(parent),
      data(new UserEditFormPrivate)
{
    setObjectName("UserEditForm");
    setWindowFlags(Qt::WindowCloseButtonHint);
    setAttribute(Qt::WA_DeleteOnClose, true);

    data->layout = new QGridLayout(this);
    data->layout->setSpacing(20);
    data->layout->setMargin(20);

    QLabel * label = new QLabel(QString::fromLocal8Bit("用户类型"));
    label->setObjectName("UserEditFormLabel");
    data->layout->addWidget(label, 0, 0, 1, 1);
    label = new QLabel(QString::fromLocal8Bit("用户姓名"));
    label->setObjectName("UserEditFormLabel");
    data->layout->addWidget(label, 1, 0, 1, 1);
    label = new QLabel(QString::fromLocal8Bit("所属部队"));
    label->setObjectName("UserEditFormLabel");
    data->layout->addWidget(label, 2, 0, 1, 1);
    label = new QLabel(QString::fromLocal8Bit("用户密码"));
    label->setObjectName("UserEditFormLabel");
    data->layout->addWidget(label, 3, 0, 1, 1);

    data->box = new QComboBox;
    data->box->setObjectName("UserEditFormCombo");
    data->box->addItem(QString::fromLocal8Bit("教员"));
    data->box->addItem(QString::fromLocal8Bit("学员"));
    data->layout->addWidget(data->box, 0, 1, 1, 2);

    data->name = new QLineEdit;
    data->name->setObjectName("UserEditFormEdit");
    data->name->setPlaceholderText(QString::fromLocal8Bit("请输入用户名..."));
    data->layout->addWidget(data->name, 1, 1, 1, 2);

    data->army = new QLineEdit;
    data->army->setObjectName("UserEditFormEdit");
    data->army->setPlaceholderText(QString::fromLocal8Bit("情输入部队名..."));
    data->layout->addWidget(data->army, 2, 1, 1, 2);

    data->password = new QLineEdit;
    data->password->setObjectName("UserEditFormEdit");
    data->password->setPlaceholderText(QString::fromLocal8Bit("情输入密码..."));
    data->layout->addWidget(data->password, 3, 1, 1, 2);

    if (list != nullptr)
    {
        data->box->setToolTip(list->at(0));
        data->name->setText(list->at(1));
        data->army->setText(list->at(2));
        data->password->setText(list->at(3));
    }

    data->ok = new QPushButton(QString::fromLocal8Bit("确定"));
    data->ok->setObjectName("UserEditFormOkButton");
    data->layout->addWidget(data->ok, 4, 1, 1, 1);
    data->cancel = new QPushButton(QString::fromLocal8Bit("取消"));
    data->cancel->setObjectName("UserEditFormCancelButton");
    data->layout->addWidget(data->cancel, 4, 2, 1, 1);

    connect(data->ok, SIGNAL(clicked()), this, SLOT(slotOkbuttonClicked()));
    connect(data->cancel, SIGNAL(clicked()), this, SLOT(close()));
}

void UserEditForm::slotOkbuttonClicked()
{
    QStringList list;
    list << data->box->currentText()
         << data->name->text()
         << data->army->text()
         << data->password->text();
    emit signalUserEdit(list);
    close();
}
