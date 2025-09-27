#!/usr/bin/env python3

import subprocess
import os
import shlex
import sys

from pathlib import Path

# ANSI color codes
RESET = "\033[0m"
BOLD = "\033[1m"
RED = "\033[31m"
YELLOW = "\033[33m"
MAGENTA = "\033[35m"

def help_message():
    print("Usage: build.py [-e | -h]")
    print("  -e: install the Python package in editable mode")
    print("  -h: show this help message and exit")

# parse command line args
editable = False
if len(sys.argv) > 2:
    print("Too many arguments.")
    help_message()
    sys.exit(1)
elif len(sys.argv) == 2:
    if sys.argv[1] == "-e":
        editable = True
        print("Set editable flag to True.")
    elif sys.argv[1] == "-h":
        help_message()
        sys.exit(0)
    else:
        print(f"Unknown option: {sys.argv[1]}")
        help_message()
        sys.exit(1)


if sys.prefix == sys.base_prefix:
    print("It looks like you are not in a Python virtual environment. It's recommended to use one - Smort is still in heavy development.")
    while True:
        answer = input("Do you want to continue anyway? [y/N]\n>> ").strip().lower()
        if answer in ["y", "yes"]:
            break
        elif answer in ["n", "no", ""]:
            print("Exiting.")
            sys.exit(0)
        else:
            print("Please answer 'y' or 'n'.")


NINJA_LIB_BUILD_CMDS = [
    ["ninja"],
    ["sudo", "ninja", "install"]
]

py_lib_install_cmds = [
    [sys.executable, "-m", "pip", "install", ".."]
]
if editable:
    py_lib_install_cmds[0].insert(4, "-e")

def log_build(message, built=False):
    status = "BUILT" if built else "BUILDING"
    print(f"{BOLD}{YELLOW}{status}{RESET} {message}")

def log_cmd(cmd, finished=False):
    status = "EXECUTED" if finished else "EXECUTING"
    print(f"{BOLD}{MAGENTA}{status}{RESET} {cmd}")


build_dir = Path(__file__).parent / "build"
if not build_dir.is_dir():
    print(f"Error: build directory {build_dir} does not exist.")
    print("Please report this error at https://github.com/AmosBarSinai/smort/issues - the build/ directory should be created once ninja has been run.")
    sys.exit(1)
os.chdir(build_dir)

def run_cmd(cmd):
    log_cmd(shlex.join(cmd))
    try:
        subprocess.run(cmd, check=True)
    except subprocess.CalledProcessError as e:
        print(f"{BOLD}{RED}BUILD FAILED{RESET}: Command `{shlex.join(cmd)}` failed with exit code {e.returncode}. Exiting.")
        sys.exit(e.returncode)
    else:
        log_cmd(shlex.join(cmd), finished=True)

log_build("Smort C++ Shared Object")
for cmd in NINJA_LIB_BUILD_CMDS:
    run_cmd(cmd)
log_build("Smort C++ Shared Object", built=True)

log_build("Smort Python Package")
for command in py_lib_install_cmds:
    run_cmd(command)
log_build("Smort Python Package", built=True)
