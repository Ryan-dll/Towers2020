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

using namespace std;
using namespace Gdiplus;

/// Score of the game
int score = 0;

/// Whether the level has started
bool levelStarted = false;

/**
 * Draw the dashboard
 * \param graphics Pointer to the graphics context
 */
void CDashboard::Draw(Graphics* graphics)
{

    auto towerEight = mGame->GetImage(L"tower8.png");
    auto towerBomb = mGame->GetImage(L"tower-bomb.png");
    auto goBtn = mGame->GetImage(L"button-go.png");

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
    const wstring score_wstr = to_wstring(score);
    const WCHAR* score_wchar = score_wstr.c_str();
    graphics->DrawString(score_wchar,  // String to draw
        -1,         // String length, -1 so it figures it out on its own
        &font,      // The font to use
        PointF(1024, 120),   // Where to draw (top left corner)
        &text);    // The brush to draw the text with

    // 8 tower
    graphics->DrawImage(towerEight.get(),
        1074, 300,
        100, 100);

    // Bomb tower
    graphics->DrawImage(towerBomb.get(),
        1074, 500,
        100, 100);

    // Go button (only shows if level isn't started)
    if (!levelStarted)
    {
        graphics->DrawImage(goBtn.get(),
            1034, 800,
            180, 90);
    }
}

/**
 * Set the score shown on Dashboard
 * \param newScore score to show
 */
void CDashboard::setScore(int newScore)
{
    score = newScore;
}

/**
 * Set the status of if level is started. Go button only shows
 * if not started.
 * 
 * \param started whether game is started
 */
void CDashboard::setLevelStarted(bool started)
{
    levelStarted = started;
}