/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

#pragma once

#include <cmath>
#include "opendrive/types.hpp"

namespace opendrive {
namespace geometry {

enum class ContactPlace
{
  Overlap,
  LeftLeft,
  RightLeft,
  LeftRight,
  RightRight,
  None
};

ContactPlace contactPlace(Lane const &leftLane, Lane const &rightLane);

inline bool near(Point const &left, Point const &right, double resolution = 1e-3)
{
  auto diff = left - right;
  return (fabs(diff.x) < resolution) && (fabs(diff.y) < resolution);
}

bool lanesOverlap(Lane const &leftLane, Lane const &rightLane, double const overlapMargin);
void invertLane(Lane &lane);
Id laneId(int roadId, int laneSectionIndex, int laneIndex);
}
}