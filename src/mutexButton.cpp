#include "mutexButton.h"

#include <QPushButton>
#include <QButtonGroup>
#include <QVector>
#include <QLayout>

struct ios::MutexButton::MutexButtonData
{
	QHBoxLayout * layout;
	QPushButton * button;
	static QVector<QButtonGroup *> * buttonGroup;
	static QVector<int> * groupRepository;
	int group;
};

QVector<QButtonGroup *> * ios::MutexButton::MutexButtonData::buttonGroup = new QVector<QButtonGroup *>;
QVector<int> * ios::MutexButton::MutexButtonData::groupRepository = new QVector<int>;

ios::MutexButton::MutexButton(QWidget * _parent) :
	BaseWidget(_parent),
	data(new MutexButtonData)
{
	data->button = new QPushButton;
	QSizePolicy sizePolicy = data->button->sizePolicy();
	sizePolicy.setHorizontalPolicy(QSizePolicy::Expanding);
	sizePolicy.setVerticalPolicy(QSizePolicy::Expanding);
	data->button->setSizePolicy(sizePolicy);
	data->button->setCheckable(true);

	data->layout = new QHBoxLayout;
	data->layout->addWidget(data->button);
	data->layout->setContentsMargins(0, 0, 0, 0);
	data->layout->setMargin(0);
	setLayout(data->layout);

	connect(data->button, SIGNAL(clicked(bool)), this, SLOT(slotClicked(bool)));
}

ios::MutexButton::~MutexButton()
{
	delete data;
}

void ios::MutexButton::setText(const QString & _text) const
{
	data->button->setText(_text);
}

void ios::MutexButton::setChecked(bool _checked) const
{
	data->button->setChecked(_checked);
}

void ios::MutexButton::setGroup(int _group) const
{
	data->group = _group;
	if (!data->buttonGroup->empty())
	{
		bool judge = false;
		for (size_t i = 0; i < data->groupRepository->length(); i++)
		{
			if (_group == data->groupRepository->at(i))
			{
				data->buttonGroup->at(i)->addButton(data->button);
				judge = true;
			}
		}
		if (!judge)
		{
			data->buttonGroup->push_back(new QButtonGroup);
			data->buttonGroup->at(data->groupRepository->length())->addButton(data->button);
			data->groupRepository->push_back(_group);
		}
	}
	else
	{
		data->buttonGroup->push_back(new QButtonGroup);
		data->buttonGroup->at(0)->addButton(data->button);
		data->groupRepository->push_back(_group);
	}
}

void ios::MutexButton::slotClicked(bool _clicked)
{
	if (_clicked)
	{
		emit signalClicked();
	}
	else
	{
		setChecked(true);
	}
}


