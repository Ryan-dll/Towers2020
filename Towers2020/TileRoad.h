/**
 * \file TileRoad.h
 *
 * \author Craig Smith
 *
 * Class that implements the Road
 */

#pragma once
#include "pch.h"
#include "Tile.h"
#include "Balloon.h"
#include "ItemVisitor.h"
#include <vector>

//class CItemVisitor;
 /**
 * CRoad class
 */
class CTileRoad : public CTile
{
public:

    /// Default constructor (disabled)
    CTileRoad() = delete;

    /// Copy constructor (disabled)
    CTileRoad(const CTileRoad&) = delete;

    CTileRoad(CGame *game, std::wstring image, std::wstring type);
    
    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) override { visitor->VisitTileRoad(this); }

    /**
     * Return the type of the road
     * \returns type of the road
     */
    std::wstring GetType() { return mType; }

    /**
     * Set the next road in the path
     * \param next The next tile in the road
     */
    void SetNext(CTileRoad* next) { mNext = next; }

    /**
     * Set the directions the balloons come from
     * \param in The incoming direction
     */
    void SetIn(std::wstring in) { mIn = in; }

    /**
     * Set the direction the balloons go to
     * \param out The outgoing direction
     */
    void SetOut(std::wstring out) { mOut = out; }
    
    /**
     * Get the direction the ballon comes from
     * \returns the direction
     */
    std::wstring GetIn() { return mIn; }

    /**
     * Give balloon to this road
     * \param balloon The balloon being givn
     */
    void GiveBalloon(std::shared_ptr<CBalloon> balloon) { mBalloons.push_back(balloon); }

	/** Handle updates for animation
	 * \param elapsed The time since the last update
     */
    void Update(double elapsed);

    /// Place a balloon in the XY coordinate space using t
    void Place(std::shared_ptr<CBalloon> balloon);


    /**
     * Get the next road after this one
     * \returns the next road
     */
    CTileRoad* GetNext() { return mNext; }

    /**
     * Get the number of balloons on this road
     * \returns the number of balloons
     */
    int NumBalloons() { return mBalloons.size(); }

    /// Save TileOpen to xml
    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

protected:

    /// Type of road
    std::wstring mType;

    /// Next road, nullptr if last
    CTileRoad* mNext = nullptr;

    /// The direction balloons will come in from
    std::wstring mIn;
   
    /// The direction balloons will leave from
    std::wstring mOut;

    /// Pointers to the balloons that are currently on our tile
    std::vector<std::shared_ptr<CBalloon>> mBalloons;
};

