
# Syati
Syati is a custom code loader for Super Mario Galaxy 2. It is able to compile custom code and link to existing functions in the game to create our own code.

# Requirements
- A revision of CodeWarrior is required to use this setup. However, if you want to download the free version of CodeWarrior, you are free to do so. Be careful, though, you will have to modify the compiler options in both the build.py and buildLoader.bin scripts.
- Python 3.7
- Knowledge of C / C++ / PowerPC

# What is supplied
Two C++ files are supplied with this kit, as a starting point for those who want to make their own hacks.
- **archive.cpp** is an implemention of a simplified archive loader. It can be used to mount any archive from the game's filesystem and access its stored files.
- **factory.cpp** is a implementation of an extended actor list. Instead of replacing actors for our new ones, we simply make our own table and load that if the first NameObj creation function finder fails.
- **SceneChangeArea.cpp** is a complete reimplementation of SceneChangeArea::control(). It takes two Obj_args in, Obj_arg0 acceses a list to which Galaxy to go to, and Obj_arg1 determines the white fade time.