/**
 * \file Dashboard.h
 *
 * \author Craig Smith
 *
 * Class that implements the Dashboard
 */

#pragma once
#include <memory>
#include "Game.h"

class CGame;

 /**
 * CDashboard class
 */
class CDashboard
{
public:
	CDashboard() = delete;

	CDashboard(const CDashboard&) = delete;

	/**
	 * CItem constructor
	 * \param game Pointer to the game which we belong
	 */
	CDashboard(CGame* game);

	void Draw(Gdiplus::Graphics* graphics);
	void setLevelStarted(bool started);

private:
	/// Pointer to the Game we belong to
	CGame* mGame;

};

