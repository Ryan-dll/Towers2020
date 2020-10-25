/**
 * \file TileHouse.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the House
 */

#include "pch.h"
#include "TileHouse.h"

using namespace std;

/**
 * Constructor for CTileHouse
 * \param game Pointer to the game object
 * \param image Filename for the image
 */
CTileHouse::CTileHouse(CGame* game, std::wstring image) : CTile(game)
{
	// Load the correct house from file given the image
	CTile::SetImage(image);
}

/**
 * Save TileHouse to an Xml node
 *
 * \param node The node we are going to be a child of
 * \returns Allocated node
 */
std::shared_ptr<xmlnode::CXmlNode> CTileHouse::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = node->AddChild(L"house");

    itemNode->SetAttribute(L"id", GetId());
    itemNode->SetAttribute(L"x", GetX());
    itemNode->SetAttribute(L"y", GetY());

    return itemNode;
}
