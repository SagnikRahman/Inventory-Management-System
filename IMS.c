#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
    int sold;
} InventoryItem;

InventoryItem inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    InventoryItem item;
    printf("Enter product ID: ");
    scanf("%d", &item.id);

    printf("Enter product name: ");
    scanf(" %[^\n]s", item.name);

    printf("Enter product quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter product price: ");
    scanf("%f", &item.price);

    item.sold = 0;

    inventory[itemCount] = item;
    itemCount++;

    printf("Product added successfully!\n");
}

void updateStock() {
    int id, quantity;
    printf("Enter product ID: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &quantity);

            inventory[i].quantity = quantity;
            found = 1;
            printf("Stock updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void recordSale() {
    int id, quantity;
    printf("Enter product ID: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter quantity sold: ");
            scanf("%d", &quantity);

            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                inventory[i].sold += quantity;
                found = 1;
                printf("Sale recorded successfully!\n");
            } else {
                printf("Insufficient stock!\n");
            }

            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
}

void generateReport() {
    printf("Inventory Report:\n");
    printf("ID\tName\tQuantity\tPrice\tSold\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\t%d\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].quantity,
               inventory[i].price,
               inventory[i].sold);
    }
}

int main() {
    int choice;
    do {
        printf("\n=== Inventory Management System ===\n");
        printf("1. Add Product\n");
        printf("2. Update Stock\n");
        printf("3. Record Sale\n");
        printf("4. Generate Report\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateStock();
                break;
            case 3:
                recordSale();
                break;
            case 4:
                generateReport();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
           }
     } while(choice!=0);
}
