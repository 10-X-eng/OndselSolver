/***************************************************************************
 *   Copyright (c) 2023 Ondsel, Inc.                                       *
 *                                                                         *
 *   See LICENSE file for details about copyright.                         *
 ***************************************************************************/

#pragma once

#include <cstddef>
#include <functional>
#include <utility>

namespace MbD
{

using ParallelIndexWork = std::function<void(std::size_t)>;
using ParallelExecutor = std::function<void(std::size_t, const ParallelIndexWork&)>;

}  // namespace MbD
