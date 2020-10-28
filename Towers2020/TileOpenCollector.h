/**
 * \file TileOpenCollector.h
 *
 * \author Ryan Shore
 *
 * Collects open tiles
 */
#pragma once
#include "ItemVisitor.h"
#include <vector>
#include <memory>
#include "Tile.h"

 /**
 * CTileOpenCollector class
 */
class CTileOpenCollector : public CItemVisitor
{
public:
    /** Visit a CTileOpen object
     * \param tile The tile we are visiting */
    virtual void VisitTileOpen(CTileOpen* tile);

    /**
     * Return the tiles
     * \returns the tiles
     */
    std::vector<CTileOpen*>& GetTiles() { return mOpenTiles; }

private:
    /// The tiles
    std::vector<CTileOpen*> mOpenTiles;

};

