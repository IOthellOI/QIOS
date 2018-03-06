#include "inputPage.h"

#include <QLayout>
#include <QLineEdit>
#include <QLabel>
#include <QFont>

struct ios::InputPage::InputPageData
{
	QGridLayout * layout;
	QLabel * label;
	QLineEdit * edit;

	//[0]-[9]:0-9 [10]:. [11]:- [12]:<- [13]:Clear [14]:Cancel [15]:Excute
	QPushButton * button[16];
};

ios::InputPage::InputPage(QWidget * _parent):
	BaseWidget(_parent),
	data(new InputPageData)
{
	data->layout = new QGridLayout;
	data->layout->setSizeConstraint(QLayout::SetFixedSize);

	data->label = new QLabel;

	data->edit = new QLineEdit("0");

	QFont font = data->edit->font();
	font.setPointSize(font.pointSize() + 8);
	data->edit->setFont(font);

	data->edit->setAlignment(Qt::AlignRight);
	data->edit->setReadOnly(true);
	data->edit->setFixedHeight(40);

	for (size_t i = 0; i < 10; i++)
	{
		data->button[i] = new QPushButton(QString::number((i + 1) % 10));
	}
	data->button[10] = new QPushButton(".");
	data->button[11] = new QPushButton("-");
	data->button[12] = new QPushButton("<-");
	data->button[13] = new QPushButton("Clear");
	data->button[14] = new QPushButton("Cancel");
	data->button[15] = new QPushButton("Excute");

	data->layout->addWidget(data->label, 0, 0, 1, 4);
	data->layout->addWidget(data->edit, 1, 0, 1, 4);

	for (size_t i = 0; i < 16; i++)
	{
		data->button[i]->setFixedHeight(40);
		data->button[i]->setFixedWidth(60);
		if (i < 10)
		{
			data->layout->addWidget(data->button[i], i / 3 + 2, i % 3);
			connect(data->button[i], SIGNAL(clicked()), this, SLOT(slotDigitClicked()));
			data->button[i]->setShortcut(QKeySequence(QString::number((i + 1) % 10)));
		}
	}

	data->layout->addWidget(data->button[10], 5, 1);
	data->layout->addWidget(data->button[11], 5, 2);
	data->layout->addWidget(data->button[12], 2, 3);
	data->layout->addWidget(data->button[13], 3, 3);
	data->layout->addWidget(data->button[14], 4, 3);
	data->layout->addWidget(data->button[15], 5, 3);

	connect(data->button[10], SIGNAL(clicked()), this, SLOT(slotPointClicked()));
	connect(data->button[11], SIGNAL(clicked()), this, SLOT(slotMinusClicked()));
	connect(data->button[12], SIGNAL(clicked()), this, SLOT(slotBackClicked()));
	connect(data->button[13], SIGNAL(clicked()), this, SLOT(slotClearClicked()));
	connect(data->button[14], SIGNAL(clicked()), this, SLOT(slotCancelClicked()));
	connect(data->button[15], SIGNAL(clicked()), this, SLOT(slotExcuteClicked()));

	data->button[10]->setShortcut(QKeySequence("."));
	data->button[11]->setShortcut(QKeySequence("-"));
	data->button[12]->setShortcut(QKeySequence("BackSpace"));
	data->button[13]->setShortcut(QKeySequence("Delete"));
	data->button[14]->setShortcut(QKeySequence("Esc"));
	data->button[15]->setShortcut(QKeySequence("Enter"));
	
	setLayout(data->layout);

	setAttribute(Qt::WA_DeleteOnClose, true);
}

ios::InputPage::~InputPage()
{
	delete data;
}

void ios::InputPage::slotDigitClicked()
{
	QPushButton * clickedButton = reinterpret_cast<QPushButton *>(sender());

	int digitvalue = clickedButton->text().toInt();

	if (data->edit->text() == "0")
	{
		data->edit->setText(QString::number(digitvalue));
	}
	else
	{
		data->edit->setText(data->edit->text() + QString::number(digitvalue));
	}
}

void ios::InputPage::slotPointClicked()
{
	if (data->edit->text().isEmpty())
	{
		data->edit->setText("0.");
	}
	else if (!data->edit->text().contains('.'))
	{
		data->edit->setText(data->edit->text() + ".");
	}
}

void ios::InputPage::slotMinusClicked()
{
	QString text = data->edit->text();
	if (!data->edit->text().contains('-'))
	{
		data->edit->setText("-" + data->edit->text());
	}
	else
	{
		text.remove('-');
		data->edit->setText(text);
	}
}

void ios::InputPage::slotBackClicked()
{
	if (data->edit->text() == "0")
	{
		return;
	}
	else
	{
		QString text = data->edit->text();
		text.chop(1);
		if (text.isEmpty())
		{
			text = "0";
		}
		data->edit->setText(text);
	}
}

void ios::InputPage::slotClearClicked()
{
	if (data->edit->text() == "0")
	{
		return;
	}
	else
	{
		data->edit->setText("0");
	}
}

void ios::InputPage::slotCancelClicked()
{
	this->close();
}

void ios::InputPage::slotExcuteClicked()
{
	emit signalExcuteClicked(data->edit->text());
	this->close();
}