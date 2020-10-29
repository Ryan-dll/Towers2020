/**
 * \file TowerBomb.h
 *
 * \author Craig Smith
 *
 * Class that implements the TowerBomb
 */

#pragma once
#include "Tower.h"
#include "Bomb.h"

/// Class CTowerBomb
class CTowerBomb :
    public CTower
{
public:
	CTowerBomb() = delete;

	CTowerBomb(const CTowerBomb&) = delete;

	/// Construct the Tower
	/// \param game Game context
	CTowerBomb(CGame* game);

	/// Fire bomb out of towers.
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
	void SetX(double xPos) override { CItem::SetX(xPos); mBomb->SetX(xPos + 21); }

	/**
	 * Setter for Y position
	 * \param yPos desired Y position
	 */
	void SetY(double yPos) override { CItem::SetY(yPos); mBomb->SetY(yPos + 21);	}

	/**
	* Setter for Y and X positions
	* \param yPos desired Y position
	* \param xPos desired X position
	*/
	void SetCoordinates(double xPos, double yPos) override { CItem::SetX(xPos); CItem::SetY(yPos); mBomb->SetX(xPos + 21); mBomb->SetY(yPos + 21); }

	/**
	* Get bomb
	* \return the bomb
	*/
	std::shared_ptr<CBomb> GetBomb() { return mBomb; };

	/**
	* Returns the time until bomb goes off, used as identifier to remove after exploding
	* \return time until fire
	*/
	int GetFireTime() { return mTimeUntilFire; };

	/// Draw the image
	virtual void Draw(Gdiplus::Graphics* graphics);

protected:
	/// Bomb belonging to the tower
	std::shared_ptr<CBomb> mBomb;

	/// Used with elapse to calculate when to fire
	double mTimeUntilFire = 3;

	/// If bomb has been exploded yet
	bool mBombUsed = false;
};

