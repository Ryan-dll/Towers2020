/**
 * \file TowerCross.h
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
* CTowerCross class
*/
class CTowerCross : public CTowerProjectile
{
public:
	/// Delete Default Constructor
	CTowerCross() = delete;

	/// Delete Default Clone
	CTowerCross(const CTowerCross&) = delete;

	/// Construct the TowerCross
	CTowerCross(CGame* game);

	/// Accepts the Tower visitor
	virtual void Accept(CTowerVisitor* visitor);

	/// Overriden Fire Tower Function
	virtual void Fire() override;

private:

	/// Determines which darts fire
	bool mCrossPattern = true;
};

