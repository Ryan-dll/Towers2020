/**
 * \file RoadCollector.h
 *
 * \author Evan Masters
 *
 * Collects roads
 */
#pragma once
#include "ItemVisitor.h"
#include <vector>
#include <memory>
#include "Tile.h"

 /**
 * CRoadCollector class
 */
class CRoadCollector : public CItemVisitor
{
public:
	/** Visit a CTileRoad object 
     * \param road The road we are visiting */
    virtual void VisitTileRoad(CTileRoad *road);

	/** 
     * Return the tiles
     * \returns the tiles
     */
    std::vector<CTileRoad *>& GetTiles() { return mTiles; }

private:
    /// The tiles
	std::vector<CTileRoad *> mTiles;

};

