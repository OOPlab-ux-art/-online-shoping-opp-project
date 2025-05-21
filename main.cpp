#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    int productId;
    string productName;
    string description;
    float price;

public:
    void setPrice(float p) { price = p; }
    void setPrice(int p) { price = static_cast<float>(p); }

    void setProductId(int i) { productId = i; }
    void setProductName(string n) { productName = n; }
    void setDescription(string d) { description = d; }

    int getProductId() { return productId; }
    string getProductName() { return productName; }
    string getDescription() { return description; }
    float getPrice() { return price; }

    virtual void display() {
        cout << "Product ID: " << productId << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Description: " << description << endl;
        cout << "Price: " << price << " JD" << endl;
    }
};

class Customer : public Product {
protected:
    int customerId;
    string customerName;
    string email;
    string address;

public:
    void setCustomerId(int i) { customerId = i; }
    void setCustomerName(string n) { customerName = n; }
    void setEmail(string e) { email = e; }
    void setAddress(string a) { address = a; }

    int getCustomerId() { return customerId; }
    string getCustomerName() { return customerName; }
    string getEmail() { return email; }
    string getAddress() { return address; }

    void display() override {
        Product::display();
        cout << "Customer ID: " << customerId << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
    }
};

class Order : public Customer {
private:
    int orderId;
    string orderDate;

public:
    void setOrderId(int id) { orderId = id; }
    void setOrderDate(string date) { orderDate = date; }

    int getOrderId() { return orderId; }
    string getOrderDate() { return orderDate; }

    void display() override {
        Customer::display();
        cout << "Order ID: " << orderId << endl;
        cout << "Order Date: " << orderDate << endl;
    }
};

int main() {
    Order o1;

    o1.setProductId(101);
    o1.setProductName("Taimaa");
    o1.setDescription("Beautiful");
    o1.setPrice(200);

    o1.setCustomerId(5);
    o1.setCustomerName("Fadwa");
    o1.setEmail("fadwakharazeh@gmail.com");
    o1.setAddress("MA'AN");

    o1.setOrderId(1001);
    o1.setOrderDate("2025-05-18");

    Product* ptr = &o1;
    ptr->display();

    return 0;
}
