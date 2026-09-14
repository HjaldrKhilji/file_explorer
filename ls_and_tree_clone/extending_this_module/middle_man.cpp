#include <iostream>
#include<string>
import list_filter_and_format;
using content_t=list_filter_and_format::directory_content_t;
using searcher=list_filter_and_format::searcher;
export storage_for_driver;
export namespace storage_for_driver{
    inline void output_search(){
        content_t temp= list_filter_and_format::list_content(path, index_for_filter,  index_for_ordering,with_custom_format, format);
        tmp.print_content(with_custom_format, format);
    }
    inline void output_search_while_checking_errors(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, formated_data& format){
        content_t temp= list_filter_and_format::list_content_while_checking_errors(path, index_for_filter,  index_for_ordering,with_custom_format, format);
        tmp.print_content(with_custom_format, format);
    }
    using storage_t=std::vector<searcher>;

    class dynamic_searcher_list: public storage{
        inline void output_search_inside_current_dir(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, formated_data& format){
            for(auto dir : storage){
                content_t temp= dir.list_content(path, index_for_filter,  index_for_ordering,with_custom_format, format);
                tmp.print_content(with_custom_format, format);
            }
        }
        inline void output_search_inside_current_dir_while_checking_errors(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, formated_data& format){
            for(auto dir : storage){
                content_t temp= dir.list_content_while_checking_errors(path, index_for_filter,  index_for_ordering,with_custom_format, format);
                tmp.print_content(with_custom_format, format);
            }
        }
    };


};
