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

CTowerEight::CTowerEight(CGame * game) : CTower(game)
{
	wstring image = L"tower8.png";
	CItem::SetImage(image);
}

void CTowerEight::Accept(CTowerVisitor* visitor)
{
	visitor->VisitTowerEight(this);
}

void CTowerEight::ArmTower()
{
	int numOfProjectiles = 8;
	for (int i = 0; i < numOfProjectiles; i++)
	{
		std::shared_ptr<CProjectile> needle;
		mProjectiles.push_back(needle);
	}
}

