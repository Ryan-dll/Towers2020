/**
 * \file TileOpen.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the Open (grass)
 */

#include "pch.h"
#include "TileOpen.h"
#include "Game.h"

using namespace std;

/**
 * Consturctor for the Open tile
 * \param game Pointer to the game
 * \param image Filename for the image
 */
CTileOpen::CTileOpen(CGame* game, std::wstring image) : CTile(game)
{
	// Load the open image
	CItem::SetImage(image);
}
