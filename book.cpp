#include "book.h"
#include "product.h"
#include <iostream>

using namespace std;

Book::Book(
        const std::string category,
        const std::string name,
        double price,
        int qty,
        const std::string isbn,
        const std::string author)
        : Product(category, name, price, qty), isbn_(isbn), author_(author) {}

Book::~Book() {}

double Book::getPrice() const { return price_; }

std::string Book::getName() const { return name_; }

void Book::subtractQty(int num) { qty_ -= num; }

int Book::getQty() const { return qty_; }

std::set<std::string> Book::keywords() const {

    std::set<std::string> nameWords = parseStringToWords(name_);
    std::set<std::string> authorWords = parseStringToWords(author_);
    std::set<std::string> words(nameWords);
    words.insert(authorWords.begin(), authorWords.end());
    words.insert(isbn_);
    return words;
}

std::string Book::displayString() const {
    return "Name: " + name_ + "\nPrice: " + to_string(price_) + "\nQuantity: " + to_string(qty_) + "\nISBN: " + isbn_ + "\nAuthor: " + author_;
}
/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Book::isMatch(std::vector<std::string>& searchTerms) const { return false; }

void Book::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}
