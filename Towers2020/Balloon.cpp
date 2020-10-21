/**
 * \file Balloon.cpp
 *
 * \author Evan Masters
 *
 * Implements a Balloon
 */
#include "pch.h"
#include "Balloon.h"

using namespace std;


/**
 * Consturctor for the Balloon
 * \param game Pointer to the game
 */
CBalloon::CBalloon(CGame* game) : CItem(game)
{
	// Load the open image
	wstring name = L"red-balloon.png";
	CItem::SetImage(name);
}
