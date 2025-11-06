# Copyright 11/06/2025 https://github.com/su8/nitruks

#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version

#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#GNU General Public License for more details

#You should have received a copy of the GNU General Public License
#along with this program. If not, see <https://www.gnu.org/licenses/>

import sys;
import itertools;

class Generate(object):
    def variants(self, word):
        return [word, word.capitalize(), word.upper()];

    def __init__(self):
        if len(sys.argv) < 4:
            sys.exit(1);
        self.user = [];
        if sys.argv[1][1] == 'f':
            self.user.append(sys.argv[2]);
        self.roles = [];
        self.seperators = ['', '_'];
        if sys.argv[3][1] == 'o':
            self.roles = [x for x in sys.argv[4:]];
        for userName, r, sep in itertools.product(self.user, self.roles, self.seperators):
            for userz, rolez in itertools.product(self.variants(userName), self.variants(r)):
                print(f"{userz}{sep}{rolez}\n");
if __name__ == '__main__':
    Generate();