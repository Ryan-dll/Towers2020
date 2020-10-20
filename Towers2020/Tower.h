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
#include "ItemVisitor.h"

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

	/// Fire projectiles out of towers.
	virtual void Fire();

	/// Keeps the tower firing
	/// \param elapsed elapsed time chunk
	void Update(double elapsed);

    /** Accept a visitor 
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) = 0;

protected:
	/// Time in between firing rounds
	double mReloadTime = 10;

	/// List of projectile pointers in tower
	std::vector < std::shared_ptr<CProjectile> > mProjectiles;

	/// Time it takes to reload a shot
	double mTimeBetween = 5;

	/// Used with elapse to calculate when to fire
	double mTimeUntilFire = 5;
};

