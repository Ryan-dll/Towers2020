/**
 * \file Trees.h
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
 * Trees constructor
 */
CTileTrees::CTileTrees(CGame* game, wstring image) : CTile(game)
{
	mImage = image;
	wstring test = L"Images/test.png";
	CItem::SetImage(test);
}
