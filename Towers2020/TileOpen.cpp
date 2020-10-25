/**
 * \file TileOpen.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the Open (grass)
 */

#include "pch.h"
#include "TileOpen.h"
#include "Game.h"

using namespace std;

/**
 * Consturctor for the Open tile
 * \param game Pointer to the game
 * \param image Filename for the image
 */
CTileOpen::CTileOpen(CGame* game, std::wstring image) : CTile(game)
{
	// Load the open image
	CItem::SetImage(image);
}

/**
 * Save TileOpen to an Xml node
 * 
 * \param node The node we are going to be a child of
 * \returns Allocated node
 */
std::shared_ptr<xmlnode::CXmlNode> CTileOpen::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = node->AddChild(L"open");

    itemNode->SetAttribute(L"id", GetId());
    itemNode->SetAttribute(L"x", GetX());
    itemNode->SetAttribute(L"y", GetY());

    return itemNode;
}
