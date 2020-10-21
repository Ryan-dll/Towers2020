#include "pch.h"
#include "RoadCollector.h"


using namespace std;

/** Visit a CTileRoad object 
 * \param road The road we are visiting */
void CRoadCollector::VisitTileRoad(CTileRoad *road) 
{
	mTiles.push_back(road);
}


