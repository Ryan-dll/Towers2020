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
#include "ItemVisitor.h"
#include "Tile.h"
#include "TileRoad.h"
#include "TowerProjectile.h"

class CItem;
class CDashboard;
class CTowerProjectile;

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

	/// Mouse mouse
	void OnMouseMove(UINT nFlags, int x, int y);

	/// Add item to the collection
	void Add(std::shared_ptr<CItem> item);

	/// Add projectile tower to the collection
	void AddProjTower(std::shared_ptr<CTowerProjectile> item);

	/// Add image from Dashboard to the collection
	void AddDashImage(std::shared_ptr<Gdiplus::Bitmap> image);
	
	// Get Pointer to image object
	std::shared_ptr<Gdiplus::Bitmap> GetImage(std::wstring filename);
	
	// Load images at the beginning of the game
	void LoadImages();
	
	/// Hit Test for the item
	std::shared_ptr<CItem> HitTest(int x, int y);

	/// Hit Tesst for dash items
	std::shared_ptr<CItem> DashHitTest(int x, int y);

	/// Adds item to front of the list in display
	///  \param item to be loaded up
	void LoadToFront(std::shared_ptr<CItem> item);

	/// Iterate through the field to place all the roads
	void SetupPath();

	/// Allow the visitor to visit all of the children
	void Accept(CItemVisitor* visitor);

	/// Return pointer to item of mAllGameItems at given index
	std::shared_ptr<CItem> GetItem(int index);

	/**
	* Get game score
	* \return score of the game
	*/
	int getScore() { return mScore; };

	/**
	* Get game score
	* \param pixel The thing we're converting
	* \return New virtual pixel
	*/
	double ConvertToVirtual(double pixel) { return (pixel - mXOffset) / mScale; }

	void SetStart(int x, int y) { mStartX = x; mStartY = y; }

private:
	/// All game items
	std::vector<std::shared_ptr<CItem>> mAllGameItems;

	/// All Projectile towers
	std::vector<std::shared_ptr<CTowerProjectile>> mAllProjectileTowers;
	
	/// All game items
	std::vector<std::shared_ptr<Gdiplus::Bitmap>> mAllDashboardImages;

	/// All the image files, used for any instance of an item
	std::map<std::wstring, std::shared_ptr<Gdiplus::Bitmap>> mImageFiles;

	/// Dashboard for the game
	std::unique_ptr<CDashboard> dashboard;

	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;

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

	/// Pointer to the first tile in the road
	CTileRoad* mStart = nullptr;

	// Keeps track of when the balloons leave
	double mBalloonDispatchTime = 0;
	
	// Number of balloons to send per level
	int mBalloonNum = 10;

	// Has the game started yet
	bool GameActive = false;

};

