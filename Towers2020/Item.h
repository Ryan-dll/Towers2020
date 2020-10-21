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
	void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Set image for this Item
	void SetImage(const std::wstring &);

	/// Draw the image
	virtual void Draw(Gdiplus::Graphics* graphics);

	/**
	*  Getter for Y position
	*  \return mY Y Position
	*/
	double GetY() { return mY; }

	/**
	*  Getter for X position
	*  \return mY X Position
	*/
	double GetX() { return mX; }

	/**
	* Setter for Y and X positions
	* \param yPos desired Y position
	* \param xPos desired X position
	*/
	void setCoordinates(double xPos, double yPos) { mX = xPos; mY = yPos; }
	
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

protected:

	/// X position of item
	double mX = 0;

	/// Y position of item
	double mY = 0;

	/// Grid X position
	int mXGrid = 0;

	/// Grid Y position
	int mYGrid = 0;

	/// ID of Item
	std::wstring mId;

	/// Pointer to image file
	std::shared_ptr<Gdiplus::Bitmap> mItemImage;
	
	/// Pointer to the Game we belong to
	CGame* mGame;

	/// Constant to be used for pi
	const double pi = 3.1415926535;

};

