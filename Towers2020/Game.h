/**
 * \file Game.h
 *
 * \author Craig Smith
 *
 * Class that implements the Game
 */

#pragma once
#include <string>
#include <vector>
#include <memory>
#include "XmlNode.h"
#include "Item.h"

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
	
private:
	/// All game items
	std::vector<std::shared_ptr<CItem>> mAllGameItems;

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
};

