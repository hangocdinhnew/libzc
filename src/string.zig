// SPDX-FileCopyrightText: 2026 hangocdinhnew
//
// SPDX-License-Identifier: BSD-3-Clause

const std = @import("std");
const root = @import("root");

pub fn memcpy(dest: ?*anyopaque, src: ?*const anyopaque, n: usize) callconv(.c) ?*anyopaque {
    if (dest == null or src == null) {
        root.panic_opt("memcpy: dest or src must not be null!");
    }

    const d: [*c]u8 = @ptrCast(dest.?);
    const s: [*c]const u8 = @ptrCast(src.?);

    for (0..n) |i| {
        d[i] = s[i];
    }

    return dest;
}

pub export fn strlen(s: [*c]const u8) callconv(.c) usize {
    const p: [*c]const u8 = s;
    var len: usize = 0;

    while (p[len] != 0) : (len += 1) {}

    return len;
}
