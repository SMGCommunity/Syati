# Syati

**Syati** provides C++ headers, linker symbols, and a loader for writing and injecting custom code into **Super Mario Galaxy 2**. SMGCommunity comprises many [example applications](https://github.com/orgs/SMGCommunity/repositories) of Syati so be sure to check those out. To compile the code, it is recommended to use [SyatiModuleBuildTool](https://github.com/SMGCommunity/SyatiModuleBuildTool). [SyatiManager](https://github.com/SMGCommunity/SyatiManager) has a frontend that can help you link and manage modules into CustomCode binaries that can be loaded by the loader.

## Supported games

All five regional versions of SMG2 are supported. The following region targets exist:

- ``SB4P``: Europe / Australia
- ``SB4E``: Americas
- ``SB4J``: Japan
- ``SB4W``: Asia (Taiwan, Hong Kong)
- ``SB4K``: Korea

## Requirements

The compiler and linker are not part of Syati and they must be provided by the user. Specifically, the following software and skills are needed to develop code for SMG2:

- The **CodeWarrior PPC EABI C/C++ Compiler**, preferrably application version 4.3.0.172. There is also a free version of that compiler, but you may have to modify the compiler options in the build script.
- A build of the [**Kamek**](https://github.com/Treeki/Kamek) linker.
- Knowledge of **C**, **C++**, and **PowerPC**.
- **Python 3.12** or newer for building the loader.
