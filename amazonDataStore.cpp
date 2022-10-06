#include "amazonDataStore.h"
#include "db_parser.h"
#include "product.h"
#include "product_parser.h"
#include "util.h"
#include <algorithm>
#include <cctype>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
AmazonDataStore::~AmazonDataStore() {

}

void AmazonDataStore::addProduct(Product* p) {

    std::set<std::string> keys;
    keys = p->keywords();

    for (std::set<std::string>::iterator i = keys.begin(); i != keys.end(); i++) {

        std::set<Product*> temp = keyProductPair[convToLower(*i)];
        temp.insert(p);
        keyProductPair[convToLower(*i)] = temp;
    }
}

void AmazonDataStore::addUser(User* u) { 
}

std::vector<Product*> AmazonDataStore::search(std::vector<std::string>& terms, int type) {
    std::vector<Product*> result;
    std::set<Product*> firstS;
    
    for (std::vector<std::string>::iterator i = terms.begin(); i != terms.end(); i++) {
        if (i == terms.begin()) {
            firstS = keyProductPair[*i];
        } else {
            if (type == 0) {
                firstS = setIntersection(firstS, keyProductPair[*i]);
            } else if (type == 1) {
                firstS = setUnion(firstS, keyProductPair[*i]);
            } else {
                cout << "Please choose a valid search type!" << endl;
            }
        }
    }
    for (std::set<Product*>::iterator it = firstS.begin(); it != firstS.end(); it++) {
        result.push_back(*it);
    }
    return result;
}

void AmazonDataStore::dump(std::ostream& ofile) {

}
