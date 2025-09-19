#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct task{
    string description ;
    bool completed;

    task(string desc){ //Constructor
        this->description =desc;
        completed=false;
    }
};
void addtask(vector<task>& tasks){
string taskdesc;
cout<<"Enter The Task: ";
getline(cin,taskdesc);
tasks.push_back(task(taskdesc));
cout<<"Task enter sucessfully......."<<"\n";

}

void viewtask(const vector<task>& tasks){
if(tasks.empty()){
    cout<<"NO task is pending....! \n";
    return ;
}
cout<<"THE LIST IF TASK IS-------"<<"\n";
for(int i=0;i<tasks.size();i++){
    cout<<i+1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
}

}

void deletetask(vector<task>& tasks){
if(tasks.empty()){
    cout<<"NO task to remove....! \n";
    return ;
}

int tasknum;
viewtask(tasks);
cout<<"Enter the no of task: ";
cin>>tasknum;

if((tasknum<1 )|| (tasknum > (int)tasks.size())){
 cout<<"Invalid task....."<<"\n";
}else{
    tasks.erase(tasks.begin() + (tasknum-1));
    cout << "Task removed successfully!\n";
}
}

void completetask(vector<task>& tasks){
if(tasks.empty()){
    cout<<"NO task to complete....! \n";
    return ;
}
int tasknum;
viewtask(tasks);
cout<<"Enter the no of task: ";
cin>>tasknum;
if((tasknum<1 )|| (tasknum > (int)tasks.size())){
 cout<<"Invalid task No....."<<"\n";
}else{
    tasks[tasknum-1].completed = true;
    cout << "Task marked as completed!\n";
}

};

int main(){
vector<task> tasks;
 int choice;

    do {
        cout << "\n===== TO-DO LIST MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore leftover newline from input

        switch(choice) {
            case 1:
                addtask(tasks);
                break;
            case 2:
                viewtask(tasks);
                break;
            case 3:
                completetask(tasks);
                break;
            case 4:
                deletetask(tasks);
                break;
            case 5:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 5);

    return 0;
}