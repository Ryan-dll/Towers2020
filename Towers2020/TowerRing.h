/**
 * \file TowerRing.h
 *
 * \author Craig Smith
 *
 * Class that implements the TowerRing
 */

#pragma once
#include "Tower.h"
#include "Ring.h"

 /**
 * CTowerRing class
 */
class CTowerRing :
    public CTower
{
public:
	CTowerRing() = delete;

	CTowerRing(const CTowerRing&) = delete;

	/// Construct the Tower
	/// \param game Game context
	CTowerRing(CGame* game);

	/// Fire ring out of towers.
	virtual void Fire();

	/// Keeps the tower firing
	/// \param elapsed elapsed time chunk
	void Update(double elapsed);

	/// Arms the tower
	void ArmTower() override;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) {};

	/**
	 * Setter for X position
	 * \param xPos desired X position
	 */
	void setX(int xPos) { mX = xPos; ring->setX(xPos + 21); }

	/**
	 * Setter for Y position
	 * \param yPos desired Y position
	 */
	void setY(int yPos) { mY = yPos; ring->setY(yPos + 21);
	}

	/**
	* Setter for Y and X positions
	* \param yPos desired Y position
	* \param xPos desired X position
	*/
	void setCoordinates(int xPos, int yPos) { mX = xPos; mY = yPos; ring->setX(xPos + 21); ring->setY(yPos + 21);}

	/**
	* Get ring
	* \return the ring
	*/
	std::shared_ptr<CRing> getRing() { return ring; };

protected:
	/// Ring belonging to the tower
	std::shared_ptr<CRing> ring;

	/// Time it takes to reload a shot
	double mTimeBetween = 5;

	/// Used with elapse to calculate when to fire
	double mTimeUntilFire = 5;
};

