clear

checker (){
    #echo "generate Test Cases"
    g++ test.cpp
    ./a.out > in.txt

    #echo "Run Brute Force Solution"
    g++ bf.cpp
    ./a.out < in.txt > bf.txt

    #echo "Run Optimized Solution"
    g++ mat_expo.cpp
    ./a.out < in.txt > mat_expo.txt

    cat in.txt
    cat bf.txt
    cat mat_expo.txt
    if cmp -s bf.txt mat_expo.txt
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
