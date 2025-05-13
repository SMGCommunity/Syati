# Syati
**Syati** provides C++ headers and symbols for writing custom code injections in **Super Mario Galaxy 2**. With this, you can write code, compile code, link to existing functions and structures in the game and load the actual changes.

# What is supplied
Syati provides C++ headers, symbols and the CustomCode loader. Examples can be found [**here.**](https://github.com/SMGCommunity/Syati-Examples)

# Future Plans
Switching to a module system, so only specific code can be compiled at will.

# Requirements
In order to use this toolkit, you need to prepare some software and skills:

- The **CodeWarrior PPC EABI C/C++ Compiler**, preferrably application version 4.3.0.172. There is also a free version of that compiler, but you may have to modify the compiler options in the two build scripts.
- A build of the [**Kamek**](https://github.com/Treeki/Kamek) linker.
- Knowledge of **C** / **C++** / **PowerPC**.
- **Python 3.7** or newer.

# Setup
Setup is easy. Put the CodeWarrior files (*mwcceppc.exe*, etc.) in ``deps/CodeWarrior`` and the Kamek files in ``deps/Kamek``.

The following region targets exist:
- **PAL**: European/Australian releases
- **USA**: American releases
- **JPN**: Japanese releases
- **TWN**: Taiwanese releases
- **KOR**: Korean releases

The generated XML patches for Riivolution can be found in the *bin* folder.
