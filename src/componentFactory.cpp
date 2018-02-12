#include "componentFactory.h"
#include "clickButton.h"
#include "dataLabel.h"
#include "dataSlider.h"
#include "entryBar.h"
#include "indicationLabel.h"
#include "mutexButton.h"
#include "navigationButton.h"
#include "progressBar.h"
#include "textLabel.h"
#include "toggleButton.h"

ios::BaseWidget * ios::ComponentFactory::create(const QString & _type)
{
	if (_type.toUpper() == "CLICKBUTTON")
	{
		return new ClickButton;
	}
	else if (_type.toUpper() == "DATALABEL")
	{
		return new DataLabel;
	}
	else if (_type.toUpper() == "DATASLIDER")
	{
		return new DataSlider;
	}
	else if (_type.toUpper() == "ENTRYBAR")
	{
		return new EntryBar;
	}
	else if (_type.toUpper() == "INDICATIONLABEL")
	{
		return new IndicationLabel;
	}
	else if (_type.toUpper() == "MUTEXBUTTON")
	{
		return new MutexButton;
	}
	else if (_type.toUpper() == "NAVIGATIONBUTTON")
	{
		return new NavigationButton;
	}
	else if (_type.toUpper() == "PROGRESSBAR")
	{
		return new ProgressBar;
	}
	else if (_type.toUpper() == "TEXTLABEL")
	{
		return new TextLabel;
	}
	else if (_type.toUpper() == "TOGGLEBUTTON")
	{
		return new ToggleButton;
	}
	else
	{
		return nullptr;
	}
}
