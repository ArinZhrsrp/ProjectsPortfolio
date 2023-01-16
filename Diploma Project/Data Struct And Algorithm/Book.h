#pragma once
#include<iostream>
#include <iomanip>
using namespace std;

template <class Datatype, class T>
class Book
{
private:
	class Node
	{
	public:
		Datatype title;
		T id;
		T ISBN;
		T publishYear;
		Datatype author;
		Datatype Publisher;
		Datatype category;
		Node* next;

	};

	Node* rear;
	Node* front;
	Node* temp;
	int count;

public:
	Book();
	void DisplayBuku();
	int numCount();
	void Enqueue(Datatype, T, Datatype, Datatype, T, Datatype, T);
	void Dequeue(Datatype, T);
	bool Empty();
	void Update(Datatype, T);
	void sortingTitle();
	void sortingId();
	void sortingAuthor();
	void sortingCategory();
	void sortingISBN();
	void sortingPublisher();
	void sortingPublishYear();
	void searching();
	void Traverse(string);
	bool checked(T);
};

template <class Datatype, class T>
Book<Datatype, T>::Book()
{
	front = NULL;
	rear = NULL;
	count = 0;
}

template <class Datatype, class T>
void Book<Datatype, T>::DisplayBuku()
{
	if (!Empty()) {
		Node* traverse = front;
		cout << "BOOK: \n";
		cout << "|| " << setw(12) << "TITLE" << setw(12);
		cout << "|| " << setw(6) << "ID" << setw(9);
		cout << "|| " << setw(10) << "AUTHOR" << setw(8);
		cout << "|| " << setw(9) << "GENRE" << setw(9);
		cout << "|| " << setw(9) << "ISBN" << setw(9);
		cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
		cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
		cout << "|| " << endl;
		cout << endl;

		int i = 1;
		while (traverse != NULL)
		{

			cout << i << ":";
			cout << setw(17) << traverse->title;
			cout << setw(15) << traverse->id;
			cout << setw(19) << traverse->author;
			cout << setw(18) << traverse->category;
			cout << setw(17) << traverse->ISBN;
			cout << setw(24) << traverse->Publisher;
			cout << setw(20) << traverse->publishYear;
			cout << endl;
			traverse = traverse->next;
			i = i + 1;



		}
	}
	else

		cout << "Our Library is empty right now\n";
}

template <class Datatype, class T>
int Book <Datatype, T>::numCount()
{
	return count;
}

template <class Datatype, class T>
void Book<Datatype, T>::Enqueue(Datatype Title, T Id, Datatype Author, Datatype Category, T ISBN, Datatype Publisher, T publishYear)
{

	Node* newNode = new Node;
	newNode->title = Title;
	newNode->id = Id;
	newNode->author = Author;
	newNode->category = Category;
	newNode->ISBN = ISBN;
	newNode->Publisher = Publisher;
	newNode->publishYear = publishYear;
	newNode->next = NULL;
	if (!Empty())  // test if queue is not empty 
		rear->next = newNode;
	else
		front = newNode;

	count++;
	rear = newNode;
}


template <class Datatype, class T>
void Book<Datatype, T>::Dequeue(Datatype title, T id)//DELETE
{

	if (Empty())// test if queue is empty 
	{
		cout << "\nData is empty!\n";
	}
	else
	{
		Node* temp = new Node;
		Node* pBefore = new Node;
		pBefore = NULL;
		temp = front;
		if (count == 1)
		{
			if (temp->id == id)
			{
				front = rear = NULL;
				count--;
				cout << "Book has deleted!\n";
			}
			else
			{
				cout << "Not Found!\n";
			}
		}
		else
		{
			while (temp->id != id && temp->next != NULL)
			{
				pBefore = temp;
				temp = temp->next;

			}

			if (temp->id == front->id)
			{
				front = front->next;

				delete temp;
				count--;
				cout << "Book has deleted!\n";
			}
			else if (temp->id == rear->id)
			{
				pBefore->next = temp->next;
				rear = pBefore;

				delete temp;
				count--;
				cout << "Book has deleted!AAAAAAAAAAA\n";
			}
			else if (temp->id == id)
			{
				pBefore->next = temp->next;

				delete temp;
				count--;
				cout << "Book has deleted!\n";
			}
			else
			{
				cout << "Not Found!\n";
			}


		}

	}


}

template <class Datatype, class T>
bool Book <Datatype, T> ::Empty()
{
	return (count == 0);
}

template<class Datatype, class T>
void Book<Datatype, T>::Update(Datatype title, T id)
{
	int choice2;
	Node* pCurr = new Node;
	pCurr = front;
	while (pCurr->title != title && pCurr->id != id && pCurr->next != 0)
	{
		pCurr = pCurr->next;
	}


	if (pCurr->title == title)
	{
	tryAgain1:
		system("cls");
		cout << "|| " << setw(12) << "TITLE" << setw(12);
		cout << "|| " << setw(6) << "ID" << setw(9);
		cout << "|| " << setw(10) << "AUTHOR" << setw(8);
		cout << "|| " << setw(9) << "GENRE" << setw(9);
		cout << "|| " << setw(9) << "ISBN" << setw(9);
		cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
		cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
		cout << "|| " << endl;
		cout << endl;
		cout << setw(17) << pCurr->title;
		cout << setw(15) << pCurr->id;
		cout << setw(19) << pCurr->author;
		cout << setw(18) << pCurr->category;
		cout << setw(17) << pCurr->ISBN;
		cout << setw(24) << pCurr->Publisher;
		cout << setw(20) << pCurr->publishYear;
		cout << endl;
		/*cout << "BOOK \n";
		cout << "__\n";
		cout << "|TITLE  -     |" << pCurr->title << "\n";
		cout << "|ID     -     |" << pCurr->id << "\n";
		cout << "|AUTHOR -     |" << pCurr->author << "\n";
		cout << "|GENRE  -     |" << pCurr->category << "\n";
		cout << "|ISBN   -     |" << pCurr->ISBN << endl;
		cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
		cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
		cout << "|             |\n";
		cout << "|_|\n\n";*/


		cout << "\n1:Title\n";
		//cout << "\n2:Id\n";
		cout << "\n2:Author\n";
		cout << "\n3:Category\n";
		cout << "\n4:Publisher\n";
		cout << "\n5:Publish Year\n";
		cout << "\n Enter you want to Update:";
		cin >> choice2;

		if (choice2 == 1)
		{
			Datatype title;
			cout << "Title now:" << pCurr->title << endl;
			cin.ignore();
			cout << "Enter title:";
			getline(cin, title);

			pCurr->title = title;

			system("cls");
			cout << "Title updated!\n";
			cout << "Title then:" << pCurr->title << endl << endl;

			/*cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|ISBN   -     |" << pCurr->ISBN << endl;
			cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
			cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
			cout << "|             |\n";
			cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;

		}
		/*else if (choice2 == 2)
		{
			T id;
			cout << "Id now:" << pCurr->id << endl;
			cout << "Enter Id:";
			cin >> id;
			pCurr->id = id;

			system("cls");
			cout << "Id updated!\n";
			cout << "Id then:" << pCurr->id << endl << endl;

			cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|             |\n";
			cout << "|             |\n";
			cout << "|_|\n\n";
		}*/
		else if (choice2 == 2)
		{
			Datatype author;
			cout << "Author now:" << pCurr->author << endl;
			cin.ignore();
			cout << "Enter author:";
			getline(cin, author);

			pCurr->author = author;

			system("cls");
			cout << "Author updated!\n";
			cout << "Author then:" << pCurr->author << endl << endl;

			/*cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|ISBN   -     |" << pCurr->ISBN << endl;
			cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
			cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
			cout << "|             |\n";
			cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;
		}
		else if (choice2 == 3)
		{
			Datatype category;
			cout << "Category now:" << pCurr->category << endl;
			cin.ignore();
			cout << "Enter category:";
			getline(cin, category);

			pCurr->category = category;

			system("cls");
			cout << "Category updated!\n";
			cout << "Category then:" << pCurr->category << endl << endl;

			/*cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|ISBN   -     |" << pCurr->ISBN << endl;
			cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
			cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
			cout << "|             |\n";
			cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;
		}
		else if (choice2 == 4)
		{
			Datatype Publisher;
			cout << "Publisher now:" << pCurr->Publisher << endl;
			cin.ignore();
			cout << "Enter publisher:";
			getline(cin, Publisher);
			/*	cin >> Publisher;*/
			pCurr->Publisher = Publisher;

			system("cls");
			cout << "Title updated!\n";
			cout << "Title then:" << pCurr->Publisher << endl << endl;

			/*cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|ISBN   -     |" << pCurr->ISBN << endl;
			cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
			cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
			cout << "|             |\n";
			cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;

		}
		else if (choice2 == 5)
		{
			T publishYear;
			cout << "publishYear now:" << pCurr->publishYear << endl;
			cout << "Enter publishYear:";
			cin >> publishYear;
			pCurr->publishYear = publishYear;

			system("cls");
			cout << "Publish Year updated!\n";
			cout << "Publish Year then:" << pCurr->publishYear << endl << endl;

			/*cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|ISBN   -     |" << pCurr->ISBN << endl;
			cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
			cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
			cout << "|             |\n";
			cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;

		}
		else
		{
			system("cls");
			cout << "Invalid number,try again\n";
			system("pause");
			goto tryAgain1;
		}

	}
	else if (pCurr->id == id)
	{
	tryAgain2:
		system("cls");
		/*cout << "BOOK \n";
		cout << "__\n";
		cout << "|TITLE  -     |" << pCurr->title << "\n";
		cout << "|ID     -     |" << pCurr->id << "\n";
		cout << "|AUTHOR -     |" << pCurr->author << "\n";
		cout << "|GENRE  -     |" << pCurr->category << "\n";
		cout << "|ISBN   -     |" << pCurr->ISBN << endl;
		cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
		cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
		cout << "|             |\n";
		cout << "|_|\n\n";*/
		cout << "|| " << setw(12) << "TITLE" << setw(12);
		cout << "|| " << setw(6) << "ID" << setw(9);
		cout << "|| " << setw(10) << "AUTHOR" << setw(8);
		cout << "|| " << setw(9) << "GENRE" << setw(9);
		cout << "|| " << setw(9) << "ISBN" << setw(9);
		cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
		cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
		cout << "|| " << endl;
		cout << endl;
		cout << setw(17) << pCurr->title;
		cout << setw(15) << pCurr->id;
		cout << setw(19) << pCurr->author;
		cout << setw(18) << pCurr->category;
		cout << setw(17) << pCurr->ISBN;
		cout << setw(24) << pCurr->Publisher;
		cout << setw(20) << pCurr->publishYear;
		cout << endl;


		cout << "\n1:Title\n";
		//cout << "\n2:Id\n";
		cout << "\n2:Author\n";
		cout << "\n3:Category\n";
		cout << "\n4:Publisher\n";
		cout << "\n5:Publish Year\n";
		cout << "\n Enter you want to Update:";
		cin >> choice2;

		if (choice2 == 1)
		{
			Datatype title;
			cout << "Title now:" << pCurr->title << endl;
			cin.ignore();
			cout << "Enter title:";
			getline(cin, title);
			pCurr->title = title;

			system("cls");
			cout << "Title updated!\n";
			cout << "Title then:" << pCurr->title << endl << endl;

			/*cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|ISBN   -     |" << pCurr->ISBN << endl;
			cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
			cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
			cout << "|             |\n";
			cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;

		}
		/*else if (choice2 == 2)
		{
			T id;
			cout << "Id now:" << pCurr->id << endl;
			cout << "Enter Id:";
			cin >> id;
			pCurr->id = id;

			system("cls");
			cout << "Id updated!\n";
			cout << "Id then:" << pCurr->id << endl << endl;

			cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|             |\n";
			cout << "|             |\n";
			cout << "|_|\n\n";
		}*/
		else if (choice2 == 2)
		{
			Datatype author;
			cout << "Author now:" << pCurr->author << endl;
			cin.ignore();
			cout << "Enter author:";
			getline(cin, author);
			pCurr->author = author;

			system("cls");
			cout << "Author updated!\n";
			cout << "Author then:" << pCurr->author << endl << endl;

			/*cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|ISBN   -     |" << pCurr->ISBN << endl;
			cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
			cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
			cout << "|             |\n";
			cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;
		}
		else if (choice2 == 3)
		{
			Datatype category;
			cout << "Category now:" << pCurr->category << endl;
			cin.ignore();
			cout << "Enter category:";
			getline(cin, category);

			pCurr->category = category;

			system("cls");
			cout << "Category updated!\n";
			cout << "Category then:" << pCurr->category << endl << endl;

			/*cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|ISBN   -     |" << pCurr->ISBN << endl;
			cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
			cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
			cout << "|             |\n";
			cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;
		}
		else if (choice2 == 4)
		{
			Datatype Publisher;
			cout << "Publisher now:" << pCurr->Publisher << endl;
			cin.ignore();
			cout << "Enter publisher:";
			getline(cin, Publisher);

			pCurr->Publisher = Publisher;

			system("cls");
			cout << "Title updated!\n";
			cout << "Title then:" << pCurr->Publisher << endl << endl;

			/*	cout << "BOOK \n";
				cout << "__\n";
				cout << "|TITLE  -     |" << pCurr->title << "\n";
				cout << "|ID     -     |" << pCurr->id << "\n";
				cout << "|AUTHOR -     |" << pCurr->author << "\n";
				cout << "|GENRE  -     |" << pCurr->category << "\n";
				cout << "|ISBN   -     |" << pCurr->ISBN << endl;
				cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
				cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
				cout << "|             |\n";
				cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;

		}
		else if (choice2 == 5)
		{
			T publishYear;
			cout << "publishYear now:" << pCurr->publishYear << endl;
			cout << "Enter publishYear:";
			cin >> publishYear;
			pCurr->publishYear = publishYear;

			system("cls");
			cout << "Publish Year updated!\n";
			cout << "Publish Year then:" << pCurr->publishYear << endl << endl;

			/*cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|ISBN   -     |" << pCurr->ISBN << endl;
			cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
			cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
			cout << "|             |\n";
			cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;

		}
		else
		{
			cout << "Invalid number,try again\n";
			system("pause");
			goto tryAgain2;
		}

	}
	else
	{
		cout << "Book does not exist" << endl;
	}
}


template <class Datatype, class T>
void Book<Datatype, T>::searching()
{

	if (Empty())
	{
		system("cls");
		cout << "Our Book is currently not available\n\n";
		cout << "Please contact our Admin and try again later\n";
	}
	else
	{
	tryAgain2:
		system("cls");
		bool foundBook = false;
		Datatype choiceRent;
		cin.ignore();
		cout << "Please insert title of book that you want to rent ( One Book at one time )\n";
		getline(cin, choiceRent);
		Node* traverse = front;
		while (traverse != NULL)
		{

			if (traverse->title == choiceRent)
			{
				cout << traverse->title << " book is availabe for rental services\n\n";
				cout << "You must return the book not less than 7 days start from today's date \n\n";
				cout << "NOTE THAT YOU WILL BE FINED 20 CENT PER DAY IF YOU RETURN THE BOOK LATE \n";
				foundBook = true;
				break;

			}

			traverse = traverse->next;

		}
		if (!foundBook)
		{
			cout << "Book Not Found\n\n";
			int yesNo;
		tryAgain3:
			cout << "Do you want to try again or not \n\n";
			cout << "1 for Yes and 2 for No \n";
			cin >> yesNo;

			if (yesNo == 1)
			{
				goto tryAgain2;
				system("cls");
			}
			else if (yesNo == 2)
			{
				cout << "Okay Then \n";
			}
			else
			{
				cout << "Invalid Choice \n";
				goto tryAgain3;

			}

		}
	}

}

template <class Datatype, class T>
void Book<Datatype, T>::sortingTitle()
{
	Node* h = front;
	Node* i;
	Node* j;
	for (i = h; i != NULL && i->next != NULL; i = i->next) {
		Node* min;
		min = i;
		for (j = i->next; j != NULL; j = j->next)
		{
			if (j->title < min->title)
				min = j;
		}
		if (min != i)
		{
			Datatype temp1, temp3, temp4, temp6;
			T temp2, temp5, temp7;
			temp1 = min->title;
			temp2 = min->id;
			temp3 = min->author;
			temp4 = min->category;
			temp5 = min->ISBN;
			temp6 = min->Publisher;
			temp7 = min->publishYear;

			min->title = i->title;
			min->id = i->id;
			min->author = i->author;
			min->category = i->category;
			min->ISBN = i->ISBN;
			min->Publisher = i->Publisher;
			min->publishYear = i->publishYear;

			i->title = temp1;
			i->id = temp2;
			i->author = temp3;
			i->category = temp4;
			i->ISBN = temp5;
			i->Publisher = temp6;
			i->publishYear = temp7;
		}
	}
	front = h;
}


template <class Datatype, class T>
void Book<Datatype, T>::sortingId()
{
	Node* h = front;
	Node* i;
	Node* j;
	for (i = h; i != NULL && i->next != NULL; i = i->next) {
		Node* min;
		min = i;
		for (j = i->next; j != NULL; j = j->next)
		{
			if (j->id < min->id)
				min = j;
		}
		if (min != i)
		{
			Datatype temp1, temp3, temp4, temp6;
			T temp2, temp5, temp7;
			temp1 = min->title;
			temp2 = min->id;
			temp3 = min->author;
			temp4 = min->category;
			temp5 = min->ISBN;
			temp6 = min->Publisher;
			temp7 = min->publishYear;

			min->title = i->title;
			min->id = i->id;
			min->author = i->author;
			min->category = i->category;
			min->ISBN = i->ISBN;
			min->Publisher = i->Publisher;
			min->publishYear = i->publishYear;

			i->title = temp1;
			i->id = temp2;
			i->author = temp3;
			i->category = temp4;
			i->ISBN = temp5;
			i->Publisher = temp6;
			i->publishYear = temp7;
		}
	}
	front = h;
}

template <class Datatype, class T>
void Book<Datatype, T>::sortingAuthor()
{
	Node* h = front;
	Node* i;
	Node* j;
	for (i = h; i != NULL && i->next != NULL; i = i->next) {
		Node* min;
		min = i;
		for (j = i->next; j != NULL; j = j->next)
		{
			if (j->author < min->author)
				min = j;
		}
		if (min != i)
		{
			Datatype temp1, temp3, temp4, temp6;
			T temp2, temp5, temp7;
			temp1 = min->title;
			temp2 = min->id;
			temp3 = min->author;
			temp4 = min->category;
			temp5 = min->ISBN;
			temp6 = min->Publisher;
			temp7 = min->publishYear;

			min->title = i->title;
			min->id = i->id;
			min->author = i->author;
			min->category = i->category;
			min->ISBN = i->ISBN;
			min->Publisher = i->Publisher;
			min->publishYear = i->publishYear;

			i->title = temp1;
			i->id = temp2;
			i->author = temp3;
			i->category = temp4;
			i->ISBN = temp5;
			i->Publisher = temp6;
			i->publishYear = temp7;
		}
	}
	front = h;
}

template <class Datatype, class T>
void Book<Datatype, T>::sortingCategory()
{
	Node* h = front;
	Node* i;
	Node* j;
	for (i = h; i != NULL && i->next != NULL; i = i->next) {
		Node* min;
		min = i;
		for (j = i->next; j != NULL; j = j->next)
		{
			if (j->category < min->category)
				min = j;
		}
		if (min != i)
		{
			Datatype temp1, temp3, temp4, temp6;
			T temp2, temp5, temp7;
			temp1 = min->title;
			temp2 = min->id;
			temp3 = min->author;
			temp4 = min->category;
			temp5 = min->ISBN;
			temp6 = min->Publisher;
			temp7 = min->publishYear;

			min->title = i->title;
			min->id = i->id;
			min->author = i->author;
			min->category = i->category;
			min->ISBN = i->ISBN;
			min->Publisher = i->Publisher;
			min->publishYear = i->publishYear;

			i->title = temp1;
			i->id = temp2;
			i->author = temp3;
			i->category = temp4;
			i->ISBN = temp5;
			i->Publisher = temp6;
			i->publishYear = temp7;
		}
	}
	front = h;
}

template <class Datatype, class T>
void Book<Datatype, T>::sortingISBN()
{
	Node* h = front;
	Node* i;
	Node* j;
	for (i = h; i != NULL && i->next != NULL; i = i->next) {
		Node* min;
		min = i;
		for (j = i->next; j != NULL; j = j->next)
		{
			if (j->ISBN < min->ISBN)
				min = j;
		}
		if (min != i)
		{
			Datatype temp1, temp3, temp4, temp6;
			T temp2, temp5, temp7;
			temp1 = min->title;
			temp2 = min->id;
			temp3 = min->author;
			temp4 = min->category;
			temp5 = min->ISBN;
			temp6 = min->Publisher;
			temp7 = min->publishYear;

			min->title = i->title;
			min->id = i->id;
			min->author = i->author;
			min->category = i->category;
			min->ISBN = i->ISBN;
			min->Publisher = i->Publisher;
			min->publishYear = i->publishYear;

			i->title = temp1;
			i->id = temp2;
			i->author = temp3;
			i->category = temp4;
			i->ISBN = temp5;
			i->Publisher = temp6;
			i->publishYear = temp7;
		}
	}
	front = h;
}

template <class Datatype, class T>
void Book<Datatype, T>::sortingPublisher()
{
	Node* h = front;
	Node* i;
	Node* j;
	for (i = h; i != NULL && i->next != NULL; i = i->next) {
		Node* min;
		min = i;
		for (j = i->next; j != NULL; j = j->next)
		{
			if (j->Publisher < min->Publisher)
				min = j;
		}
		if (min != i)
		{
			Datatype temp1, temp3, temp4, temp6;
			T temp2, temp5, temp7;
			temp1 = min->title;
			temp2 = min->id;
			temp3 = min->author;
			temp4 = min->category;
			temp5 = min->ISBN;
			temp6 = min->Publisher;
			temp7 = min->publishYear;

			min->title = i->title;
			min->id = i->id;
			min->author = i->author;
			min->category = i->category;
			min->ISBN = i->ISBN;
			min->Publisher = i->Publisher;
			min->publishYear = i->publishYear;

			i->title = temp1;
			i->id = temp2;
			i->author = temp3;
			i->category = temp4;
			i->ISBN = temp5;
			i->Publisher = temp6;
			i->publishYear = temp7;
		}
	}
	front = h;
}

template <class Datatype, class T>
void Book<Datatype, T>::sortingPublishYear()
{
	Node* h = front;
	Node* i;
	Node* j;
	for (i = h; i != NULL && i->next != NULL; i = i->next) {
		Node* min;
		min = i;
		for (j = i->next; j != NULL; j = j->next)
		{
			if (j->publishYear < min->publishYear)
				min = j;
		}
		if (min != i)
		{
			Datatype temp1, temp3, temp4, temp6;
			T temp2, temp5, temp7;
			temp1 = min->title;
			temp2 = min->id;
			temp3 = min->author;
			temp4 = min->category;
			temp5 = min->ISBN;
			temp6 = min->Publisher;
			temp7 = min->publishYear;

			min->title = i->title;
			min->id = i->id;
			min->author = i->author;
			min->category = i->category;
			min->ISBN = i->ISBN;
			min->Publisher = i->Publisher;
			min->publishYear = i->publishYear;

			i->title = temp1;
			i->id = temp2;
			i->author = temp3;
			i->category = temp4;
			i->ISBN = temp5;
			i->Publisher = temp6;
			i->publishYear = temp7;
		}
	}
	front = h;
}

template <class Datatype, class T>
void Book<Datatype, T>::Traverse(string title)
{
	Node* pCurr = new Node;
	if (count == 0)
		cout << "There is no data about this book " << endl;
	else
	{
		pCurr = front;

		while (pCurr->title != title && pCurr->next != 0)
		{
			pCurr = pCurr->next;
		}
		if (pCurr->title == title)
		{
			system("cls");
			/*cout << "BOOK \n";
			cout << "__\n";
			cout << "|TITLE  -     |" << pCurr->title << "\n";
			cout << "|ID     -     |" << pCurr->id << "\n";
			cout << "|AUTHOR -     |" << pCurr->author << "\n";
			cout << "|GENRE  -     |" << pCurr->category << "\n";
			cout << "|ISBN   -     |" << pCurr->ISBN << endl;
			cout << "|PUBLISHER -  |" << pCurr->Publisher << endl;
			cout << "|YEAR PUBLISH-|" << pCurr->publishYear << endl;
			cout << "|             |\n";
			cout << "|_|\n\n";*/
			cout << "|| " << setw(12) << "TITLE" << setw(12);
			cout << "|| " << setw(6) << "ID" << setw(9);
			cout << "|| " << setw(10) << "AUTHOR" << setw(8);
			cout << "|| " << setw(9) << "GENRE" << setw(9);
			cout << "|| " << setw(9) << "ISBN" << setw(9);
			cout << "|| " << setw(15) << "PUBLISHER" << setw(9);
			cout << "|| " << setw(15) << "PUBLISH YEAR" << setw(9);
			cout << "|| " << endl;
			cout << endl;
			cout << setw(17) << pCurr->title;
			cout << setw(15) << pCurr->id;
			cout << setw(19) << pCurr->author;
			cout << setw(18) << pCurr->category;
			cout << setw(17) << pCurr->ISBN;
			cout << setw(24) << pCurr->Publisher;
			cout << setw(20) << pCurr->publishYear;
			cout << endl;
		}
		else
			cout << "Book does not exist" << endl;
	}
}

template<class Datatype, class T>
bool Book<Datatype, T>::checked(T check)
{
	bool found = true;
	Node* pCurr = new Node;
	pCurr = front;

	while (pCurr->ISBN != check && pCurr->id != check && pCurr->next != 0)
	{
		pCurr = pCurr->next;
	}

	if (pCurr->id == check)
	{
		found = false;
	}

	if (pCurr->ISBN == check)
	{
		found = false;
	}

	return found;
}