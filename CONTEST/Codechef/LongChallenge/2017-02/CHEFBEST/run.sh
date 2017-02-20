clear

checker (){
    #echo "generate Test Cases"
    g++ test.cpp
    ./a.out > in.txt

    #echo "Run Brute Force Solution"
    g++ bf.cpp
    ./a.out < in.txt > bf.txt

    #echo "Run Optimized Solution"
    g++ letSee.cpp
    ./a.out < in.txt > letSee.txt

    if cmp -s bf.txt letSee.txt
    then
       echo "AC"
    else
       echo "WA"
       #diff bf.txt partial.txt
       #gedit bf.txt &
       #gedit partial.txt &
    fi

}

for i in {1..1}
do
   checker
done
