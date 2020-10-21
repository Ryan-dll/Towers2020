#pragma once
#include "Item.h"
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

	/// Load item from xml
	void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /**
     * Return the X position in the grid
     * \returns X position in the grid
     */
    int GetXGrid() { return mXGrid; }

    /**
     * Return the Y position in the grid
     * \returns Y position in the grid
     */
    int GetYGrid() { return mYGrid; }

    /**
     * Return the image for the road
     * \returns image for the road
     */
     std::wstring GetImage() { return mImage; }

protected:

    /// Constructor
    CTile(CGame * game);

private:
	/// Grid X position
	int mXGrid = 0;

	/// Grid Y position
	int mYGrid = 0;

    /// Image for house
    std::wstring mImage;
};
