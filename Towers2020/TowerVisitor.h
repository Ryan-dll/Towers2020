/**
 * \file TowerVisitor.h
 *
 * \author RyanShore
 *
 * Visitor Class for Towers
 */

#pragma once

class CTowerEight;

class CTowerVisitor
{
public:
	/// Destructor
	virtual ~CTowerVisitor() {}
	/// Visits Tower8
	/// /param pointer to Tower8 tower
	virtual void VisitTowerEight(CTowerEight* tower) {}
};
