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
	wstring name = L"grass1.png";
	CItem::SetImage(image);
}