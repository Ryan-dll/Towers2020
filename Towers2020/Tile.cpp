#include "pch.h"
#include "Tile.h"

/**
 * Constructor for CTile
 * \param game Pointer to the game object
 */
CTile::CTile(CGame * game) : CItem(game)
{
	// Dont need this guy now, but maybe later...
}


/**
 * Load the attributes for an item node.
 *
 * \param node The Xml node we are loading the item from
 */
void CTile::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) 
{
    CItem::XmlLoad(node);
    mXGrid = node->GetAttributeDoubleValue(L"x", 0);
    //CItem::setX(mXGrid * 64);
    mYGrid = node->GetAttributeDoubleValue(L"y", 0);
    //CItem::setY(mYGrid * 64);
    //mId = node->GetAttributeValue(L"id", L"");
}

/**
 * Save the tile to xml
 * \param node The node 
 * \return the node
 */
std::shared_ptr<xmlnode::CXmlNode> CTile::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = node->AddChild(L"tile");
    /*
    itemNode->SetAttribute(L"id", mId);
    itemNode->SetAttribute(L"x", mX);
    itemNode->SetAttribute(L"y", mY);
    */
    return itemNode;
    return std::shared_ptr<xmlnode::CXmlNode>();
}