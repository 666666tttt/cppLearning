# Lecture 15

Move Semantics

This project showcases the difference in performance between code that uses move semantics and code which does not. By default, move semantics operations for the `Photo` class are disabled. To enable them and see the difference in performance, run `cmake` like so:

```sh
cmake . -DENABLE_MOVE_SEMANTICS=1
```
next:
```sh
make
```
last:
```sh
./main
```


如果再次运行拷贝语义版本，需要删除所有生成的文件，文件夹
包括：CMakeFiles、cmake_install.cmake、CMakeCache.txt、main、Makefile

然后执行：

```sh
cmake .
make
./main
```

