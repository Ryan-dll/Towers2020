/**
 * \file Open.h
 *
 * \author Craig Smith
 *
 * Class that implements the Open (grass)
 */

#include "pch.h"
#include "TileOpen.h"
#include "Game.h"

using namespace std;

CTileOpen::CTileOpen(CGame* game, wstring image) : CTile(game)
{
	// Load the open image
	wstring name = L"grass1.png";
	CItem::SetImage(name);
}
