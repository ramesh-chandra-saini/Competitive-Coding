clear

checker (){
    #echo "generate Test Cases"
    g++ test.cpp
    ./a.out > in.txt

    #echo "Run Brute Force Solution"
    g++ opti.cpp
    ./a.out < in.txt > opti.txt

    #echo "Run Optimized Solution"
    g++ opti2.cpp
    ./a.out < in.txt > opti2.txt

    if cmp -s opti.txt opti2.txt
    then
       echo "AC"
    else
       echo "WA"
       #diff bf.txt partial.txt
       #gedit bf.txt &
       #gedit partial.txt &
    fi

}

for i in {1..10}
do
   checker
done
