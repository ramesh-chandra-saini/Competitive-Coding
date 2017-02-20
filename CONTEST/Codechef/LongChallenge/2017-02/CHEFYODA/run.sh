clear

checker (){
    #echo "generate Test Cases"
    g++ test.cpp
    ./a.out > in.txt

    #cat in.txt

    #echo "Run Brute Force Solution"
    g++ bf.cpp
    ./a.out < in.txt > bf.txt

    #echo "Run Optimized Solution"
    g++ opti.cpp
    ./a.out < in.txt > opti.txt

    if cmp -s bf.txt opti.txt
    then
       echo "Verdict : AC"
    else
       echo "Verdict : WA"
       #diff bf.txt partial.txt
       #gedit bf.txt &
       #gedit partial.txt &
    fi

}

for i in {1..1}
do
   checker
done
