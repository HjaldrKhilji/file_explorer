#include <iostream>
#include<string>
import list_filter_and_format;
using content_t=list_filter_and_format::directory_content_t;
using searcher=list_filter_and_format::searcher;
namespace posix{
    extern "C"{
        #include <unistd.h>
        #include <dirent.h>
        #include <fcntl.h>
    }
}
export storage_for_driver;
export namespace storage_for_driver{
    inline void output_search(){
        content_t temp= list_filter_and_format::list_content();
        //print content and done
    }
    inline void output_search_while_checking_errors(){
        content_t temp= list_filter_and_format::list_content_while_checking_errors();
        //print content and done
    }
    using storage_t=std::vector<searcher>;

    class dynamic_searcher_list: public storage{
        inline void output_search_inside_current_dir(){
            for(auto dir : storage){
                content_t temp= dir.list_content();
                //print content and done
            }
        }
        inline void output_search_inside_current_dir(){
            for(auto dir : storage){
                content_t temp= dir.list_content_while_checking_errors();
                //print content and done
            }
        }
    };


};
