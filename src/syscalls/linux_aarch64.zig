pub inline fn _exit(status: i32) noreturn {
    asm volatile (
        \\ mov x8, #93
        \\ svc #0
        :
        : [status] "{x0}" (status),
        : .{
          .x0 = true,
          .x8 = true,
          .memory = true,
        });

    unreachable;
}

pub inline fn write(fd: i32, buf: [*c]const u8, len: usize) isize {
    return asm volatile (
        \\ mov x8, #64
        \\ svc #0
        : [ret] "={x0}" (-> isize),
        : [fd] "{x0}" (fd),
          [buf] "{x1}" (buf),
          [len] "{x2}" (len),
        : .{
          .x0 = true,
          .x1 = true,
          .x2 = true,
          .x8 = true,
          .memory = true,
        });
}
