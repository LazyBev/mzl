# Check dependecies

```bash
git clone https://github.com/LazyBev/mzl.git; cd mzl; chmod +x check_deps.sh; ./check_deps
```

# How to use

Include `mzl.h` and `mzl.c` in your project directory and when compiling your project file do

```bash
gcc {your_files}.c mzl.c -lglfw -lGLEW -lGL
```
