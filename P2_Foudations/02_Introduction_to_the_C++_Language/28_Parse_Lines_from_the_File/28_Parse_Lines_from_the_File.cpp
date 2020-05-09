/*
Write a function ParseLine which accepts a string as an argument. 
Use std::istringstream to parse the line by comma chars, and store the ints in a vector. 
ParseLine should return the line as a vector<int>.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cout;
using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;

// TODO: Add the ParseLine function here.
vector<int> ParseLine(string line){

    vector<int> rst;
    istringstream myrerader(line);
    char c;
    int n;
    while(myrerader>>n>>c){
        rst.push_back(n);
    }

    return rst;
}


void ReadBoardFile(string path) {
  ifstream myfile (path);
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      cout << line << "\n";
    }
  }
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

#include "read.cpp" // For testing.

int main() {
  ReadBoardFile("../../28_Parse_Lines_from_the_File/1.board");
  TestParseLine(); // For testing.
  // Leave commented out.
  // PrintBoard(board);
}
