#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order{
    char customerName[50];
    char item[50];
    int quantity;
    float price;
    struct Order *next;
}Order;


Order *front = NULL;
Order *rear = NULL;

int isEmpty(){
    return front == NULL;
}

void displayItems(char **items, float *price, int itemCount){
    printf("\nList of Items\n");
    for(int i = 0; i < itemCount; i++){
        printf("%d. %s - %.2f\n", i+1, *(items + i), *price + i);
    }
    printf("\n");
}

void addOrder(char *customerName, char *item, int quantity, float price){
    Order *new_order = (Order *)malloc(sizeof(Order));
    strcpy(new_order->customerName, customerName);
    strcpy(new_order->item, item);
    new_order->quantity = quantity;
    new_order->price = price;
    new_order->next = NULL;

    if(rear == NULL){
        rear = front = new_order;
        return;
    }

    rear->next = new_order;
    rear = new_order;

    printf("Item %s ordered by %s succesfully!", item, customerName);
}

void serveOrder(){
    if(isEmpty()){
        printf("No orders available!");
        return;
    }

    Order *temp = front;
    printf("Serving %d of %s to %s", temp->quantity, temp->item, temp->customerName);
    front = front->next;
    
    if(front == NULL){
        rear = NULL;
    }

    free(temp);

}

void viewOrders(){
    if(isEmpty()){
        printf("No current orders available.");
        return;
    }

    Order *current = front;
    printf("Current Orders.\n");
    int count = 1;
    while(current != NULL){
        printf("[%d] %s - (%d) - %.2f each for %s\n", count, current->item, current->quantity, current->price, current->customerName);
        current = current->next;
        count++;
    }

    printf("\n");
}

float totalSales(){
    float totalSales = 0.0;
    Order *current = front;

    while(current != NULL){
        totalSales += current->quantity * current->price;
        current = current->next;
    }
    return totalSales;
}

void totalSalesPerItem(){
    char items[100][50];
    float totals[100];
    int quantity[100];
    int count = 0;

    Order *current = front;

    float grandTotal = 0;

    while(current != NULL){
        int found = 0;

        for(int i = 0; i < count ; i++){
            if(strcmp(items[i], current->item) == 0){
                totals[i] += current->price;
                quantity[i]++;
                found = 1;
                break;
            }
        }
        if(!found){
            strcpy(items[count], current->item);
            totals[count] = current->price;
            quantity[count] =1;
            count++;
            break;
        }
        grandTotal += current->price;
        current = current->next;
    }
    printf("\n=== Total Sales Report ===\n");
    for(int i = 0; i < count; i++){
        printf("%-10s - %d pcs - ₱%.2f\n", items[i], quantity[i], totals[i]);
    }
    printf("-----------------------------\n");
}

int main(){

    int choice, itemNumber;
    char customerName[50];
    int quantity;
    float sales;
    float price[10] = {99.50, 75.25, 89.99, 94.25, 106.99, 110, 125, 167, 199.99, 200};
    char *item[10] = {
        "Lechon Manok",
        "Lechon Baka",
        "Lechon Baki",
        "Lechon Kalabaw",
        "Lechon Isda",
        "Balbacua",
        "Lechon Baboy",
        "Lechon Kanding",
        "Lechon Kawali",
        "Seafoods"
    };
    int itemCount = 10;
    do{
        printf("Klint's Restaurant\n");
        displayItems(item, price, itemCount);
        printf("1. Add Order.\n");
        printf("2. Serve Order.\n");
        printf("3. View Orders.\n");
        printf("4. View Total Sales Per Item. \n");
        printf("5. Exit.\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
            getchar();
            printf("Enter customer name: ");
            fgets(customerName, sizeof(customerName), stdin);
            customerName[strcspn(customerName, "\n")] = 0;
            printf("Enter order to add & quantity: ");
            scanf("%d %d", &itemNumber, &quantity);

            if(itemNumber < 0 || itemNumber > 10){
                printf("Invalid Order!");
            }
            else{
                addOrder(customerName, item[itemNumber - 1], quantity, price[itemNumber - 1]);
            }
            break;
            case 2:
            serveOrder();
            break;
            case 3:
            viewOrders();
            break;
            case 4:
            totalSalesPerItem();
            sales = totalSales();
            printf("Total Sales: PHP %.2f", sales);
            break;
        }

    } while(choice != 5);
    

    return 0;
}