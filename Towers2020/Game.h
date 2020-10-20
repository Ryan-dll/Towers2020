/**
 * \file Game.h
 *
 * \author Craig Smith
 *
 * Class that implements the Game
 */

#pragma once
#include <string>
#include "Item.h"
#include <vector>
#include <map>
#include <memory>
#include "XmlNode.h"
#include "Dashboard.h"

class CItem;
class CDashboard;

 /**
 * CGame class
 */
class CGame
{
public:
	// Constructor
	CGame();

	/// Load the level from an XML file	
	void Load(const std::wstring& filename);

	/// Handle each XML item
	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);
	
	/// Draw the screen and all items on it
	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

	/// Update each item for the elapsed time
	void Update(double elapsed);

	/// Mouse click	
	void OnLButtonDown(int x, int y);

	/// Add item to the collection
	void Add(std::shared_ptr<CItem> item);

	// Get Pointer to image object
	std::shared_ptr<Gdiplus::Bitmap> GetImage(std::wstring filename);
	
	// Load images at the beginning of the game
	void LoadImages();
	
	/// Hit Test for the item
	std::shared_ptr<CItem> HitTest(int x, int y);

	/// Adds item to front of the list in display
	///  \param item to be loaded up
	void LoadToFront(std::shared_ptr<CItem> item);

	/// Setter for graphics to the pointer in Childview
	/// \param graphics pointer from childview
	void SetGraphics(Gdiplus::Graphics* graphics) { mGraphics = graphics; }

	/// Setter for graphics to the pointer in Childview
	/// \return graphics pointer from childview
	Gdiplus::Graphics* GetGraphics() { return mGraphics; }

	/// Iterate through the field to place all the roads
	void SetupPath();

	/// Allow the visitor to visit all of the children
	void Accept(CItemVisitor* visitor);

private:
	/// All game items
	std::vector<std::shared_ptr<CItem>> mAllGameItems;
	
	/// All the image files, used for any instance of an item
	std::map<std::wstring, std::shared_ptr<Gdiplus::Bitmap>> mImageFiles;

	/// Dashboard for the game
	std::unique_ptr<CDashboard> dashboard;

	/// Game score
	int mScore = 0;

	/// Width of level
	int mWidth = 0;

	/// Height of level
	int mHeight = 0;

	/// Start position X
	int mStartX = 0;

	/// Start position Y
	int mStartY = 0;

	/// Scale for virtual pixels
	float mScale = 0;
	
	/// X Offset for virtual pixels
	float mXOffset = 0;

	/// Y Offset for virtual pixels
	float mYOffset = 0;
	
	/// Game area width in virtual pixels
    const static int Width = 1224;

    /// Game area height in virtual pixels
    const static int Height = 1024;

	/// Pointer to graphics for Draw
	Gdiplus::Graphics* mGraphics;
};

