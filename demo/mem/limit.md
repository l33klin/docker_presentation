# 物理内存 + SWAP <= 300 MB；1024*1024*300 = 314572800
```
$ cd /sys/fs/cgroup/memory
$ sudo mkdir klin_mem

$ sudo su
$ echo 314572800 > klin_mem/memory.limit_in_bytes
$ echo 0 > klin_mem/memory.swappiness

$ cd -
$ sudo cgexec -g memory:klin_mem ./mem.o
```