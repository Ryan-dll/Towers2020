/**
 * \file TileRoad.h
 *
 * \author Craig Smith
 *
 * Class that implements the Road
 */

#pragma once
#include "Tile.h"

 /**
 * CRoad class
 */
class CTileRoad :
    public CTile
{
public:

    /// Default constructor (disabled)
    CTileRoad() = delete;

    /// Copy constructor (disabled)
    CTileRoad(const CTileRoad&) = delete;

    CTileRoad(CGame *game, std::wstring image, std::wstring type);

protected:
    /// Image for road
    std::wstring mImage;

    /// Type of house
    std::wstring mType;
};

