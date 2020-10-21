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
	void Draw(Gdiplus::Graphics* graphics) override;

	/// Moves the dart
	/// \param elapsed elapsed time chunk
	void Update(double elapsed);

	/// Getter for Angle
	/// \return Angle of projectile
	double GetAngle() { return mRotation; }

	/// Getter for Active
	/// \return Projectile status
	bool GetActive() { return mActive; }

	/// Setter for Angle
	/// \param Angle of projectile
	void SetAngle(double Angle) { mRotation = Angle; }

	/// Setter for Active
	/// \param set Sets Projectile status
	void SetActive(bool set) { mActive = set; }

	/// Setter for original X and Y Locations
	/// \param y desired Y position
	/// \param x desired X position
	void SetOrigin(double x, double y) { mOriginX = x; mOriginY = y; }

	/// Resets Projectile Position and Disables it
	void ResetDart();

protected:
	/// Speed of projectile
	double mSpeed = 100;

	/// Rotation of Projectile
	double mRotation = 0;
	
	/// Is this currently being used?
	bool mActive = false;

	/// X axis location upon being created
	double mOriginX = 0;

	/// Y axis locaion upon being created
	double mOriginY = 0;

};


