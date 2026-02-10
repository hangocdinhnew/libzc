const std = @import("std");
const windows = std.os.windows;
const kernel32 = windows.kernel32;

pub export fn _exit(exit: i32) noreturn {
    kernel32.ExitProcess(@intCast(exit));
}

pub export fn write(fd: i32, buf: [*c]const u8, len: usize) isize {
    const handle = switch (fd) {
        1 => kernel32.GetStdHandle(windows.STD_OUTPUT_HANDLE),
        2 => kernel32.GetStdHandle(windows.STD_ERROR_HANDLE),
        else => return -1,
    };

    var written: u32 = 0;

    const ok = kernel32.WriteFile(
        handle,
        buf,
        @intCast(len),
        &written,
        null,
    );

    if (ok == 0) return -1;
    return @intCast(written);
}
