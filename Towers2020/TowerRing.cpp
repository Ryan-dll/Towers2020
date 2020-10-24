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
	mGame = game;
	ring = make_unique<CRing>(game);
	mGame->Add(ring);

	wstring image = L"tower-rings.png";
	CItem::SetImage(image);
}

void CTowerRing::Fire()
{
	ring->Fire();
}

void CTowerRing::Update(double elapsed)
{
	mTimeUntilFire -= elapsed;

	if (mTimeUntilFire <= 0)
	{
		Fire();
		mTimeUntilFire = mTimeBetween;
	}
}

void CTowerRing::ArmTower()
{
	// Sets the towers position to itself, which also moves the ring
	setCoordinates(mX, mY);
}
