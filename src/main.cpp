#include <QApplication>
#include <QFile>
#include <QIcon>

#include "dataPool.h"
#include "windowForm.h"
#include "iniRead.h"
#include "loginForm.h"

#pragma execution_character_set("utf-8")

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);

	a.setFont(QFont("Microsoft Yahei", 10));
	a.setWindowIcon(QIcon("./res/ico/main.ico"));

	QFile file("./res/qss/styleSheet.css");
	if (file.open(QFile::ReadOnly))
	{
		QString qss = QLatin1String(file.readAll());
		qApp->setStyleSheet(qss);
		file.close();
	}

	LoginForm c;
	c.show();
	
	return a.exec();
}