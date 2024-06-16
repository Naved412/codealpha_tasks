#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
void
display_task (string task[], int task_count,vector<bool>status)
{
  cout << "\n\n\tTasks to do:  " << endl;
  cout << "*************************************************" << endl;
  for (int i = 0; i < task_count; i++)
	{
	  cout << "task " << i + 1 << ":  " << task[i];
      if(status[i+1]){
        cout<<"\t(It is completed)"<<endl;
      }else{
        cout<<endl;
      }
	}
  cout << "*************************************************\n\n" <<endl;
}

int
main ()
{
  string task[10] = { "" };
  vector<bool>visited(10,0);
  // string completed[10];
  // int complet_count = 0;
  int option = -1, task_count = 0, del_task, i;
  while (option != 0)
	{
	  cout << "<-----------To Do List ----------->" << endl;
	  cout << "Enter 1 To Add task" << endl;
	  cout << "Enter 2 To view all your tasks" << endl;
	  cout << "Enter 3 To Delete a task" << endl;
	  cout<<"Enter 4 to mark as complete task."<<endl;
	  cout << "Enter 5 To Exit" << endl;
	  
	  cin >> option;

	  switch (option)
		{
		case 1:
		  {
			if (task_count > 9)
			  {
				cout << " No of task is full " << endl;
			  }
			else
			  {
				cout << "Enter a New Task:  " << endl;
				cin.ignore ();
				getline (cin, task[task_count]);
				task_count++;
			  }

			break;
		  }
		case 2:
		  {
			display_task (task, task_count,visited);
		  }
		  break;
		case 3:
		  {
			cout << "Enter Task No to delete" << endl;
			cin >> del_task;
			if (del_task < 0 || del_task > 9)
			  {
				cout << "you entered invalid no" << endl;
			  }
			else
			  {
				cout << "task " << del_task << " deleted succesfully" << endl;
				for (i = del_task+1; i < task_count; i++)
				  {

					task[i] = task[i + 1];

				  }

				task_count--;
			  }
		  }
		  break;
		 case 4:
		    int completion;
		    cout<<"Enter the task No that is completed: ";
		    cin>>completion;
		    if(visited[completion] == 1){
		        cout<<"Already visited marked."<<endl;
		    }else{
		        visited[completion] = 1;
		    }
		    break;
		case 5:
		  {
			cout << "Program Terminated sucessfully " << endl;
		  }
		  break;
		default:
		  {
			cout << "You entered Invalid Option !!!" << endl;
		  }
		}

	}



  return 0;
}