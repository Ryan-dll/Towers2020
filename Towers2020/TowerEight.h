/**
 * \file TowerEight.h
 *
 * \author RyanShore
 *
 * Tower that shoots 8 projectiles at once in a circle
 */

#pragma once
#include "Tower.h"
#include <memory>
#include "Game.h"

/**
 * CTowerVisitor class instantiation
 */
class CTowerVisitor;

/**
* CTowerEight class
*/
class CTowerEight : public CTower
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

	/// Overridden Arm Tower Function
	virtual void ArmTower() override;

	/// Overriden Fire Tower Function
	virtual void Fire() override;

private:
};

