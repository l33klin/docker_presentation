执行一个死循环，并获得进程pid
```
$ while : ; do : ; done &
```
新建一个cgroups的CPU子分组
```
$ cd /sys/fs/cgroup/cpu
$ sudo su
$ mkdir klin_cpu && cd klin_cpu
```
设置这个分组的CPU配额， 20000/100000 = 20%
```
$ cat cpu.cfs_period_us
$ cat cpu.cfs_quota_us
$ echo 20000 > cpu.cfs_quota_us
```
将刚刚的pid加入这个分组的限制内
```
$ echo [pid] > tasks
```
使用top命令查看刚刚那个死循环的CPU占用降到了20%
```
$ top
```
杀掉死循环进程
```
$ kill -9 [pid]
```