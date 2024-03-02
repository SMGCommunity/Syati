# Syati
**Syati** provides C++ headers and symbols for writing custom code injections in **Super Mario Galaxy 2**. With this, you can write code, compile code, link to existing functions and structures in the game and load the actual changes.

# What is supplied
Syati provides C++ headers, symbols and the CustomCode loader. Examples can be found [**here.**](https://github.com/SMGCommunity/Syati-Examples)

# Future Plans
The loader currently only supports ``Kamek`` version 1, which is outdated. Support for new hooks and the general format should be implemented in future versions.

# Requirements
In order to use this toolkit, you need to prepare some software and skills:

- The **CodeWarrior PPC EABI C/C++ Compiler**, preferrably application version 4.3.0.172. There is also a free version of that compiler, but you may have to modify the compiler options in the two build scripts.
- A build of the [**Kamek**](https://github.com/Treeki/Kamek) linker.
- Knowledge of **C** / **C++** / **PowerPC**.
- **Python 3.7** or newer.

# Building
Setup is easy. Put the CodeWarrior files (*mwcceppc.exe*, etc.) in ``deps/CodeWarrior`` and the Kamek files in ``deps/Kamek``. Now, try to run the build scripts to check if they recognize the tools.

Provided you have all the requirements set up, building is very easy. To build a binary of your new custom code, run:
```python build.py REGION```, where REGION is the game's target region to build for.

To build the loader, run this instead:
```python buildloader.py REGION```, where REGION is, again, the target region to build for.

The following region targets exist:
- **PAL**: European/Australian releases
- **USA**: American releases
- **JPN**: Japanese releases
- **TWN**: Taiwanese releases
- **KOR**: Korean releases

The generated XML patches for Riivolution can be found in the *bin* folder.
