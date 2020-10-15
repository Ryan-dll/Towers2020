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

class CProjectile : public CItem
{
public:

protected:
	/// Speed of projectile
	double mSpeed = 10;

	/// Rotation of Projectile
	double mRotation = 90;

	/// Pointer to Projectile
	std::unique_ptr<Gdiplus::Bitmap> mProjectileImage;
};


