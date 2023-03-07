#ifndef WORDLIST_FILEPARSER_H
#define WORDLIST_FILEPARSER_H

#include "Constant.h"
#include <string>

class FileParser {
private:
    char* words[WORDS_MAX_NUM];
    int wordsNum;

public:
    FileParser(std::string filename);

    char** getWords();

    int getWordsNum() const;
};

#endif //WORDLIST_FILEPARSER_H