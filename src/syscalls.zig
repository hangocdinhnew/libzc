pub inline fn __exit(exit: i32) noreturn {
    asm volatile (
        \\ movq $60, %rax
        \\ syscall
        :
        : [status] "{rdi}" (exit),
        : .{ .rax = true, .rdi = true });

    unreachable;
}
