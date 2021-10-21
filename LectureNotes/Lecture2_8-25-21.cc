/*
Algorithm 1: Sieve of Eartosthenes
The Concept: Removing Prime Numbers 
            p -> 2 ... n
            p-> 2 3 4 ... 15
            1st iter: 2 3 5 7 9 11 13 15 // getting rid of numbers of multiple of 2 and staring on 2
            2nd iter: 2 3 5 7 11 13 // staring on 3 and getting rid of multiples of 3
            //Input: A positive number, > 1
            for p <- 2 to n do A[p] <- p
            for p <- 2 to [2^(1/2)] <- p
                if A[P] != 0
                j <- p*p
                while j <= n do:
                    A[p] = 0
                    j <- j+p
                    i <- 0
                    for p<- 2 to n do:
                    if A[p] != 0
                        L[i] <- A[p]
                        i = i+1
                    return L
    Fundamentals of Algorithm Patterns Solving:
        # Notes
            // 1. Understaning the problem
            // 2. Assesting the capabilityes of computational of devics
            // 3. Exact vs. Apx. Problem Solving 
            // 4. Design the algorithm and data structure
            // 5. Proving the correctness
            // 6. Analyze the algorithm
                    - Time useage: how long its going to take when there is large amount of data? 
                    - Space Efficiency: Make sure it doesnt take much space 
            // 7. Coding the Algorithm
        # Problem Type
            // 1. Sorting Problems 
            // 2. Searching Problems 
            // 3. Geometric Problems 
            // 4. Gpahing Problems
            // 5. Combraltorial Problems 
    Fundamentals of Dara Structions
        # Notes
            // Arrays: Can reach the element any way.
                [0][][][][n-1]
                Adv. quick accability -> search by index; 
                Dis. Fixed size of array, allocate a chunk of memory;
            // Linked Lists: Can reach the element any way. 
                Single: [item]->[]->[]->[], Double: [item|item]->[]->[]->[]; 
                 Adv. easy to add/delete elements;
                 Disa. Searching always begins at the head of the list 
            // Stack: Last in First out
                [0]
                [1]
                [2] -> First Out using: pop()

            // Queue: First in First Out
                [2]
                [1]
                [0] -> First in First Out: using Enqueu() and Dequeu
            // Graph: G = <V,E>; V = vertex, E = edge
                Undirected Graph: Elements can be accessed any way.
                    (u)------(v) 
                Directed Graph: Elements cant be accessed any way.
                    (u)=====(v)
            // Graph Representation
                    (a)-(c)-b
                    |    |   |
                    d-----e--f
                    Adjaceney Matrix:
                        {a,a:0,a,b:0,a,c:1,a,d:1,a,e:0,a,f:0}
                        {b,a:0,b,b:0,b,c:1,b,d:0,b,e:0,b,f:1}
                        {c,a:1,c,b:1,a,c:1,a,d:1,a,e:0,a,f:0}
                        {d,a:0,a,b:0,a,c:1,a,d:1,a,e:0,a,f:0}
                        {e,a:0,a,b:0,a,c:1,a,d:1,a,e:0,a,f:0}
                        {f,a:0,a,b:0,a,c:1,a,d:1,a,e:0,a,f:0}
                    Adjaceney Linked Lists:
                        [a]->c->d
                        [b]->c->f
                        [c]->a->b->e
                        [d]->a->e
                        [e]->c -> d->f 
                        [f] -> b->e
                For an undirected graph with no loops 
                    0 <= |E| <= |V|(|V-1)/2
                    u--v
                    \  |
                     w
            Spase Graph -> a graph with only a few qdges
            Dense Graph -> a graph with very few  edges missing
            Complete Graph -> every part of vertices an edege is connecting 
            Weighted Grah/ Weighted Digraph :  
                                        a---5---b
                                        |     /  |
                                        1   7    4
                                        |/       |
                                        c----2---d
                                         a b c d 
                                       a {inf,5,1,inf:
                                       b  5,inf,7,4;
                                       c  1,7,inf,2;
                                       d inf,4,2,inf} 
            Cycle: A path of positive length that starts and ends at the same vertex without  travessing the same vertex more than once a -c -d - b - a 
                 d - b - a - c- d - b
                
                
                 








*/