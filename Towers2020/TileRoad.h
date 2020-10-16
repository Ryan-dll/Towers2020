/**
 * \file Road.h
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
class CRoad :
    public CTile
{
public:
    /// Default constructor (disabled)
    CRoad() = delete;

    /// Copy constructor (disabled)
    CRoad(const CRoad&) = delete;

    CRoad(std::wstring image, std::wstring type);

protected:
    /// Image for road
    std::wstring mImage;

    /// Type of house
    std::wstring mType;
};

