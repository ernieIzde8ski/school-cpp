#!/usr/bin/python

"""
Quickly handles creating the next directory.
"""

from pathlib import Path
import re


if __name__ != "__main__":
    raise RuntimeError("mknext.py cannot be a module!")

FILLER_TEXT = r"""/*
  Ernest Izdebski, %DATE%

  %DESCRIPTION%
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";
}
"""


root = Path(__file__).parent
_pattern = re.compile(r"(\d\d)(-.+)+")

def get_highest():
    """Returns the highest numbered project in this folder."""
    current_highest: int = -1
    for p in root.iterdir():
        if not p.is_dir():
            continue
        match = _pattern.match(p.name)
        if match:
            n = int(match[1])
            current_highest = max(current_highest, n)
    return current_highest

def get_new_project_name():
    """Asks for a project name if none is provided."""
    import sys
    res = sys.argv[1] if len(sys.argv) > 1 else input("Project name?  ")
    return res.strip().replace(" ", "-").lower()

num = str(get_highest()+1).zfill(2)
title = get_new_project_name()
target = Path(f"{num}-{title}")
print("Creating folder at path:", target)
target.mkdir()
main_file = target / "main.cpp"
main_file.write_text(FILLER_TEXT)
(target / "main.cpp").touch()
