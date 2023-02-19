#ifndef LIBRARY_b_H
#define LIBRARY_b_H
#include<iostream> 
#include<fstream>
#include<string>
using namespace std;


//structure for book details, reader, and authors
struct Books{
    string book_name;
    string category;
    int ISBN;
    string author;
    int price;
    string reader;
    int amount;
};

//function to add new book
void add_book(Books b[], int s){
    cout<<"\nEnter the number of book details you want to add: ";
    int n;
    cin>>n;
    //if the array size is less than the number of books user wants to add
    if(s<n){
        cout<<"\nArray size is small to add the books.\n";
    }
    else{
        for(int i=0;i<n;i++){
            cout<<"\nEnter the book name: ";
            cin>>b[i].book_name;
            cout<<"\nEnter the category: ";
            cin>>b[i].category;
            cout<<"\nEnter the ISBN: ";
            cin>>b[i].ISBN;
            cout<<"\nEnter the author name: ";
            cin>>b[i].author;
            cout<<"\nEnter the price: ";
            cin>>b[i].price;
            cout<<"\nEnter the reader name: ";
            cin>>b[i].reader;
            cout<<"\nEnter the amount: ";
            cin>>b[i].amount;
        }
    }
}

//function to search for a specific book
void search_book(Books b[], int s){
   string book;
    int flag=0;
    cout<<"\nEnter the book name to be searched: ";
    cin>>book;
    for(int i=0;i<s;i++){
        if(b[i].book_name == book){
            cout<<"\nBook found.\n";
            cout<<"\nBook Name: "<<b[i].book_name;
            cout<<"\nCategory: "<<b[i].category;
            cout<<"\nISBN: "<<b[i].ISBN;
            cout<<"\nAuthor Name: "<<b[i].author;
            cout<<"\nPrice: "<<b[i].price;
            cout<<"\nReader Name: "<<b[i].reader;
            cout<<"\nAmount: "<<b[i].amount;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"\nBook not found.\n";
    }
}

//function to update an existing book
void update_book(Books b[], int s){
    string book;
    int flag=0;
    cout<<"\nEnter the book name to be updated: ";
    cin>>book;
    for(int i=0;i<s;i++){
        if(b[i].book_name == book){
            cout<<"\nEnter the new book name: ";
            cin>>b[i].book_name;
            cout<<"\nEnter the new category: ";
            cin>>b[i].category;
            cout<<"\nEnter the new ISBN: ";
            cin>>b[i].ISBN;
            cout<<"\nEnter the new author name: ";
            cin>>b[i].author;
            cout<<"\nEnter the new price: ";
            cin>>b[i].price;
            cout<<"\nEnter the new reader name: ";
            cin>>b[i].reader;
            cout<<"\nEnter the new amount: ";
            cin>>b[i].amount;
            flag=1;
            cout<<"\nBook updated.\n";
            break;
        }
    }
    if(flag==0){
        cout<<"\nBook not found.\n";
    }
}

//function to delete an existing book
void delete_book(Books b[], int s){
    string book;
    int flag=0;
    cout<<"\nEnter the book name to be deleted: ";
    cin>>book;
    for(int i=0;i<s;i++){
        if(b[i].book_name == book){
            for(int j=i;j<s-1;j++){
                b[j]=b[j+1];
            }
            flag=1;
            cout<<"\nBook deleted.\n";
            break;
        }
    }
    if(flag==0){
        cout<<"\nBook not found.\n";
    }
}

//function to sort the books
void sort_book(Books b[], int s){
    int flag;
    Books temp;
    do{
        flag=0;
        for(int i=0;i<s-1;i++){
            if(b[i].price>b[i+1].price){
                temp=b[i];
                b[i]=b[i+1];
                b[i+1]=temp;
                flag=1;
            }
        }
    }while(flag==1);
    cout<<"\nBooks sorted.\n";
}

//function to display the books
void display_book(Books b[], int s){
    cout<<"\nBook Details:\n";
    cout<<"\nBook Name\tCategory\tISBN\tAuthor Name\tPrice\tReader Name\tAmount\n";
    for(int i=0;i<s;i++){
        cout<<b[i].book_name<<"\t"<<b[i].category<<"\t"<<b[i].ISBN<<"\t"<<b[i].author<<"\t"<<b[i].price<<"\t"<<b[i].reader<<"\t"<<b[i].amount<<"\n";
    }
}

//function to print the menu
void print_menu(){
    cout<<"\n1. Add a new book.\n";
    cout<<"2. Search for a specific book.\n";
    cout<<"3. Update existing book record.\n";
    cout<<"4. Delete an existing book.\n";
    cout<<"5. Sort the books.\n";
    cout<<"6. Display the books.\n";
    cout<<"7. Exit.\n";
}




#endif
