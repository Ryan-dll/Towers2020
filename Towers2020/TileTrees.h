/**
 * \file TileTrees.h
 *
 * \author Craig Smith
 *
 * Class that implements the TileTrees
 */

#pragma once
#include "Tile.h"
#include "ItemVisitor.h"

 /**
 * CTileTrees class
 */
class CTileTrees :
    public CTile
{
public:
    /// Default constructor (disabled)
    CTileTrees() = delete;

    /// Copy constructor (disabled)
    CTileTrees(const CTileTrees&) = delete;

    /// Constructor
    CTileTrees(CGame * game, std::wstring image);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) override { visitor->VisitTileTrees(this); }

    /// Save TileOpen to xml
    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);


};

