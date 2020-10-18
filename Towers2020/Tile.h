#pragma once
#include "Item.h"
#include "Game.h"

 /**
 * CTile class
 */
class CTile : public CItem
{
public:
    /// Copy constructor (disabled)
    CTile(const CTile&) = delete;

protected:
    CTile(CGame * game);

};
