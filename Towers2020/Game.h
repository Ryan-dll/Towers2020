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
	void Load(const std::wstring& filename);
	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

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
};

