```
$ while : ; do : ; done &
```
获得进程pid

```
$ cd /sys/fs/cgroup/cpu
$ sudo su
$ mkdir klin_cpu && cd klin_cpu

$ cat cpu.cfs_period_us
$ cat cpu.cfs_quota_us
$ echo 20000 > cpu.cfs_quota_us
$ echo [pid] > tasks

$ kill -9 [pid]
```