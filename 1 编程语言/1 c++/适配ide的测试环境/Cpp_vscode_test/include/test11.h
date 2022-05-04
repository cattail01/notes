#ifndef TEST_11_H
#define TEST_11_H

#include <string>
#include <map>
#include <vector>
#include <memory>

class StrBlob{
    public:
        typedef std::vector<std::string>::size_type size_type;
        StrBlob();
        StrBlob(std::initializer_list<std::string> il);
        size_type size(){return data->size();}
        bool empty(){return data->empty();}
        
    private:
        std::shared_ptr<std::vector<std::string>> data;
};

void count_words_1();
void count_words_2();
void count_word_myself(std::string);
void count_word_exclude_upper_and_others(std::string);
void difference_between_multi_and_not();
void test_11_9(const char *);



#endif // TEST_11_H
