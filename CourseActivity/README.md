### shmget() 
The shmget() function is used to create or access a shared memory segment in Linux systems. The general syntax of the shmget() function is as follows:
					
					int shmget(key_t key, size_t size, int shmflg);
				
key: A unique identifier for the shared memory segment. This can be generated using the ftok() function, or it can be a predefined constant such as IPC_PRIVATE or a user-defined value.

size: The size of the shared memory segment, in bytes.

shmflg: A set of flags that control the behavior of the shmget() function. Some of the most commonly used flags are:

- IPC_CREAT: Creates a new shared memory segment if one with the given key does not already exist.
- IPC_EXCL: When used in conjunction with IPC_CREAT, causes the function to return an error if a shared memory segment with the given key already exists.
- 0666: Permissions to access the shared memory segment. The last three digits specify the permissions for the owner, group, and others respectively in octal format.

The shmget() function returns the shared memory segment identifier (a non-negative integer) if it is successful, and -1 otherwise.

### shmat()
The shmat() function is used to attach a shared memory segment to the address space of a process in Linux systems. The general syntax of the shmat() function is as follows:

                                void *shmat(int shmid, const void *shmaddr, int shmflg);

shmid: The identifier of the shared memory segment that you want to attach to the process. This is typically obtained using the shmget() function.

shmaddr: The address at which to attach the shared memory segment. This argument is typically set to NULL to let the kernel choose the address at which to attach the shared memory segment.

shmflg: A set of flags that control the behavior of the shmat() function. Some of the commonly used flags are:

- SHM_RDONLY: Attaches the shared memory segment in read-only mode.
- SHM_RND : Use this option in order to attach the shared memory segment to a random address.
- 0: Default flag, It attaches the shared memory segment in read-write mode.


The shmat() function returns a pointer to the start of the shared memory segment if it is successful, and (void *) -1 otherwise.

### shmdt()
The shmdt() function is used to detach a shared memory segment from the address space of a process in Linux systems. The general syntax of the shmdt() function is as follows:

                                              int shmdt(const void *shmaddr);
                                              
shmaddr: A pointer to the start of the shared memory segment that you want to detach. This pointer is typically obtained by calling shmat() function.

The shmdt() function returns 0 if it is successful, and -1 otherwise.
