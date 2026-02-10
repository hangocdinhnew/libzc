pub inline fn _exit(exit: i32) noreturn {
    asm volatile (
        \\ movq $60, %rax
        \\ syscall
        :
        : [status] "{rdi}" (exit),
        : .{ .rax = true, .rdi = true, .rcx = true, .r11 = true });

    unreachable;
}

pub inline fn write(fd: i32, buf: [*c]const u8, len: usize) isize {
    return asm volatile (
        \\ movq $1, %rax
        \\ syscall
        : [ret] "={rax}" (-> isize),
        : [fd] "{rdi}" (fd),
          [buf] "{rsi}" (buf),
          [len] "{rdx}" (len),
        : .{ .rax = true, .rdi = true, .rsi = true, .rdx = true, .rcx = true, .r11 = true, .memory = true });
}
