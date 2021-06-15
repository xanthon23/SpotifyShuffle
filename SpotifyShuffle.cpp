#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using std::string;
using std::vector;
using std::cout;

int main() {
    // initialize random number generator
    std::random_device rd;
    std::mt19937 g(rd());

    // open input file
    string file_name{"input.txt"};
    std::ifstream in_file{file_name};
    if ( !in_file ) {
        std::cerr << "Error: Failed to open file \"" << file_name << "\"\n";
        return -1;
    }

    vector<string> words;
    // if you want to avoid too many reallocations:
    const int expected = 100000000;
    words.reserve(expected);

    string word;
    while ( in_file >> word ) {
        words.push_back(word);
    }

    std::cout << "Number of elements read: " << words.size() << '\n';
    std::cout << "Beginning shuffle..." << std::endl;

    std::shuffle(words.begin(),words.end(),g);

    std::cout << "Shuffle done." << std::endl;

    // do whatever you need to do with the shuffled vector...
    std::ofstream output_file("./NewPlaylist.txt");
    std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(words.begin(), words.end(), output_iterator);
    return 0;
}
