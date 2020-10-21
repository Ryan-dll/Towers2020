/**
 * \file TileRoad.h
 *
 * \author Craig Smith
 *
 * Class that implements the Road
 */

#pragma once
#include "Tile.h"
#include "ItemVisitor.h"

 /**
 * CRoad class
 */
class CTileRoad : public CTile
{
public:

    /// Default constructor (disabled)
    CTileRoad() = delete;

    /// Copy constructor (disabled)
    CTileRoad(const CTileRoad&) = delete;

    CTileRoad(CGame *game, std::wstring image, std::wstring type);
    
    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) override { visitor->VisitTileRoad(this); }

protected:
    /// Image for road
    std::wstring mImage;

    /// Type of house
    std::wstring mType;
};

