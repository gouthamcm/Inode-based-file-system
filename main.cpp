/* 
    Created by Goutham C M on 14/11/2021
    INODE based File system implementation in c++
*/

#include <iostream>

using namespace std;

void create_disk();

void mount_disk();

void exit_appl();

void create_file();

void open_file();

void read_file();

void write_file();

void append_file();

void close_file();

void delete_file();

void list_of_files();

void list_of_opened_files();

void unmount();

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
            create_disk();
        }
        else if (choicex == 2)
        {
            mount_disk();
            while (1)
            {
                cout << "==================";
                cout << "\n1. Create File";
                cout << "\n2. Open File";
                cout << "\n3. Read File";
                cout << "\n4. Write File";
                cout << "\n5. Append File";
                cout << "\n6. Close File";
                cout << "\n7. Delete File";
                cout << "\n8. List of Files";
                cout << "\n9. List of opened Files";
                cout << "\n10. Unmount";
                cin >> choicey;
                if (choicey == 1)
                {
                    create_file();
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
                else if (choicey == 9)
                {
                    unmount();
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
        }
        else
        {
            cout << "Wrong choice.. enter again\n";
        }
    }
    return 0;
}