/**
 * \file Trees.h
 *
 * \author Craig Smith
 *
 * Class that implements the Trees
 */

#pragma once
#include "Item.h"

 /**
 * CTrees class
 */
class CTrees :
    public CItem
{
public:
    /// Default constructor (disabled)
    CTrees() = delete;

    /// Copy constructor (disabled)
    CTrees(const CTrees&) = delete;

    /// Constructor
    /// \param image Image for trees
    CTrees(std::wstring image);

private:

    /// Image for trees
    std::wstring mImage;
};

