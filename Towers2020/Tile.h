#pragma once
#include "Item.h"
#include "Game.h"
#include "ItemVisitor.h"

 /**
 * CTile class
 */
class CTile : public CItem
{
public:
    /// Copy constructor (disabled)
    CTile(const CTile&) = delete;

    /// Default constructor
    CTile() = delete;

    /** Accept a visitor 
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor *visitor) = 0;

protected:

    /// Constructor
    CTile(CGame * game);

};
