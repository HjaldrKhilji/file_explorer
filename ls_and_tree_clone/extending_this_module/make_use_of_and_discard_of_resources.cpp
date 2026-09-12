#include <iostream>
#include<string>
import list_filter_and_format;
using content_t=list_filter_and_format::directory_content_t;
namespace posix{
    extern "C"{
        #include <unistd.h>
        #include <dirent.h>
        #include <fcntl.h>
    }
}
export storage_for_driver;
export namespace storage_for_driver{
    class dynamic_searcher_list{
        dynamic_searcher_list()=default;
        void add(list_filter_and_format::searcher element){
            storage.push_back(element);
        }
        void output_search_and_discard_data_through_storage(){
            for(auto dir : storage){
                content_t temp= dir.list_content();
                //print content and done
            }
        }
    private:
        storage_t storage;

        using storage_t=std::vector<list_filter_and_format::searcher>;
        using value_type=storage_t::value_type;
        using size_type=storage_t::size_type;
    };

};
