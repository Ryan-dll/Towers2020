/**
 * \file Tower.h
 *
 * \author RyanShore
 *
 * General Class for towers
 */

#include "pch.h"
#include "Tower.h"
#include <stdlib.h>
#include <iostream>

/**
 * Constructor for CTower
 * \param game Pointer to the game object
 */
CTower::CTower(CGame * game) : CItem(game)
{
}

/**
 * Updates Tower in elapsed intervals
 */
void CTower::Update(double elapsed)
{
    mTimeUntilFire -= elapsed;
    if (mTimeUntilFire <= 0)
    {
        mTimeUntilFire += mTimeBetween;
        Fire();
    }
}

/**
 * Save item to xml file
 * \param node Xmlnode
 * \returns Xmlnode
*/
std::shared_ptr<xmlnode::CXmlNode> CTower::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    return std::shared_ptr<xmlnode::CXmlNode>();
}
