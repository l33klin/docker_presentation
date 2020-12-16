环境准备：在当前目录下执行
```bash
$ sh prepare.sh
```
联合挂载：切换到test目录执行挂载
```bash
$ cd test
$ mount -t overlay overlay -olowerdir=B:A,upperdir=C,workdir=W D
```
对`D`目录中的文件进行增删改，观察A, B, C, D中的文件以及内容的变化
