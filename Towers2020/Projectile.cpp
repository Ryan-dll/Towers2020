#include "pch.h"
#include "Projectile.h"
#include <math.h>
#include "BalloonCollector.h"
#include <vector>

using namespace std;

/// Constant to covert radians to degrees.
const double RtoD = 57.2957795;


/**
 * Consturctor for the Projectile
 * \param game Pointer to the game
 */
CProjectile::CProjectile(CGame* game) : CItem(game)
{
    std::wstring image = L"dart.png";
    CItem::SetImage(image);
}

/**
 * Draw the rotated dart. Rotation is determined by the member
 * variable mAngle, which is the rotation in radians.
 *
 * @param graphics The graphics context to draw on.
 */
void CProjectile::Draw(Gdiplus::Graphics* graphics)
{
    
    if (mActive == true) 
    {
        int wid = mItemImage->GetWidth();
        int hit = mItemImage->GetHeight();
        auto save = graphics->Save();
        graphics->TranslateTransform((Gdiplus::REAL)(GetX()),
            (Gdiplus::REAL)(GetY()));
        graphics->RotateTransform((Gdiplus::REAL)(mRotation * RtoD));
        graphics->DrawImage(mItemImage.get(), 0, 0, wid, hit);
        graphics->Restore(save);
    }
}

void CProjectile::Update(double elapsed)
{
    if (mActive == true)
    {
        double wid = 32;
        double hit = 6;
        double newY = sin(mRotation);
        double newX = cos(mRotation);

        double velocity = elapsed * mSpeed;

        newY *= velocity;
        newX *= velocity;

        mX += newX;
        mY += newY;
        // Locate Balloons in relation to dart
        CBalloonCollector bc;
        mGame->Accept(&bc);
        vector<CBalloon*> balloons = bc.GetBalloons();
        for (auto balloon : balloons)
        {
            double dx = balloon->GetX() - GetX() + (wid / 2.0);
            double dy = balloon->GetY() - GetY() + (hit / 2.0);
            double distance = sqrt((dx * dx) + (dy * dy));
            if (distance < 24)
            {
                mGame->TakeBalloon(balloon, 10);
            }
        }

        ResetDart();
    }
}

void CProjectile::ResetDart()
{
    double dx = mX - mOriginX;
    double dy = mY - mOriginY;

    // Determine how far away we are
    double result = sqrt(dx * dx + dy * dy);
    
    if (result >= 90)
    {
        mX = mOriginX;
        mY = mOriginY;
        mActive = false;
    }
}
