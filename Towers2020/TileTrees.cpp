/**
 * \file TileTrees.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the Trees
 */

#include "pch.h"
#include "TileTrees.h"
#include "Game.h"

using namespace std;

 /**
 * Consturctor for the TileTrees tile
 * \param game Pointer to the game
 * \param image Filename for the image
 */
CTileTrees::CTileTrees(CGame* game, std::wstring image) : CTile(game)
{
	mImage = image;
	wstring test = L"test.png";
	CItem::SetImage(image);
}
