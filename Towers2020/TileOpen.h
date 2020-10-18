/**
 * \file Open.h
 *
 * \author Craig Smith
 *
 * Class that implements the Open (grass)
 */

#pragma once
#include "Item.h"
#include "Tile.h"
#include "Game.h"

 /**
 * CTileOpen class
 */
class CTileOpen : public CTile
{
public:
    /// Default constructor (disabled)
    CTileOpen() = delete;

    /// Copy constructor (disabled)
    CTileOpen(const CTileOpen&) = delete;

    /// Constructor
    /// \param image Image for house
    CTileOpen(CGame * game, std::wstring image);

private:

    /// Image for house
    std::wstring mImage;
};

