import glob
import shutil
import subprocess
import os
import sys


def err(message: str):
    print(f"Error: {message}")
    sys.exit(1)


# Get the target region from the command line
if len(sys.argv) < 2:
    err("Did not specify a target region.")

region = sys.argv[1]

# Check if CodeWarrior and Kamek are present in the toolchain
if not os.path.exists("CodeWarrior/mwcceppc.exe"):
    err("CodeWarrior compiler not found.")
if not os.path.exists("Kamek/Kamek.exe"):
    err("Kamek linker not found.")

# Define the compiler options and command
compiler_options = [
    "-i .",
    "-I-",
    "-i include",
    "-nodefaults",
    "-proc gekko",
    "-Cpp_exceptions off",
    "-enum int",
    "-O4,s",
    "-fp hard",
    "-func_align 4",
    "-str pool",
    "-sdata 0",
    "-sdata2 0",
    f"-D{region}",
    "-DGEKKO",
    "-DMTX_USE_PS",
    "-MMD",
    "-rtti off",
    "-c",
    "-o"
]

command = "CodeWarrior\mwcceppc.exe " + " ".join(compiler_options)

# Clean the entire build folder first if it exists
if os.path.exists("build"):
    shutil.rmtree("build", ignore_errors=True)

# Fetch all source C++ files that need to be compiled
tasks = list()

for root, dirs, files in os.walk("source"):
    for file in files:
        if file.endswith(".cpp"):
            source_path = os.path.join(root, file)
            build_path = source_path.replace("source", "build").replace(".cpp", ".o")

            os.makedirs(os.path.dirname(build_path), exist_ok=True)

            tasks.append((source_path, build_path))

if len(tasks) < 1:
    err("No C++ files to compile!")


# Process all compile tasks
for task in tasks:
    source_path, build_path = task

    print(f"Compiling {source_path}...")

    if subprocess.call(f"{command} {build_path} {source_path}", shell=True) != 0:
        err("Compiler error.")

# Link all object files and create the CustomCode binary
print("Linking...")

object_files = " ".join([task[1] for task in tasks])

kamek_cmd = f"Kamek\Kamek.exe {object_files} -externals=symbols/{region}.txt -output-kamek=CustomCode_{region}.bin"

if subprocess.call(kamek_cmd, shell=True) != 0:
    err("Linking failed.")

# Remove all useless "d" files
for f in glob.glob("*.d"):
    os.remove(f)

print("Done!")
