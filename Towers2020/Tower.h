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
	/// Delete default destructor
	CTower() = delete;

	/// Delete default Copy
	CTower(const CTower&) = delete;
	
	/// Construct the Tower
	CTower(CGame* game);

	/// Fire projectiles out of towers.
	virtual void Fire() {};

	/// Keeps the tower firing
	/// \param elapsed elapsed time chunk
	virtual void Update(double elapsed);

    /** Accept a visitor 
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) = 0;

	/// Used to calc distance between previous points
	/// \return Difference in X coordinates
	double XDifference() { return GetX() - mLastX; }

	/// Used to calc distance between previous points
	/// \return Difference in X coordinates
	double YDifference() { return GetY() - mLastY; }

	/// Arms the tower with X number of projectiles
	virtual void ArmTower() {};

	/// Save item to xml file
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

protected:
	/// Time it takes to reload a shot
	double mTimeBetween = 5;

	/// Used with elapse to calculate when to fire
	double mTimeUntilFire = 5;

	/// Distance from tower
	double mT = 20;

	/// Last location in X direction
	double mLastX = 0;

	/// Last location in Y direction
	double mLastY = 0;
};

