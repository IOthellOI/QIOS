#include <QApplication>
#include <QFile>
#include <QIcon>

#include "dataPool.h"
#include "mainForm.h"
#include "iniRead.h"
#include "loginForm.h"

#pragma execution_character_set("utf-8")

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);

	a.setFont(QFont("Microsoft Yahei", 9));

	QFile file("./res/qss/styleSheet.css");
	if (file.open(QFile::ReadOnly))
	{
		QString qss = QLatin1String(file.readAll());
		qApp->setStyleSheet(qss);
		file.close();
	}
	DataPool d;

	IniRead i;

	//WindowForm w;
	//w.show();
		
	LoginForm w;
	w.show();
	
	return a.exec();
}