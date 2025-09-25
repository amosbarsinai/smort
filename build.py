#!/usr/bin/env python3

import subprocess
import os
import shlex
import sys

from pathlib import Path

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

PY_LIB_INSTALL_CMDS = [
    [sys.executable, "-m", "pip", "install", ".."]
]

def log_build(message, built=False):
    status = "BUILT" if built else "BUILDING"
    print(f"\033[1;33m{status}\033[0m {message}")

def log_cmd(cmd, finished=False):
    status = "EXECUTED" if finished else "EXECUTING"
    print(f"\033[1;35m{status}\033[0m {cmd}")


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
        print(f"\033[1;31mBUILD FAILED\033[0m: Command `{shlex.join(cmd)}` failed with exit code {e.returncode}. Exiting.")
        sys.exit(e.returncode)
    else:
        log_cmd(shlex.join(cmd), finished=True)

log_build("Smort C++ Shared Object")
for cmd in NINJA_LIB_BUILD_CMDS:
    run_cmd(cmd)
log_build("Smort C++ Shared Object", built=True)

log_build("Smort Python Package")
for command in PY_LIB_INSTALL_CMDS:
    run_cmd(command)
log_build("Smort Python Package", built=True)
