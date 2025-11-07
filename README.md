# nitruks [![C/C++ CI](https://github.com/su8/nitruks/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/su8/nitruks/actions/workflows/c-cpp.yml)
Generate alternate case from runtime strings. Perfect for generating permutations of credentials for testing or security auditing. Generates all possible combinations of a username and many roles with different casing styles and separators. It's useful for creating variations of strings, such as for password cracking tools like rainbow tables to be used by `john the ripper`.

# Compile

```make
make -j8 # to use 8 cores/threads in parallel compile
sudo make install
```

---

## Running the program

`nitruks hello world`

---

## Python version of nitruks

```python
import sys;
import itertools;

class Generate(object):
    def __init__(self):
        self.roles = [x for x in sys.argv[1:]];
        str2 = set();
        for x in self.roles:
            for z in itertools.permutations(x, len(x)):
                str2.add(z);
        for v in str2:
            print("{0}".format(''.join([''.join(y) for y in v])));
if __name__ == '__main__':
    Generate();

# And use it like this: python main.py hello world
```

---

## Rust version of nitruks

File `Cargo.toml`

```python
[package]
name = "nitruks"

[[bin]]
name = "nitruks"
path = "/home/USERNAME_GOES_HERE/nitruks.rs"

[dependecies]
itertools = "0.14.0"
```

File `nitruks.rs`

```rust
use std::env;
extern crate itertools;
use itertools::Itertools;

fn main() {
    let args: Vec<String> = env::args().skip(1).collect();
    let mut str: Vec<String> = Vec::new();
    for x in args {
        for z in x.chars().permutations(x.len()) { str.push(z.collect::<String>()); }
    }
    let str: Vec<String> = str.iter().cloned().collect::<std::collections::HashSet<_>>().iter().cloned().collect();
    for v in str {
        println!("{}", v);
    }
}
```

Then run:

```bash
cargo build
cargo install
.cargo/bin/nitruks hello
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