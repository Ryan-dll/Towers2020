/**
 * \file TileOpen.h
 *
 * \author Craig Smith
 *
 * Class that implements the Open (grass)
 */

#pragma once
#include "Item.h"
#include "Tile.h"
#include "Game.h"
#include "ItemVisitor.h"

 /**
 * CTileOpen class
 */
class CTileOpen : public CTile
{
public:
    /// Default constructor (disabled)
    CTileOpen() = delete;

    /// Copy constructor (disabled)
    CTileOpen(const CTileOpen&) = delete;

    /// Constructor
    CTileOpen(CGame * game, std::wstring image);

    /// Save TileOpen to xml
    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) override { visitor->VisitTileOpen(this); }

};

