#include <iostream>
#include <string>
#include"Book.h"
using namespace std;

void main()
{
	Book <string, int> buku1;
	int MainMenuChoice;

	buku1.Enqueue("Harry Potter", 214, "Jack", "Fantasy", 32786, "Bloomsbury", 2014);
	buku1.Enqueue("Little Big", 216, "OroJackson", "Action", 32712, "EA", 2011);
	buku1.Enqueue("Suamiku Cleaner", 212, "SahabatPena", "Romance", 37482, "PTS", 2012);
	buku1.Enqueue("Mario Cart", 211, "Will", "Adventure", 82201, "SONY", 2012);
	buku1.Enqueue("Little Big 2", 213, "OroJackson", "Action", 63637, "EA", 2014);
	buku1.Enqueue("Mario Cart 2", 217, "Will", "Adventure", 91745, "SONY", 2015);

mainMenu:
	cout << "\t\t******" << endl;
	cout << "\t\t|  WELCOME TO OUR LIBRARY MANAGEMENT SYSTEM  |" << endl;
	cout << "\t\t******" << endl;


	cout << "  1 - I am User\n";
	cout << "  2 - I am An Admin\n\n";
	cout << "  Select aside from 1 and 2 if you want to quit \n";
	cin >> MainMenuChoice;

	if (MainMenuChoice == 1)
	{
		system("cls");
		int userMenuChoice;

	userMenu:
		cout << "  1 - To display Book\n";
		cout << "  2 - To rental a Book\n";
		cout << "  3 - Back\n";
		cin >> userMenuChoice;

		if (userMenuChoice == 1)
		{
			if (buku1.Empty())
			{
				system("cls");
				cout << "Our Book is currently not available\n\n";
				cout << "Please contact our Admin and try again later\n";
			}
			else if (!buku1.Empty())
			{
				system("cls");
				cout << "Total of our currently available Book: " << buku1.numCount() << "\n";

			userMenu_display:
				int displayMenu;
				cout << "  0 - Go back\n";
				cout << "  1 - Display All\n";
				cout << "  2 - Sort\n";
				cout << "  3 - Search\n ";
				cin >> displayMenu;

				if (displayMenu == 1)
				{
					system("cls");
					buku1.DisplayBuku();
				}

				else if (displayMenu == 2)
				{
					system("cls");
				sortMenu:
					int sortMenuChoice;
					cout << "  1 - By Title\n";
					cout << "  2 - By Id\n";
					cout << "  3 - By Author\n";
					cout << "  4 - By Category\n";
					cout << "  5 - By ISBN\n";
					cout << "  6 - By Publisher\n";
					cout << "  7 - By Publish Year\n";
					cout << "  8 - Back\n";
					cin >> sortMenuChoice;
					system("cls");

					if (sortMenuChoice == 1)
					{
						buku1.sortingTitle();
						buku1.DisplayBuku();
					}

					else if (sortMenuChoice == 2)
					{
						buku1.sortingId();
						buku1.DisplayBuku();
					}

					else if (sortMenuChoice == 3)
					{
						buku1.sortingAuthor();
						buku1.DisplayBuku();
					}

					else if (sortMenuChoice == 4)
					{
						buku1.sortingCategory();
						buku1.DisplayBuku();
					}

					else if (sortMenuChoice == 5)
					{
						buku1.sortingISBN();
						buku1.DisplayBuku();
					}

					else if (sortMenuChoice == 6)
					{
						buku1.sortingPublisher();
						buku1.DisplayBuku();
					}

					else if (sortMenuChoice == 7)
					{
						buku1.sortingPublishYear();
						buku1.DisplayBuku();
					}

					else if (sortMenuChoice == 8)
					{
						system("cls");
						goto userMenu_display;
					}
					else
					{
						cout << "Invalid choice. Please try again \n";
						goto sortMenu;
					}

					int userMenuLast1;
					cout << "\n";
					cout << "  0 - Exit Program\n";
					cout << "  1 - Back\n";
					cout << "  2 - Go to Home Page\n";

					cin >> userMenuLast1;
					if (userMenuLast1 == 1)
					{
						system("cls");
						goto sortMenu;
					}
					else if (userMenuLast1 == 2)
					{
						system("cls");
						goto mainMenu;
					}
					else if (userMenuLast1 == 0)
					{
						exit(0);
					}
				}
				else if (displayMenu == 3)
				{
					string title;
					cin.ignore();
					cout << "Please insert the book title that you are looking for : ";
					getline(cin, title);

					buku1.Traverse(title);

				}
				else if (displayMenu == 0)
				{
					system("cls");
					goto userMenu;
				}

				else
				{
					cout << "Invalid choice. Please try again \n";
					goto userMenu_display;
				}

				int userMenuLast2;
				cout << "\n";
				cout << "  0 - Exit Program\n";
				cout << "  1 - Back\n";
				cout << "  2 - Go to Home Page\n";

				cin >> userMenuLast2;
				if (userMenuLast2 == 1)
				{
					system("cls");
					goto userMenu_display;
				}
				else if (userMenuLast2 == 2)
				{
					system("cls");
					goto mainMenu;
				}
				else if (userMenuLast2 == 0)
				{
					exit(0);
				}
			}

			/*int menuDalam2;
			cout << "\n";
			cout << "  0 - Exit Program\n";
			cout << "  1 - Go to Main Menu\n";
			cout << "  2 - Back\n";
			cout << "  3 - Go to Home Page\n";

			cin >> menuDalam2;
			if (menuDalam2 == 1)
			{
				system("cls");
				goto userMenu;
			}
			else if (menuDalam2 == 2)
			{
				system("cls");
				goto tryAgain9;
			}
			else if (menuDalam2 == 3)
			{
				system("cls");
				goto mainMenu;
			}*/
		}
		else if (userMenuChoice == 2)
		{
			buku1.searching();

			int rentChoice;
			cout << "\n\n";
			cout << "  0 - Exit the Program\n";
			cout << "  1 - Go to Home Page\n";
			cout << "  2 - Back\n";
			cin >> rentChoice;

			if (rentChoice == 1)
			{
				system("cls");
				goto mainMenu;

			}

			else if (rentChoice == 2)
			{
				system("cls");
				goto userMenu;
			}

			else if (rentChoice == 0)
			{
				exit(0);
			}
			else
			{
				system("cls");
				cout << "Invalid Choice. Try Again \n";
				goto userMenu;
			}
		}
		else if (userMenuChoice == 3)
		{
			system("cls");
			goto mainMenu;
		}
		else
		{
			system("cls");
			cout << "Invalid Choice. Try Again \n";
			goto userMenu;
		}
	}








	else if (MainMenuChoice == 2)
	{
	AdminLogInMenu:
		system("cls");
		string Username;
		string pass;
		cout << "Enter Admin Username\n";
		cin >> Username;
		cout << "Enter Password\n";
		cin >> pass;

		if ((Username == "Adib" || Username == "Rifqi" || Username == "Shirin") && pass == "1234") {
			int adminMenuChoice;

		adminMenu1:
			system("cls");
			cout << "  1 - Add Book to library\n";
			cout << "  2 - Delete Book from library\n";
			cout << "  3 - Display Book \n";
			cout << "  4 - Edit Book details\n";
			cout << "  5 - LogOut\n\n";
			cout << "  Please enter your option : ";
			cin >> adminMenuChoice;

			if (adminMenuChoice == 1)
			{

			addBookMenu:
				system("cls");
				string Title, Author, Category, Publisher;
				int Id, ISBN, publishYear;
				bool found = true;

				cin.ignore();
				cout << "Please insert Title of the book: \n";
				getline(cin, Title);

			insertId:
				cout << "Please insert ID of the book: \n";
				cin >> Id;
				found = buku1.checked(Id);
				if (!found)
				{
					cout << "\n Id was uses!!**Try another\n";
					system("pause"); cout << endl;
					goto insertId;

				}

				cin.ignore();
				cout << "Please insert Author of the book: \n";
				getline(cin, Author);
				cout << "Please insert Category of the book: \n";
				cin >> Category;

			insertISBN:
				cout << "Please insert ISBN of the book: \n";
				cin >> ISBN;
				found = buku1.checked(ISBN);
				if (!found)
				{
					cout << "\n Id was uses!!**Try another\n";
					system("pause"); cout << endl;
					goto insertISBN;

				}

				cin.ignore();
				cout << "Please insert Publisher of the book: \n";
				getline(cin, Publisher);
					cout << "Please insert publish year of the book: \n";
				cin >> publishYear;

				buku1.Enqueue(Title, Id, Author, Category, ISBN, Publisher, publishYear);
				cout << "Your added Book is :\n";
				buku1.DisplayBuku();

				int addedBookChoice;
				cout << "\n";
			addBookMenuInvalid:
				cout << "  1 - Add another book to library\n";
				cout << "  2 - Go back to Admin Menu \n";
				cout << "  3 - Go back to Home Page \n";
				cin >> addedBookChoice;

				if (addedBookChoice == 1)
				{
					goto addBookMenu;
				}
				else if (addedBookChoice == 2)
				{
					system("cls");
					goto adminMenu1;
				}
				else if (addedBookChoice == 3)
				{
					system("cls");
					goto mainMenu;
				}
				else
				{
					system("cls");
					cout << "Invalide Choice \n";
					goto addBookMenuInvalid;
				}
			}

			else if (adminMenuChoice == 2)
			{
			deletedata:
				system("cls");
				buku1.DisplayBuku();
				string choice;

				string title;
				int id = 0;
				cout << "\n*DELETE*\n";
				cout << "Book to delete (id), 0 [back]:"; cin >> id;

				if (id == 0)
				{
					goto adminMenu1;
				}
				cout << "Do you want to delete (Y/N)?:"; cin >> choice;

				if (choice == "y" || choice == "Y")
				{
					buku1.Dequeue(title, id);

					cout << "\n See data? (Y/N)";
					cin >> choice;
					if (choice == "y" || choice == "Y")
					{
						buku1.DisplayBuku();
						int adminDisplayMenuLast;
						cout << "\n";
						cout << "  0 - Exit Program\n";
						cout << "  1 - Go to Admin Menu\n";
						cout << "  2 - Delete\n";

						cin >> adminDisplayMenuLast;

						if (adminDisplayMenuLast == 1)
						{

							goto adminMenu1;
						}
						else if (adminDisplayMenuLast == 2)
						{
							system("cls");
							goto deletedata;
						}
						else if (adminDisplayMenuLast == 0)
						{
							exit(0);
						}
					}
					else if (choice == "n" || choice == "N")
					{
					choices:
						int adminDisplayMenuLast;

						cout << "1 - Delete\n";
						cout << "2 - Admin Menu\n";
						cin >> adminDisplayMenuLast;

						if (adminDisplayMenuLast == 1)
						{
							system("cls");
							goto deletedata;
						}
						else if (adminDisplayMenuLast == 2)
						{

							goto adminMenu1;
						}
						else
						{
							cout << "Invalid enter\n";
							system("pause");
							goto choices;
						}
					}
				}
				else if (choice == "n" || choice == "N")
				{
					cout << "\nDidnt delete nothing\n";

					cout << "\n See data?(Y/N)";
					cin >> choice;
					if (choice == "y" || choice == "Y")
					{
						buku1.DisplayBuku();
						int adminDisplayMenuLast;
						cout << "\n";
						cout << "  0 - Exit Program\n";
						cout << "  2 - Delete\n";
						cout << "  1 - Go to Admin Menu\n";
						cin >> adminDisplayMenuLast;

						if (adminDisplayMenuLast == 1)
						{

							goto adminMenu1;
						}
						else if (adminDisplayMenuLast == 2)
						{
							system("cls");
							goto deletedata;
						}
						else if (adminDisplayMenuLast == 0)
						{
							exit(0);
						}
					}
					else if (choice == "n" || choice == "N")
					{
					choiced:
						int adminDisplayMenuLast;
						cout << "1 - Delete\n";
						cout << "2 - Admin Menu\n";
						cin >> adminDisplayMenuLast;

						if (adminDisplayMenuLast == 1)
						{
							system("cls");
							goto deletedata;
						}
						else if (adminDisplayMenuLast == 2)
						{

							goto adminMenu1;
						}
						else
						{
							cout << "Invalid enter\n";
							system("pause");
							goto choiced;
						}
					}

				}
				else
				{
					cout << "\nWrong enter try again\n";
					system("pause");
					goto deletedata;
				}
			}

			else if (adminMenuChoice == 3)
			{
				if (buku1.Empty())
				{
					system("cls");
					cout << "Our Book is currently not available\n\n";
					cout << "Please add a Book to our library\n\n";

				}
				else if (!buku1.Empty())
				{
				displayAdminMenu:
					system("cls");
					cout << "Total of our currently available Book: " << buku1.numCount() << "\n";

					int displayMenuChoice;
					cout << "  0 - Go back to Admin menu\n";
					cout << "  1 - Display All\n";
					cout << "  2 - Sort\n";
					cout << "  3 - Search\n";
					cin >> displayMenuChoice;

					if (displayMenuChoice == 0)
					{
						system("cls");
						goto adminMenu1;
					}
					else if (displayMenuChoice == 1)
					{
						system("cls");
						buku1.DisplayBuku();
					}

					else if (displayMenuChoice == 2)
					{
					adminMenuDisplay_sort:
						system("cls");
						int sortAdminChoice;
						cout << "  1 - By Title\n";
						cout << "  2 - By Id\n";
						cout << "  3 - By Author\n";
						cout << "  4 - By Category\n";
						cout << "  5 - By ISBN\n";
						cout << "  6 - By Publisher\n";
						cout << "  7 - By Publish Year\n";
						cout << "  8 - Back\n";
						cin >> sortAdminChoice;

						system("cls");
						if (sortAdminChoice == 1)
						{
							buku1.sortingTitle();
							buku1.DisplayBuku();
						}

						else if (sortAdminChoice == 2)
						{
							buku1.sortingId();
							buku1.DisplayBuku();
						}

						else if (sortAdminChoice == 3)
						{
							buku1.sortingAuthor();
							buku1.DisplayBuku();
						}

						else if (sortAdminChoice == 4)
						{
							buku1.sortingCategory();
							buku1.DisplayBuku();
						}

						else if (sortAdminChoice == 5)
						{
							buku1.sortingISBN();
							buku1.DisplayBuku();
						}

						else if (sortAdminChoice == 6)
						{
							buku1.sortingPublisher();
							buku1.DisplayBuku();
						}

						else if (sortAdminChoice == 7)
						{
							buku1.sortingPublishYear();
							buku1.DisplayBuku();
						}

						else if (sortAdminChoice == 8)
						{
							system("cls");
							goto displayAdminMenu;
						}

						else
						{
							cout << "Invalid choice. Please try again \n";
							goto adminMenuDisplay_sort;
						}

						int adminMenuDisplay_sortLast;
						cout << "\n";
						cout << "  0 - Exit Program\n";
						cout << "  1 - Go to Admin Menu\n";
						cout << "  2 - Back\n";
						cout << "  3 - Logout\n";

						cin >> adminMenuDisplay_sortLast;
						if (adminMenuDisplay_sortLast == 1)
						{
							system("cls");
							goto adminMenu1;
						}
						else if (adminMenuDisplay_sortLast == 2)
						{
							system("cls");
							goto adminMenuDisplay_sort;
						}
						else if (adminMenuDisplay_sortLast == 3)
						{
							system("cls");
							goto mainMenu;
						}
						else if (adminMenuDisplay_sortLast == 0)
						{
							exit(0);
						}
						/*int menuDalam8;
						cout << "\n";
						cout << "  0 - Exit Program\n";
						cout << "  1 - Back\n";
						cout << "  2 - Go to Home Page\n";

						cin >> menuDalam8;
						if (menuDalam8 == 1)
						{
							system("cls");
							goto adminMenuDisplay_sort;
						}
						else if (menuDalam8 == 2)
						{
							system("cls");
							goto mainMenu;
						}*/
					}

					else if (displayMenuChoice == 3)
					{
						string title;
						cin.ignore();
						cout << "Please insert the book title that you are looking for : ";
						getline(cin, title);

						buku1.Traverse(title);
					}

				}

				int adminDisplayMenuLast;
				cout << "\n";
				cout << "  0 - Exit Program\n";
				cout << "  1 - Go to Admin Menu\n";
				cout << "  2 - Back\n";

				cin >> adminDisplayMenuLast;
				if (adminDisplayMenuLast == 1)
				{
					system("cls");
					goto adminMenu1;
				}
				else if (adminDisplayMenuLast == 2)
				{
					system("cls");
					goto displayAdminMenu;
				}
				else if (adminDisplayMenuLast == 0)
				{
					exit(0);
				}
			}

			else if (adminMenuChoice == 4)
			{
			tryAgain11:
				system("cls");

				cout << "Updated\n"; cout << "*\n\n";
				if (buku1.Empty())
				{
					cout << "@Our Library is empty right now@\n\n";
				}

				int option;
				cout << "Search to Updated(Pick no)\n";
				cout << "1.Title\n";
				cout << "2.Id\n";
				cout << "3.Back\n";
				cout << "Option : ";
				cin >> option;

				if (option == 1)
				{
					system("cls");
					string title;
					int id = 0;
					buku1.DisplayBuku();
					cin.ignore();
					cout << "\nSearch title : ";
					getline(cin, title);

					buku1.Update(title, id);
					system("pause");
					goto tryAgain11;
				}
				else if (option == 2)
				{
					system("cls");
					string title;
					int id;
					buku1.DisplayBuku();
					cout << "\nSearch id : ";
					cin >> id;
					buku1.Update(title, id);
					system("pause");
					goto tryAgain11;
				}
				else
				{
					system("cls");
					goto adminMenu1;
				}
			}

			else if (adminMenuChoice == 5)
			{
				system("cls");
				goto mainMenu;
			}

			else
			{
				system("cls");
				goto adminMenu1;
			}
		}
		else
		{

			cout << "\nIncorrect Password Or Username \n";
			cout << "Please try again \n";
			system("pause");
			goto AdminLogInMenu;
		}
	}
	else
	{
		cout << "-------------------------------------------\n";
		cout << "Thanks for using LIBRARY MANAGEMENT SYSTEM \n";
		cout << "-------------------------------------------\n";
		/*system("pause");
		system("cls");*/

	}



}