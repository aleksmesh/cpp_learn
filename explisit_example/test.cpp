// Find and return the index of the first character in a string which does not have the same neighborhood
// Return -1 if there are not any.

#include <string>
#include <iostream>
#include <cassert>

#include <unordered_set>

#include <fmt/core.h>
#include <fmt/ranges.h>

int findUniqChar(const std::string& s) {
  unsigned char ln = '\0';
  unsigned char rn = '\0';
  for ( size_t i = 0, sz = s.size(); i < sz; ++i ) {
    if ( ( 0 < i && s[i] != s[i-1] )
        && ( i < sz - 1 && < s[i] != s[i+1] ) ) {
      return i;
    }
  }
  return -1;
}

int main() {
    assert(findUniqChar("aabbcdeec") == 4);
    assert(findUniqChar("aabbccc") == -1);
    assert(findUniqChar("abbb") == 0);
    assert(findUniqChar("babbbab") == 0);
    assert(findUniqChar("bbba") == 3);
    assert(findUniqChar("baabba") == 0);
    assert(findUniqChar("bbbb") == -1);
    assert(findUniqChar("abb") == 0);
    assert(findUniqChar("bb") == -1);
    assert(findUniqChar("ab") == 0);
    assert(findUniqChar("b") == 0);
    assert(findUniqChar("") == -1);
	
    std::cout << "OK\n";
	
    return 0;
}
