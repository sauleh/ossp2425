# threads

## task1
* write from 1 to 10 on two threads with small sleep time
* run multiple times
* observe the patterns of how numbers are mixed together 

## task 2.1
* use a different color for each thread and observe when colors are not printed as expected
* explain how this error happens

## task 2.2
* make the loop variable gloal and observe errors that arise from this
* explain how these errors happen

## task 2.3
* use mutex to fix both problems above

## task 3 (if time permits)
* create a deadlock 
* fix it with using pthread_mutex_trylock

## task 4 (if time permits)
* give the color of a thread as an input parameter to the thread
* return the number of lines printed as an output paramter received by thread_join

# sockets

# task4
* create an uppercase server
server -i
input> sample sentence
output> SAMPLE SENTENCE

# task5
server <port>
<waiting>
client <ip> <port>
input> sample sentence   
output> SAMPLE SENTENCE

# task7 (if time permits)
use mostly the same code path in server for (-i) vs (port)
use read/write with socket or STDIN_FILENO/STDOUT_FILENO
