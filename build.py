#!/usr/bin/env python3

import subprocess
import os
import shlex
import sys

NINJA_LIB_BUILD_CMDS = [
    ["ninja"],
    ["sudo", "ninja", "install"]
]

PY_LIB_INSTALL_CMDS = [
    ["pip", "install", ".."]
]

def log_build(message, built=False):
    print(f"\033[1;33m{ {False: "BUILDING", True: "BUILT"}[built]}\033[0m {message}")

def log_cmd(cmd, finished=False):
    print(f"\033[1;35m{ {False: "EXECUTING", True: "EXECUTED"}[finished]}\033[0m {cmd}")

os.chdir(os.path.join(os.path.dirname(__file__), "build"))

log_build("smort")
for command in NINJA_LIB_BUILD_CMDS + PY_LIB_INSTALL_CMDS:
    log_cmd(shlex.join(command))
    exit_code = subprocess.run(command).returncode
    if exit_code != 0:
        print(f"Command `{command}` failed with exit code {exit_code}. Exiting.")
        sys.exit(exit_code)
    else:
        log_cmd(shlex.join(command), finished=True)
log_build("smort", built=True)
