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

#pragma execution_character_set("utf-8")

using namespace ios;

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);
	ios::MainWindow window;
	window.show();
	return a.exec();
}