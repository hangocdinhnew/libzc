// SPDX-FileCopyrightText: 2026 hangocdinhnew
// SPDX-License-Identifier: BSD-3-Clause

const root = @import("root");
const builtin = @import("builtin");

pub const AUXVType = extern struct {
    a_type: usize,
    a_val: usize,
};

pub export var environ: [*c][*c]u8 = undefined;
pub export var auxv: [*c]const AUXVType = undefined;
pub export var apple: [*c]const [*c]u8 = undefined;

extern fn main(argc: i32, argv: [*]const [*c]u8) i32;

pub fn startfunction() callconv(.naked) noreturn {
    switch (builtin.target.os.tag) {
        .linux => switch (builtin.target.cpu.arch) {
            .x86_64 => {
                asm volatile (
                    \\ movq %rsp, %rdi
                    \\ callq _start_impl
                );
            },

            .aarch64 => {
                asm volatile (
                    \\mov x0, sp
                    \\bl _start_impl
                );
            },

            else => @compileError("Unsupported Linux Architecture"),
        },

        .macos => switch (builtin.target.cpu.arch) {
            .x86_64 => {
                asm volatile (
                    \\ movq %rsp, %rdi
                    \\ callq __start_impl
                );
            },

            .aarch64 => {
                asm volatile (
                    \\mov x0, sp
                    \\bl __start_impl
                );
            },

            else => @compileError("Unsupported MacOS Architecture"),
        },

        else => @compileError("Unsupported platform"),
    }

    @setRuntimeSafety(false);
    unreachable;
}

export fn _start_impl(stack_ptr: [*]usize) noreturn {
    const argc: i32 = @intCast(stack_ptr[0]);

    const argv: [*c]const [*c]u8 =
        @ptrCast(&stack_ptr[1]);

    environ = @ptrCast(&stack_ptr[1 + @as(usize, @intCast(argc)) + 1]);

    var p: [*]usize = @ptrCast(environ);
    while (p[0] != 0) {
        p += 1;
    }

    p += 1;

    if (builtin.target.os.tag == .linux) {
        auxv = @ptrCast(p);
    } else {
        apple = @ptrCast(p);
    }

    const ret = main(argc, argv);

    root.syscalls._exit(ret);
}
