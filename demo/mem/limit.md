# 
物理内存 + SWAP <= 300 MB；`1024*1024*300 = 314572800`
### 编译
```
$ gcc -o mem.o mem.c
$ ./mem.o
```
### 设置限制
```
$ cd /sys/fs/cgroup/memory
$ sudo mkdir klin_mem

$ sudo su
$ echo 314572800 > klin_mem/memory.limit_in_bytes
$ echo 0 > klin_mem/memory.swappiness
```
### 使用cgroup限制执行
```
$ cd -
$ sudo cgexec -g memory:klin_mem ./mem.o
```