/**
 * \file Tower.h
 *
 * \author RyanShore
 *
 * General Class for towers
 */

#include "pch.h"
#include "Tower.h"
#include <chrono>
#include <thread>
#include <stdlib.h>

/**
 * Constructor for CTower
 * \param game Pointer to the game object
 */
CTower::CTower(CGame * game) : CItem(game)
{
	// Dont need this guy now, but maybe later...
}

/**
 * Determines if a location is valid for tower placement
 * \returns true if location is valid
 */
bool CTower::CanPlace()
{
    return false;
}

/**
 * Constantly runs while the Tower object is active
 */
void CTower::Activate()
{
}

/**
 * Fires Projectiles from tower
 */
void CTower::Fire()
{
}
