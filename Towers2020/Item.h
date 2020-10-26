/**
 * \file Item.h
 *
 * \author Craig Smith
 *
 * Class that implements the Item
 */

#pragma once
#include "XmlNode.h"

//class CGame;
class CItemVisitor;
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
	virtual void setX(int xPos) { mX = xPos; }

    /**
     * Setter for Y position
	 * \param yPos desired Y position
     */
	virtual void setY(int yPos) { mY = yPos; }

	/// Load item from xml
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Save item to xml
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

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

	/** Accept a visitor 
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) = 0;

	/**
	* Return Id of item
	* \return Id of item
	*/
	std::wstring GetId() { return mId; };

	/**
	* Return X grid positon of item
	* \return X position
	*/
	int GetXGrid() { return mXGrid; };

	/**
	* Return Y grid positon of item
	* \return Y position
	*/
	int GetYGrid() { return mYGrid; };

	/// Set the XY grid of the item
	void SetGrid(int xGrid, int yGrid);


protected:

	/**
	* Return a pointer to the game
	* \return Y position
	*/
	CGame * GetGame() { return mGame; };

protected:
	/// X position of item
	double mX = 0;

	/// Y position of item
	double mY = 0;

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

	/// Constant to be used for pi
	const double pi = 3.1415926535;

};

