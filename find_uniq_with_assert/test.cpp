// Find and return the index of the first character in a string which does not have the same neighborhood
// Return -1 if there are not any.

#include <string>
#include <iostream>
#include <cassert>

#include <unordered_set>

int findUniqChar(const std::string& s) {

  std::unordered_set<char> repeats;

  int counter = 0;
  for ( auto c : s ) {
    ++counter;
    if ( repeats.end() != repeats.find(c) ) {
      continue;
    }
    if ( std::string::npos == s.find( c, counter ) ) {
      return counter-1;
    }
    repeats.insert(c);
  }
  return -1;
}

int main() {
    assert(findUniqChar("aabbcdeec") == 5);
    assert(findUniqChar("aabbccc") == -1);
    assert(findUniqChar("abbb") == 0);
    assert(findUniqChar("babbbab") == -1);
    assert(findUniqChar("bbba") == 3);
    assert(findUniqChar("baabba") == -1);
    assert(findUniqChar("bbbb") == -1);
    assert(findUniqChar("abb") == 0);
    assert(findUniqChar("bb") == -1);
    assert(findUniqChar("ab") == 0);
    assert(findUniqChar("b") == 0);
    assert(findUniqChar("") == -1);
	
    std::cout << "OK\n";
	
    return 0;
}
