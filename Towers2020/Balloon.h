/**
 * \file Balloon.h
 *
 * \author Evan Masters
 *
 * Implements a Balloon
 */
#pragma once

#include "Item.h"
#include "ItemVisitor.h"

 /**
 * CBalloon class
 */
class CBalloon : public CItem
{
public:
	CBalloon() = delete;

	/**
	 * Copy constructor (disabled)
	 */
	CBalloon(const CBalloon&) = delete;

    /// Default Constructor
    /// \param game The game we belong to
    CBalloon(CGame* game);

    /** Accept a visitor 
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) { visitor->VisitBalloon(this); }
     
    /** 
    * Get the current T value for the balloon
    * \returns the T value
    */
    double GetT() { return mT; }

    /** 
    * Set the current T value for the balloon
    * \param t The t value to set
    */
    void SetT(double t) { mT = t; }

private:
    /// The inter tile pos 
    double mT = 0;

};

