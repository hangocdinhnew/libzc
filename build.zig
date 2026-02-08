// SPDX-FileCopyrightText: 2026 hangocdinhnew
// SPDX-License-Identifier: BSD-3-Clause

const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{ .default_target = .{
        .os_tag = .freestanding,
        .abi = .none,
    } });
    const optimize = b.standardOptimizeOption(.{});

    const mod = b.addModule("libzc", .{
        .root_source_file = b.path("src/root.zig"),
        .target = target,
        .optimize = optimize,
    });

    const lib = b.addLibrary(.{
        .name = "zc",
        .root_module = mod,
    });

    b.installArtifact(lib);
    b.installDirectory(.{
        .source_dir = b.path("include/"),
        .install_dir = .header,
        .install_subdir = "",
    });
}
