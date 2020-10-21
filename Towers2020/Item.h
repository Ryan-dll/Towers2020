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
class CItemVisitor;

 /**
 * CItem class
 */
class CItem
{
public:
	CItem() = delete;

	CItem(const CItem&) = delete;
	
    /**
     * CItem constructor
	 * \param game Pointer to the game which we belong
     */
	CItem(CGame * game) { mGame = game; }
	
    /**
     * Setter for X position
	 * \param xPos desired X position
     */
	void setX(int xPos) { mX = xPos; }

    /**
     * Setter for Y position
	 * \param yPos desired Y position
     */
	void setY(int yPos) { mY = yPos; }

	/// Load item from xml
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Set image for this Item
	void SetImage(const std::wstring &);

	/// Draw the image
	virtual void Draw(Gdiplus::Graphics* graphics);

	/**
	*  Getter for Y position
	*  \return mY Y Position
	*/
	int GetY() { return mY; }

	/**
	*  Getter for X position
	*  \return mY X Position
	*/
	int GetX() { return mX; }

	/**
	* Setter for Y and X positions
	* \param yPos desired Y position
	* \param xPos desired X position
	*/
	void setCoordinates(int yPos, int xPos) { mX = xPos; mY = yPos; }
	
	/**  Test this item to see if it has been clicked on
	* \param x X location on the item to test
	* \param y Y location on the item to test
	* \return true if clicked on */
	virtual bool HitTest(int x, int y);

	/// Determine distance between 2 items
	/// \param other Item being compared
	/// \return Distance as a double in pixels
	double Distance(std::shared_ptr<CItem> other);

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/** Accept a visitor 
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) = 0;

protected:

	/// X position of item
	int mX = 0;

	/// Y position of item
	int mY = 0;

	/// X grid position
	int mXGrid = 0;

	/// Y grid position
	int mYGrid = 0;

	/// ID of Item
	std::wstring mId;

	/// Pointer to image file
	std::shared_ptr<Gdiplus::Bitmap> mItemImage;
	
	/// Pointer to the Game we belong to
	CGame* mGame;

};

