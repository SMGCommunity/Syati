# Syati-Swap
**Syati-Swap** is an experimental branch of Syati that implements relocatable code binaries. It provides C++ headers and symbols for writing custom code injections in **Super Mario Galaxy 2**. With this, you can write code, compile code, link to existing functions and structures in the game and load the actual changes.

# Progress Map
|Feature          |Status|Notes
|---              |---   |---
|Loader           |✅   |Base work done. All implementation *should* work correctly.
|Linker (Syalink) |🟥   |
|Build Tool       |🟥   |
|Rewrite modules  |🟥   |Only primary modules, such as Syati_ObjectFactories, will be rewritten to support relocatable modules.

# Code Binaries
When compiling modules with Syati-Swap, multiple `.rsm` (Relocatable Syati Module) files will be generated. These files hold the compiled code, linking data and module dependencies.

# Requirements
In order to use this toolkit, you need to prepare some software and skills:

- The **CodeWarrior PPC EABI C/C++ Compiler**, preferrably application version 4.3.0.172. There is also a free version of that compiler, but you may have to modify the compiler options in the two build scripts.
- A build of the [**Kamek**](https://github.com/Treeki/Kamek) linker.
- Knowledge of **C** / **C++** / **PowerPC**.
- **Python 3.7** or newer.

# Setup
~~Setup is easy. Put the CodeWarrior files (*mwcceppc.exe*, etc.) in ``deps/CodeWarrior`` and the Kamek files in ``deps/Kamek``~~ (This will be rewritten once I make a linker).

The following region targets exist:
|Name|Letter|Description
|--- |---   |---
|USA |E     |American releases
|PAL |P     |European/Australian releases
|JPN |J     |Japanese releases
|TWN |W     |Taiwanese releases
|KOR |K     |Korean releases