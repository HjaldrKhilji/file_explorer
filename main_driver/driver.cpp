#include <iostream>
#include<string>
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
            searcher_list.push_back(searcher_element_t{element});
        }
        inline void pop_searcher_from_back(std::string element){
            searcher_list.pop_back();
        }
        inline void clear(){
            searcher_list.clear()
        }
        inline void add_searcher_and_change_working_dir(std::string element){
            int fd= open(path_name.c_str(), O_DIRECTORY);
            searcher_list.push_back(searcher_element_t{fd});
            fchdir(fd);
        }
        inline void output_search(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, formated_data& format){
            searcher_list.output_search(path, index_for_filter,  index_for_ordering,with_custom_format, format);
        }
        inline void output_search_inside_current_dir(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, formated_data& format){
            storage_for_driver::output_search_inside_current_dir(path, index_for_filter,  index_for_ordering,with_custom_format, format);
        }
        inline void output_search_while_checking_errors(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, formated_data& format){
            searcher_list.output_search_while_checking_errors(path, index_for_filter,  index_for_ordering,with_custom_format, format);
        }
        inline void output_search_inside_current_dir_while_checking_errors(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, formated_data& format){
            storage_for_driver::output_search_inside_current_dir_while_checking_errors(path, index_for_filter,  index_for_ordering,with_custom_format, format);
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
