pub inline fn _exit(status: i32) noreturn {
    asm volatile (
        \\movz x16, #0x0001
        \\movk x16, #0x2000, lsl #16
        \\ svc #0
        :
        : [status] "{x0}" (status),
        : .{
          .x0 = true,
          .x16 = true,
          .memory = true,
        });

    unreachable;
}

pub inline fn write(fd: i32, buf: [*c]const u8, len: usize) isize {
    return asm volatile (
        \\movz x16, #0x0004
        \\movk x16, #0x2000, lsl #16
        \\svc #0
        : [ret] "={x0}" (-> isize),
        : [fd] "{x0}" (fd),
          [buf] "{x1}" (buf),
          [len] "{x2}" (len),
        : .{
          .x0 = true,
          .x1 = true,
          .x2 = true,
          .x16 = true,
          .memory = true,
        });
}
