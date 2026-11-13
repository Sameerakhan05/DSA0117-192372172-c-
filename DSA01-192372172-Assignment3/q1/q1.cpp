
#include <iostream>
#include <string>
#include <stdexcept>

class Book {
private:
    std::string title;
    std::string author;
    int copies;

public:

    
    Book() : Book("", "Unknown", 0) {
    }

    explicit Book(std::string t) : Book(t, "Unknown", 0) {
    }

    
    Book(std::string t, std::string a, int c)
        : title(t), author(a), copies(c) {

        if (c < 0) {
            throw std::invalid_argument(
                "Copies cannot be negative!"
            );
        }
    }

    
    void display() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Copies: " << copies << std::endl;
        std::cout << "-------------------" << std::endl;
    }
};

int main() {

    try {

        
        Book b1;

        Book b2("C++ Programming");

    
        Book b3("Java Programming", "James Gosling", 5);

        std::cout << "Default Constructor:" << std::endl;
        b1.display();

        std::cout << "Title Constructor:" << std::endl;
        b2.display();

        std::cout << "Parameterized Constructor:" << std::endl;
        b3.display();

        
        std::cout << "Testing Negative Copies:" << std::endl;

        Book b4("Python", "Guido", -2);
        b4.display();

    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

