clear
checker () {


    g++ test.cpp
    ./a.out > in.txt

    cat in.txt

    g++ bf.cpp
    ./a.out < in.txt > bf.txt

    g++ Sherlock_and_Inversions.cpp
    ./a.out < in.txt > opti.txt




    if cmp -s bf.txt opti.txt
        then
           echo "Verdict : AC"
        else
           echo "Verdict : WA"
           exit
           #diff bf.txt partial.txt
           #gedit bf.txt &
           #gedit partial.txt &
        fi




}
for i in {1..20}
do
   checker
done
