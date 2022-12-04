#pragma once
#include <string>
using namespace std;

const int MAX_INT = 0x7FFFFFFF;

const int HT_FOLDER_MAX_SIZE = 50;
const int HT_FILE_MAX_SIZE = 500;

const char VALID_CHARS[] = {
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',

  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
  'u', 'v', 'w', 'x', 'y', 'z',

  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
  'U', 'V', 'W', 'X', 'Y', 'Z',

  '_', '.', '-', '(', ')'
};

constexpr int NUM_CHILD_TRIE_NODE = sizeof(VALID_CHARS) / sizeof(char);

const string ORDERED_FOLDER_NAME = "OrderedFolder";
