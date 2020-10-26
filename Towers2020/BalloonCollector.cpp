#include "pch.h"
#include "BalloonCollector.h"

/** Visit a CBalloon object 
* \param balloon The balloon we are visiting */
void CBalloonCollector::VisitBalloon(CBalloon* balloon)
{
	mBalloons.push_back(balloon);
}

