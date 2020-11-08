# /bin/bash
T=test

echo Create test
mkdir -p $T

echo Create dirs: bin, lib64, lib
mkdir -p $T/bin $T/usr/bin $T/lib64 $T/lib/x86_64-linux-gnu

echo Copy commands
cp -v /bin/bash $T/bin
cp -v /bin/ls $T/bin
cp -v /usr/bin/tree $T/usr/bin

echo Copy libs
for cmd in /bin/ls /bin/bash /usr/bin/tree; do
    list="$(ldd $cmd | egrep -o '/lib.*\.[0-9]')"
    for i in $list; do cp -v "$i" "${T}${i}"; done;
done