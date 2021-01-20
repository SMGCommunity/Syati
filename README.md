# Syati
Syati is a custom code loader for Super Mario Galaxy 2. It is able to compile custom code and link to existing functions in the game to create our own code. This codebase is what is used in Super Mario Island. 

# Requirements
- A revision of CodeWarrior is required to use this setup. However, if you want to download the free version of CodeWarrior, you are free to do so. Be careful, though, you will have to modify the compiler options in both the build.py and buildLoader.bin scripts.
- Python 3.7
- Knowledge of C / C++ / PowerPC

# What is supplied
Two C++ files are supplied with this kit, as a starting point for those who want to make their own hacks.
- ExtendedActorFactory.cpp is a implementation of an extended actor list. Instead of replacing actors for our new ones, we simply make our own table and load that if the first NameObj creation function finder fails.
- SceneChangeArea.cpp is a complete reimplementation of SceneChangeArea::control(). It takes two obj_args in, obj_arg0 acceses a list to which Galaxy to go to, and obj_arg1 determines the white fade time.