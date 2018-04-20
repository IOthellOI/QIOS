#include "titleButton.h"
#include "dataPool.h"

TitleButton::TitleButton(QWidget * _parent) :
	QPushButton(_parent)
{
	setObjectName("TitleButton");

    connect(this, SIGNAL(clicked()), this, SLOT(slotButtonClick()));

    connect(this, SIGNAL(signalTitleCommand(QString)), DataPool::internalDataMap()->value("titleCommand"), SLOT(slotDataUpdate(QString)));
}

TitleButton::~TitleButton()
{
}

void TitleButton::slotButtonClick()
{
    if(this->text() == "最小化")
    {
        emit signalTitleCommand("minimize");
    }
    else if(this->text() == "关闭")
    {
        emit signalTitleCommand("close");
    }
}
