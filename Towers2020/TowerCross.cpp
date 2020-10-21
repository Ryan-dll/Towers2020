/**
 * \file TowerCross.cpp
 *
 * \author RyanShore
 *
 * Tower that shoots 8 projectiles at once in a circle
 */

#include "pch.h"
#include "TowerCross.h"
#include "TowerVisitor.h"
#include "Projectile.h"


using namespace std;

/**
 * Consturctor for the TowerCross
 * \param game Pointer to the game
 */
CTowerCross::CTowerCross(CGame* game) : CTowerProjectile(game)
{
	wstring image = L"tower8.png";
	CItem::SetImage(image);
	mTimeBetween = 1.75;
	mTimeUntilFire = 1.75;
	/// Prepare for firing

}

/**
 * Accept function for visitor
 * \param visitor Pointer to the visitor
 */
void CTowerCross::Accept(CTowerVisitor* visitor)
{
	visitor->VisitTowerCross(this);
}

void CTowerCross::Fire()
{
	for (auto& item : mProjectiles)
	{
		if (mCrossPattern == true)
		{
			item->SetActive(true);
		}
		mCrossPattern = !mCrossPattern;
	}
	mCrossPattern = !mCrossPattern;

}

