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
		auto needle = std::make_shared<CProjectile>(GetGame());
		double a = needle->GetAngle();
		double sn = sin(a);
		double cs = cos(a);

		double x = GetX() + GetItemImage()->GetWidth() / 2.0 + cs;
		double y = GetY() + GetItemImage()->GetHeight() / 2.0 + sn * mT;

		needle->SetCoordinates(x, y);
		needle->SetOrigin(x, y);

		double newAngle = (i / 4.0) * GetPi();
		needle->SetAngle(newAngle);

		mProjectiles.push_back(needle);
		GetGame()->Add(needle);
	}
}

/**
 * Updates Tower in elapsed intervals
 */
void CTowerProjectile::Update(double elapsed)
{
	// This if statement probably isnt nessicary, since we now just 
	// don't call update when the game isnt active
	if (GetGame()->GetGameActive() == true) 
	{
		mTimeUntilFire -= elapsed;
		if (mTimeUntilFire <= 0)
		{
			mTimeUntilFire += mTimeBetween;
			Fire();
		}
	}


	//for (auto &i : mProjectiles)
	//{
	//	double a = i->GetAngle();
	//	double sn = sin(a);
	//	double cs = cos(a);

	//	double x = mX + mItemImage->GetWidth() / 2.0 + cs;
	//	double y = mY + mItemImage->GetHeight() / 2.0 + sn * mT;

	//	i->SetOrigin(x, y);
	//}

	//double newX = mX - mLastX;
	//double newY = mY - mLastY;

	//for (auto &i : mProjectiles)
	//{
	//	double x = i->GetX() + newX;
	//	double y = i->GetY() + newY;
	//	i->SetOrigin(x, y);
	//}

	//mLastX = mX;
	//mLastY = mY;
}
