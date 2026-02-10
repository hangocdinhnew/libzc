pub inline fn _exit(status: i32) noreturn {
    asm volatile (
        \\ movq $0x2000001, %rax
        \\ syscall
        :
        : [status] "{rdi}" (status),
        : .{
          .rax = true,
          .rdi = true,
          .rcx = true,
          .r11 = true,
          .memory = true,
        });

    unreachable;
}

pub inline fn write(fd: i32, buf: [*c]const u8, len: usize) isize {
    return asm volatile (
        \\ movq $0x2000004, %rax
        \\ syscall
        : [ret] "={rax}" (-> isize),
        : [fd] "{rdi}" (fd),
          [buf] "{rsi}" (buf),
          [len] "{rdx}" (len),
        : .{
          .rax = true,
          .rdi = true,
          .rsi = true,
          .rdx = true,
          .rcx = true,
          .r11 = true,
          .memory = true,
        });
}
