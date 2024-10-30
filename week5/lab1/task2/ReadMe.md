# NVIDIA pthread signaling using pthread_cond_wait/signal
ProxyFS is a disributed read/write hierarchical POSIX file system layered on top of Swift object storage developed by NVIDIA. 

NVIDIA has a client tool for accessing this filesystem remotely called proxyfs-jrpc-client. Please inspect the code below and describe in simple terms why this client is using pthread_cond_wait and pthread_cond_signal.  

https://github.com/NVIDIA/proxyfs-jrpc-client/blob/development/pool.c
