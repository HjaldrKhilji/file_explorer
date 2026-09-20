module;
#include <iostream>
#include<string>
#include<vector>
import list_filter_and_format;
import print_content;
export module storage_for_driver;
using content_t=list_filter_and_format::directory_content_t;
export namespace storage_for_driver{
    inline void output_search(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, print_content::formated_data& format){
        content_t temp= list_filter_and_format::list_content(path, index_for_filter,  index_for_ordering);
        temp.print_content(with_custom_format, format);
    }
    inline void output_search_while_checking_errors(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, print_content::formated_data& format){
        content_t temp= list_filter_and_format::list_content_while_checking_errors(path, index_for_filter,  index_for_ordering);
        temp.print_content(with_custom_format, format);
    }
    using storage_t=std::vector<list_filter_and_format::searcher>;

    class dynamic_searcher_list: public storage_t{
    public:
        inline dynamic_searcher_list()=default;
        inline dynamic_searcher_list(std::vector<std::string> search_paths){
            auto back_it= std::back_insert_iterator<storage_t>(*this);
            for(auto x: search_paths){
                *back_it= list_filter_and_format::searcher{x};
            }
        }
        inline void output_search(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, print_content::formated_data& format){
            for(auto dir : *this){
                content_t temp= dir.list_content(path, index_for_filter,  index_for_ordering);
                temp.print_content(with_custom_format, format);
            }
        }
        inline void output_search_while_checking_errors(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering,bool with_custom_format, print_content::formated_data& format){
            for(auto dir : *this){
                content_t temp= dir.list_content_while_checking_errors(path, index_for_filter,  index_for_ordering);
                temp.print_content(with_custom_format, format);
            }
        }
    };


};
