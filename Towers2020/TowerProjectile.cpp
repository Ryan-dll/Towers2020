#include "pch.h"
#include "TowerProjectile.h"

/**
 * Constructor for CTowerProjectile
 * \param game Pointer to the game object
 */
CTowerProjectile::CTowerProjectile(CGame* game) : CTower(game)
{
	// Dont need this guy now, but maybe later...
}

/**
 * Arm the tower
 */
void CTowerProjectile::ArmTower()
{
	int numOfProjectiles = 8;
	for (double i = 1; i <= numOfProjectiles; i++)
	{
		auto needle = std::make_shared<CProjectile>(mGame);
		double a = needle->GetAngle();
		double sn = sin(a);
		double cs = cos(a);

		double x = mX + mItemImage->GetWidth() / 2.0 + cs;
		double y = mY + mItemImage->GetHeight() / 2.0 + sn * mT;

		needle->setCoordinates(x, y);
		needle->SetOrigin(x, y);

		double newAngle = (i / 4.0) * pi;
		needle->SetAngle(newAngle);

		mProjectiles.push_back(needle);
		mGame->Add(needle);
	}
}