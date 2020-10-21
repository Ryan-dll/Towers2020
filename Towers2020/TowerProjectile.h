/**
 * \file TowerProjectile.h
 *
 * \author RyanShore
 *
 * Intermediate class for all towers using darts
 */

#pragma once
#include "Tower.h"
#include <memory>
#include "Game.h"

/**
* CTowerProjectile class
*/
class CTowerProjectile : public CTower
{
public:
	/// Delete Default Constructor
	CTowerProjectile() = delete;

	/// Delete Default Clone
	CTowerProjectile(const CTowerProjectile&) = delete;

	/// Construct the TowerProjectile
	CTowerProjectile(CGame* game);

	/// Arms the tower with X number of projectiles
	virtual void ArmTower();

protected:
	/// List of projectile pointers in tower
	std::vector < std::shared_ptr<CProjectile> > mProjectiles;

};

