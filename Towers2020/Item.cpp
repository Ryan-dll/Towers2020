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
    mX = node->GetAttributeDoubleValue(L"x", 0);
    mY = node->GetAttributeDoubleValue(L"y", 0);
    mId = node->GetAttributeValue(L"id", L"");
}

/**
 *  Set the image file to draw
 * \param file The base filename. Blank files are allowed
 */
void CItem::SetImage(const std::wstring &file)
{
    /// Todo: Use code in game to get a poiter to the image rather
    ///  than loading it from file again
    if (!file.empty())
    {
        wstring filename = file;
        mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
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
        mItemImage.release();
    }
}



/**
 *  Set the image file to draw
 * \param file The base filename. Blank files are allowed
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
            -200, 0,
            wid, hit);
}
