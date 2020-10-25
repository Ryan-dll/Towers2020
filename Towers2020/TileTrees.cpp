/**
 * \file TileTrees.cpp
 *
 * \author Craig Smith
 *
 * Class that implements the Trees
 */

#include "pch.h"
#include "TileTrees.h"
#include "Game.h"

using namespace std;

 /**
 * Consturctor for the TileTrees tile
 * \param game Pointer to the game
 * \param image Filename for the image
 */
CTileTrees::CTileTrees(CGame* game, std::wstring image) : CTile(game)
{
	CItem::SetImage(image);
}


/**
 * Save TileTrees to an Xml node
 *
 * \param node The node we are going to be a child of
 * \returns Allocated node
 */
std::shared_ptr<xmlnode::CXmlNode> CTileTrees::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = node->AddChild(L"trees");

	itemNode->SetAttribute(L"id", GetId());
	itemNode->SetAttribute(L"x", GetX());
	itemNode->SetAttribute(L"y", GetY());

	return itemNode;
}