#include <iostream>
#include<string>
#include<array>
//tree must be implemented in some other file and it would probably require a different file, where it tries to make use of the whole project in order to accomplish the desired task
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

}
export module list_filter_and_format
export namespace list_filter_and_format {
    struct directory_content_t{
        dirent **restrict dir_list;
        std::size_t lenght;
        inline directory_content_t(directory_content_t&&)=default;
        inline void operator=(directory_content_t&&)=default;
        //for simplicity, no copying because none is needed
        inline void print_content(std::ostream){
            //todo
        }
        inline ~directory_content_t(){
        for(int i=0; i<content.lenght; i++){
            free(content.dir_list[i]);
        }
        }
    };
    inline directory_content_t list_content(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering){
        directory_content_t result;
        result.lenght=scandir(path.c_str(), &result.dir_list, filter_list[index_for_filter], ordering_list[index_for_ordering]);
        return result;
    }
    class searcher{
    public:
        std::array<main_function_type> filter_list{&filter_non};
        std::array<main_ordering_type> ordering_list{&total_no_op_order};
        inline driver(int d){
        directory_fd=d;
        }
        inline driver(std::string path_name){
            fd= open(path_name.c_str(), O_DIRECTORY);
        }
        inline directory_content_t list_content(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering){
            directory_content_t result;
            result.lenght=scandirat(directory_fd, path.c_str(), &result.dir_list, filter_list[index_for_filter], ordering_list[index_for_ordering]);
            return result;
        }
        inline ~searcher(){
            close(directory_fd);
        }
    private:
        int directory_fd;


    };


};
