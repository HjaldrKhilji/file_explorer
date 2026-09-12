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
    inline void output_search_and_discard_data_inside_current_dir(){
        content_t temp= list_content();
        //print content and done
    }
    class dynamic_searcher_list{
        inline dynamic_searcher_list()=default;
        inline void add(value_type element){
            storage.push_back(element);
        }
        inline void output_search_and_discard_data_through_storage(){
            for(auto dir : storage){
                content_t temp= dir.list_content();
                //print content and done
            }
        }

        inline value_type& operator[](size_type index){
            return storage[index];
        }
    private:
        storage_t storage;

        using storage_t=std::vector<value_type>;
        using value_type=storage_t::value_type;
        using size_type=storage_t::size_type;
    };

};
