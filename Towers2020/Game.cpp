/**
 * \file Game.h
 *
 * \author Craig Smith
 *
 * Class that implements the Game
 */

#include "pch.h"
#include "Game.h"
#include <memory>
#include "XmlNode.h"
#include "Item.h"
#include "TileRoad.h"
#include "TileHouse.h"
#include "TileTrees.h"
#include "TileOpen.h"
#include "TowerEight.h"
#include <iostream>
#include <map>
#include "Dashboard.h"
#include "TileCollector.h"
#include "RoadCollector.h"
#include "TowerCollector.h"
#include "TileOpenCollector.h"
#include "Balloon.h"
#include "Ring.h"
#include "TowerRing.h"
#include "TowerCross.h"
#include "TowerBomb.h"

using namespace std;
using namespace xmlnode;
using namespace Gdiplus;

/// This multi dimentional map holds information defined in XML declarations for when
/// the objects are later created
map<wstring, map<wstring, wstring>> declarations;

std::unique_ptr<Gdiplus::Bitmap> image;


/**
 * Constructor
 */
CGame::CGame()
{
    LoadImages();
    mDashboard = make_unique<CDashboard>(this);
    mGrabbedItem = nullptr;
}

/**
 * Destructor
 */
CGame::~CGame()
{
    mStart = nullptr;
    mGrabbedItem = nullptr;
    mAllGameItems.clear();
    mImageFiles.clear();
}

/**
 * Load the game from XML file.
 *
 * \param filename The filename of the file to load the game from.
 */
void CGame::Load(const std::wstring& filename)
{
    // TODO: Load clears the playing area
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

        // Clear the current level
        Clear();

        // Get root info
        if (root->GetName() == L"level")
        {
            mHeight = root->GetAttributeIntValue(L"height", 0);
            mWidth = root->GetAttributeIntValue(L"width", 0);
            mStartX = root->GetAttributeIntValue(L"start-x", 0);
            mStartY = root->GetAttributeIntValue(L"start-y", 0);
        }

        // Traverse the children of the root
        for (auto node : root->GetChildren())
        {

            if (node->GetName() == L"declarations")
            {
                for (auto subNode : node->GetChildren()) {
                    declarations[subNode->GetAttributeValue(L"id", L"")][L"image"] = subNode->GetAttributeValue(L"image", L"");
                    declarations[subNode->GetAttributeValue(L"id", L"")][L"type"] = subNode->GetAttributeValue(L"type", L"");
                }
            }

            if (node->GetName() == L"items")
            {
                for (auto subNode : node->GetChildren()) {
                    XmlItem(subNode);
                }
            }
        }

        std::cout << "Level Loaded!";

    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }

    // This will eventually need to move to the load menu function
    SetupPath();
}

/**
* Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CGame::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    // A pointer for the item we are loading
    shared_ptr<CItem> item;

    // We have an item. What type?
    //wstring type = node->GetAttributeValue(L"type", L"");
    wstring type = node->GetName();

    // Get declaration values, if they exist. We'll pass them to the constructor if appropriate.
    auto image_dec = declarations[node->GetAttributeValue(L"id", L"")][L"image"];
    auto type_dec = declarations[node->GetAttributeValue(L"id", L"")][L"type"];

    if (type == L"road")
    {
        item = make_shared<CTileRoad>(this, image_dec, type_dec);
    }
    else if (type == L"open")
    {
        item = make_shared<CTileOpen>(this, image_dec);
    }
    else if (type == L"house")
    {
        item = make_shared<CTileHouse>(this, image_dec);
    }
    else if (type == L"trees")
    {
        item = make_shared<CTileTrees>(this, image_dec);
    }

    if (item != nullptr)
    {
        item->XmlLoad(node);

        // Add item to the All Items array.
        Add(item);
    }
}

/**
 * Draw the game area
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
    // Fill the background with black
    SolidBrush brush(Color::Black);
    graphics->FillRectangle(&brush, 0, 0, width, height);

    //
    // Automatic Scaling
    //
    float scaleX = float(width) / float(mWidthVp);
    float scaleY = float(height) / float(mHeightVp);
    mScale = min(scaleX, scaleY);

    // Ensure it is centered horizontally
    mXOffset = (float)((width - CGame::mWidthVp * mScale) / 2);

    // Ensure it is centered vertically
    mYOffset = (float)((height - CGame::mHeightVp * mScale) / 2);

    graphics->TranslateTransform(mXOffset, mYOffset);
    graphics->ScaleTransform(mScale, mScale);

    // From here on you are drawing virtual pixels 
    
    for (auto i : mAllGameItems)
    {
        i->Draw(graphics);
    }

    // Draw the dashboard
    mDashboard->Draw(graphics);

}

/**
* Handle a click on the game area
* \param x X location clicked on
* \param y Y location clicked on
*/
void CGame::OnLButtonDown(int x, int y)
{
    double oX = (x - mXOffset) / mScale;
    double oY = (y - mYOffset) / mScale;

    if (!mGameActive)
    {
        if ((0 <= oX) && (oX <= 1024) && (0 <= oY) && (oY <= 1024))
        {
            // Try and find a tower to grab
            // Get all the towers
            vector<CTower*> towers;
            CTowerCollector towerCollector;
            Accept(&towerCollector);
            towers = towerCollector.GetTowers();

            auto found = find_if(towers.begin(), towers.end(), [oX, oY](CTower* tower)
                {
                    bool xWithin = (tower->GetX() < oX) && (tower->GetX() + 65 > oX);
                    bool yWithin = (tower->GetY() < oY) && (tower->GetY() + 65 > oY);
                    return xWithin && yWithin;
                });
            if (found != towers.end())
            {
                mGrabbedItem = *found;
                // Set the old tile that the tower used to reside on to free
                mGrabbedItem->GetPlaced()->SetIsOccupied(false);
                mGrabbedItem->SetPlaced(nullptr);
            }
        }
    }
    if ((1024 <= oX) && (oX <= 1224) && (0 <= oY) && (oY <= 1024))
    {
        mGrabbedItem = mDashboard->DashHitTest(oX, oY);
    }
}
/**
* Handle when mouse is released
* \param x X location clicked on
* \param y Y location clicked on
*/
void CGame::OnLButtonUp(double x, double y)
{
    bool Check = CheckForPlacement(mGrabbedItem,x,y);
}

/**
* Handle a click on the game area
* \param nFlags Flags set in Childview
* \param x X location clicked on
* \param y Y location clicked on
*/
void CGame::OnMouseMove(UINT nFlags, int x, int y)
{
    double oX = ((x - 25 - mXOffset) / mScale);
    double oY = ((y - 25 - mYOffset) / mScale);
    // See if an item is currently being moved by the mouse
    if (mGrabbedItem != nullptr)
    {
        // If an item is being moved, we only continue to 
        // move it while the left button is down.
        if (nFlags & MK_LBUTTON)
        {
            mGrabbedItem->SetCoordinates(oX, oY);
        }
    }
}

/**
* Update objects in the playing area
* \param elapsed Elapsed time since last update
*/
void CGame::Update(double elapsed)
{
    if (mGameActive)
    {
        if (mStart != nullptr && mBalloonNum > 0)
        {
            mBalloonDispatchTime += elapsed;
            if (mBalloonDispatchTime > 0.375)
            {
                mBalloonDispatchTime -= 0.375;
                shared_ptr<CBalloon> balloon;
                balloon = make_shared<CBalloon>(this);
                wstring input = mStart->GetIn();
                if (input == L"N")
                {
                    balloon->SetX(mStart->GetX());
                    balloon->SetY(mStart->GetY() - 32);
                } 
                else if (input == L"S")
                {
                    balloon->SetX(mStart->GetX());
                    balloon->SetY(mStart->GetY() + 32);
                }
                else if (input == L"W")
                {
                    balloon->SetX(mStart->GetX() + 32);
                    balloon->SetY(mStart->GetY());
                }
                else if (input == L"E")
                {
                    balloon->SetX(mStart->GetX() - 32);
                    balloon->SetY(mStart->GetY());
                }
                // THis is completely wrong.  Re-read the project description!!! 
                //AddBalloon(shared_ptr<CItem>(balloon));
                Add(shared_ptr<CItem>(balloon));
                mStart->GiveBalloon(balloon);
                mBalloonNum--;
            }
        }
        for (auto item : mAllGameItems)
        {
            item->Update(elapsed);
        }
        if (mToDelete.size() > 0)
        {
            DeleteScheduled();
        }
    }
}

	
/**
* Update objects in the playing area
* \param item Item to add to the collection
*/
void CGame::Add(std::shared_ptr<CItem> item)
{
    mAllGameItems.push_back(item);
}

/**
* Load the images for objects into all of the main maps
*/
void CGame::LoadImages()
{

    const vector<std::wstring> mKeys =
    {
        L"button-go.png", L"castlea.png", L"castleb.png", L"dart.png",
        L"grass1.png", L"grass2.png", L"house1.png", L"house2.png",
        L"house3.png", L"house4a.png", L"house4b.png", L"red-balloon.png",
        L"roadEW.png", L"roadEWstart.png", L"roadNE.png", L"roadNS.png",
        L"roadNW.png", L"roadSE.png", L"roadSW.png", L"test.png",
        L"tower8.png", L"tower-bomb.png", L"tower-rings.png", L"trees1.png",
        L"trees2.png", L"trees3.png", L"trees4.png", L"new-Cross-Tower.png",
        L"tower-cross.png", L"button-replay.png", L"button-stop.png"
    };
    
    for (wstring filename : mKeys)
    {
        shared_ptr<Bitmap> image;
        if (!filename.empty())
        {
            wstring fullpath = L"images\\" + filename;
            image = shared_ptr<Bitmap>(Bitmap::FromFile(fullpath.c_str()));
            if (image->GetLastStatus() != Ok)
            {
                wstring msg(L"Failed to open ");
                msg += filename;
                AfxMessageBox(msg.c_str());
                return;
            }
            else
            {
                mImageFiles.insert(make_pair(filename, image));
            }
        }
    }
}

/**
* Get an image from the map and return a pointer to it
* \param filename The filename we want to load 
* \returns pointer to Image
*/
shared_ptr<Bitmap> CGame::GetImage(wstring filename)
{
    shared_ptr<Bitmap> image;
    try 
    {
        image = mImageFiles.at(filename);
    }
    catch (const out_of_range& orr)
    {
        image = nullptr;
    }
    return image;
}


/**
* Check if an item is clicked by the mouse
* \param x The x coordinate
* \param y The y coordinate
* \returns pointer to item
*/
std::shared_ptr<CItem> CGame::HitTest(int x, int y)
{
    for (auto i = mAllGameItems.rbegin(); i != mAllGameItems.rend(); i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return nullptr;
}

/** Take the item passed in and move its location to the
*   front of list
*/
/*
void CGame::LoadToFront(std::shared_ptr<CItem> item)
{
    auto loc = find(begin(mAllGameItems), end(mAllGameItems), item);

    if (loc != end(mAllGameItems))
    {
        mAllGameItems.erase(loc);
        mAllGameItems.push_back(item);
    }
}*/

/**
* Local Function for getting a road with a specific grid position
* \param roads The collection of roads
* \param gridX the X grid position
* \param gridY the Y grid position
* \returns iterator at the spot where it was found
*/
vector<CTileRoad*>::iterator GetRoad(vector<CTileRoad*> & roads, int gridX, int gridY)
{
    return find_if(roads.begin(), roads.end(), [gridX, gridY](CTileRoad* road)
    {
        return (road->GetXGrid() == gridX && road->GetYGrid() == gridY);
    });
}

/**
* Setup the path for the balloons to follow
*/
void CGame::SetupPath()
{
    
    // Get a list of all the road tiles from the Road Visitor
    CRoadCollector coll;
    Accept(&coll);
    std::vector<CTileRoad *> roads = coll.GetTiles();
    
    // From the start path, iterate through the path setting up prev road
    // and next road for all of the tiles
    // Look through the collection for the starting
    CTileRoad * start = nullptr;
    for (auto road : roads)
    {
        if (road->GetXGrid() == mStartX && road->GetYGrid() == mStartY)
        {
            // Found the start position
            start = road;
            break;
        }

    }
    if (start == nullptr)
    {
        return;
    }
    // Give a starting direction and a road type find the next direction
    // Find the starting direction
    int gridX = mStartX;
    int gridY = mStartY;

    
    wstring current = L""; // Hardcode this for now, we can fix later
    wstring iType = start->GetType();
    vector<wchar_t> v(iType.begin(), iType.end());
    for (int i = 0; i < v.size(); i++)
    { 
        if (v.at(i) == L'N')
        {
            // See if there is road to north
            auto testRoad = GetRoad(roads, gridX, gridY - 1);
            if (testRoad != roads.end() && current.empty())
            {
                current = L"N";
            }
        }
        else if (v.at(i) == L'S')
        {
            // See if there is road to north
            auto testRoad = GetRoad(roads, gridX, gridY + 1);
            if (testRoad != roads.end() && current.empty())
            {
                current = L"S";
            }
        }
        else if (v.at(i) == L'E')
        {
            // See if there is road to north
            auto testRoad = GetRoad(roads, gridX + 1, gridY);
            if (testRoad != roads.end() && current.empty())
            {
                current = L"E";
            }
        }
        else if (v.at(i) == L'W')
        {
            // See if there is road to north
            auto testRoad = GetRoad(roads, gridX - 1, gridY);
            if (testRoad != roads.end() && current.empty())
            {
                current = L"W";
            }
        }
    }

    auto oldPtr = start;
    mStart = start;
    // Move through all the roads until we get to the end
    bool done = false;
    while (!done)
    {
        wstring type = oldPtr->GetType();
        wstring flipped;
        if (current == L"E") { flipped = L"W"; }
        else if (current == L"W") { flipped = L"E"; }
        else if (current == L"N") { flipped = L"S"; }
        else if (current == L"S") { flipped = L"N"; }
        string::size_type pos = type.find(flipped);
        if (pos != string::npos)
        {
            type.erase(pos, 1);
        }
        oldPtr->SetIn(flipped);
        if (type == L"N") gridY--;
        else if (type == L"S") gridY++;
        else if (type == L"W") gridX--;
        else if (type == L"E") gridX++;
        oldPtr->SetOut(type);
        auto newIt = GetRoad(roads, gridX, gridY);
        if (newIt == roads.end())
        {
            // path stops here.
            oldPtr->SetNext(nullptr);
            break;
        }
        if (gridX > 15 || gridX < 0 || gridY > 15 || gridY < 0)
        {
            /// Bad Xml, return
            oldPtr->SetNext(nullptr);
            break;
        }
        oldPtr->SetNext(*newIt);
        oldPtr = *newIt;
        current = type;
    }
}


/**
* Accept the visitor so it can visit the items
* \param visitor The visitor we are using to visit
*/
void CGame::Accept(CItemVisitor* visitor)
{
    for (auto item : mAllGameItems)
    {
        item->Accept(visitor);
    }
}

/**
* Return pointer to item of mAllGameItems at given index
* \param index Index of item to get
* \return Item from vector
*/
std::shared_ptr<CItem> CGame::GetItem(int index)
{
    return mAllGameItems[index];
}

/**  Save the game as a .tower XML file.
*
* Open an XML file and stream the city data to it.
*
* \param filename The filename of the file to save the city to
*/
void CGame::Save(const wstring& filename)
{
    //
    // Create an XML document
    //
    auto root = CXmlNode::CreateDocument(L"level");

    for (auto item : mAllGameItems)
    {
        item->XmlSave(root);
    }

    try
    {
        root->Save(filename);
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}

void CGame::ArmTowers()
{
    vector<CTower*> towers;
    CTowerCollector collector;
    Accept(&collector);
    towers = collector.GetTowers();
    for (auto tower : towers)
    {
        tower->ArmTower();
    }
}


/**
* Take a balloon back from a road
* \param balloon The balloon to take
* \param points The number of points to add or subtract
*/
void CGame::TakeBalloon(CBalloon * balloon, int points)
{
    ScheduleDelete(pair<CItem *,int>(balloon, points));
}


/**
* Schedule the deletion of an item
* Enter 0 for the second part of the pair if you 
* don't want to edit the score
* \param item The item and score to delete
*/
void CGame::ScheduleDelete(pair<CItem *, int> item)
{
    mToDelete.push_back(item);
}

/**
* Deletes all scheduled items, Adjusts score as well
*/
void CGame::DeleteScheduled()
{
    for (auto item : mToDelete)
    {
        // Remove the item from the main collection
        auto loc = find_if(mAllGameItems.begin(), mAllGameItems.end(), [item](shared_ptr<CItem> shared_item) { return shared_item.get() == item.first; });

        if (loc != mAllGameItems.end())
        {
            mAllGameItems.erase(loc);
            mScore += item.second;
        }
    }
    mToDelete.clear();
}

/**
* Determines if a tower can be placed in a location
* \param x coordinate in x direction
* \param y coordinate in y direction
* \param tower Tower we're comparing
* \return true if a location is found, false otherwise
*/
bool CGame::CheckForPlacement(CTower* tower, double x, double y)
{
    if (mGrabbedItem != nullptr)
    {
        CTileOpenCollector OpenCollect;
        Accept(&OpenCollect);
        std::vector<CTileOpen*> tiles = OpenCollect.GetTiles();
        
        for (auto tile : tiles)
        {
            double oX = (x - mXOffset) / mScale;
            double oY = (y - mYOffset) / mScale;
            double TileX = tile->GetX();
            double TileY = tile->GetY();
            if (oX > TileX && oX < (TileX + 64) && oY > TileY && oY < (TileY + 64) && (tile->GetIsOccupied() == false) && tower != nullptr)
            {
                tile->SetIsOccupied(true);
                // This keeps track of the tile the tower is placed on for easy moving
                tower->SetPlaced(tile);
                tower->SetCoordinates(TileX, TileY);
                mGrabbedItem = nullptr;
                return true;
            }
        }
        
        if (!mAllGameItems.empty()) 
        {
            auto loc = find_if(mAllGameItems.begin(), mAllGameItems.end(), [tower](shared_ptr<CItem> shared_item) { return shared_item.get() == tower; });
            if (loc != end(mAllGameItems))
            {
                mAllGameItems.erase(loc);
            }
        }
    }
    mGrabbedItem = nullptr;
    return false;
}


/**
*  Clear the game item data.
*
* Deletes all known items in the game.
*/
void CGame::Clear() 
{ 
    mAllGameItems.clear(); 
    bombCount = 0;
    mGameActive = false;
    mBalloonNum = 25;
    mBalloonDispatchTime = 0;
}
