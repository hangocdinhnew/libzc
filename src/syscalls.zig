// SPDX-FileCopyrightText: 2026 hangocdinhnew
// SPDX-License-Identifier: BSD-3-Clause

pub export fn _exit(exit: i32) noreturn {
    asm volatile (
        \\ movq $60, %rax
        \\ syscall
        :
        : [status] "{rdi}" (exit),
        : .{ .rax = true, .rdi = true });

    unreachable;
}
