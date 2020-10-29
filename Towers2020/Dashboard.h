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
class CTower;

 /**
 * CDashboard class
 */
class CDashboard
{
public:
	CDashboard() = delete;

	CDashboard(const CDashboard&) = delete;

	/// Constructor
	CDashboard(CGame* game);

	/// Destructor
	~CDashboard();

	/// Draw the dashboard
	void Draw(Gdiplus::Graphics* graphics);
	void SetLevelStarted(bool started);
	
	/// Return the item the user clicked on in the dashboard
	CTower* DashHitTest(int x, int y);

private:
	/// Pointer to the Game we belong to
	CGame* mGame;

};

