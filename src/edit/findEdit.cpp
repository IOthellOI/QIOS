#include "findEdit.h"
#include <QAction>
#include <QIcon>

FindEdit::FindEdit(QWidget *_parent) :
    QLineEdit(_parent)
{
    setObjectName("FindEdit");
    setPlaceholderText(QString::fromLocal8Bit("请输入查询信息..."));
    QAction * action = new QAction;
    action->setIcon(QIcon("./res/ico/magnifier.png"));
    addAction(action, QLineEdit::TrailingPosition);
    connect(action, SIGNAL(triggered()), this, SLOT(slotClicked()));
}

FindEdit::~FindEdit()
{

}

void FindEdit::slotClicked()
{
    emit signalClicked();
}
