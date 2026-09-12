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
        inline driver(std::vector<std::string> paths):searcher_list{paths}
        {}
        inline change_effective_working_dir(std::string dir){
            chdir(dir.c_str());
        }
        inline void add_searcher(std::string element){
            searcher_list.add(searcher_element_t{element});
        }
        inline void add_searcher_and_change_working_dir(std::string element){
            int fd= open(path_name.c_str(), O_DIRECTORY);
            searcher_list.add(searcher_element_t{fd});
            fchdir(fd);
        }
        inline void output_search_and_discard_data_through_storage(){
            searcher_list.output_search_and_discard_data_through_storage();
        }
        inline void output_search_and_discard_data_inside_current_dir(){
            storage_for_driver::output_search_and_discard_data_inside_current_dir();
        }
        inline void change_an_entry(search_size_t index, searcher_element_t a){
            searcher_list[index]=a;
        }
        
    private:
        using searcher_element_t= storage_for_driver::dynamic_searcher_list::value_type;
        using search_size_t= storage_for_driver::dynamic_searcher_list::size_type;
        storage_for_driver::dynamic_searcher_list searcher_list{};
        
    };
}
