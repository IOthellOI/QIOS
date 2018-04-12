#include "computerTable.h"
#include "xmlRead.h"

#include <cassert>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QPushButton>
#include <QLabel>
#include <QVector>

class ComputerTableLabel : public QLabel
{
public:
	ComputerTableLabel(QWidget * _parent = nullptr) :
		QLabel(_parent)
	{
		setObjectName("ComputerTableLabel");
	}

	virtual ~ComputerTableLabel() {};
};

class ComputerTableButton : public QPushButton
{
public:
	ComputerTableButton(QWidget * _parent = nullptr) :
		QPushButton(_parent)
	{
		setObjectName("ComputerTableButton");
	}

	virtual ~ComputerTableButton() {};
};

struct ComputerTableItem
{
	ComputerTableLabel identifier;
	ComputerTableLabel name;
	ComputerTableLabel ethernetState;
	ComputerTableLabel realtimeState;
	ComputerTableButton computerRestart;
	ComputerTableButton computerShutdown;
	ComputerTableLabel programState;
	ComputerTableButton programRestart;
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
	
	verticalHeader()->setVisible(false);

	horizontalHeader()->setSectionsClickable(false);

	setEditTriggers(QAbstractItemView::NoEditTriggers);

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

	while (!node.isNull())
	{
		header << node.attribute("value");
		node = node.nextSiblingElement();
	}

	setColumnCount(header.size());
	setHorizontalHeaderLabels(header);

	element = element.nextSiblingElement();
	node = element.firstChildElement();

	ComputerTableItem * item = nullptr;

	int row = 0;
	int column = 0;
	while (!node.isNull())
	{
		setRowCount(++row);

		item = new ComputerTableItem;

		item->identifier.setText(node.attribute("identifier"));
		setCellWidget(row - 1, column++, &item->identifier);

		item->name.setText(node.attribute("name"));
		setCellWidget(row - 1, column++, &item->name);
		setCellWidget(row - 1, column++, &item->ethernetState);
		setCellWidget(row - 1, column++, &item->realtimeState);
		setCellWidget(row - 1, column++, &item->computerRestart);
		setCellWidget(row - 1, column++, &item->programState);
		setCellWidget(row - 1, column++, &item->programRestart);
		
		column = 0;
		node = node.nextSiblingElement();
	}
}
