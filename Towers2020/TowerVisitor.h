/**
 * \file TowerVisitor.h
 *
 * \author RyanShore
 *
 * Visitor Class for Towers
 */

#pragma once

class CTowerEight;
class CTowerCross;

/**
* CTowerVisitor class
*/
class CTowerVisitor
{
public:
	/// Destructor
	virtual ~CTowerVisitor() {}
	/// Visits Tower8
	/// \param tower pointer to Tower8 tower
	virtual void VisitTowerEight(CTowerEight* tower) {}
	/// Visits TowerCross
	/// \param tower pointer to TowerCross tower
	virtual void VisitTowerCross(CTowerCross* tower) {}
};
