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
	void setX(int xPos) { mX = xPos; bomb->setX(xPos + 21); }

	/**
	 * Setter for Y position
	 * \param yPos desired Y position
	 */
	void setY(int yPos) {
		mY = yPos; bomb->setY(yPos + 21);
	}

	/**
	* Setter for Y and X positions
	* \param yPos desired Y position
	* \param xPos desired X position
	*/
	void setCoordinates(int xPos, int yPos) { mX = xPos; mY = yPos; bomb->setX(xPos + 21); bomb->setY(yPos + 21); }

	/**
	* Get bomb
	* \return the bomb
	*/
	std::shared_ptr<CBomb> getBomb() { return bomb; };

	/**
	* Returns the time until bomb goes off, used as identifier to remove after exploding
	* \return time until fire
	*/
	int getFireTime() { return mTimeUntilFire; };

	/// Draw the image
	virtual void Draw(Gdiplus::Graphics* graphics);

protected:
	/// Bomb belonging to the tower
	std::shared_ptr<CBomb> bomb;

	/// Used with elapse to calculate when to fire
	double mTimeUntilFire = 3;

	/// If bomb has been exploded yet
	bool bombUsed = false;
};

