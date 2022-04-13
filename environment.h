// SPDX-License-Identifier: MPL-2.0
// Copyright © 2021 yuzu Emulator Project (https://github.com/yuzu-emu/yuzu/)

#pragma once

#include <array>

#include <shader_compiler/common/common_types.h>
#include <shader_compiler/program_header.h>
#include <shader_compiler/shader_info.h>
#include <shader_compiler/stage.h>

namespace Shader {

class Environment {
public:
    virtual ~Environment() = default;

    [[nodiscard]] virtual u64 ReadInstruction(u32 address) = 0;

    [[nodiscard]] virtual u32 ReadCbufValue(u32 cbuf_index, u32 cbuf_offset) = 0;

    [[nodiscard]] virtual TextureType ReadTextureType(u32 raw_handle) = 0;

    [[nodiscard]] virtual u32 TextureBoundBuffer() const = 0;

    [[nodiscard]] virtual u32 LocalMemorySize() const = 0;

    [[nodiscard]] virtual u32 SharedMemorySize() const = 0;

    [[nodiscard]] virtual std::array<u32, 3> WorkgroupSize() const = 0;

    virtual void Dump(u64 hash) = 0;

    [[nodiscard]] const ProgramHeader& SPH() const noexcept {
        return sph;
    }

    [[nodiscard]] const std::array<u32, 8>& GpPassthroughMask() const noexcept {
        return gp_passthrough_mask;
    }

    [[nodiscard]] Stage ShaderStage() const noexcept {
        return stage;
    }

    [[nodiscard]] u32 StartAddress() const noexcept {
        return start_address;
    }

protected:
    ProgramHeader sph{};
    std::array<u32, 8> gp_passthrough_mask{};
    Stage stage{};
    u32 start_address{};
};

} // namespace Shader
