Sort of a skeleton for writing a screen emulator for 8bit cpu emulation. Going to use it for a CHIP-8 emulator in c and maybe a 6502 something or other later.

You'll probably need to install libglut, do it like this
```bash
sudo apt install libglut-dev
```

Then do a make

If you wanna setup the debugger and the vscode shit do this

```bash
sudo apt-get install build-essential gdb
```

Ok there's some tedious bullshit we had to do, make sure you check out whats in .vscode/tasks.json and .vscode/launch.json.
It should work now.

