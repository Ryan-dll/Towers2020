/**
 * \file Dashboard.h
 *
 * \author Craig Smith
 *
 * Class that implements the Dashboard
 */

#pragma once

 /**
 * CDashboard class
 */
class CDashboard
{
public:
	void Draw(Gdiplus::Graphics* graphics);
	void setScore(int newScore);
	void setLevelStarted(bool started);
};

