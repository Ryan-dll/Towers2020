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
#include "Balloon.h"
#include "Ring.h"
#include "TowerRing.h"
#include "TowerCross.h"

using namespace std;
using namespace xmlnode;
using namespace Gdiplus;

/// This multi dimentional map holds information defined in XML declarations for when
/// the objects are later created
map<wstring, map<wstring, wstring>> declarations;

std::unique_ptr<Gdiplus::Bitmap> image;

CGame::CGame()
{
    // Load test image from file
    //std::wstring testimage = L"Images/test.png";
    //image = unique_ptr<Bitmap>(Bitmap::FromFile(testimage.c_str()));
    LoadImages();
    dashboard = make_unique<CDashboard>(this);
    
    //auto testTower = make_shared<CTowerEight>(this);
    //testTower->setCoordinates(200, 200);
    //testTower->ArmTower();
    //this->Add(testTower);

    auto testTower2 = make_shared<CTowerCross>(this);
    testTower2->setCoordinates(100, 200);
    testTower2->ArmTower();
    this->Add(testTower2);

    // Test adding ring
    //auto ring = make_shared<CRing>(this);
    //ring->setCoordinates(600, 600);
    //this->Add(ring);

    // Test adding ring Tower
    //auto ringTower = make_shared<CTowerRing>(this);
    //ringTower->setCoordinates(600, 300);
    //this->Add(ringTower);

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

        // Clear the current level?

        
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
    float scaleX = float(width) / float(Width);
    float scaleY = float(height) / float(Height);
    mScale = min(scaleX, scaleY);

    // Ensure it is centered horizontally
    mXOffset = (float)((width - CGame::Width * mScale) / 2);

    // Ensure it is centered vertically
    mYOffset = (float)((height - CGame::Height * mScale) / 2);

    graphics->TranslateTransform(mXOffset, mYOffset);
    graphics->ScaleTransform(mScale, mScale);

    // From here on you are drawing virtual pixels 
    
    for (auto i : mAllGameItems)
    {
        i->Draw(graphics);
    }

    // Draw the dashboard
    dashboard->Draw(graphics);

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
    mGrabbedItem = DashHitTest(oX, oY);

}

/**
* Handle a click on the game area
* \param nFlags Flags set in Childview
* \param x X location clicked on
* \param y Y location clicked on
*/
void CGame::OnMouseMove(UINT nFlags, int x, int y)
{
    double oX = ((x -50 - mXOffset) / mScale);
    double oY = ((y - 50 - mYOffset) / mScale);
    // See if an item is currently being moved by the mouse
    if (mGrabbedItem != nullptr)
    {
        // If an item is being moved, we only continue to 
        // move it while the left button is down.
        if (nFlags & MK_LBUTTON)
        {
            mGrabbedItem->setCoordinates(oX, oY);
        }
        else
        {
            // When the left button is released, we release the
            // item.
            mGrabbedItem = nullptr;
        }
    }
}

/**
* Update objects in the playing area
* \param elapsed Elapsed time since last update
*/
void CGame::Update(double elapsed)
{
    if (true)
    {
        for (auto item : mAllGameItems)
        {
            item->Update(elapsed);
        }
        if (mStart != nullptr && mBalloonNum > 0)
        {
            mBalloonDispatchTime += elapsed;
            if (mBalloonDispatchTime > 0.375)
            {
                mBalloonDispatchTime -= 0.375;
                // Add test balloon
                shared_ptr<CBalloon> balloon;
                balloon = make_shared<CBalloon>(this);
                balloon->setX(mStart->GetX() - 32);
                balloon->setY(mStart->GetY());
                Add(shared_ptr<CItem>(balloon));
                mStart->GiveBalloon(balloon);
                mBalloonNum--;
            }
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
* Update objects in the playing area
* \param image Item to add to the collection
*/
void CGame::AddDashImage(std::shared_ptr<Gdiplus::Bitmap> image)
{
    mAllDashboardImages.push_back(image);
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
        L"roadEW.png", L"roadEW.png", L"roadNE.png", L"roadNS.png",
        L"roadNW.png", L"roadSE.png", L"roadSW.png", L"test.png",
        L"tower8.png", L"tower-bomb.png", L"tower-rings.png", L"trees1.png",
        L"trees2.png", L"trees3.png", L"trees4.png"
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
/**
* Returns a pointer to a new tower if clicked
* \param x Coordinate
* \param y Coordinate
* \return Shared pointer to new tower
*/
std::shared_ptr<CItem> CGame::DashHitTest(int x, int y)
{
    double wid = 100;
    double hit = 100;

    for (auto i = mAllDashboardImages.rbegin(); i != mAllDashboardImages.rend(); i++)
    {
        // Test for TowerEight
        double testX = x - 1074.0 + wid / 2;
        double testY = y - 300.0 + hit / 2;

        if (testX > 0 && testY > 0 && testX <= wid && testY <= hit)
        {
            std::shared_ptr<CTowerEight> newTower = std::make_shared<CTowerEight>(this);
            newTower->setCoordinates(300, 200);
            newTower->ArmTower();
            this->Add(newTower);
            return newTower;
        }
    }
    return nullptr;
}

/** Take the item passed in and move its location to the
*   front of list
*/
void CGame::LoadToFront(std::shared_ptr<CItem> item)
{
    auto loc = find(begin(mAllGameItems), end(mAllGameItems), item);

    if (loc != end(mAllGameItems))
    {
        mAllGameItems.erase(loc);
        mAllGameItems.push_back(item);
    }
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
    wstring current = L"E"; // Hardcode this for now, we can fix later
    int gridX = mStartX;
    int gridY = mStartY;
    
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
        auto newIt = find_if(roads.begin(), roads.end(), [gridX, gridY](CTileRoad* road)
            {
                return (road->GetXGrid() == gridX && road->GetYGrid() == gridY);
            });
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
