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
        .name = "libzc",
        .root_module = mod,
    });

    b.installArtifact(lib);
}
