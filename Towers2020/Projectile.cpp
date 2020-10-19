#include "pch.h"
#include "Projectile.h"

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
 * @param offsetX An X offset added to the position of the dart.
 * @param offsetY A Y offset added to the position of the dart.
 */
void CProjectile::Draw(Gdiplus::Graphics* graphics, int offsetX, int offsetY)
{
    int wid = mProjectileImage->GetWidth();
    int hit = mProjectileImage->GetHeight();
    auto save = graphics->Save();
    graphics->TranslateTransform((GetX() + offsetX),
        (GetY() + offsetY));
    graphics->RotateTransform((mRotation * RtoD));
    graphics->DrawImage(mProjectileImage.get(), 0, 0, wid, hit);
    graphics->Restore(save);
}
