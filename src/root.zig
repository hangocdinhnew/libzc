// SPDX-FileCopyrightText: 2026 hangocdinhnew
// SPDX-License-Identifier: BSD-3-Clause

const std = @import("std");

pub const syscalls = @import("syscalls.zig");
pub const crt = @import("crt.zig");

// CRT
comptime {
    @export(&crt._start, .{ .name = "_start" });
}
