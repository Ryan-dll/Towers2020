/**
 * \file House.h
 *
 * \author Craig Smith
 *
 * Class that implements the House
 */

#include "pch.h"
#include "TileHouse.h"

using namespace std;

//CHouse::CHouse()
//{
//	mImage = image;
//}

CTileHouse::CTileHouse(CGame* game, wstring image) : CTile(game)
{
	// Load the correct house from file given the image
	CTile::SetImage(image);
}
