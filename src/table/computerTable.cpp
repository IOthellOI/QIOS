#include "computerTable.h"
#include "xmlRead.h"

#include <cassert>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QLayout>

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

class ComputerTableRestartButton : public ComputerTableButton
{
public:
	ComputerTableRestartButton(QWidget * _parent = nullptr) :
		ComputerTableButton(_parent)
	{
		setObjectName("ComputerTableRestartButton");
	}
	~ComputerTableRestartButton() {};
};

class ComputerTableShutdownButton : public ComputerTableButton
{
public:
	ComputerTableShutdownButton(QWidget * _parent = nullptr) :
		ComputerTableButton(_parent)
	{
		setObjectName("ComputerTableShutdownButton");
	}
	~ComputerTableShutdownButton() {};
};

struct ComputerTableItem
{
	ComputerTableLabel identifier;
	ComputerTableLabel name;
	ComputerTableLabel ethernetState;
	ComputerTableLabel realtimeState;
	ComputerTableRestartButton computerRestart;
	ComputerTableShutdownButton computerShutdown;
	ComputerTableLabel programState;
	ComputerTableRestartButton programRestart;
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

	data->vector = new QVector<ComputerTableItem *>;

	horizontalHeader()->setStretchLastSection(true);

	setShowGrid(false);

	setAlternatingRowColors(true);
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
		header << node.attribute("value");
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

		item->identifier.setAlignment(Qt::AlignCenter);
		item->identifier.setText(QString("") + node.attribute("identifier") + "");
		setCellWidget(row, column++, &item->identifier);

		item->name.setAlignment(Qt::AlignCenter);
		item->name.setText(QString("") + node.attribute("name") + "");
		setCellWidget(row, column++, &item->name);

		item->ethernetState.setAlignment(Qt::AlignCenter);
		item->ethernetState.setText(QString("") + u8"未接通" + "");
		setCellWidget(row, column++, &item->ethernetState);

		item->realtimeState.setAlignment(Qt::AlignCenter);
		item->realtimeState.setText(QString("") + u8"未接通" + "");
		setCellWidget(row, column++, &item->realtimeState);

		QWidget * widget = new QWidget;
		widget->setContentsMargins(50, 0, 50, 0);
		QHBoxLayout * layout = new QHBoxLayout(widget);
		layout->setMargin(0);
		layout->setSpacing(30);
		layout->addWidget(&item->computerRestart);
		layout->addWidget(&item->computerShutdown);
		item->computerRestart.setText(u8"重启");
		item->computerShutdown.setText(u8"关机");
		setCellWidget(row, column++, widget);

		item->programState.setAlignment(Qt::AlignCenter);
		item->programState.setText(QString("") + u8"未连通" + "");
		setCellWidget(row, column++, &item->programState);

		widget = new QWidget;
		widget->setContentsMargins(50, 0, 50, 0);
		layout = new QHBoxLayout(widget);
		layout->setMargin(0);
		layout->addWidget(&item->programRestart);
		item->programRestart.setText(u8"重启");
		setCellWidget(row, column++, widget);
		
		++row;
		column = 0;
		node = node.nextSiblingElement();
	}

}
