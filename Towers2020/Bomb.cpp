/**
 * \file Bomb.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the Bomb
 */

#include "pch.h"
#include "Bomb.h"

using namespace Gdiplus;

CBomb::CBomb(CGame* game) : CItem(game)
{
	mXInit = mX;
	mYInit = mY;
}

void CBomb::Update(double elapsed)
{
	if (mActive)
	{
		if (mDiameter < mDiameterMax)
		{
			mDiameter += elapsed * mFireRate;
			mX -= elapsed * mFireRate / 2.35;
			mY -= elapsed * mFireRate / 2.35;
		}
		else {
			mDiameter = mDiameterInitial;
			mX = mXInit;
			mY = mYInit;
			mActive = false;
		}
	}
}

void CBomb::Draw(Gdiplus::Graphics* graphics)
{
	SolidBrush brush(Color(128, 0, 0));
	graphics->FillEllipse(&brush, mX, mY, mDiameter, mDiameter);
}
