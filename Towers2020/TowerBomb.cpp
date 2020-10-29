/**
 * \file TowerBomb.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the TowerBomb
 */

#include "pch.h"
#include "TowerBomb.h"
#include "Game.h"
#include <memory>

using namespace std;

CTowerBomb::CTowerBomb(CGame* game) : CTower(game)
{
	mBomb = make_unique<CBomb>(game);
	GetGame()->Add(mBomb);
	GetGame()->IncreaseBombCount();
	mTimeUntilFire = game->GetBombCount() * 3.0;


	wstring image = L"tower-bomb.png";
	CItem::SetImage(image);
}

void CTowerBomb::Fire()
{
	mBomb->Fire();
}

void CTowerBomb::Update(double elapsed)
{
	if (GetGame()->GetGameActive() == true)
	{
		mTimeUntilFire -= elapsed;

		if (mTimeUntilFire <= 0 && !mBombUsed)
		{
			Fire();
			mBombUsed = true;
		}
	}
}

/**
 * Draw the image
 * \param graphics Pointer to the graphics context
 */
void CTowerBomb::Draw(Gdiplus::Graphics* graphics)
{
	if (mTimeUntilFire > 0) {
		// Draw the image
		int wid = GetItemImage()->GetWidth() / 2;
		int hit = GetItemImage()->GetHeight() / 2;
		//    graphics->DrawImage(mItemImage.get(),
		//            mX, mY,
		//            wid, hit);
		graphics->DrawImage(GetItemImage().get(),
			GetX(), GetY(),
			65, 65);
	}
}

void CTowerBomb::ArmTower()
{
	// Sets the towers position to itself, which also moves the bomb
	SetCoordinates(GetX(), GetY());
}
