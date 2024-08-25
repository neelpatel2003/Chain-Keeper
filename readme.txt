Introduction
This C++ project simulates a file system using a linked list data structure. It manages inode information, including ID, name, size, permissions, and timestamps. The system operates within a fixed data block size and allocates new blocks as needed.

Features
Inode Management:
Creation, deletion, and modification of inodes.
Tracking of inode attributes (ID, name, size, permissions, timestamps).
Data Block Allocation:
Dynamic allocation of data blocks based on inode size.
Permissions:
Implementation of read/write permissions for inodes.
User Interface:
Menu-driven interface for interacting with the file system.
Usage
Compile:
Bash
g++ -o filesystem simulation.cpp
Use code with caution.

Run:
Bash
./filesystem
Use code with caution.

Follow the on-screen prompts to perform operations like creating, deleting, and modifying inodes.
Dependencies
A C++ compiler (e.g., g++)
Notes
The code assumes a fixed maximum data block size.
For more complex file systems, consider implementing features like directory structures, file system persistence, and security measures.
Future Enhancements
Implement a more efficient data block allocation strategy (e.g., bitmap or buddy system).
Add support for different file types (e.g., text, binary, executable).
Integrate with a real file system for testing and integration.
Enjoy exploring and experimenting with this file system simulation!