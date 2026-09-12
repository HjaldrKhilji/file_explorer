#include <iostream>
#include<string>

namespace posix{
extern "C"{
    #include <unistd.h>
    #include <dirent.h>
    #include <fcntl.h>
}
}
import list_filter_and_format;
import storage_for_driver;

export module driver;
export namespace driver{
class Driver{
public:
    driver(std::vector<std::string> paths):searcher_list{paths}
    {}
    change_effective_working_dir(std::string dir){
        chdir(dir.c_str());
    }
    void add_searcher(std::string element){
        searcher_list.add(searcher_element_t{element});
    }
    void add_searcher_and_change_working_dir(std::string element){
        int fd= open(path_name.c_str(), O_DIRECTORY);
        searcher_list.add(searcher_element_t{fd});
        fchdir(fd);
    }

private:
    using searcher_element_t= storage_for_driver::dynamic_searcher_list::value_type;
    using search_size_t= storage_for_driver::dynamic_searcher_list::size_type;
    storage_for_driver::dynamic_searcher_list searcher_list{};

};
}
