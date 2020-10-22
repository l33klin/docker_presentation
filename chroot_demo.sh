# /bin/bash
T=$HOME/test

echo Create $HOME/test
mkdir -p $T

echo Create dirs: bin, lib64, lib
mkdir -p $HOME/test/{bin,usr/bin,lib64,lib/x86_64-linux-gnu}

echo Copy command
cp -v /bin/{bash,ls} $HOME/test/bin
cp -v /usr/bin/tree $HOME/test/usr/bin

echo Copy libs
for cmd in /bin/ls /bin/bash /usr/bin/tree; do
    list="$(ldd $cmd | egrep -o '/lib.*\.[0-9]')"
    for i in $list; do cp -v "$i" "${T}${i}"; done;
done
