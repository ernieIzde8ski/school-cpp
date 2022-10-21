#!/usr/bin/env python3

"""
Quickly handles creating the next directory.
"""


if __name__ != "__main__":
    raise RuntimeError("mknext.py cannot be a module!")


import re
from datetime import datetime
from pathlib import Path
from typing import Iterable

from tap import Tap
from textwrap import fill, wrap

import sys

if sys.stdout.isatty():
    from colors import red, green
else:

    def red(s, bg=None, style=None):
        return s

    green = red

FILLER_TEXT = r"""/*
  {STUDENT}, {DATE}

  {DESCRIPTION}
*/

#include <iostream>

int main() {{
  std::cout << "Hello World!\n";
}}
"""

def case_split(string: str) -> Iterable[str]:
    buffer = ""
    for s in string:
        if s.isupper():
            if buffer:
                yield buffer
            buffer = s.lower()
        else:
            buffer += s
    if buffer:
        yield buffer

class Settings(Tap):
    title: str
    description: str = ""
    nonschool: bool = False
    student: str = "Ernest Izdebski"

    ## extra type validation and such
    def configure(self) -> None:
        # this is called after class initialization
        # make arguments positional/aliased
        self.add_argument("title")
        self.add_argument("-D", "--description")
        self.add_argument("-N", "--nonschool")
        self.add_argument("-S", "--student")

    def process_args(self) -> None:
        # this is called after .parse_args
        while not self.description:
            print(red("A description was not provided. Please provide one:"))
            self.description = input().strip()

        self.title = self.title.strip().replace(" ", "-")
        if self.title.endswith(".cpp"):
            title = self.title.removesuffix(".cpp")
            self.title = "-".join(case_split(title))
        else:
            self.title = self.title.lower()
        # make first letter capitalized, split lines by width 70
        self.description = self.description.removeprefix("Write").strip()
        self.description = fill(
            self.description[:1].upper() + self.description[1:], subsequent_indent="  "
        )

    ## utils
    def generate_cpp_file(self, unformatted_text=FILLER_TEXT) -> str:
        date = datetime.now().strftime(r"%Y-%m-%d")
        return unformatted_text.format(
            STUDENT=self.student, DATE=date, DESCRIPTION=self.description
        )

    def generate_new_proj_name(self, proj_folder: Path) -> Path:
        # find highest numbered project
        pattern = re.compile(r"n-(\d\d)(-.+)+" if self.nonschool else r"(\d\d)(-.+)+")
        highest: int = -1

        for path in proj_folder.iterdir():
            if not path.is_dir():
                continue
            # change if newly found number exists & is higher than previous
            match = pattern.match(path.name)
            if match:
                highest = max(highest, int(match[1]))

        # compose response
        resp = (
            ("n-" if self.nonschool else "")
            + str(highest + 1).zfill(2)
            + "-"
            + self.title
        )

        # make result a Path
        return proj_folder / resp


# get values
root = Path(__file__).parent
settings = Settings().parse_args()

file_contents = settings.generate_cpp_file()
target_folder = settings.generate_new_proj_name(root)

# create files
print(green(f"Creating folder at path: {target_folder}"))
target_folder.mkdir()
(target_folder / "main.cpp").write_text(file_contents)
