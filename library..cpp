#include<iostream> 
#include<fstream>
#include<string>
#include "LIBRARY_b.H"
using namespace std;

int main(){
   int choice, n;
    cout<<"\nEnter the size of array: ";
    cin>>n;
    int *book;
	Books b[n];
    //populate the array from a file
   ifstream fin("file.txt");
   fin.open("file.txt");
    for(int i=0;i<n;i++){
        fin>>b[i].book_name;
        fin>>b[i].category;
        fin>>b[i].ISBN;
        fin>>b[i].author;
        fin>>b[i].price;
        fin>>b[i].reader;
        fin>>b[i].amount;
    }
    do{
        print_menu();
        cin>>choice;
        switch(choice){
            case 1:
                add_book(b, n);
                break;
            case 2:
                search_book(b, n);
                break;
            case 3:
                update_book(b, n);
                break;
            case 4:
                delete_book(b, n);
                break;
            case 5:
                sort_book(b, n);
                break;
            case 6:
                display_book(b, n);
                break;
            case 7:
                break;
            default:
                cout<<"\nInvalid choice.\n";
        }
    }while(choice!=7);
    //overwrite the same file with the latest contents of the array
    ofstream fout("file.txt");
    for(int i=0;i<n;i++){
        fout<<b[i].book_name<<" ";
        fout<<b[i].category<<" ";
        fout<<b[i].ISBN<<" ";
        fout<<b[i].author<<" ";
        fout<<b[i].price<<" ";
        fout<<b[i].reader<<" ";
        fout<<b[i].amount<<"\n";
    }
    //write the statistical report in a separate text file
   ofstream fout1("report.txt");
   fout1.open("report.txt",ios::out);
    fout1<<"Number of records: "<<n<<"\n";
    fout1<<"Date of last update: "<<__DATE__<<"\n";
    fout1<<"Time of last update: "<<__TIME__<<"\n";
    return 0;
}

