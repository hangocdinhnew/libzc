// SPDX-FileCopyrightText: 2026 hangocdinhnew
//
// SPDX-License-Identifier: BSD-3-Clause

const linux_x86_64 = @import("syscalls/linux_x86_64.zig");
const linux_aarch64 = @import("syscalls/linux_aarch64.zig");
const macos_x86_64 = @import("syscalls/macos_x86_64.zig");
const macos_aarch64 = @import("syscalls/macos_aarch64.zig");

const builtin = @import("builtin");

const backend = switch (builtin.target.os.tag) {
    .linux => switch (builtin.target.cpu.arch) {
        .x86_64 => linux_x86_64,
        .aarch64 => linux_aarch64,
        else => @compileError("Unsupported Linux architecture"),
    },

    .macos => switch (builtin.target.cpu.arch) {
        .x86_64 => macos_x86_64,
        .aarch64 => macos_aarch64,
        else => @compileError("Unsupported macOS architecture"),
    },

    else => @compileError("Unsupported operating system"),
};

pub export fn _exit(exit: i32) noreturn {
    backend._exit(exit);
}

pub export fn write(fd: i32, buf: [*c]const u8, len: usize) isize {
    return backend.write(fd, buf, len);
}
