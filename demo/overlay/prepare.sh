# /bin/bash
T=test
 
echo Create test
mkdir -p $T

echo Create A, B, W, C, D, E, W2
cd $T
mkdir A B W C D E W2

echo Create some files
echo a > A/a.txt
echo b > A/b.txt
echo c > B/c.txt
echo d > D/d.txt
ln A/a.txt B/a.txt
ln B/c.txt D/c.txt