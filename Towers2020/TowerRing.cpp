/**
 * \file TowerRing.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the TowerRing
 */

#include "pch.h"
#include "TowerRing.h"
#include <memory>

using namespace std;

CTowerRing::CTowerRing(CGame* game) : CTower(game)
{

	mRing = make_unique<CRing>(game);
	GetGame()->Add(mRing);

	wstring image = L"tower-rings.png";
	CItem::SetImage(image);
}

void CTowerRing::Fire()
{
	mRing->Fire();
}

void CTowerRing::Update(double elapsed)
{
	if (GetGame()->GetGameActive() == true)
	{
		mTimeUntilFire -= elapsed;
		if (mTimeUntilFire <= 0)
		{
			mTimeUntilFire += mTimeBetween;
			Fire();
		}
	}
}

void CTowerRing::ArmTower()
{
	// Sets the towers position to itself, which also moves the ring
	SetCoordinates(GetX(), GetY());
}
