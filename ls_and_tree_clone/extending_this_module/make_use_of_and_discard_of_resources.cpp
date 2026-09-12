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
export storage_for_driver;
export namespace storage_for_driver{
    class dynamic_searcher_list{
        dynamic_searcher_list()=default;
        void add(list_filter_and_format::searcher element){
            storage.push_back(element);
        }
    private:
        storage_t storage;
        using storage_t=std::vector<list_filter_and_format::searcher>;
        using value_type=storage_t::value_type;
        using size_type=storage_t::size_type;
    };

};
