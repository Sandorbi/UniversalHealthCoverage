/*
 * File: UniversalHealthCoverage.cpp
#include <iostream>
#include <string>
#include "set.h"
#include "Set.h"
#include "vector.h"
#include "console.h"
#include <tokenscanner.h>
#include <simpio.h>
using namespace std;

/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.
 */
bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
                               Vector< Set<string> >& result);


bool canOfferUniversalCoverage(Set<string>& cities, Vector< Set<string> >& locations, int numHospitals, Vector< Set<string> >& result) {
    if (locations.size() == 0 || result.size() == numHospitals) {
        Set<string> citiesCovered;
        foreach (Set<string> set in result) {
            foreach (string str in set) {
                citiesCovered += str;
            }
        }
        if (citiesCovered.size() == cities.size()) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (result.size() < numHospitals) {
        Set<string> covered = locations[0];
        locations.remove(0);
        result.push_back(covered);
        if (canOfferUniversalCoverage(cities, locations, numHospitals, result)) {
            return true;
        }
        result.remove(result.size() - 1);
        if(canOfferUniversalCoverage(cities, locations, numHospitals, result)) {
            return true;
        }
        locations.insert(0,covered);
    }
    return false;
}

int main() {
    return 0;
}
