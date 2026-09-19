module;
export module posix;
export namespace posix{
    extern "C" {
        #include <dirent.h>
        #include <fcntl.h>
        #include <unistd.h>
        struct macros{
        static constexpr auto o_directory=O_DIRECTORY;
        };
    }
}
