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

 /**
 * CTower class
 */
class CTower : public CItem
{
public:
	CTower() = delete;

	CTower(const CTower&) = delete;
	
	/// Construct the Tower
	CTower(CGame* game);

	/// Determines if a location is valid for tower placement
	bool CanPlace();

	/// Arms the tower with X number of projectiles
	virtual void ArmTower() {};

protected:
	/// Time in between firing rounds
	double mReloadTime = 10;

	/// List of projectile pointers in tower
	std::vector < std::shared_ptr<CProjectile> > mProjectiles;
};

