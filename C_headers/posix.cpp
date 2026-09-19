module;
export module posix;
export namespace posix{
    extern "C" {
        #include <dirent.h>
        #include <fcntl.h>
    }
}
