/**
 * \file Item.h
 *
 * \author Craig Smith
 *
 * Class that implements the Item
 */

#include "pch.h"
#include "Item.h"
#include "XmlNode.h"

using namespace std;
using namespace Gdiplus;

/**
 * Load the attributes for an item node.
 *
 * \param node The Xml node we are loading the item from
 */
void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    mXGrid = node->GetAttributeDoubleValue(L"x", 0);
    mX = mXGrid * 64;
    mYGrid = node->GetAttributeDoubleValue(L"y", 0);
    mY = mYGrid * 64;
    mId = node->GetAttributeValue(L"id", L"");
}

/**
 * Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CItem::SetImage(const std::wstring &file)
{
    /// Todo: Use code in game to get a poiter to the image rather
    ///  than loading it from file again
    mItemImage = mGame->GetImage(file);
    /*if (!file.empty())
    {
        wstring filename = L"images\\" + file;
        mItemImage = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
        if (mItemImage->GetLastStatus() != Ok)
        {
            wstring msg(L"Failed to open ");
            msg += filename;
            AfxMessageBox(msg.c_str());
            return;
        }
    }
    else
    {
        //mItemImage.release();
    }*/
}



/**
 * Draw the image
 * \param graphics Pointer to the graphics context
 */
void CItem::Draw(Graphics* graphics)
{
    // Draw the image
    int wid = mItemImage->GetWidth()/2;
    int hit = mItemImage->GetHeight()/2;
//    graphics->DrawImage(mItemImage.get(),
//            mX, mY,
//            wid, hit);
    graphics->DrawImage(mItemImage.get(),
            mX, mY,
            65, 65);
}

/**
 * Determine the distance from this item to some other item.
 * \param other Other item we are testing
 * \return Distance in pixels
 */
double CItem::Distance(std::shared_ptr<CItem> other)
{
    // Create a vector in the direction we are from the nudger
    double dx = mX - other->mX;
    double dy = mY - other->mY;

    // Determine how far away we are
    return sqrt(dx * dx + dy * dy);
}
