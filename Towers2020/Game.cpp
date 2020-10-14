/**
 * \file Game.h
 *
 * \author Craig Smith
 *
 * Class that implements the Game
 */

#include "pch.h"
#include "Game.h"
#include <memory>
#include "XmlNode.h"
#include "Item.h"
#include "Road.h"
#include "House.h"
#include "Trees.h"
#include "Open.h"
#include <iostream>
#include <map>

using namespace std;
using namespace xmlnode;

/// This multi dimentional map holds information defined in XML declarations for when
/// the objects are later created
map<wstring, map<wstring, wstring>> declarations;

/**
 * Load the game from XML file.
 *
 * \param filename The filename of the file to load the game from.
 */
void CGame::Load(const std::wstring& filename)
{
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

        // Clear the current level?

        // Traverse the children of the root
        for (auto node : root->GetChildren())
        {
            //if (node->GetType() == NODE_ELEMENT)
            //{
            //  XmlItem(node);
            //}

            if (node->GetName() == L"level")
            {
                for (auto subNode : node->GetChildren()) {
                    mHeight = subNode->GetAttributeIntValue(L"height", 0);
                    mWidth = subNode->GetAttributeIntValue(L"width", 0);
                    mStartX = subNode->GetAttributeIntValue(L"start-x", 0);
                    mStartY = subNode->GetAttributeIntValue(L"start-y", 0);
                }
            }

            if (node->GetName() == L"declarations")
            {
                for (auto subNode : node->GetChildren()) {
                    declarations[subNode->GetAttributeValue(L"id", L"")][L"image"] = subNode->GetAttributeValue(L"image", L"");
                    declarations[subNode->GetAttributeValue(L"id", L"")][L"type"] = subNode->GetAttributeValue(L"type", L"");
                }
            }

            if (node->GetName() == L"items")
            {
                for (auto subNode : node->GetChildren()) {
                    XmlItem(subNode);
                }
            }
        }

        std::cout << "Level Loaded!";

    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}

/**
* Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CGame::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    // A pointer for the item we are loading
    shared_ptr<CItem> item;

    // We have an item. What type?
    //wstring type = node->GetAttributeValue(L"type", L"");
    wstring type = node->GetName();

    // Get declaration values, if they exist. We'll pass them to the constructor if appropriate.
    auto image_dec = declarations[node->GetAttributeValue(L"id", L"")][L"image"];
    auto type_dec = declarations[node->GetAttributeValue(L"id", L"")][L"type"];

    if (type == L"road")
    {
        item = make_shared<CRoad>(image_dec, type_dec);
    }
    else if (type == L"open")
    {
        item = make_shared<COpen>();
    }
    else if (type == L"house")
    {
        item = make_shared<CHouse>(image_dec);
    }
    else if (type == L"trees")
    {
        item = make_shared<CTrees>(image_dec);
    }

    if (item != nullptr)
    {
        item->XmlLoad(node);

        // Add item to the All Items array.
        // TODO: This should be abstracted more, Game should have Add()
        mAllGameItems.push_back(item);
    }
}