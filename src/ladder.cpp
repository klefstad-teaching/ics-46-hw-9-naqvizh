#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cout << "Error with words: " << word1 << ", " << word2 << ": " << msg << endl;
} // DONE

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) // Are str1 and str2 neighbors
{
    if (str1 == str2) return true; // A word is neighbors with itself
    int size1 = str1.size();
    int size2 = str2.size();
    if (abs(size1 - size2) > 1) return false; // the words cannot vary by > 1 character length
    
    int count = 0;
    int c1 = 0;
    int c2 = 0;
    while (c1 < size1 && c2 < size2) {
        if (str1[c1] == str2[c2]) { // letters are the same, keep going
            ++c1;
            ++c2;
        }
        else {
            if (size1 > size2) ++c1; // str1 is longer so scoot it down
            else if (size2 > size1) ++c2; // str2 is longer so scoot it down
            else { // keep moving
                ++c1;
                ++c2;
            }
            ++count; 
        }
    }
    // remaining chars
    count += abs(size1 - c1);
    count += abs(size2 - c2);
    return count == d; // is the difference between them > 1?
} // DONE?

bool is_adjacent(const string& word1, const string& word2)
{
    if (word1 == word2) return true; // A word is neighbors with itself
    int size1 = word1.size();
    int size2 = word2.size();
    if (abs(size1 - size2) > 1) return false; // the words cannot vary by > 1 character length
    
    int count = 0;
    int c1 = 0;
    int c2 = 0;
    while (c1 < size1 && c2 < size2) {
        if (word1[c1] == word2[c2]) { // letters are the same, keep going
            ++c1;
            ++c2;
        }
        else {
            if (size1 > size2) ++c1; // word1 is longer so scoot it down
            else if (size2 > size1) ++c2; // word2 is longer so scoot it down
            else { // keep moving
                ++c1;
                ++c2;
            }
            ++count; 
        }
    }
    // remaining chars
    count += abs(size1 - c1);
    count += abs(size2 - c2);
    return count == 1; // is the difference between them > 1?
} // DONE?

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    if (word_list.empty()) return {};

    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    std::unordered_set<std::string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();

        string last_word = ladder.back();

        for (const string& word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);

                    if (word == end_word) return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }   
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name)
{
    return;
}

void print_word_ladder(const vector<string>& ladder)
{
    if (ladder.empty()) {
        cout << "Error: No ladder found" << endl;
        return;
    }
    for (const string& word : ladder) {
        cout << word << " " << endl;
    }
    cout << endl;
} // DONE?

void verify_word_ladder()
{
    return;
}

// g++ -o ladder_main src/ladder.cpp src/ladder_main.cpp