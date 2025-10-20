#include <iostream>
#include <string>
using namespace std;

struct BookDetails {
    string author;
    int pageCount;
};

struct MultimediaDetails {
    int duration;
    string format;
};

class LibraryItem {
private:
    int itemID;
    string title;
    double fileSize;
    int accessCount;
    static int totalItems;

public:
    BookDetails bookInfo;
    MultimediaDetails mediaInfo;

    LibraryItem() : itemID(0), title("Unknown"), fileSize(0.0), accessCount(0) {
        totalItems++;
    }

    LibraryItem(int id, string t, double size, int count) : itemID(id), title(t), fileSize(size), accessCount(count) {
        totalItems++;
    }

    void accessItem() {
        accessCount++;
    }

    void displayDetails() const {
        cout << "Item ID: " << itemID << "\nTitle: " << title
             << "\nFile Size: " << fileSize << " MB\nAccess Count: " << accessCount << endl;
    }

    static int getTotalItems() {
        return totalItems;
    }
};

int LibraryItem::totalItems = 0;

void displayAllDetails(const LibraryItem& item) {
    item.displayDetails();

    if (!item.bookInfo.author.empty()) {
        cout << "Author: " << item.bookInfo.author
             << "\nPage Count: " << item.bookInfo.pageCount << endl;
    }

    if (!item.mediaInfo.format.empty()) {
        cout << "Duration: " << item.mediaInfo.duration << " minutes"
             << "\nFormat: " << item.mediaInfo.format << endl;
    }
}

int main() {
    LibraryItem book1(201, "C++ Programming", 1.5, 0);
    book1.bookInfo = {"Bjarne Stroustrup", 350};

    LibraryItem media1(202, "Learning C++ Video", 600.0, 0);
    media1.mediaInfo = {45, "MP4"};

    LibraryItem item3;

    book1.accessItem();
    media1.accessItem();
    media1.accessItem();

    cout << "Details for book1:" << endl;
    displayAllDetails(book1);
    cout << "\nDetails for media1:" << endl;
    displayAllDetails(media1);

    cout << "\nDetails for item3:" << endl;
    item3.displayDetails();

    cout << "\nTotal Library Items Created: " << LibraryItem::getTotalItems() << endl;

    return 0;
}
