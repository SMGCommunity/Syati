import glob
import subprocess
import os.path
from os import path
import sys
from pathlib import Path


def err(str):
    print(f"Error: {str}")
    sys.exit(1)


region = sys.argv[1]

# Try to create build folder if it does not exist
if not os.path.exists("build"):
    os.mkdir("build")
# Clean existing object files
else:
    for f in glob.glob(os.path.join("build", "*.o")):
        os.remove(f)

# Check if CodeWarrior and Kamek are in the build directory
if not os.path.exists("CodeWarrior/mwcceppc.exe"):
    err("CodeWarrior compiler not found.")

if not os.path.exists("Kamek/Kamek.exe"):
    err("Kamek not found.")

# Fetch CPP files that will be compiled
cpp_files = glob.glob("source/*.cpp")

if len(cpp_files) <= 0:
    err("No C++ files to compile!") 

cmd = f"CodeWarrior\mwcceppc.exe -i . -I- -i include -nodefaults -proc gekko -Cpp_exceptions off -enum int -O4,s -fp hard -sdata 0 -sdata2 0 -D{region} -DGEKKO -DMTX_USE_PS -MMD -rtti off -c -o"

for cpp_file in cpp_files:
    name = Path(cpp_file).stem

    print(f"Compiling {name}.cpp...")

    if subprocess.call(f"{cmd} build/{name}.o {cpp_file}", shell=True) != 0:
        err("Compiler error.")

print("Linking...")

o_files = glob.glob("build/*.o")
o_str = ' '.join([str(e) for e in o_files])

kamek_cmd = f"Kamek\Kamek.exe {o_str} -externals=symbols/{region}.txt -output-kamek=CustomCode_{region}.bin"
if subprocess.call(kamek_cmd, shell=True) != 0:
    err("Linking failed.")

# Remove "d" files
for f in  glob.glob("*.d"):
    os.remove(f)

print("Done!")
