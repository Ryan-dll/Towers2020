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
	
	CTowerEight() = delete;

	CTowerEight(const CTowerEight&) = delete;
	
	// Construct the TowerEight
	// \param game Pointer to the game to which we belong
	CTowerEight(CGame* game);

	/// Accepts the Tower visitor
	/// \param visitor Pointer to the visitor
	virtual void Accept(CTowerVisitor* visitor);

	/// Overridden Arm Tower Function
	virtual void ArmTower() override;

private:
};

