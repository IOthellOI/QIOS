#include <QApplication>
#include <QLayout>
#include <QPixmap>
#include <QTextCodec>

#include "clickButton.h"
#include "toggleButton.h"
#include "mutexButton.h"
#include "navigationButton.h"
#include "textLabel.h"
#include "indicationLabel.h"
#include "dataSlider.h"
#include "dataLabel.h"
#include "progressBar.h"
#include "entryBar.h"
#include "mainWindow.h"
#include "inputPage.h"
#include "dataButton.h"

#include <QFile>

#pragma execution_character_set("utf-8")

using namespace ios;

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);

	//a.setFont(QFont("Microsoft Yahei", 9));
	//a.setWindowIcon(QIcon("../res/ico/main.ico"));

	//QFile file("../res/qss/darkblack.css");
	//if (file.open(QFile::ReadOnly))
	//{
	//	QString qss = QLatin1String(file.readAll());
	//	QString paletteColor = qss.mid(20, 7);
	//	qApp->setPalette(QPalette(QColor(paletteColor)));
	//	qApp->setStyleSheet(qss);
	//	file.close();
	//}

	ios::MainWindow w;
	w.show();

	return a.exec();
}