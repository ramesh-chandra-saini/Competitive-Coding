clear

echo "generate Test Cases"
g++ test.cpp
./a.out > in.txt

echo "Run Brute Force Solution"
g++ bf.cpp
./a.out < in.txt > bf.txt

echo "Run Optimized Solution"
g++ opti.cpp
./a.out < in.txt > opti.txt

cat bf.txt
cat opti.txt
if cmp -s bf.txt opti.txt
then
   echo "AC"
else
   echo "WA"
   diff bf.txt opti.txt
   #gedit bf.txt &
   #gedit partial.txt &
fi
