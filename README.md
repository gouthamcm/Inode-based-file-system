# Inode based file system

## Prerequisites

You need to install GNU g++ complier
`sudo apt-get install g++`

## Installation
Go to the project directory and run `g++ main.cpp -o main`.
This will generate the output file and to run the application run, `./main`

## Architecture Overview
The following things will be present in the application:

### Section 1:

This is the region outside the disks. From here you will create a disk and then
mount/open it to perform all basic operations mentioned in section 2.

- create disk: Creates an empty disk of size 500Mb. 
While creating an empty disk a unique name will be given to it which will be used
to mount it.
- mount disk: Opens the specified disk for various file operations. As mentioned
in section 2.
- exit: Close the application.

### Section 2:

This is the region inside the disk. You may have multiple disks. You will open only 1 disk
at a time. After opening/mounting a particular disk, you will perform below mentioned
operations in the disk:

- create file: creates an empty text file.
- open file: opens a particular file in read/write/append mode as specified in input,
multiple files can be opened simultaneously.
- read file: Displays the content of the file.
- write file: Write fresh data to file(override previous data in file). Type `exit()` to come out from the mode.
- append file: Append new data to an existing file data. Type `exit()` to come out from the mode.
- close file: Closes the file.
- delete file: Deletes the file.
- list of files: List all files present in the current disk.
- list of opened files: List all opened files and specify the mode they are open in.
- unmount: Closes the currently mounted disk.

