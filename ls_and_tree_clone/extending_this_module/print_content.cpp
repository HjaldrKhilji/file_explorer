module;
#include <print>
export module print_content;

namespace posix{
    extern "C"{
        #include <dirent.h>
    }
}

export namespace print_content{
    struct formated_data{
        std::string filename_pre_fix;
        std::string filename_post_fix;
        std::string d_ino_pre_fix;
        std::string d_ino_post_fix;
        std::string d_off_pre_fix;
        std::string d_off_post_fix;
        std::string d_reclean_pre_fix;
        std::string d_reclean_post_fix;
        std::string d_type_pre_fix;
        std::string d_type_post_fix;
    };
    inline void print_content_without_pre_post_fixes_impl(posix::dirent* data_to_print){
        std::println("{}/", data_to_print->d_name);
        std::println("{}",  data_to_print->d_ino);
        std::println("{}",  data_to_print->d_off);
        std::println("{}",  data_to_print->d_reclen);
        std::println("{}",  data_to_print->d_type);
    }
    inline void print_content_with_pre_post_fixes_impl(posix::dirent* data_to_print, formated_data& format){
        std::println("{}{}{}", format.filename_pre_fix, data_to_print->d_name, format.filename_post_fix);
        std::println("{}{}{}", format.d_ino_pre_fix, data_to_print->d_name, format.d_ino_post_fix);
        std::println("{}{}{}", format.d_off_pre_fix, data_to_print->d_name, format.d_off_post_fix);
        std::println("{}{}{}", format.d_reclean_pre_fix, data_to_print->d_name, format.d_reclean_post_fix);
        std::println("{}{}{}", format.d_type_pre_fix, data_to_print->d_name, format.d_type_post_fix);
    }
    inline void print_content(posix::dirent* data_to_print, bool with_custom_format, formated_data& format){
        if(with_custom_format){
            print_content_with_pre_post_fixes_impl(data_to_print, format);
        }
        else{
            print_content_without_pre_post_fixes_impl(data_to_print);
        }
    }

};
