/**
 * \file TileHouse.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the House
 */

#include "pch.h"
#include "TileHouse.h"

using namespace std;

/**
 * Constructor for CTileHouse
 * \param game Pointer to the game object
 * \param image Filename for the image
 */
CTileHouse::CTileHouse(CGame* game, std::wstring image) : CTile(game)
{
	// Load the correct house from file given the image
	CTile::SetImage(image);
}
