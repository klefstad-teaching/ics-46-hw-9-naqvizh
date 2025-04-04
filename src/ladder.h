#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

void error(string word1, string word2, string msg); // DONE
bool edit_distance_within(const std::string& str1, const std::string& str2, int d); // DONE?
bool is_adjacent(const string& word1, const string& word2); // DONE?
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list); // DONE?
void load_words(set<string> & word_list, const string& file_name); // DONE?
void print_word_ladder(const vector<string>& ladder); // DONE?
void verify_word_ladder(); // DONE?
