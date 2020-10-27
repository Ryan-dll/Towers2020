/**
 * \file Message.h
 *
 * \author Team Pink Lady
 *
 *  Class that display in-game messages
 */

#pragma once
#include <string>

/**
 * Display in-game message
 */
class CMessage
{
public:

	CMessage();

	~CMessage();
	
	/// Draw the begin message
	void DrawBeginMessage(Gdiplus::Graphics* graphics, int level);
};

