/**
 * \file Message.cpp
 *
 * \author Team Pink Lady
 */

#include "pch.h"
#include "Message.h"

using namespace Gdiplus;

/**
 * Constructor for message
 */
CMessage::CMessage()
{
}

/**
 * Destructor for message
 */
CMessage::~CMessage()
{
}

/**
 * Draw the begin message
 * \param graphics The graphics context
 * \param level The level number
 */
void CMessage::DrawBeginMessage(Graphics* graphics, int level)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 115);

	SolidBrush red(Color(255, 105, 180));
	graphics->DrawString(L"Level   Begin!", -1, &font, PointF(0, 400), &red);

	switch (level)
	{
	case 0:
		graphics->DrawString(L"0", -1, &font, PointF(400, 400), &red);
		break;
	case 1:
		graphics->DrawString(L"1", -1, &font, PointF(400, 400), &red);
		break;
	case 2:
		graphics->DrawString(L"2", -1, &font, PointF(400, 400), &red);
		break;
	}

}
