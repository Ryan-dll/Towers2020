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

	/**
	 * Constructor for message
	 */
	CMessage();

	/**
	 * Destructor for message
	 */
	~CMessage();
	
	/**
	 * Draw the begin message
	 * \param graphics The graphics context
	 * \param level The level number
	 */
	void DrawBeginMessage(Gdiplus::Graphics* graphics, int level);

	/**
	 * Draw the end message
	 * \param graphics The graphics context
	 * \param level The level number
	 */
	void DrawEndMessage(Gdiplus::Graphics* graphics);
};

