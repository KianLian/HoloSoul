// Code by Kian


#include "UI/Widgets/HoloUserWidget.h"

void UHoloUserWidget::SetWidgetController(UObject* Controller)
{
	WidgetController = Controller;
	WidgetConstructSet();
}

