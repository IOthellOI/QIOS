#include <QApplication>
#include <QFile>

#include "clickButton.h"

#pragma execution_character_set("utf-8")


int main(int argc, char * argv[])
{
	QApplication a(argc, argv);

	ClickButton button;
	button.show();

	return a.exec();
}