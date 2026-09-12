#include <iostream>
#include<string>
#include<array>
//error checking and memory management must be done by the caller, along with anything else that must be added for additional redundency
namespace posix{
    extern "C"{
        #include <dirent.h>
        #include <fcntl.h>

    }
    using filter_type=int (const struct dirent *)*;
    int filter_non(const struct dirent *) {
        return 1;
    }
    using ordering_type=int (const struct dirent **,const struct dirent **)*;
    int total_no_op_order(const struct dirent **,const struct dirent **) {
        return -1;
    }
    struct directory_content_t{
        dirent **restrict dir_list;
        std::size_t lenght;
    };
}
export module list_filter_and_format
export namespace list_filter_and_format {
    directory_content_t list_dirs(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering){
        directory_content_t result;
        result.lenght=scandir(path.c_str(), &result.dir_list, filter_list[index_for_filter], ordering_list[index_for_ordering]);
        return result;
    }
    class searcher{
    public:
        std::array<main_function_type> filter_list{&filter_non};
        std::array<main_ordering_type> ordering_list{&total_no_op_order};
        driver(int d){
        directory_fd=d;
        }
        driver(std::string path_name){
            fd= open(path_name.c_str(), O_DIRECTORY);
        }
        directory_content_t list_dirs(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering){
            directory_content_t result;
            result.lenght=scandirat(directory_fd, path.c_str(), &result.dir_list, filter_list[index_for_filter], ordering_list[index_for_ordering]);
            return result;
        }
    private:
        int directory_fd;//this is a none owning file descriptor, meaning, this module dosent own it


    };


};
