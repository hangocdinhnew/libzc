// SPDX-FileCopyrightText: 2026 hangocdinhnew
// SPDX-License-Identifier: BSD-3-Clause

const std = @import("std");
const builtin = @import("builtin");

pub const syscalls = @import("syscalls.zig");
pub const crt = @import("crt.zig");
pub const string = @import("string.zig");

pub fn panic(message: []const u8, _: ?*std.builtin.StackTrace, _: ?usize) noreturn {
    _ = syscalls.write(1, message.ptr, message.len);
    _ = syscalls.write(1, "\n", 1);

    syscalls._exit(1);
}

pub fn panic_opt(message: []const u8) void {
    if (builtin.mode == .Debug or builtin.mode == .ReleaseSafe) {
        @panic(message);
    }

    return;
}

comptime {
    // CRT
    @export(&crt.startfunction, .{ .name = "_start" });

    // Strings
    @export(&string.memcpy, .{ .name = "memcpy" });
}
