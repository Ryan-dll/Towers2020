/**
 * \file TowerVisitor.h
 *
 * \author RyanShore
 *
 * Visitor Class for Towers
 */

#pragma once

class CTowerEight;

/**
* CTowerVisitor class
*/
class CTowerVisitor
{
public:
	/// Destructor
	virtual ~CTowerVisitor() {}
	/// Visits Tower8
	/// /param tower pointer to Tower8 tower
	virtual void VisitTowerEight(CTowerEight* tower) {}
};
