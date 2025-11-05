/*
Copyright 11/05/2025 https://github.com/su8/nitruks
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>

std::vector<std::string> variants(const std::string &word);

int main(int argc, char *argv[]) {
  if (argc < 6) { return EXIT_FAILURE; }
  std::vector<std::string> usernames = {"frost"};
  std::vector<std::string> roles = {"user", "root"};
  std::vector<std::string> separators = {"", "_"};
  if (argv[1][1] == 'f') { usernames = {argv[2]}; };
  if (argv[3][1] == 'o') { roles = {argv[4], argv[5]}; };
  for (const auto &x : usernames) {
    for (const auto &z : roles) {
      for (const auto &sep : separators) {
        for (const auto &user : variants(x)) { // Iterate over all combinations
          for (const auto &role : variants(z)) { std::cout << user << sep << role << std::endl; }
        }
      }
    }
  }
  return EXIT_SUCCESS;
}

std::vector<std::string> variants(const std::string &word) {
  std::vector<std::string> result;
  result.emplace_back(word);
  std::string capitalized = word;
  if (!capitalized.empty()) { capitalized[0] = static_cast<char>(std::toupper(capitalized[0])); }
  result.emplace_back(capitalized);
  std::string upper = word;
  std::transform(upper.begin(), upper.end(), upper.begin(), [](unsigned char ch) { return std::toupper(ch); } );
  result.emplace_back(upper);
  return result;
}
