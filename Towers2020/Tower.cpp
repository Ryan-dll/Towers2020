/**
 * \file Tower.h
 *
 * \author RyanShore
 *
 * General Class for towers
 */

#include "pch.h"
#include "Tower.h"

CTower::CTower(CGame * game) : CItem(game)
{
	// Dont need this guy now, but maybe later...
}

bool CTower::CanPlace()
{
    return false;
}
