/**
 * \file TowerEight.h
 *
 * \author RyanShore
 *
 * Tower that shoots 8 projectiles at once in a circle
 */

#pragma once
#include "TowerProjectile.h"
#include <memory>
#include "Game.h"
#include "ItemVisitor.h"

/**
 * CTowerVisitor class instantiation
 */
class CTowerVisitor;

/**
* CTowerEight class
*/
class CTowerEight : public CTowerProjectile
{
public:
	/// Delete Default Constructor
	CTowerEight() = delete;

	/// Delete Default Clone
	CTowerEight(const CTowerEight&) = delete;
	
	/// Construct the TowerEight
	CTowerEight(CGame* game);

	/// Overriden Fire Tower Function
	virtual void Fire() override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) override { visitor->VisitTowerEight(this); }

private:
};

