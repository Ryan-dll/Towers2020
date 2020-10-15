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

class CTowerVisitor;

class CTowerEight : public CTower
{
public:
	/// Accepts the Tower visitor
	/// /param Pointer to the visitor
	virtual void Accept(CTowerVisitor* visitor);

	/// Overridden Arm Tower Function
	virtual void ArmTower() override;

private:
};

