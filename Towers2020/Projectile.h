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

 /**
 * CProjectile class
 */
class CProjectile : 
	public CItem
{
public:
	/// Construct the Projectile
	CProjectile(CGame* game);

	void Draw(Gdiplus::Graphics* graphics, int offsetX, int offsetY);

protected:
	/// Speed of projectile
	double mSpeed = 10;

	/// Rotation of Projectile
	double mRotation = 90;

	/// Pointer to Projectile
	std::unique_ptr<Gdiplus::Bitmap> mProjectileImage;

	/// Distance from tower
	double mT = 10;
};


