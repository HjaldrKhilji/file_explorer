//tree must be implemented in some other file and it would probably require a different file, where it tries to make use of the whole project in order to accomplish the desired task
module;
#include <iostream>
#include <string>
#include <array>
#include <system_error>
#include <print>
#include <locale>
import posix;
import print_content;
export module list_filter_and_format;


using filter_type=int (*) (const posix::dirent *);
int filter_non(const posix::dirent *) {
        return 1;
    }
using ordering_type=int (*) (const posix::dirent **,const posix::dirent **);
int total_no_op_order(const posix::dirent **,const posix::dirent **) {
        return -1;
    }
auto filter_list= std::to_array({&filter_non});
auto ordering_list= std::to_array({&total_no_op_order});

export namespace list_filter_and_format {
    struct directory_content_t{
        posix::dirent** dir_list;
        std::size_t lenght;
        constexpr inline directory_content_t()=default;
        constexpr inline directory_content_t(directory_content_t&&)=default;
        constexpr inline directory_content_t& operator=(directory_content_t&&)=default;
        //for simplicity, no copying because none is needed
        inline void print_content(posix::dirent* data_to_print, bool with_custom_format, print_content::formated_data& format){
            print_content::print_content_impl(data_to_print, with_custom_format, format);
        }
        inline ~directory_content_t(){
        for(int i=0; i<lenght; i++){
            free(dir_list[i]);
        }
        }

    };
inline directory_content_t list_content(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering){
        directory_content_t result;
        result.lenght=posix::scandir(path.c_str(), &result.dir_list, filter_list[index_for_filter], ordering_list[index_for_ordering]);
        return result;
    }
inline directory_content_t list_content_while_checking_errors(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering){
        directory_content_t result = list_content(path, index_for_filter, index_for_ordering);
        if(result.lenght==-1){
            const std::error_condition econd =
            std::system_category().default_error_condition(errno);
            std::locale::global(std::locale(""));
            std::cerr.imbue(std::locale());//pretends your system is using utf-8 which most systems do (println) dosent support std::wcerr or std::wcout since they are wostreams rather than ostreams(println only accepts this).
            std::println(std::cerr, "Category:     {}\nValue:   {}\nMessage:  {}\n\n",
                         econd.category().name(), econd.value(), econd.message());
        }
        return result;
    }
class searcher{
    public:
        inline searcher(int d):directory_fd{d}{        }
        inline searcher(std::string path_name){
            directory_fd= posix::open(path_name.c_str(), posix::macros::o_directory);
        }
        inline directory_content_t list_content(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering){
            directory_content_t result;
            result.lenght=posix::scandirat(directory_fd, path.c_str(), &result.dir_list, filter_list[index_for_filter], ordering_list[index_for_ordering]);
            return result;
        }
        inline directory_content_t list_content_while_checking_errors(std::string path, std::size_t index_for_filter, std::size_t index_for_ordering){
            directory_content_t result = list_content(path, index_for_filter, index_for_ordering);
            if(result.lenght==-1){
                const std::error_condition econd =
                std::system_category().default_error_condition(errno);
                std::locale::global(std::locale(""));
                std::cerr.imbue(std::locale());//pretends your system is using utf-8 which most systems do (println) dosent support std::wcerr or std::wcout since they are wostreams rather than ostreams(println only accepts this).
                std::println(std::cerr, "Category:     {}\nValue:   {}\nMessage:  {}\n\n",
                             econd.category().name(), econd.value(), econd.message());
            }
            return result;
        }

        inline ~searcher(){
            posix::close(directory_fd);
        }
    private:
        int directory_fd;


    };


};
