#pragma once
#include "ItemVisitor.h"
#include <vector>
#include <memory>

class CTower;

class CTowerCollector : public CItemVisitor
{

public:
	/** Visit a CTowerBomb object 
     * \param bomb The road we are visiting */
    virtual void VisitTowerBomb(CTowerBomb *bomb);

	/** Visit a CTowerRing object 
     * \param ring The ring we are visiting */
    virtual void VisitTowerRing(CTowerRing *ring);

	/** Visit a CTowerEight object 
     * \param eight The eight we are visiting */
    virtual void VisitTowerEight(CTowerEight *eight);

	/** Visit a CTowerCross object 
     * \param cross The cross we are visiting */
    virtual void VisitTowerCross(CTowerCross *cross);

	/** 
     * Return the towers
     * \returns the towers
     */
    std::vector<CTower *>& GetTowers() { return mTowers; }

private:
    /// The towers
	std::vector<CTower *> mTowers;
};

