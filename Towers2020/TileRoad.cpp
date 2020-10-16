/**
 * \file Game.h
 *
 * \author Craig Smith
 *
 * Class that implements the Road
 */

#include "pch.h"
#include "TileRoad.h"

/**
* Consturctor for Road
* \param image The image for the road object
* \param type The type (direction) of road
*/
CRoad::CRoad(std::wstring image, std::wstring type)
{
	mImage = image;
	mType = type;
}