/**
 * \file TowerEight.cpp
 *
 * \author RyanShore
 *
 * Tower that shoots 8 projectiles at once in a circle
 */

#include "pch.h"
#include "TowerEight.h"
#include "TowerVisitor.h"
#include "Projectile.h"

using namespace std;

/**
 * Consturctor for the TowerEight
 * \param game Pointer to the game
 */
CTowerEight::CTowerEight(CGame * game) : CTower(game)
{
	wstring image = L"tower8.png";
	CItem::SetImage(image);
}

/**
 * Consturctor for the TowerEight
 * \param visitor Pointer to the visitor
 */
void CTowerEight::Accept(CTowerVisitor* visitor)
{
	visitor->VisitTowerEight(this);
}

/**
 * Arm the tower
 */
void CTowerEight::ArmTower()
{
	int numOfProjectiles = 8;
	for (int i = 0; i < numOfProjectiles; i++)
	{
		std::shared_ptr<CProjectile> needle;
		mProjectiles.push_back(needle);
	}
}

