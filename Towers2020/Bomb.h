/**
 * \file Bomb.h
 *
 * \author Craig Smith
 *
 * Class that implements the Bomb
 */

#pragma once
#include "Item.h"

 /// Class CBomb
class CBomb :
    public CItem
{
public:
	CBomb() = delete;

	CBomb(const CBomb&) = delete;

	/**
	 * CRing constructor
	 * \param game Pointer to the game which we belong
	 */
	CBomb(CGame* game);

	/// Fire the ring
	void Fire() { mActive = true; };

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed);

	/// Draw the image
	/// \param graphics Graphics context
	virtual void Draw(Gdiplus::Graphics* graphics);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) {};

	/**
	 * Setter for X position
	 * \param xPos desired X position
	 */
	void setX(int xPos) { mX = xPos; mXInit = xPos; }

	/**
	 * Setter for Y position
	 * \param yPos desired Y position
	 */
	void setY(int yPos) { mY = yPos; mYInit = yPos; }

	/**
	* Setter for Y and X positions
	* \param yPos desired Y position
	* \param xPos desired X position
	*/
	void setCoordinates(int yPos, int xPos) { this->mX = xPos; this->mY = yPos; mXInit = xPos; mYInit = yPos; }

	/**
	* Get current diameter of ring
	* \return diameter of ring
	*/
	int getRingDiameter() { return mDiameter; };

	/**
	* Is ring active
	* \return if active
	*/
	bool isActive() { return mActive; };

private:
	/// Current diameter of the ring
	int mDiameter = 0;

	/// Initial diameter of the ring (equal to radius * 2)
	double mDiameterInitial = 0;

	/// Maximum diameter of the ring when fired (equal to radius * 2)
	double mDiameterMax = 200;

	/// Rate of fire, in pixels per second
	double mFireRate = 800;

	/// If ring is currently being fired
	bool mActive = false;

	/// Initial X position of the ring, will be set back to this location after firing
	int mXInit = 0;

	/// Initial Y position of the ring, will be set back to this location after firing
	int mYInit = 0;
};

