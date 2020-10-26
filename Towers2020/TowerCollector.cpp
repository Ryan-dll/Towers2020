/**
 * \file TowerCollector.cpp
 *
 * \author Evan Masters
 */

#include "pch.h"
#include "TowerCollector.h"


/** Visit a CTowerBomb object 
 * \param bomb The road we are visiting */
void CTowerCollector::VisitTowerBomb(CTowerBomb* bomb)
{
	mTowers.push_back((CTower*)bomb);
}

/** Visit a CTowerRing object 
 * \param ring The ring we are visiting */
void CTowerCollector::VisitTowerRing(CTowerRing* ring)
{
	mTowers.push_back((CTower*)ring);
}

/** Visit a CTowerEight object 
 * \param eight The eight we are visiting */
void CTowerCollector::VisitTowerEight(CTowerEight* eight)
{
	mTowers.push_back((CTower*)eight);
}

/** Visit a CTowerCross object 
 * \param cross The cross we are visiting */
void CTowerCollector::VisitTowerCross(CTowerCross* cross)
{
	mTowers.push_back((CTower*)cross);
}
