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

	/**
	 * Copy constructor (disabled)
	 */
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
	virtual void Accept(CItemVisitor* visitor) { visitor->VisitTowerRing(this); };

	/**
	 * Setter for X position
	 * \param xPos desired X position
	 */
	virtual void SetX(double xPos) override { CItem::SetX(xPos); mRing->SetX(xPos + 32.5); }

	/**
	 * Setter for Y position
	 * \param yPos desired Y position
	 */
	virtual void SetY(double yPos) override { CItem::SetY(yPos); mRing->SetY(yPos + 32.5);
	}

	/**
	* Setter for Y and X positions
	* \param yPos desired Y position
	* \param xPos desired X position
	*/
	virtual void SetCoordinates(double xPos, double yPos) override { SetX(xPos); SetY(yPos); mRing->SetX(xPos + 32.5); mRing->SetY(yPos + 32.5);}

	/**
	* Get ring
	* \return the ring
	*/
	std::shared_ptr<CRing> getRing() { return mRing; };

protected:
	/// Ring belonging to the tower
	std::shared_ptr<CRing> mRing;

	/// Time it takes to reload a shot
	double mTimeBetween = 5;

	/// Used with elapse to calculate when to fire
	double mTimeUntilFire = 5;
};

