// SPDX-FileCopyrightText: 2026 hangocdinhnew
// SPDX-License-Identifier: BSD-3-Clause

const root = @import("root");

extern fn main(argc: i32, argv: [*]const [*:0]u8, envp: [*]const [*:0]u8) i32;

pub fn startfunction() callconv(.naked) noreturn {
    asm volatile (
        \\ movq %rsp, %rdi
        \\ callq _start_impl
    );

    @setRuntimeSafety(false);
    unreachable;
}

export fn _start_impl(stack_ptr: [*]usize) noreturn {
    const argc: i32 = @intCast(stack_ptr[0]);

    const argv: [*]const [*:0]u8 =
        @ptrCast(&stack_ptr[1]);

    const envp: [*]const [*:0]u8 =
        @ptrCast(&stack_ptr[1 + @as(usize, @intCast(argc)) + 1]);

    const ret = main(argc, argv, envp);

    root.syscalls._exit(ret);
}
