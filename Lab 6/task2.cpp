#include <iostream>
using namespace std;

class FlightCrew {
protected:
    int crewID;
    int yearsOfService;
    int totalSalary;

public:
    FlightCrew(int id = 0, int years = 0, int salary = 0) : crewID(id), yearsOfService(years), totalSalary(salary) {}

    virtual double bonus() const = 0;

    virtual bool isEligible() const = 0;
};

class Pilot : public FlightCrew {
private:
    int flightHours;
    bool hasMilitaryExperience;

public:
    Pilot(int id = 0, int years = 0, int salary = 0, int hours = 0, bool military = false)
        : FlightCrew(id, years, salary), flightHours(hours), hasMilitaryExperience(military) {}

    double bonus() const override {
        return flightHours * (0.1 * totalSalary);
    }

    bool isEligible() const override {
        return (yearsOfService >= 5 && flightHours > 100);
    }
};

class CabinCrew : public FlightCrew {
private:
    int trainingSessionsAttended;
    int totalFlightsServed;

public:
    CabinCrew(int id = 0, int years = 0, int salary = 0, int sessions = 0, int flights = 0)
        : FlightCrew(id, years, salary), trainingSessionsAttended(sessions), totalFlightsServed(flights) {}

    double bonus() const override {
        return totalFlightsServed * (0.05 * totalSalary);
    }

    bool isEligible() const override {
        return (totalFlightsServed >= 10 && trainingSessionsAttended >= 5);
    }
};

int main() {
    Pilot pilot(101, 6, 50000, 120, true);
    cout << "Pilot Bonus: $" << pilot.bonus() << endl;
    cout << "Pilot Eligibility: " << (pilot.isEligible() ? "Eligible for promotion" : "Not eligible for promotion") << endl;

    cout << endl;

    CabinCrew cabinCrew(201, 4, 30000, 6, 12);
    cout << "Cabin Crew Bonus: $" << cabinCrew.bonus() << endl;
    cout << "Cabin Crew Eligibility: " << (cabinCrew.isEligible() ? "Eligible for promotion" : "Not eligible for promotion") << endl;

    return 0;
}
