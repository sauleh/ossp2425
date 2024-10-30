# working with linux kernel linked list
1. download the doubley linked list from linux kernel from the address below:
https://raw.githubusercontent.com/torvalds/linux/refs/heads/master/tools/usb/usbip/libsrc/list.h

2. Observe and compile main.c
3. Modify main.c to add 500,000 entries to the linked list from two different threads (without locking)
4. delete all the allocated memory from the main thread and count the entries.
5. print the number of deleted entries from the linked list
6. compile and run a few times. how does the printed number compare to the expected number?
7. use Mutex to make adding threadsafe
