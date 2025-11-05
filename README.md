# nitruks [![C/C++ CI](https://github.com/su8/nitruks/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/su8/nitruks/actions/workflows/c-cpp.yml)
Generate alternate case from runtime strings. Perfect to generate rainbow tables to be used by `john the ripper` to crack passwords.

# Compile

```make
make -j8 # to use 8 cores/threads in parallel compile
sudo make install
```

---

## Program options

**You must specify which option to use. Without specifying one, the program won't do anything.**

`-f` the username/starting string

`-o` the roles, must be exactly `2` separated by space

Example running the program `nitruks -f frost -o user root`

---

## Python version of nitruks

```python
import itertools

class Generate(object):
  def variants(self, word):
    return [word, word.capitalize(), word.upper()];

  def __init__(self):
    self.user = ['frost'];
    self.roles = ['user', 'root'];
    self.seperators = ['', '_'];
    for userName, r, sep in itertools.product(self.user, self.roles, self.seperators):
      for userz, rolez, in itertools.product(self.variants(userName), self.variants(r)):
        print(f"{userz}{sep}{rolez}\n");

if __name__ == '__main__':
  Generate();
```

---

## Windows users

Tested with [Visual Studio Code Editor](https://code.visualstudio.com/download), but you need to install [MingW](https://github.com/niXman/mingw-builds-binaries/releases/download/12.2.0-rt_v10-rev0/x86_64-12.2.0-release-posix-seh-rt_v10-rev0.7z), once downloaded extract it to **C:\MingW**, then re-open [Visual Studio Code Editor](https://code.visualstudio.com/download), you might want to install C\C++ extensions if you plan to write C\C++ code with the editor. If you plan to contribute to this project go to **File->Preferences->Settings** and type to search for **cppStandard** and set it to c17 to both C++ and C.

I use **One Monokai** theme for the [VScode Editor](https://code.visualstudio.com/download)

In [Visual Studio Code Editor](https://code.visualstudio.com/download), go to **Terminal->Configure Tasks...->Create tasks.json from template** and copy and paste this into it:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
        "type": "cppbuild",
        "label": "C/C++",
        "command": "C:\\MingW\\bin\\g++.exe",
        "args": [
            "-fdiagnostics-color=always",
            "-std=c++17",
            "-ggdb",
            "-lpthread",
            "-Wall",
            "-Wextra",
            "-O2",
            "-pipe",
            "-pedantic",
            "-Wundef",
            "-Wshadow",
            "-W",
            "-Wwrite-strings",
            "-Wcast-align",
            "-Wstrict-overflow=5",
            "-Wconversion",
            "-Wpointer-arith",
            "-Wformat=2",
            "-Wsign-compare",
            "-Wendif-labels",
            "-Wredundant-decls",
            "-Winit-self",
            "${file}",
            "-o",
            "${fileDirname}/${fileBasenameNoExtension}"
        ],
        "options": {
            "cwd": "C:\\MingW\\bin"
        },
        "problemMatcher": [
            "$gcc"
        ],
        "group": {
            "kind": "build",
            "isDefault": true
        },
        "detail": "compiler: C:\\MingW\\bin\\g++.exe"
    }
]
}
```

Optioanlly if you want to play around with the code from VSCode's console -- press `CTRL + SHIFT + B` wait until it compiles, after that press **CTRL** + **\`** and paste this `cp -r C:\Users\YOUR_USERNAME_GOES_HERE\Desktop\main.exe C:\MingW\bin;cd C:\MingW\bin;.\main.exe`

---

## Uninstall

```make
sudo make uninstall
```
