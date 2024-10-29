using System;
using System.Threading;

class Program
{
    private static int sharedCounter = 0;
    private static readonly object lockObject = new object();
    private const int ThreadCount = 100;  // Number of threads to create
    private const int Iterations = 100000000;  // Number of iterations each thread will perform

    static void Main()
    {
        Thread[] threads = new Thread[ThreadCount];

        // Create and start threads
        for (int i = 0; i < ThreadCount; i++)
        {
            threads[i] = new Thread(IncrementCounter);
            threads[i].Start();
        }

        // Wait for all threads to complete
        foreach (Thread thread in threads)
        {
            thread.Join();
        }

        Console.WriteLine($"Final value of sharedCounter: {sharedCounter}");
    }

    static void IncrementCounter()
    {
        for (int i = 0; i < Iterations; i++)
        {
            lock (lockObject)  // Lock the shared resource
            {
                sharedCounter++;
            }
        }
    }
}
