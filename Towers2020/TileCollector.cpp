/**
 * \file TileCollector.cpp
 *
 * \author Evan Masters
 *
 * Collects all items that are tiles
 */

#include "pch.h"
#include "TileCollector.h"

using namespace std;

/** Visit a CTileHouse object 
 * \param house The house we are visiting */
void CTileCollector::VisitTileHouse(CTileHouse *house) 
{
	mTiles.push_back((CTile *)house);
}

/** Visit a CTileOpen object 
 * \param open The open we are visiting */
void CTileCollector::VisitTileOpen(CTileOpen *open) 
{
	mTiles.push_back((CTile *)open);
}

/** Visit a CTileRoad object 
 * \param road The road we are visiting */
void CTileCollector::VisitTileRoad(CTileRoad *road) 
{
	mTiles.push_back((CTile *)road);
}

/** Visit a CTileTrees object 
 * \param trees The trees we are visiting */
void CTileCollector::VisitTileTrees(CTileTrees *trees) 
{
	mTiles.push_back((CTile *)trees);
}
