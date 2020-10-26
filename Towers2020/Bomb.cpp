/**
 * \file Bomb.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the Bomb
 */

#include "pch.h"
#include "TowerBomb.h"
#include "Bomb.h"
#include "BalloonCollector.h"
#include <vector>

using namespace Gdiplus;
using namespace std;

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
			// Find all balloons within the range of the ring
			CBalloonCollector bc;
			CItem::GetGame()->Accept(&bc);
			vector<CBalloon*> balloons = bc.GetBalloons();
			for (auto balloon : balloons)
			{
				double dx = (balloon->GetX() + 32) - GetX();
				double dy = GetY() - (balloon->GetY() + 32);
				double distance = sqrt((dx * dx) + (dy * dy));
				if (distance < mDiameter / 2)
				{
					CItem::GetGame()->TakeBalloon(balloon, 3);
				}
			}
		}
		else
		{
			mDiameter = mDiameterInitial;
			//mX = mXInit;
			//mY = mYInit;
			mActive = false;
		}
	}
}

void CBomb::Draw(Gdiplus::Graphics* graphics)
{
	SolidBrush brush(Color(128, 0, 0));
	graphics->FillEllipse(&brush, GetX() - (mDiameter / 2), GetY() - (mDiameter / 2), mDiameter, mDiameter);
}
