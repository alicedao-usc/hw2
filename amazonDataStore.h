#ifndef AMAZONDATASTORE_H
#define AMAZONDATASTORE_H
#include "datastore.h"
#include "db_parser.h"
#include "product.h"
#include "product_parser.h"
#include "user.h"
#include "util.h"
#include <queue>
#include <map>
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"

class AmazonDataStore : public DataStore {
public:
    ~AmazonDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type) ;

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

    std::map<std::string, std::set<Product*>> keyProductPair;

};

#endif
