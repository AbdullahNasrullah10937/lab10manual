#include <iostream>
using namespace std;

class Book {
protected:
	string title;
	string author;
	double price;
public:
	Book(const string& t, const string& a, double p) : title(t), author(a), price(p) {}
	virtual void displayDetails()
	{
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Price: " << price << endl;
	}
};


class FictionBook : public Book
{
private:
	string genre;
public:
	FictionBook(const string& t, const string& a, double p, const string& g)
		: Book(t, a, p), genre(g) {}

	void displayDetails() override {
		Book displayDetails();
		cout << "Genre: " << genre << endl;
	}

};


class NonFictionBook : public Book {
private:
	string subject;

public:
	NonFictionBook(const string& t, const string& a, double p, const string& s)
		: Book(t, a, p), subject(s) {}

	void displayDetails() override {
		Book displayDetails();
		cout << "Subject: " << subject << endl;
	}

};


class eBook : public Book {
private:
	string format;
	string fileLocation;

public:
	eBook(const string& t, const string& a, double p, const string& f, const string& loc)
		: Book(t, a, p), format(f), fileLocation(loc) {}

	void displayDetails() override {
		Book displayDetails();
		cout << "Format: " << format << endl;
		cout << "File Location: " << fileLocation << endl;
	}
};


class AudioBook : public Book {
private:
	string narrator;
	int duration;

public:
	AudioBook(const string& t, const string& a, double p, const string& n, int d)
		: Book(t, a, p), narrator(n), duration(d) {}

	void displayDetails() override {
		Book displayDetails();
		cout << "Narrator: " << narrator << endl;
		cout << "Duration: " << duration << endl;
	}
};

int main() {
	Book* bookPtr = nullptr;

	int choice;
	do {
		cout << "Menu:" << endl;
		cout << "1. Display details of base Book" << endl;
		cout << "2. Display details of FictionBook" << endl;
		cout << "3. Display details of NonFictionBook" << endl;
		cout << "4. Display details of eBook" << endl;
		cout << "5. Display details of AudioBook" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			// Base Book
			bookPtr = new Book("Base Book", "Base Author", 10.00);
			break;
		case 2:
			// FictionBook
			bookPtr = new FictionBook("Fiction Book", "Fiction Author", 15.00, "Fiction Genre");
			break;
		case 3:
			// NonFictionBook
			bookPtr = new NonFictionBook("Non-Fiction Book", "Non-Fiction Author", 20.00, "Non-Fiction Subject");
			break;
		case 4:
			// eBook
			bookPtr = new eBook("eBook", "eBook Author", 5.00, "PDF", "/path/to/ebook.pdf");
			break;
		case 5:
			// AudioBook
			bookPtr = new AudioBook("Audio Book", "Audio Author", 25.00, "Narrator Name", 600);
			break;
		case 0:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice! Please try again." << endl;
			break;
		}

		if (bookPtr) {
			bookPtr->displayDetails();
			delete bookPtr;
		}

	} while (choice != 0);


}
