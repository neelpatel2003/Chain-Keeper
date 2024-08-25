#include <bits/stdc++.h>
using namespace std;
const int maxi_size = 10;
bool flag = 0;
int Blocksize = 0;
int activeBlock = 1;
int freq = 1;

struct Inode
{
    int dbID;
    int id;
    string name;
    int size;
    string permissions;
    Inode *next;
    time_t start_time;
    time_t update_time;
};

map<int, Inode *> Information;

class LinkedList
{
public:
    LinkedList() : temp(nullptr), headOfList(nullptr) {}

    void insertInode(int id, const string &name, int size, const string &permissions)
    {
        Inode *newInode = new Inode;
        Blocksize += size;
        if (Blocksize > maxi_size)
        {
            Blocksize = size;
            ++activeBlock;
            temp = NULL;
            flag = 1;
            cout << "\nThis file exceeds the size of the data-block,\nso this file will be saved in the next data-block.\n";
        }
        newInode->dbID = activeBlock;
        newInode->id = id;
        newInode->name = name;
        newInode->size = size;
        newInode->permissions = permissions;

        if (temp == nullptr)
        {
            temp = newInode;
            headOfList = newInode;
            Information[activeBlock] = temp;
        }
        else
        {
            temp->next = newInode;
            temp = newInode;
        }

        newInode->next = nullptr;
    }

    void displayInode()
    {
        for (auto node : Information)
        {
            cout << "INodes in DataBlock : " << freq << endl
                 << endl;
            Inode *current = node.second;
            while (current != nullptr)
            {
                cout << "\tID: " << current->id << ", Name: " << current->name << ", Size: " << current->size
                     << ", Permissions: " << current->permissions << endl;
                current = current->next;
            }
            freq++;
            cout << endl;
        }
        freq = 1;
    }

    void displayInode(int inodeID)
    {
        for (auto node : Information)
        {
            Inode *current = node.second;
            while (current != nullptr)
            {
                if (current->id == inodeID)
                {
                    cout << "Data_Block: " << current->dbID << ", ID: " << current->id << ", Name: " << current->name << ", Size: " << current->size
                         << ", Permissions: " << current->permissions << endl;
                    cout << endl;
                    current->start_time = time(0);
                    cout << "Starting Time: " << ctime(&current->start_time);
                    current->update_time = time(0);
                    cout << "Updated Time: " << ctime(&current->update_time) << endl;

                    return;
                }
                current = current->next;
            }
        }
        cout << "Inode not found with ID " << inodeID << endl;
    }

    void updatePermissions(int inodeID)
    {
        for (auto node : Information)
        {
            Inode *current = node.second;
            while (current != nullptr)
            {
                if (current->id == inodeID)
                {
                    cout << "Enter new permissions for inode " << inodeID << ": ";
                    cin >> current->permissions;
                    cout << "Permissions updated." << endl;
                    current->update_time = time(0);
                    return;
                }
                current = current->next;
            }
        }
        cout << "Inode not found with ID " << inodeID << endl;
    }
    void updateName(int inodeID)
    {
        for (auto node : Information)
        {
            Inode *current = node.second;
            while (current != nullptr)
            {
                if (current->id == inodeID)
                {
                    cout << "Enter new name of inode " << inodeID << ": ";
                    cin >> current->name;
                    cout << "Name updated." << endl;
                    current->update_time = time(0);
                    return;
                }
                current = current->next;
            }
        }
        cout << "Inode not found with ID " << inodeID << endl;
    }
    void updateSize(int inodeID)
    {
        for (auto node : Information)
        {
            Inode *current = node.second;
            while (current != nullptr)
            {
                if (current->id == inodeID)
                {
                    cout << "Enter new size of inode " << inodeID << ": ";
                    cin >> current->size;
                    cout << "Size updated." << endl;
                    current->update_time = time(0);
                    return;
                }
                current = current->next;
            }
        }
        cout << "Inode not found with ID " << inodeID << endl;
    }

    void deleteInode(int inodeID)
    {
        for (auto node : Information)
        {
            Inode *current = node.second;
            Inode *previous = nullptr;

            while (current != nullptr)
            {
                if (current->id == inodeID)
                {
                    if (previous != nullptr)
                    {
                        previous->next = current->next;
                    }
                    else
                    {
                        headOfList = current->next;
                    }
                    delete current;
                    cout << "Inode with ID " << inodeID << " has been deleted." << endl;
                    return;
                }
                previous = current;
                current = current->next;
            }
        }
        cout << "Inode not found with ID " << inodeID << endl;
    }

private:
    Inode *temp;
    Inode *headOfList;
};

int main()
{
    time_t startTime = time(0);
    LinkedList inodeList;
    int id, size;
    string name, permissions;
    char choice;
    char op;
    cout << "\nWelcome to our project on INode!" << endl;
    cout << endl;
    cout << "Do you wish to insert a new inode?\n";
    cout << "Enter Y for Yes and N for No\n";
    cin >> choice;

    switch (choice)
    {
    case 'Y':
        cout << "Enter ID for the new inode: ";
        cin >> id;
        cout << "Enter name for the new inode: ";
        cin >> name;
        cout << "Enter size of the new inode(in bytes): ";
        cin >> size;
        cout << "Enter permissions(read or write) for the new inode: ";
        cin >> permissions;
        inodeList.insertInode(id, name, size, permissions);
        break;
    default:
        cout << "\nSee you next time. Have a nice day! \n"
             << endl;
        return 0;
    }
    while (true)
    {
        cout << "\n What do you want to do next?\n Please choose from the below options...\n"
             << endl;
        cout << "Operations on Inode\n";
        cout << "1. Insert Inode\n";
        cout << "2. Display Inode using ID\n";
        cout << "3. Display all INodes\n";
        cout << "4. Update Permissions\n";
        cout << "5. Delete Inode\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> op;
        cout << endl;
        switch (op)
        {
        case '1':
            cout << "Enter ID for the new inode: ";
            cin >> id;
            cout << "Enter name for the new inode: ";
            cin >> name;
            cout << "Enter size of the new inode(in bytes): ";
            cin >> size;
            cout << "Enter permissions(read or write) for the new inode: ";
            cin >> permissions;
            inodeList.insertInode(id, name, size, permissions);
            break;
        case '2':
            cout << "Enter the ID to find an inode: ";
            cin >> id;
            cout << "\nInode Details:\n";
            inodeList.displayInode(id);
            break;
        case '3':
            cout << "\nInode List:\n\n";
            inodeList.displayInode();
            break;
        case '4':
            cout << "Enter the ID of the inode to update permissions: ";
            cin >> id;
            inodeList.updateName(id);
            inodeList.updateSize(id);
            inodeList.updatePermissions(id);

            break;
        case '5':
            cout << "Enter the ID of the inode to delete: ";
            cin >> id;
            inodeList.deleteInode(id);
            break;
        case '6':
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}
