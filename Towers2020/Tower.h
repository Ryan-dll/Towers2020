/**
 * \file Tower.h
 *
 * \author RyanShore
 *
 * General Class for towers
 */

#pragma once
#include "Item.h"
#include "Projectile.h"
#include <vector>
#include <memory>

class CTower : public CItem
{
public:
	/// Determines if a location is valid for tower placement
	/// /returns true if location is valid
	bool CanPlace();

	/// Arms the tower with X number of projectiles
	virtual void ArmTower() {};

protected:
	/// Time in between firing rounds
	double mReloadTime = 10;

	/// List of projectile pointers in tower
	std::vector < std::shared_ptr<CProjectile> > mProjectiles;
};

