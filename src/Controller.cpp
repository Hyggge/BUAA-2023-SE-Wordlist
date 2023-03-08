#include "Controller.h"
#include "Core.h"
#include "Exceptions.h"

Controller::Controller(UserOptions userOptions, char* words[], int len) {
   this->userOptions = userOptions;
   this->words = words;
   this->len = len;
}

Controller::~Controller() {
    for (char* &word : this->result) {
        free(word);
    }
}

void Controller::run() {
    if (userOptions.n + userOptions.w + userOptions.c == 0) {
        throw MissingFunctionalOptionException();
    } else if (userOptions.n + userOptions.w + userOptions.c > 1 ||
        userOptions.n && (userOptions.h + userOptions.t + userOptions.j > 0)) {
        throw OptionIncompatibilityException();
    }
    if (userOptions.n) {
       gen_chains_all(words, len, result);
    } else if (userOptions.w) {
       gen_chain_word(words, len, result, userOptions.h, userOptions.t, userOptions.j, userOptions.r);
    } else {
       gen_chain_char(words, len, result, userOptions.h, userOptions.t, userOptions.j, userOptions.r);
    }
}