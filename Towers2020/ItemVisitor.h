/**
 * \file ItemVisitor.h
 *
 * \author Evan Masters
 *
 * Item visitor base class
 */

#pragma once
#include "Game.h"

class CTileHouse;
class CTileOpen;
class CTileRoad;
class CTileTrees;
class CTowerEight;
//class CTowerRing;
//class CTowerCross;
//class CTowerBomb


/**
 * Item visitor base class
 */
class CItemVisitor
{
public:
	virtual ~CItemVisitor() {}
	
	/** Visit a CTileHouse object 
     * \param house The house we are visiting */
    virtual void VisitTileHouse(CTileHouse *house) {}

	/** Visit a CTileOpen object 
     * \param open The open we are visiting */
    virtual void VisitTileOpen(CTileOpen *open) {}

	/** Visit a CTileRoad object 
     * \param road The road we are visiting */
    virtual void VisitTileRoad(CTileRoad *road) {}

	/** Visit a CTileTrees object 
     * \param trees The trees we are visiting */
    virtual void VisitTileTrees(CTileTrees *trees) {}

	/** Visit a CTowerEight object 
     * \param towereight The towereight we are visiting */
    virtual void VisitTowerEight(CTowerEight *towereight) {}
    
	/** Visit a CTowerCross object 
     * \param towercross The towercross we are visiting */
    //virtual void VisitTowerCross(CTowerCross *towercross) {}

	/** Visit a CTowerRing object 
     * \param towerring The towerring we are visiting */
    //virtual void VisitTowerRing(CTowerRing *towerring) {}

	/** Visit a CTowerBomb object 
     * \param towerbomb The towerbomb we are visiting */
    //virtual void VisitTowerBomb(CTowerBomb *towerbomb) {}
};

