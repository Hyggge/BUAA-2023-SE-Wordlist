#include "test.h"


TEST(genChainsAll, genChainsAllTest1) {
    int len = 4;
    char* words[] = {"woo", "oom", "moon", "noox"};
    const char* expected[] = {
            "woo oom",
            "moon noox",
            "oom moon",
            "woo oom moon",
            "oom moon noox",
            "woo oom moon noox"
    };

    char* result[100];
    int resultLen = gen_chains_all(words, len, result);
    ASSERT_EQ(resultLen, 6);

    std::sort(expected, expected + resultLen, my_cmp);
    std::sort(result, result + resultLen, my_cmp);

    for (int i = 0; i < 6; ++i) {
    ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainsAll, genChainsAllTest2) {
    char* words[] = {"aa", "ab", "bb", "bc", "cc"};
    const char* expected[] = {
            "bc cc",
            "ab bc",
            "ab bc cc",
            "bb bc",
            "bb bc cc",
            "ab bb",
            "ab bb bc",
            "ab bb bc cc",
            "aa ab",
            "aa ab bc",
            "aa ab bc cc",
            "aa ab bb",
            "aa ab bb bc",
            "aa ab bb bc cc"
    };

    int len = sizeof(words) / sizeof(words[0]);
    int expectedLen = sizeof(expected) / sizeof(expected[0]);
    char* result[100];
    int resultLen = gen_chains_all(words, len, result);
    ASSERT_EQ(resultLen, expectedLen);

    std::sort(expected, expected + resultLen, my_cmp);
    std::sort(result, result + resultLen, my_cmp);

    for (int i = 0; i < expectedLen; ++i) {
        ASSERT_STREQ(result[i], expected[i]);
    }
}

TEST(genChainsAll, genChainsAllTest3) {
    char* words[] = {"ab", "bc", "ca"};
    int len = sizeof(words) / sizeof(words[0]);
    char* result[100];
    try {
        gen_chains_all(words, len, result);
        FAIL();
    } catch (std::logic_error& e) {
        ASSERT_STREQ(e.what(), "Circle detected");
    } catch (...) {
        FAIL();
    }
}

TEST(genChainsAll, genChainsAllTest4) {
    char* words[] = {"wa", "aba", "aca"};
    int len = sizeof(words) / sizeof(words[0]);
    char* result[100];
    try {
        gen_chains_all(words, len, result);
        FAIL();
    } catch (std::logic_error& e) {
        ASSERT_STREQ(e.what(), "Circle detected");
    } catch (...) {
        FAIL();
    }
}

TEST(genChainsAll, genChainsAllTest5) {
    char* words[] = {"wA", "aBa"};
    int len = sizeof(words) / sizeof(words[0]);
    char* result[100];
    try {
        gen_chains_all(words, len, result);
        FAIL();
    } catch (std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "Word must be lower case in core");
    } catch (...) {
        FAIL();
    }
}

TEST(genChainsAll, genChainsAllTest6) {
    char* words[] = {
            "aa", "ab", "bb", "bc", "cc", "cd", "dd", "de", "ee", "ef",
            "ff", "fg", "gg", "gh", "hh", "hi", "ii", "ij", "jj", "jk",
            "kk", "kl", "ll", "lm",
    };
    int len = sizeof(words) / sizeof(words[0]);
    char* result[20010];
    try {
        gen_chains_all(words, len, result);
        FAIL();
    } catch (std::logic_error& e) {
        ASSERT_STREQ(e.what(), "Length of result exceeds the upper limit(20000)");
    } catch (...) {
        FAIL();
    }
}