//Arsal Khan ID:300211969

#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// Base class HeritageSite
class HeritageSite {
protected:
    int siteID;
    string name;
    string location;
    int categoryID;

public:
    HeritageSite(int id, string n, string loc, int catID)
        : siteID(id), name(n), location(loc), categoryID(catID) {}

    virtual void viewSiteDetails() {
        cout << "Site ID: " << siteID << "\nName: " << name
             << "\nLocation: " << location << "\nCategory ID: " << categoryID << endl;
    }

    virtual void updateProfile(string newName, string newLocation, int newCategoryID) {
        name = newName;
        location = newLocation;
        categoryID = newCategoryID;
    }

    virtual string getDescription() const = 0; // Pure virtual function

    int getSiteID() const { return siteID; }
    int getCategoryID() const { return categoryID; }

    bool operator==(const HeritageSite &other) const { return siteID == other.siteID; }
};

// Derived class CulturalSite
class CulturalSite : public HeritageSite {
private:
    string culturalSignificance;

public:
    CulturalSite(int id, string n, string loc, int catID, string significance)
        : HeritageSite(id, n, loc, catID), culturalSignificance(significance) {}

    void viewSiteDetails() override {
        HeritageSite::viewSiteDetails();
        cout << "Cultural Significance: " << culturalSignificance << endl;
    }

    string getDescription() const override {
        return "Cultural Site: " + name + ", Significance: " + culturalSignificance;
    }
};

// Derived class NaturalSite
class NaturalSite : public HeritageSite {
private:
    string ecosystemType;

public:
    NaturalSite(int id, string n, string loc, int catID, string ecosystem)
        : HeritageSite(id, n, loc, catID), ecosystemType(ecosystem) {}

    void viewSiteDetails() override {
        HeritageSite::viewSiteDetails();
        cout << "Ecosystem Type: " << ecosystemType << endl;
    }

    string getDescription() const override {
        return "Natural Site: " + name + ", Ecosystem: " + ecosystemType;
    }
};

// Class Category
class Category {
private:
    int categoryID;
    string categoryName;
    vector<shared_ptr<HeritageSite>> siteList;

public:
    Category(int id, string name) : categoryID(id), categoryName(name) {}

    void addSite(shared_ptr<HeritageSite> site) {
        siteList.push_back(site);
    }

    void viewCategoryDetails() {
        cout << "Category ID: " << categoryID << "\nCategory Name: " << categoryName << "\nSites: " << endl;
        for (const auto &site : siteList) {
            cout << " - " << site->getDescription() << endl;
        }
    }

    int getCategoryID() const { return categoryID; }
    string getCategoryName() const { return categoryName; }
};

// Class PreservationEffort
class PreservationEffort {
private:
    int effortID;
    int siteID;
    string description;
    string date;

public:
    PreservationEffort(int eID, int sID, string desc, string d)
        : effortID(eID), siteID(sID), description(desc), date(d) {}

    int getSiteID() const { return siteID; }

    void viewEffortDetails() const {
        cout << "Effort ID: " << effortID << "\nSite ID: " << siteID
             << "\nDescription: " << description << "\nDate: " << date << endl;
    }
};

// Class HeritageInventorySystem
class HeritageInventorySystem {
private:
    vector<shared_ptr<HeritageSite>> heritageSites;
    vector<Category> categories;
    vector<PreservationEffort> preservationEfforts;

    Category* findCategoryByID(int categoryID) {
        for (auto &category : categories) {
            if (category.getCategoryID() == categoryID)
                return &category;
        }
        return nullptr;
    }

public:
    bool doesCategoryExist(int categoryID) {
        return findCategoryByID(categoryID) != nullptr;
    }

    vector<Category>& getCategories() {
        return categories;
    }

    void addSite(shared_ptr<HeritageSite> site) {
        heritageSites.push_back(site);
        Category* category = findCategoryByID(site->getCategoryID());
        if (category) {
            category->addSite(site);
        } else {
            cout << "Warning: No matching category for category ID: " << site->getCategoryID() << endl;
        }
    }

    void addCategory(Category category) {
        categories.push_back(category);
    }

    void recordPreservationEffort(int effortID, int siteID, string description, string date) {
        bool siteExists = false;
        for (const auto &site : heritageSites) {
            if (site->getSiteID() == siteID) {
                siteExists = true;
                break;
            }
        }

        if (siteExists) {
            preservationEfforts.emplace_back(effortID, siteID, description, date);
            cout << "Preservation effort recorded successfully." << endl;
        } else {
            cout << "Error: Site ID not found." << endl;
        }
    }

    void viewPreservationHistory(int siteID) {
        bool historyFound = false;
        for (const auto &effort : preservationEfforts) {
            if (effort.getSiteID() == siteID) {
                effort.viewEffortDetails();
                historyFound = true;
            }
        }

        if (!historyFound) {
            cout << "No preservation history found for Site ID: " << siteID << endl;
        }
    }

    void viewAllSites() {
        for (const auto &site : heritageSites) {
            site->viewSiteDetails();
            cout << endl;
        }
    }
};

// Main function
int main() {
    HeritageInventorySystem system;
    int choice;

    system.addCategory(Category(1, "Cultural Heritage"));
    system.addCategory(Category(2, "Natural Heritage"));

    system.addSite(make_shared<CulturalSite>(101, "Gitwangak Battle Hill", "Kitwanga, BC", 1, "Gitxsan Nation history."));
    system.addSite(make_shared<NaturalSite>(102, "Great Bear Rainforest", "Northern BC", 2, "Large coastal rainforest."));

    do {
        // Main Menu
        cout << "\n--- Heritage Inventory System Menu ---\n";
        cout << "1. Register a Heritage Site\n";
        cout << "2. Add a Category\n";
        cout << "3. View Heritage Sites\n";
        cout << "4. Record Preservation Efforts\n";
        cout << "5. View Preservation History\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, categoryID;
            string name, location, significance, ecosystem;
            cout << "Enter Heritage Site ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Location: ";
            getline(cin, location);
            cout << "Enter Category ID: ";
            cin >> categoryID;
            cin.ignore();

            // Check if the category exists using the public method
            if (!system.doesCategoryExist(categoryID)) {
                cout << "Category with ID " << categoryID << " does not exist.\n";
                cout << "Would you like to create this category or select an existing one?\n";
                cout << "1. Create a new category\n";
                cout << "2. Select an existing category\n";
                int option;
                cin >> option;
                cin.ignore();
                
                if (option == 1) {
                    string categoryName;
                    cout << "Enter new Category Name: ";
                    getline(cin, categoryName);
                    system.addCategory(Category(categoryID, categoryName));
                    cout << "New category created.\n";
                } else if (option == 2) {
                    // Display available categories
                    cout << "Available Categories:\n";
                    for (const auto &existingCategory : system.getCategories()) {
                        cout << "ID: " << existingCategory.getCategoryID()
                             << ", Name: " << existingCategory.getCategoryName() << endl;
                    }
                    cout << "Enter the Category ID to select: ";
                    cin >> categoryID;
                    cin.ignore();
                } else {
                    cout << "Invalid option selected. Proceeding with default option.\n";
                }
            }

            cout << "Enter type of site (1 for Cultural, 2 for Natural): ";
            int siteType;
            cin >> siteType;
            if (siteType == 1) {
                cout << "Enter Cultural Significance: ";
                cin.ignore();
                getline(cin, significance);
                system.addSite(make_shared<CulturalSite>(id, name, location, categoryID, significance));
            } else if (siteType == 2) {
                cout << "Enter Ecosystem Type: ";
                cin.ignore();
                getline(cin, ecosystem);
                system.addSite(make_shared<NaturalSite>(id, name, location, categoryID, ecosystem));
            } else {
                cout << "Invalid site type!\n";
            }
            break;
        }
        case 2: {
            int categoryID;
            string categoryName;
            cout << "Enter Category ID: ";
            cin >> categoryID;
            cin.ignore();
            cout << "Enter Category Name: ";
            getline(cin, categoryName);
            system.addCategory(Category(categoryID, categoryName));
            break;
        }
        case 3:
            system.viewAllSites();
            break;
        case 4: {
            int effortID, siteID;
            string description, date;
            cout << "Enter Effort ID: ";
            cin >> effortID;
            cout << "Enter Site ID (xxx): ";
            cin >> siteID;
            cin.ignore();
            cout << "Enter Description: ";
            getline(cin, description);
            cout << "Enter Date (YYYY-MM-DD): ";
            cin >> date;
            system.recordPreservationEffort(effortID, siteID, description, date);
            break;
        }
        case 5: {
            int siteID;
            cout << "Enter Site ID: ";
            cin >> siteID;
            system.viewPreservationHistory(siteID);
            break;
        }
        case 6:
            cout << "Exiting system." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
