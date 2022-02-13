# tlpi
Coding exercises from the The linux programming interface book


## Chapter 4 Notes
	
### Syscalls

	* open()

	* read()

	* write()

		* An important thing to make a note of is that since the kernel performs buffering of Disk I/O, So while dealing with disk files a successful return from write() doesn't guarantee that data has been transferred to disk  
	* close()

	* lseek()

	* ioctl()

	* Summary
		* get an open file descriptor using open().

		* write to the file and read from the file using read()/write().

		* close the file descriptor using close().

		* Since all file types and device drivers implement the same i/o interface It allows for universality of I/O.

			* Meaning a program can be used with any kind of file without requiring code specific to that file.

		* For each open file kernel maintains a file offset(implicitly updated by reads and writes).

		* lseek() can explicitly update the offset to any position within the file or past the EOF too.

		* A file in which data has been written post the previous EOF contains holes, reading from Holes returns bytes containing 0s.

		* ioctl() catchall for any file operations outside the standard file I/O Model. 
