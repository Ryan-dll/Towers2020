/**
 * \file TileRoad.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the Road
 */

#include "pch.h"
#include "TileRoad.h"
#include "Game.h"

using namespace std;

/**
* Consturctor for Road
* \param game poiner to the CGame class we were created in
* \param image The image for the road object
* \param type The type (direction) of road
*/
CTileRoad::CTileRoad(CGame * game, std::wstring image, std::wstring type) : CTile(game)
{
	mImage = image;
	mType = type;
	CItem::SetImage(image);
}

/// Handle updates for animation
///\param elapsed The time since the last update
void CTileRoad::Update(double elapsed)
{
	vector<shared_ptr<CBalloon>> toDelete;
	// For each balloon we own, move
	for (auto balloon : mBalloons)
	{
		auto t = balloon->GetT();
		t += 2 * elapsed;
		if (t > 1)
		{
			// For now reset T to 0, but later we will
			// pass the balloon to the next tile
			toDelete.push_back(balloon);

			if (mNext != nullptr)
			{
				mNext->GiveBalloon(balloon);
			}
			t -= 1;
			balloon->SetT(t);
		}
		else
		{
			balloon->SetT(t);
			Place(balloon);
		}
	}
	for (auto item : toDelete)
	{
		mBalloons.erase(std::remove(mBalloons.begin(), mBalloons.end(), item));
	}
}

/**
* Place the balloon given a t value
* \param balloon The balloon to place
*/
void CTileRoad::Place(shared_ptr<CBalloon> balloon)
{
	auto t = balloon->GetT();
	auto x = GetX() + 32;
	auto y = GetY() + 32;
	if (t < 0.5)
	{
		// First half of tile
		// Coming in from side mIn
		if (mIn == L"N")
		{
			y = GetY() + t * 64;
		} 
		else if (mIn == L"S")
		{
			y = GetY() + 64 + (-t * 64);
		}
		else if (mIn == L"W")
		{
			x = GetX() + t * 64;
		}
		else if (mIn == L"E")
		{
			x = GetX() + 64 + (-t * 64);
		}
		balloon->setX(x - 32);
		balloon->setY(y - 32);
	}
	else
	{
		// Second half of tile
		// Going out to side mOut
		if (mOut == L"N")
		{
			y = GetY() + 64 + (-t * 64);
		} 
		else if (mOut == L"S")
		{
			y = GetY() + t * 64;
		}
		else if (mOut == L"W")
		{
			x = GetX() + 64 + (-t * 64);
		}
		else if (mOut == L"E")
		{
			x = GetX() + t * 64;
		}
		balloon->setX(x - 32);
		balloon->setY(y - 32);
	}
}
