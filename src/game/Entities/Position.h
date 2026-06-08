/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _POSITION_H
#define _POSITION_H

#include <string>

struct Position
{
    Position() : x(0.0f), y(0.0f), z(0.0f), o(0.0f) {}
    Position(float _x, float _y, float _z, float _o) : x(_x), y(_y), z(_z), o(_o) {}
    Position(float _x, float _y, float _z) : x(_x), y(_y), z(_z), o(0.f) {}
    float x, y, z, o;
    float GetPositionX() const { return x; }
    float GetPositionY() const { return y; }
    float GetPositionZ() const { return z; }
    float GetPositionO() const { return o; }
    bool IsEmpty() const { return x == 0.f && y == 0.f && z == 0.f; }
    float GetAngle(const float x, const float y) const;
    float GetDistance(Position const& other) const; // WARNING: Returns squared distance for performance reasons
    float GetDistance2d(Position const& other) const; // WARNING: Returns squared distance for performance reasons
    void RelocateOffset(Position const& offset);
    std::string to_string() const;
};

bool operator!=(const Position& left, const Position& right);

#endif
