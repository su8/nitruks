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
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {
  for (int x = 1; x < argc; x++) {
    std::string s = argv[x];
    std::sort(s.begin(), s.end());
    while (std::next_permutation(s.begin(), s.end())) { std::cout << s << std::endl; }
  }
  return EXIT_SUCCESS;
}