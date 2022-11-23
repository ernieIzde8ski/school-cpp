#!/usr/bin/env python3

"""
Quickly handles creating the next directory.
"""


if __name__ != "__main__":
    raise RuntimeError("mknext.py cannot be a module!")


import re
import subprocess as sp
import sys
from datetime import datetime
from pathlib import Path
from textwrap import fill
from typing import Iterable

from tap import Tap

if sys.stdout.isatty():
    from colors import green, red
else:

    def red(s, bg=None, style=None):
        return s

    green = red

FILLER_TEXT = r"""/*
  {STUDENT}, {DATE}

  {DESCRIPTION}
*/

#include <iostream>
{HEADERS}

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
    """Folder name for new directory."""
    description: str = ""
    """Description filled in at the top of the main.cpp file."""
    nonschool: bool = False
    """If is not a homework assignment."""
    student: str = "Ernest Izdebski"
    """Name of student."""
    include_headers: list[str] = []
    """Headers from headers/ directory to include in file. Linked symbolically."""
    debug_settings: bool = False
    """Output Settings class without doing anything."""

    ## extra type validation and such
    # this is called after class initialization
    def configure(self) -> None:
        # make arguments positional/aliased
        self.add_argument("title")
        self.add_argument("-D", "--description")
        self.add_argument("-N", "--nonschool")
        self.add_argument("-S", "--student")

        # headers need default arguments specified
        self.add_argument("-H", "--include-headers", nargs="*", default=[])

    def process_args(self) -> None:
        # this is called after .parse_args

        # validate title
        self.title = self.title.strip().replace(" ", "-")
        if self.title.endswith(".cpp"):
            title = self.title.removesuffix(".cpp")
            self.title = "-".join(case_split(title))
        else:
            self.title = self.title.lower()

        # assert description
        while not self.description:
            print(red("A description was not provided. Please provide one:"))
            self.description = input().strip()

        # validate description
        # make first letter capitalized, split lines by width 70
        self.description = self.description.removeprefix("Write").strip()
        self.description = fill(
            self.description[:1].upper() + self.description[1:], subsequent_indent="  "
        )

        # validate headers
        new_headers = set()
        headir = Path("headers")
        for header in self.include_headers:
            header = header.removeprefix("headers/")
            if not (headir / header).exists():
                raise ValueError(f"Header 'headers/{header}' not found")
            new_headers.add(header)
        self.include_headers = sorted(new_headers)

    ## utils
    def generate_cpp_file(self, unformatted_text=FILLER_TEXT) -> str:
        date = datetime.now().strftime(r"%Y-%m-%d")
        inclusions = (f'#include "{header}"' for header in self.include_headers)
        return unformatted_text.format(
            STUDENT=self.student,
            DATE=date,
            DESCRIPTION=self.description,
            HEADERS="\n".join(inclusions),
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
settings = Settings(underscores_to_dashes=True).parse_args()

if settings.debug_settings:
    print(settings)
    exit()

file_contents = settings.generate_cpp_file()
target_folder = settings.generate_new_proj_name(root)

# create files
print(green(f"Creating folder at path: {target_folder}"))
target_folder.mkdir()
(target_folder / "main.cpp").write_text(file_contents)

# create symbolic links to header files
if settings.include_headers:
    print("Creating symbolic links...")
    link_name = target_folder.name
    for header in settings.include_headers:
        command = ["ln", "-rs", "-T", f"headers/{header}", f"{link_name}/{header}"]
        print("Command: ", command)
        sp.run(command)

ass = str(target_folder / "assignment.txt")
print("Opening assignment.txt file")

sp.run(["touch", ass])  # makes autosave work by creating an existing file
sp.run(["${EDITOR}", ass])
sp.run(["chmod", "444", ass])  # make file unwriteable

print("Done!")
