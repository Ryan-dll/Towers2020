/**
 * \file TileTrees.h
 *
 * \author Craig Smith
 *
 * Class that implements the TileTrees
 */

#pragma once
#include "Tile.h"

 /**
 * CTileTrees class
 */
class CTileTrees :
    public CTile
{
public:
    /// Default constructor (disabled)
    CTileTrees() = delete;

    /// Copy constructor (disabled)
    CTileTrees(const CTileTrees&) = delete;

    /// Constructor
    CTileTrees(CGame * game, std::wstring image);

private:

    /// Image for trees
    std::wstring mImage;
};

