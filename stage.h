// SPDX-License-Identifier: MPL-2.0
// Copyright © 2021 yuzu Emulator Project (https://github.com/yuzu-emu/yuzu/)

#pragma once

#include <shader_compiler/common/common_types.h>

namespace Shader {

enum class Stage : u32 {
    VertexB,
    TessellationControl,
    TessellationEval,
    Geometry,
    Fragment,

    Compute,

    VertexA,
};
constexpr u32 MaxStageTypes = 6;

[[nodiscard]] constexpr Stage StageFromIndex(size_t index) noexcept {
    return static_cast<Stage>(static_cast<size_t>(Stage::VertexB) + index);
}

} // namespace Shader
