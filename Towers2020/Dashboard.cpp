/**
 * \file Dashboard.h
 *
 * \author Craig Smith
 *
 * Class that implements the Dashboard
 */

#include "pch.h"
#include "Dashboard.h"
#include <string>
#include "Item.h"
#include "Tower.h"
#include "TowerProjectile.h"
#include "TowerEight.h"
#include "TowerCross.h"
#include "TowerRing.h"
#include "TowerBomb.h"

using namespace std;
using namespace Gdiplus;

/// Whether the level has started
//bool levelStarted = false;

/// Pointer to image for TowerEight
shared_ptr<Bitmap> towerEight;

/// Pointer to image for TomerBomb
shared_ptr<Bitmap> towerBomb;

/// Pointer to image for TomerCross
shared_ptr<Bitmap> towerCross;

/// Pointer to image for TomerCross
shared_ptr<Bitmap> towerRing;

/// Pointer to image for Go Button
shared_ptr<Bitmap> goBtn;

/// Pointer to image for Stop Button
shared_ptr<Bitmap> stopBtn;


/**
 * CDashboard Constructor
 * \param game Pointer to the game which we belong
 */
CDashboard::CDashboard(CGame* game)
{
    mGame = game;

    towerEight = mGame->GetImage(L"tower8.png");
    towerCross = mGame->GetImage(L"new-Cross-Tower.png");
    towerBomb = mGame->GetImage(L"tower-bomb.png");
    towerRing = mGame->GetImage(L"tower-rings.png");
    goBtn = mGame->GetImage(L"button-go.png");
    stopBtn = mGame->GetImage(L"button-stop.png");
}

/**
 * CDashboard Destructor
 */
CDashboard::~CDashboard()
{

    towerEight.reset();
    towerCross.reset();
    towerBomb.reset();
    towerRing.reset();
    goBtn.reset();
    stopBtn.reset();
}

/**
 * Draw the dashboard
 * \param graphics Pointer to the graphics context
 */
void CDashboard::Draw(Graphics* graphics)
{

    SolidBrush background(Color(120, 120, 120));
    SolidBrush text(Color(255, 255, 255));

    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 24);

    // Background
    graphics->FillRectangle(&background, 1024, 0, 200, 1024);

    // "Score"
    graphics->DrawString(L"Score",  // String to draw
        -1,         // String length, -1 so it figures it out on its own
        &font,      // The font to use
        PointF(1024, 20),   // Where to draw (top left corner)
        &text);    // The brush to draw the text with

    // Score number
    const wstring score_wstr = to_wstring(mGame->getScore());
    const WCHAR* score_wchar = score_wstr.c_str();
    graphics->DrawString(score_wchar,  // String to draw
        -1,         // String length, -1 so it figures it out on its own
        &font,      // The font to use
        PointF(1024, 120),   // Where to draw (top left corner)
        &text);    // The brush to draw the text with

    // 8 tower
    graphics->DrawImage(towerEight.get(),
        1074, 200,
        100, 100);

    // Ring tower
    graphics->DrawImage(towerRing.get(),
        1074, 350,
        100, 100);

    // Cross Tower
    graphics->DrawImage(towerCross.get(),
        1074, 500,
        100, 100);

    // Bomb tower
    graphics->DrawImage(towerBomb.get(),
        1074, 650,
        100, 100);

    // Go button (only shows if level isn't started)
    if (!mGame->GetGameActive())
    {
        graphics->DrawImage(goBtn.get(),
            1034, 800,
            180, 90);
    }
    // Replay and stop button (only shows if level is started)
    else
    {
        graphics->DrawImage(stopBtn.get(),
            1034, 800,
            180, 90);
    }
}

/**
 * Set the status of if level is started. Go button only shows
 * if not started.
 * 
 * \param started whether game is started
 */
void CDashboard::setLevelStarted(bool started)
{
    //levelStarted = started;
    mGame->SetGameActive(true);
}

/**
* Returns a pointer to a new tower if clicked
* \param x Coordinate
* \param y Coordinate
* \return Shared pointer to new tower
*/
CTower * CDashboard::DashHitTest(int x, int y)
{

    double wid = 100;
    double hit = 100;

    double testX = x - 1074.0 - 40 + wid / 2;
    double testY = y - 200.0 - 40 + hit / 2;

    if (!mGame->GetGameActive())
    {
        // Test for TowerEight

        std::shared_ptr<CTower> newTower;
        if (testX > 0 && testY > 0 && testX <= wid && testY <= hit)
        {
            newTower = std::make_shared<CTowerEight>(mGame);
            newTower->SetCoordinates(1050, 200);
            mGame->Add(newTower);
            return newTower.get();
        }

        // Test for TowerRing
        testX = x - 1074.0 - 40 + wid / 2;
        testY = y - 350.0 - 40 + hit / 2;

        if (testX > 0 && testY > 0 && testX <= wid && testY <= hit)
        {
            newTower = std::make_shared<CTowerRing>(mGame);
            newTower->SetCoordinates(x, y);
            mGame->Add(newTower);
            return newTower.get();
        }

        // Test for TowerCross
        testX = x - 1074.0 - 40 + wid / 2;
        testY = y - 500.0 - 40 + hit / 2;

        if (testX > 0 && testY > 0 && testX <= wid && testY <= hit)
        {
            newTower = std::make_shared<CTowerCross>(mGame);
            newTower->SetCoordinates(1050, 200);
            mGame->Add(newTower);
            return newTower.get();
        }

        // Test for TowerBomb
        testX = x - 1074.0 - 40 + wid / 2;
        testY = y - 650.0 - 40 + hit / 2;

        if (testX > 0 && testY > 0 && testX <= wid && testY <= hit)
        {
            newTower = std::make_shared<CTowerBomb>(mGame);
            newTower->SetCoordinates(1050, 200);
            mGame->Add(newTower);
            return newTower.get();
        }
    }


    // Test for Go and Stop Button
    wid = 180;
    hit = 90;
    testX = x - 1034.0 - 40 + wid / 2;
    testY = y - 800.0 - 40 + hit / 2;

    if (testX > 0 && testY > 0 && testX <= wid && testY <= hit)
    {

        if (!mGame->GetGameActive())
        {

            mGame->SetGameActive(true);
            mGame->ArmTowers();
        }
        else
        {
            mGame->SetGameActive(false);
        }
    }
    return nullptr;
}
