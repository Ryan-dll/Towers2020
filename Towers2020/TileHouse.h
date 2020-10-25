/**
 * \file TileHouse.h
 *
 * \author Craig Smith
 *
 * Class that implements the TileHouse
 */

#pragma once
#include "Tile.h"
#include "Game.h"
#include "ItemVisitor.h"

 /**
 * CTileHouse class
 */
class CTileHouse : public CTile
{
public:
    /// Default constructor (disabled)
    CTileHouse() = delete;

    /// Copy constructor (disabled)
    CTileHouse(const CTileHouse&) = delete;

    /// Constructor
    CTileHouse(CGame* game, std::wstring image);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) override { visitor->VisitTileHouse(this); }

    /// Save TileOpen to xml
    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

};

