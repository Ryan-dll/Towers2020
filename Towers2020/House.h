/**
 * \file House.h
 *
 * \author Craig Smith
 *
 * Class that implements the House
 */

#pragma once
#include "Item.h"

 /**
 * CHouse class
 */
class CHouse :
    public CItem
{
public:
    /// Default constructor (disabled)
    CHouse() = delete;

    /// Copy constructor (disabled)
    CHouse(const CHouse&) = delete;

    /// Constructor
    /// \param image Image for house
    CHouse(std::wstring image);

private:
    /// Image for house
    std::wstring mImage;
};

