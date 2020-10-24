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
	mGame = game;
	bomb = make_unique<CBomb>(game);
	mGame->Add(bomb);
	mGame->IncreaseBombCount();
	mTimeUntilFire = game->getBombCount() * 3;


	wstring image = L"tower-bomb.png";
	CItem::SetImage(image);
}

void CTowerBomb::Fire()
{
	bomb->Fire();
}

void CTowerBomb::Update(double elapsed)
{
	mTimeUntilFire -= elapsed;

	if (mTimeUntilFire <= 0 && !bombUsed)
	{
		Fire();
		bombUsed = true;
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
		int wid = mItemImage->GetWidth() / 2;
		int hit = mItemImage->GetHeight() / 2;
		//    graphics->DrawImage(mItemImage.get(),
		//            mX, mY,
		//            wid, hit);
		graphics->DrawImage(mItemImage.get(),
			mX, mY,
			65, 65);
	}
}

void CTowerBomb::ArmTower()
{
	// Sets the towers position to itself, which also moves the bomb
	setCoordinates(mX, mY);
}
