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
	mXInit = GetX();
	mYInit = GetY();
}

void CBomb::Update(double elapsed)
{
	if (mActive)
	{
		if (mDiameter < mDiameterMax)
		{
			mDiameter += elapsed * mFireRate;
			SetX(GetX() - elapsed * mFireRate / 2.35);
			SetY(GetY() - elapsed * mFireRate / 2.35);
		}
		else {
			mDiameter = mDiameterInitial;
			SetX(mXInit);
			SetY(mYInit);
			mActive = false;
		}
	}
}

void CBomb::Draw(Gdiplus::Graphics* graphics)
{
	SolidBrush brush(Color(128, 0, 0));
	graphics->FillEllipse(&brush, GetX(), GetY(), mDiameter, mDiameter);
}
