# File System Simulation using Linked Lists

This C++ project simulates a file system using a linked list data structure. It manages inode information, including ID, name, size, permissions, and timestamps. The system operates within a fixed data block size and allocates new blocks as needed.

## Features

* **Inode Management:**
  * Creation, deletion, and modification of inodes.
  * Tracking of inode attributes (ID, name, size, permissions, timestamps).
* **Data Block Allocation:**
  * Dynamic allocation of data blocks based on inode size.
* **Permissions:**
  * Implementation of read/write permissions for inodes.
* **User Interface:**
  * Menu-driven interface for interacting with the file system.

## Usage

1. **Compile:**
   ```bash
   g++ -o filesystem simulation.cpp
2. **Run:**
   ```bash
   ./filesystem
3. **Follow the on screen prompts to perform operations like creating, deleting, and modifying inodes.**

## Dependencies
  * A C++ compiler (e.g., g++) is required.

## Notes
  * The code assumes a fixed maximum data block size.
  * For more complex file systems, consider implementing features like directory structures, file system persistence, and security measures.
