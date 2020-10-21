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

	/// Accepts the Tower visitor
	virtual void Accept(CTowerVisitor* visitor);

	/// Overriden Fire Tower Function
	virtual void Fire() override;

private:
};

