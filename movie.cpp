#include "movie.h"
#include <iomanip>
#include <sstream>

using namespace std;

Movie::Movie(
        const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating)
        : Product(category, name, price, qty), genre_(genre), rating_(rating) {}

Movie::~Movie() {}

double Movie::getPrice() const { return price_; }

std::string Movie::getName() const { return name_; }

void Movie::subtractQty(int num) { qty_ -= num; }

int Movie::getQty() const { return qty_; }

std::set<std::string> Movie::keywords() const {

    std::set<std::string> nameWords = parseStringToWords(name_);
    std::set<std::string> words(nameWords);
    words.insert(genre_);
    return words;
}

std::string Movie::displayString() const {
    return "Name: " + name_ + "\nPrice: " + to_string(price_) + "\nQuantity: " + to_string(qty_) + "\nGenre: " + genre_ + "\nRating: " + rating_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Movie::isMatch(std::vector<std::string>& searchTerms) const { return false; }

void Movie::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}
