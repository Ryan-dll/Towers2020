/**
 * \file BalloonCollector.h
 *
 * \author Evan Masters
 *
 * Collects the Balloons
 */
#pragma once
#include "ItemVisitor.h"
#include <vector>
#include <memory>

class CBalloon;

/**
 * Collects the Balloons
 */
class CBalloonCollector : public CItemVisitor
{
public:
	/// Visit a CBalloon object 
    virtual void VisitBalloon(CBalloon *balloon);

	/** 
     * Return the balloons
     * \returns the balloons
     */
    std::vector<CBalloon *>& GetBalloons() { return mBalloons; }

private:
    /// The balloons
	std::vector<CBalloon *> mBalloons;
};

