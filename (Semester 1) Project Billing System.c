#include <stdio.h>
#include <string.h>

#define CATEGORIES 10
#define PRODUCTS_PER_CATEGORY 5

// Structure to store product details
typedef struct {
    char name[30];
    float price;
} Product;

// Structure to store category details
typedef struct {
    char categoryName[30];
    Product products[PRODUCTS_PER_CATEGORY];
} Category;

// Function to display all products
void displayProducts(Category categories[]) {
    printf("\nAvailable Products:\n");
    for (int i = 0; i < CATEGORIES; i++) {
        printf("\n%d. %s\n", i + 1, categories[i].categoryName);
        for (int j = 0; j < PRODUCTS_PER_CATEGORY; j++) {
            printf("   %d%d. %s - $%.2f\n", i + 1, j + 1, categories[i].products[j].name, categories[i].products[j].price);
        }
    }
}

// Function to handle shopping
void shop(Category categories[]) {
    int choice, productChoice, quantity;
    float total = 0;
    char continueShopping;
    
    printf("\nWelcome to the Shopping System!\n");
    do {
        displayProducts(categories);
        printf("\nEnter category number: ");
        scanf("%d", &choice);
        
        if (choice < 1 || choice > CATEGORIES) {
            printf("Invalid category selection. Try again.\n");
            continue;
        }
        
        printf("Enter product number: ");
        scanf("%d", &productChoice);
        
        if (productChoice < 1 || productChoice > PRODUCTS_PER_CATEGORY) {
            printf("Invalid product selection. Try again.\n");
            continue;
        }
        
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        float cost = categories[choice - 1].products[productChoice - 1].price * quantity;
        total += cost;
        
        printf("Added %d x %s to cart. Subtotal: $%.2f\n", quantity, categories[choice - 1].products[productChoice - 1].name, cost);
        printf("Do you want to continue shopping? (y/n): ");
        scanf(" %c", &continueShopping);
        
    } while (continueShopping == 'y' || continueShopping == 'Y');
    
    printf("\nTotal Bill: $%.2f\n", total);
    printf("Thank you for shopping!\n");
}

int main() {
    Category categories[CATEGORIES] = {
        {"Electronics", { {"Laptop", 800}, {"Phone", 500}, {"Headphones", 50}, {"Monitor", 200}, {"Keyboard", 30} }},
        {"Groceries", { {"Rice", 2}, {"Flour", 1.5}, {"Milk", 1}, {"Eggs", 0.5}, {"Butter", 3} }},
        {"Clothing", { {"Shirt", 20}, {"Jeans", 40}, {"Jacket", 60}, {"Shoes", 80}, {"Hat", 15} }},
        {"Furniture", { {"Chair", 30}, {"Table", 50}, {"Sofa", 200}, {"Bed", 500}, {"Cabinet", 100} }},
        {"Toys", { {"Doll", 10}, {"Car", 15}, {"Puzzle", 5}, {"Teddy Bear", 25}, {"Lego", 40} }},
        {"Stationery", { {"Notebook", 2}, {"Pen", 1}, {"Eraser", 0.5}, {"Markers", 3}, {"Ruler", 1.5} }},
        {"Beauty Products", { {"Lipstick", 15}, {"Perfume", 40}, {"Shampoo", 10}, {"Cream", 20}, {"Lotion", 12} }},
        {"Sports", { {"Football", 25}, {"Basketball", 30}, {"Tennis Racket", 50}, {"Badminton", 40}, {"Shoes", 80} }},
        {"Books", { {"Novel", 10}, {"Comics", 5}, {"Magazine", 3}, {"Textbook", 30}, {"Dictionary", 20} }},
        {"Appliances", { {"Toaster", 25}, {"Blender", 40}, {"Microwave", 100}, {"Washing Machine", 300}, {"Fridge", 500} }}
    };
    
    shop(categories);
    return 0;
}
