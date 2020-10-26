/**
 * \file TowerEight.cpp
 *
 * \author RyanShore
 *
 * Tower that shoots 8 projectiles at once in a circle
 */

#include "pch.h"
#include "TowerEight.h"
#include "Projectile.h"


using namespace std;

/**
 * Consturctor for the TowerEight
 * \param game Pointer to the game
 */
CTowerEight::CTowerEight(CGame * game) : CTowerProjectile(game)
{
	wstring image = L"tower8.png";
	CItem::SetImage(image);
	/// Prepare for firing
	
}

void CTowerEight::Fire()
{
	for (auto& item : mProjectiles)
	{
		item->SetActive(true);
	}

}

