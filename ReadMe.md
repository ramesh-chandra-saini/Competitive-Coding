
### Introduction  
This software runs several version of prim's algorithm.

### How to run ?
    bash run.sh 
goto src directory and execute above command
        
### Technical Detail
    - src dir    => containing all programs
    - input dir  => storing input graph
    - output dir => consists output files

### src dir 
    - graph_generation.cpp  => graph generation
    - graph_simplify.cpp    => graph simplification
    - prim.cpp              => prim's algo
    - prim_minPMA.cpp       => prim's minPMA algo
    - prim_sortPMA.cpp      => prim's sortPMA algo 
    - sort_comparision_info.cpp => sort execution time list based on edges
    - graph.py => to plot graph of execution times of different algorithms

### input dir
    - general_graph.txt => randomly generated graph
    - simple_graph.txt  => simple graph of abov one
    
### output dir
    - prim.txt  
    - prim_minPMA.txt
    - prim_sortPMA.txt
    - time.txt
