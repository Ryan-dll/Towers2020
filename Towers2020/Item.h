/**
 * \file Item.h
 *
 * \author Craig Smith
 *
 * Class that implements the Item
 */

#pragma once
#include "XmlNode.h"
#include "Game.h"

class CGame;

 /**
 * CItem class
 */
class CItem
{
public:
	CItem() = delete;

	CItem(const CItem&) = delete;
	
	// Construct the Item
	// \param game Pointer to the game to which we belong
	CItem(CGame * game) { mGame = game; }
	
	/// Setter for X position
	/// \param xPos desired X position
	void setX(int xPos) { mX = xPos; }

	/// Setter for Y position
	/// \param yPos desired Y position
	void setY(int yPos) { mY = yPos; }

	/// Load item from xml
	void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Set image for this Item
	void SetImage(const std::wstring &);

	// Draw the image
	void Draw(Gdiplus::Graphics *graphics);

protected:

	/// X position of item
	int mX = 0;

	/// Y position of item
	int mY = 0;

	/// Grid X position
	int mXGrid = 0;

	/// Grid Y position
	int mYGrid = 0;

	/// ID of Item
	std::wstring mId;

	/// Pointer to image file
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;
	
	// Pointer to the Game we belong to
	CGame* mGame;

};

