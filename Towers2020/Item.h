/**
 * \file Item.h
 *
 * \author Craig Smith
 *
 * Class that implements the Item
 */

#pragma once
#include "XmlNode.h"

 /**
 * CItem class
 */
class CItem
{
public:
	/// Setter for X position
	/// \param xPos desired X position
	void setX(int xPos) { mX = xPos; }

	/// Setter for Y position
	/// \param yPos desired Y position
	void setY(int yPos) { mY = yPos; }

	/// Load item from xml
	void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

protected:
	/// X position of item
	int mX;

	/// Y position of item
	int mY;

	/// ID of Item
	std::wstring mId;
};

