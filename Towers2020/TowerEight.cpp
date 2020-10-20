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
	/// Prepare for firing
	ArmTower();
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
		auto needle = std::make_shared<CProjectile>(mGame);
		mProjectiles.push_back(needle);
	}
}

void CTowerEight::Fire()
{
	Gdiplus::Graphics* graphics = mGame->GetGraphics();
	//std::shared_ptr<CProjectile> dart = mProjectiles[0];
	for (auto i : mProjectiles) {
		auto dart = i;
	}
	//dart->setCoordinates(300, 300);
	//dart->Draw(graphics, 10, 10);
}

