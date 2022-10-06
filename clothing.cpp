#include "clothing.h"
#include <iomanip>
#include <sstream>

using namespace std;

Clothing::Clothing(
        const std::string category, const std::string name, double price, int qty, std::string size, std::string brand)
        : Product(category, name, price, qty), size_(size), brand_(brand) {}

Clothing::~Clothing() {}

double Clothing::getPrice() const { return price_; }

std::string Clothing::getName() const { return name_; }

void Clothing::subtractQty(int num) { qty_ -= num; }

int Clothing::getQty() const { return qty_; }

std::set<std::string> Clothing::keywords() const {

    std::set<std::string> nameWords = parseStringToWords(name_);
    std::set<std::string> brandWords = parseStringToWords(brand_);
    std::set<std::string> words(nameWords);
    words.insert(brandWords.begin(), brandWords.end());
    return words;
}

std::string Clothing::displayString() const {
      return "Name: " + name_ + "\nPrice: " + to_string(price_) + "\nQuantity: " + to_string(qty_) + "\nSize: " + size_ + "\nBrand: " + brand_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Clothing::isMatch(std::vector<std::string>& searchTerms) const { return false; }

void Clothing::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}
