#include <stdio.h>
#include <string.h>

struct Item {
    int id;
    char name[30];
    int price;
    int quantity;
} cart[100];

int cartSize = 0;


char *itemNames[] = {"Apple", "Banana", "Mango", "Orange"};
int priceList[] = {10, 20, 15, 30};


void addItem();
void removeItem();
void viewCart();
void clearCart();
void displayMenu();

int main() {
    int choice;

    printf("Shopping Cart Management System\n");

    while (1) {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                viewCart();
                break;
            case 4:
                clearCart();
                break;
            case 5:
                printf("Exiting program. Thank you for shopping!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nShopping Cart Management System\n");
    printf("1. Add Item to Cart\n");
    printf("2. Remove Item from Cart\n");
    printf("3. View Cart\n");
    printf("4. Clear Cart\n");
    printf("5. Exit\n");
}

void addItem() {
    int id, quantity;
    printf("Available Items:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s (Price: %d)\n", i + 1, itemNames[i], priceList[i]);
    }

    printf("Enter the item ID to add (1-4): ");
    scanf("%d", &id);
    if (id < 1 || id > 4) {
        printf("Invalid item ID.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);
    if (quantity <= 0) {
        printf("Invalid quantity.\n");
        return;
    }


    cart[cartSize].id = id;
    strcpy(cart[cartSize].name, itemNames[id - 1]);
    cart[cartSize].price = priceList[id - 1];
    cart[cartSize].quantity = quantity;
    cartSize++;

    printf("Item added to cart successfully!\n\n");
}

void removeItem() {
    if (cartSize == 0) {
        printf("Cart is empty. Nothing to remove.\n\n");
        return;
    }

    int id;
    printf("Enter the item ID to remove: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < cartSize; i++) {
        if (cart[i].id == id) {
            found = 1;
            for (int j = i; j < cartSize - 1; j++) {
                cart[j] = cart[j + 1];
            }
            cartSize--;
            printf("Item removed from cart successfully!\n\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found in the cart.\n\n");
    }
}

void viewCart() {
    if (cartSize == 0) {
        printf("Cart is empty.\n\n");
        return;
    }

    printf("Items in your cart:\n");
    printf("ID\tName\t\tPrice\tQuantity\tTotal\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < cartSize; i++) {
        printf("%d\t%s\t\t%d\t%d\t\t%d\n", cart[i].id, cart[i].name, cart[i].price, cart[i].quantity, cart[i].price * cart[i].quantity);
    }
    printf("\n");
}

void clearCart() {
    cartSize = 0;
    printf("Cart cleared successfully!\n\n");
}

