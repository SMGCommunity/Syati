import glob
import subprocess
import os.path
from os import path
import sys
from pathlib import Path

def err(str):
    print(f"Error: {str}")
    sys.exit(1)

if not os.path.exists("build"):
    os.mkdir("build")

if not os.path.exists("CodeWarrior/mwcceppc.exe"):
    err("CodeWarrior compiler not found.")

if not os.path.exists("Kamek/Kamek.exe"):
    err("Kamek not found.")

cpp_files = glob.glob("source/*.cpp")

if len(cpp_files) <= 0:
    err("No C++ files to compile!") 

cmd = f"CodeWarrior\mwcceppc.exe -i . -I- -i include -nodefaults -proc gekko -Cpp_exceptions off -enum int -O4,s -fp hard -sdata 0 -sdata2 0 -DGEKKO -DMTX_USE_PS -MMD -rtti off -c -o"

for cpp_file in cpp_files:
    name = Path(cpp_file).stem
    print(f"Compiling {name}.cpp...")
    cmdNew = f"{cmd} build/{name}.o source/{name}.cpp"
    if subprocess.call(cmdNew, shell=True) != 0:
        err("Compiler error.")

print("Linking...")

o_files = glob.glob("build/*.o")
o_str = ' '.join([str(e) for e in o_files])

kamek_cmd = f"Kamek\Kamek.exe {o_str} -externals=symbols/USA.txt -output-kamek=CustomCode.bin"
if subprocess.call(kamek_cmd, shell=True) != 0:
    err("Linking failed.")

print("Done!")