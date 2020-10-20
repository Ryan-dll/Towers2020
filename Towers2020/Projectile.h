/**
 * \file Projectile.h
 *
 * \author RyanShore
 *
 * Implements a Projectile
 */

#pragma once
#include <memory>
#include "Item.h"
#include "ItemVisitor.h"

 /**
 * CProjectile class
 */
class CProjectile : 
	public CItem
{
public:
	/// Construct the Projectile
	CProjectile(CGame* game);

	/// Draw the Projectile
	void Draw(Gdiplus::Graphics* graphics, int offsetX, int offsetY);

	/// Moves the dart
	/// \param elapsed elapsed time chunk
	void Update(double elapsed);

	/// Getter for Angle
	/// \return Angle of projectile
	double GetAngle() { return mRotation; }

	 /** Accept a visitor (not really)
     * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) {};
	

protected:
	/// Speed of projectile
	double mSpeed = 10;

	/// Rotation of Projectile
	double mRotation = 0;

	/// Pointer to Projectile
	std::unique_ptr<Gdiplus::Bitmap> mProjectileImage;

	/// Distance from tower
	double mT = 0;
};


