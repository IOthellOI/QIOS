#include "computerTable.h"
#include "xmlRead.h"

#include <cassert>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QLayout>

struct ComputerTableItem
{
	QLabel identifier;
	QLabel name;
	QLabel ethernetState;
	QLabel realtimeState;
	QPushButton computerRestart;
	QPushButton computerShutdown;
	QLabel programState;
	QPushButton programRestart;
};

struct ComputerTable::ComputerTablePrivate
{
	QVector<ComputerTableItem *> * vector;
};

ComputerTable::ComputerTable(QWidget * _parent) :
	QTableWidget(_parent),
	data(new ComputerTablePrivate)
{
	setObjectName("ComputerTable");
	horizontalHeader()->setObjectName("ComputerTable");
	verticalHeader()->setVisible(false);
	horizontalHeader()->setSectionsClickable(false);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	horizontalHeader()->setStretchLastSection(true);
	setShowGrid(false);
	setAlternatingRowColors(true);
	setSelectionMode(QAbstractItemView::NoSelection);
	setFocusPolicy(Qt::NoFocus);

	data->vector = new QVector<ComputerTableItem *>;
}

ComputerTable::~ComputerTable()
{

}

void ComputerTable::loadConfig(const QString & _path)
{
	assert(!_path.isEmpty());
	XmlRead xmlRead;
	xmlRead.loadFile(_path);
	QDomElement root = xmlRead.rootElement();
	QDomElement element = root.firstChildElement();
	QDomElement node = element.firstChildElement();

	QStringList header;

	setColumnCount(7);

	for (int i = 0; !node.isNull(); i++)
	{
		header << node.attribute("item");
		setColumnWidth(i, node.attribute("width").toInt());
		node = node.nextSiblingElement();
	}

	setHorizontalHeaderLabels(header);

	element = element.nextSiblingElement();
	node = element.firstChildElement();

	verticalHeader()->setDefaultSectionSize(element.attribute("height").toInt());

	ComputerTableItem * item = nullptr;

	int row = 0;
	int column = 0;
	while (!node.isNull())
	{
		setRowCount(row + 1);

		item = new ComputerTableItem;

		item->identifier.setObjectName("ComputerTableLabel");
		item->identifier.setAlignment(Qt::AlignCenter);
		item->identifier.setText(node.attribute("identifier"));
		setCellWidget(row, column++, &item->identifier);

		item->name.setObjectName("ComputerTableLabel");
		item->name.setAlignment(Qt::AlignCenter);
		item->name.setText(node.attribute("name"));
		setCellWidget(row, column++, &item->name);

		item->ethernetState.setObjectName("ComputerTableLabel");
		item->ethernetState.setAlignment(Qt::AlignCenter);
		item->ethernetState.setText(u8"未接通");
		setCellWidget(row, column++, &item->ethernetState);

		item->realtimeState.setObjectName("ComputerTableLabel");
		item->realtimeState.setAlignment(Qt::AlignCenter);
		item->realtimeState.setText(u8"未接通");
		setCellWidget(row, column++, &item->realtimeState);

		QWidget * widget = new QWidget;
		widget->setContentsMargins(50, 0, 50, 0);
		QHBoxLayout * layout = new QHBoxLayout(widget);
		layout->setMargin(0);
		layout->setSpacing(30);
		item->computerRestart.setObjectName("ComputerTableRestartButton");
		item->computerShutdown.setObjectName("ComputerTableShutdownButton");
		layout->addWidget(&item->computerRestart);
		layout->addWidget(&item->computerShutdown);
		item->computerRestart.setText(u8"重启");
		item->computerShutdown.setText(u8"关机");
		setCellWidget(row, column++, widget);

		item->programState.setObjectName("ComputerTableLabel");
		item->programState.setAlignment(Qt::AlignCenter);
		item->programState.setText(u8"未连通");
		setCellWidget(row, column++, &item->programState);

		widget = new QWidget;
		widget->setContentsMargins(50, 0, 50, 0);
		layout = new QHBoxLayout(widget);
		layout->setMargin(0);
		item->programRestart.setObjectName("ComputerTableRestartButton");
		layout->addWidget(&item->programRestart);
		item->programRestart.setText(u8"重启");
		setCellWidget(row, column++, widget);
		
		++row;
		column = 0;
		node = node.nextSiblingElement();
	}
}
