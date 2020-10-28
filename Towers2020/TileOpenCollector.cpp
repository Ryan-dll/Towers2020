/**
 * \file TileOpenCollector.cpp
 *
 * \author Ryan Shore
 */

#include "pch.h"
#include "TileOpenCollector.h"

using namespace std;

void CTileOpenCollector::VisitTileOpen(CTileOpen* tile)
{
	mOpenTiles.push_back(tile);
}