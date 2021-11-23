/* 
    Created by Goutham C M on 14/11/2021
    INODE based File system implementation in c++
*/

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct super_block
{
    int number_of_inodes;
    int number_of_diskblocks;
    int size_of_blocks;
};

struct inode
{
    int size;
    int first_block;
    char name[80];
};

struct disk_block
{
    int next_block_num;
    char data[512];
};

struct super_block sb;
struct inode *inodes;
struct disk_block *disk_blocks;


void printfs(string diskname)
{
    FILE *fp;
    fp = fopen(&diskname[0], "r");
    fread(&sb, sizeof(super_block), 1, fp);

    for (int i = 0; i < sb.number_of_inodes; i++)
    {
        fread(&inodes[i], sizeof(inode), 1, fp);
    }

    for (int i = 0; i < sb.number_of_diskblocks; i++)
    {
        fread(&disk_blocks[i], sizeof(disk_block), 1, fp);
    }

    cout << "Super Block Info\n";
    cout << "Number of disk blocks\t" << sb.number_of_diskblocks << endl;
    cout << "Number of Inodes\t" << sb.number_of_inodes << endl;
    cout << "Size of blocks\t" << sb.size_of_blocks << endl;
    cout << "\nINODES\n\n";
    for (int i = 0; i < sb.number_of_inodes; i++)
    {
        cout << "size: " << inodes[i].size << "\t"
             << "first block: " << inodes[i].first_block << "\t"
             << "name: " << inodes[i].name << endl;
    }
    cout << "\nDISK BLOCKS\n\n";
    for (int i = 0; i < sb.number_of_diskblocks; i++)
    {
        cout << "Block No.: " << i << "\t"
             << "Next Block: " << disk_blocks[i].next_block_num << "\tData: " << disk_blocks[i].data << endl;
    }
    fclose(fp);
}

void syncfs(string diskname)
{

    FILE *fp;
    fp = fopen(&diskname[0], "w+");

    fwrite(&sb, sizeof(super_block), 1, fp);

    for (int i = 0; i < sb.number_of_inodes; i++)
    {
        fwrite(&inodes[i], sizeof(inode), 1, fp);
    }

    for (int i = 0; i < sb.number_of_diskblocks; i++)
    {
        fwrite(&disk_blocks[i], sizeof(disk_block), 1, fp);
    }

    fclose(fp);
}
void create_disk(string name_of_the_disk)
{
    sb.number_of_inodes = 10;
    sb.number_of_diskblocks = 100;
    sb.size_of_blocks = sizeof(disk_block);

    inodes = (inode *)malloc(sizeof(inode) * sb.number_of_inodes);
    disk_blocks = (disk_block *)malloc(sizeof(disk_block) * sb.number_of_diskblocks);

    for (int i = 0; i < sb.number_of_inodes; i++)
    {
        inodes[i].size = -1;
        inodes[i].first_block = -1;
        strcpy(inodes[i].name, "empty");
    }

    for (int i = 0; i < sb.number_of_diskblocks; i++)
    {
        disk_blocks[i].next_block_num = -1;
        // disk_blocks[i].data
    }
    syncfs(name_of_the_disk);
    // printfs(name_of_the_disk);
    return;
}

void mount_disk(string diskname)
{
    FILE *fp;
    fp = fopen(&diskname[0], "r");

    fread(&sb, sizeof(super_block), 1, fp);

    inodes = (inode *)malloc(sizeof(inode) * sb.number_of_inodes);
    disk_blocks = (disk_block *)malloc(sizeof(disk_block) * sb.number_of_diskblocks);

    fread(inodes, sizeof(inode), sb.number_of_inodes, fp);

    fread(disk_blocks, sizeof(disk_block), sb.number_of_diskblocks, fp);
    printfs(diskname);

    fclose(fp);

    return;
}
int empty_inode(){
    for(int i=0; i<sb.number_of_inodes; i++){
        if(inodes[i].first_block==-1){
            return i;
        }
    }
    return -1;
}
int empty_disk(){
    for(int i=0; i<sb.number_of_diskblocks; i++){
        if(disk_blocks[i].next_block_num==-1){
            return i;
        }
    }
    return -1;
}
void exit_appl()
{
    exit(0);
    return;
}

int create_file(string file_name, string disk_name)
{
    //find empty inode
    //claim it
    // printfs(disk_name);
    int inode_loc=empty_inode();
    if(inode_loc==-1){
        // error
        cout<<"No free location found for inode\n";
        return -1;
    }
    int disk_loc = empty_disk();
    if(disk_loc==-1){
        //error
        cout<<"No free location found for disk block\n";
        return -1;
    }
    inodes[inode_loc].first_block=disk_loc;
    strcpy(inodes[inode_loc].name, &file_name[0]);
    disk_blocks[disk_loc].next_block_num=-2;
    syncfs(disk_name);
    return inode_loc;
}

void open_file()
{
    return;
}

void read_file()
{
    return;
}

void write_file()
{
    return;
}

void append_file()
{
    return;
}

void close_file()
{
    return;
}

void delete_file()
{
    return;
}

void list_of_files()
{
    return;
}

void list_of_opened_files()
{
    return;
}

void unmount()
{
    return;
}

int main()
{
    int choicex, choicey;
    while (1)
    {
        cout << "Which operation would you like to perform?\n";
        cout << "1. Create Disk\n2. Mount Disk\n3. Exit\n";
        cin >> choicex;
        if (choicex == 1)
        {
            string name_of_the_disk;
            // cout<<
            cin >> name_of_the_disk;
            create_disk(name_of_the_disk);
        }
        else if (choicex == 2)
        {
            string disk_name;
            cin >> disk_name;
            mount_disk(disk_name);
            while (1)
            {
                cout << "\n===========================\n";
                cout << "\n1. Create File";
                cout << "\n2. Open File";
                cout << "\n3. Read File";
                cout << "\n4. Write File";
                cout << "\n5. Append File";
                cout << "\n6. Close File";
                cout << "\n7. Delete File";
                cout << "\n8. List of Files";
                cout << "\n9. List of opened Files";
                cout << "\n10 Unmount\n";
                cout << "===========================\n\n";

                cin >> choicey;
                if (choicey == 1)
                {
                    string file_name;
                    cout<<"Enter file name:\n";
                    cin>>file_name;
                    int fd = create_file(file_name, disk_name);
                    if(fd == -1){
                        continue;
                    }
                    cout<<"File created! here is the descriptor: "<<fd<<endl;
                    printfs(disk_name);
                }
                else if (choicey == 2)
                {
                    open_file();
                }
                else if (choicey == 3)
                {
                    read_file();
                }
                else if (choicey == 4)
                {
                    write_file();
                }
                else if (choicey == 5)
                {
                    append_file();
                }
                else if (choicey == 6)
                {
                    close_file();
                }
                else if (choicey == 7)
                {
                    delete_file();
                }
                else if (choicey == 8)
                {
                    list_of_files();
                }
                else if (choicey == 9)
                {
                    list_of_opened_files();
                }
                else if (choicey == 10)
                {
                    unmount();
                    break;
                }
                else
                {
                    cout << "Wrong choice.. enter again\n";
                }
            }
        }
        else if (choicex == 3)
        {
            exit_appl();
            break;
        }
        else
        {
            cout << "Wrong choice.. enter again\n";
        }
    }
    return 0;
}