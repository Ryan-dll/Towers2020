/**
 * \file Message.cpp
 *
 * \author Team Pink Lady
 */

#include "pch.h"
#include "Message.h"

using namespace Gdiplus;

CMessage::CMessage()
{
}

CMessage::~CMessage()
{
}

void CMessage::DrawBeginMessage(Graphics* graphics, int level)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 40);

	SolidBrush red(Color(255, 0, 0));
	std::wstring str = L"Begin Level " + std::to_wstring(level);
	graphics->DrawString(str.c_str(), -1, &font, PointF(175, 400), &red);

}

void CMessage::DrawEndMessage(Graphics* graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 40);

	SolidBrush red(Color(255, 0, 0));
	std::wstring str = L"Completed Level!";
	graphics->DrawString(str.c_str(), -1, &font, PointF(175, 400), &red);

}
