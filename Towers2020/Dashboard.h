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
	CDashboard(CGame* game) { mGame = game; }

	void Draw(Gdiplus::Graphics* graphics);
	void setScore(int newScore);
	void setLevelStarted(bool started);

private:
	/// Pointer to the Game we belong to
	CGame* mGame;
};

