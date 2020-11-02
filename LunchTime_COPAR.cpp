// https://www.codechef.com/LTIME89B/problems/COPAR
/*
Problem statement Explaination

The aim of the problem is to divide the  given list/array  of length N
into two parts of length l ,N-l
such that when we calculate the produts of the first l and the last n-l elements
the resulting products would be coprimes

coprime:
any two numbers are called coprimes when their gcd is 1
i.e have no common prime factors

we have to find the length where we can make the first split
i.e smallest possible index where you can perform the split

[2,3,4,5,7]

given this array 
we can make the split at length 3
i.e [2,3,4] and [5,7] because 24 and 35 are coprimes

Problem solving approach


#1 basic brute force
of checking at every possible index by spliting the array at that index
and then calculatig progucts for the left array and the right array
and then checking if the gcd is one or not

this approach wont be working as the given constrains are in the order of
10^5

and moreover our products of the sublists would be very large(possible overflow)
and thus calculating the gcd is also difficult



#2 Prime Factorisation

[2,3,4,5,7]
2 3 4 5 7
[2,3,4] and [5,7]
the primefactors of the left array are {2,3} and the right array are {5,7}
since they are disjoin we can justify that the partion is correct

# we cant have the partition at anywhere before the index 2 .
i.e 2 is the minmum index where this is satisfying
#

Working
Lets say we are given the elements a1--a6 and the primefactors of each elements
{2,3} {3,5} {5,2} {2} {11,7} {11}
a1    a2    a3    a4    a5    a6 (now we have to make the range for each of teh primefactors)
-------2------------*
-----3----*
         ---5---*
         			   --7--*
                        -----11------*
[2     2       1      0   1    0]
i.e now from this we can observe that we can make the partitions
after one of the range ends* in order to have distinct factors in both the 
parts of the array after partition

now for each index we shall count the number of active ranges at that point
as shown in the array
[2     2       1      0   1    0]
we will not include a range at an index if it ends there
for example while considering the active range for index 2 we dint consider
---3---* as it ended there

after calculating the active ranges array the final answer would be the first index
where we find 0 in the array of active ranges



Finding active ranges:
before starting this we should make an map < prime factors,[start,end]>
i.e for each of the primes we should find whats the first occurrence and whats the 
last occurrence { can refer to the solution to see how it is done}

once we get the ranges of start and end for each prime
we would form active ranges array using the {[difference array approach for the numbers of the array]}
prime&		{2,3} {3,5} {5,2} {2} {11,7} {11}
ranges		a1    a2    a3    a4    a5    a6 (now we have to make the range for each of the primefactors)
2 [1,4]     1                 -1
3 [1,2]     1     -1
5 [2,3]            1    -1
7 [5,5]                             1-1
11[5,6]                              1    -1
           [2  0        -1    -1    1     -1]		

 in the difference array approach we put a +1 at begining of the range and -1 at the end of the 
 range

now we take the cumulative sum of the formed array
           [2  2   1   0   1  0]
           hence we found the active ranges array
           now we simply iterate over this and return the first occurrence of 0 in the array
*/
