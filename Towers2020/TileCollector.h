/**
 * \file TileCollector.cpp
 *
 * \author Evan Masters
 *
 * Collects all items that are tiles
 */
#pragma once
#include "ItemVisitor.h"
#include <vector>
#include <memory>
#include "Tile.h"


/**
 * CTileCollector class
 */
class CTileCollector : public CItemVisitor
{
public:
	/** Visit a CTileHouse object 
     * \param house The house we are visiting */
    virtual void VisitTileHouse(CTileHouse *house);

	/** Visit a CTileOpen object 
     * \param open The open we are visiting */
    virtual void VisitTileOpen(CTileOpen *open);

	/** Visit a CTileRoad object 
     * \param road The road we are visiting */
    virtual void VisitTileRoad(CTileRoad *road);

	/** Visit a CTileTrees object 
     * \param trees The trees we are visiting */
    virtual void VisitTileTrees(CTileTrees *trees);
     
	/** 
     * Return the tiles
     * \returns the tiles
     */
    std::vector<CTile *>& GetTiles() { return mTiles; }

private:
    /// Collection of the tiles
	std::vector<CTile *> mTiles;

};

