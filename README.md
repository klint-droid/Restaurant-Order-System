Perfect 🔥 You’ve built a **complete Restaurant Ordering System using Linked Lists in C**, with features like enqueue (add order), dequeue (serve order), viewing orders, and calculating total sales.

Here’s your **ready-to-copy, professional `README.md`** file — clean, well-formatted, and GitHub-ready 👇

---

````markdown
# 🍽️ Klint's Restaurant Ordering System (C Linked List Project)

This project is a **Restaurant Ordering System** built in **C language**, using a **Linked List** to manage customer orders dynamically.  
It simulates a restaurant queue where customers place orders (enqueue) and are served in order (dequeue), following a **First-In, First-Out (FIFO)** system.

---

## 🧠 Features

✅ Display list of menu items and prices  
✅ Add an order (enqueue)  
✅ Serve an order (dequeue)  
✅ View all current orders  
✅ Calculate total sales  
✅ Generate total sales per item report  

---

## 🧩 Data Structure Overview

### 📦 `struct Order`

```c
typedef struct Order{
    char customerName[50];
    char item[50];
    int quantity;
    float price;
    struct Order *next;
} Order;
````

Each node in the linked list represents an **order**, containing:

* `customerName` → Name of the customer
* `item` → The food item ordered
* `quantity` → Number of items ordered
* `price` → Price per item
* `next` → Pointer to the next order in the queue

---

## 🧱 Global Pointers

```c
Order *front = NULL;
Order *rear = NULL;
```

* `front`: Points to the **first order** (next to be served).
* `rear`: Points to the **last order** (most recently added).

This forms a **queue structure** using a **singly linked list**.

---

## ⚙️ Core Functions

| Function                                                                   | Purpose                                            |
| -------------------------------------------------------------------------- | -------------------------------------------------- |
| `int isEmpty()`                                                            | Checks if the order queue is empty                 |
| `void displayItems(char **items, float *price, int itemCount)`             | Displays the restaurant menu                       |
| `void addOrder(char *customerName, char *item, int quantity, float price)` | Adds a new order to the queue                      |
| `void serveOrder()`                                                        | Serves and removes the first order (dequeue)       |
| `void viewOrders()`                                                        | Displays all active/pending orders                 |
| `float totalSales()`                                                       | Computes total sales from all orders               |
| `void totalSalesPerItem()`                                                 | Displays per-item total sales and quantity summary |

---

## 🍔 Example Menu Setup

```c
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

float price[10] = {99.50, 75.25, 89.99, 94.25, 106.99, 110, 125, 167, 199.99, 200};
```

---

## 🧮 Sample Program Flow

```
Klint's Restaurant

List of Items
1. Lechon Manok - 99.50
2. Lechon Baka - 75.25
3. Lechon Baki - 89.99
...
10. Seafoods - 200.00

1. Add Order
2. Serve Order
3. View Orders
4. View Total Sales Per Item
5. Exit
Choice: 1
Enter customer name: Juan Dela Cruz
Enter order to add & quantity: 1 2
Item Lechon Manok ordered by Juan Dela Cruz successfully!

Choice: 3
Current Orders.
[1] Lechon Manok - (2) - 99.50 each for Juan Dela Cruz

Choice: 2
Serving 2 of Lechon Manok to Juan Dela Cruz

Choice: 4
=== Total Sales Report ===
Lechon Manok - 2 pcs - ₱199.00
-----------------------------
Total Sales: PHP 199.00
```

---

## 🧮 Total Sales Report Logic

`totalSalesPerItem()` groups orders by item name and adds up:

* Total quantity sold per item
* Total amount earned from each item

Also calls:

```c
sales = totalSales();
printf("Total Sales: PHP %.2f", sales);
```

to display **grand total sales**.

---

## 🧠 Learning Objectives

This project helps practice:

* ✅ Implementing a **linked list as a queue**
* ✅ Using **structures (`struct`) and pointers**
* ✅ Managing **dynamic memory** with `malloc()` and `free()`
* ✅ Working with **arrays of strings (`char *item[]`)**
* ✅ Writing **modular functions** in C

---

## 🖥️ How to Compile and Run

### Compile

```bash
gcc restaurant.c -o restaurant
```

### Run

```bash
./restaurant
```

---

## 🧑‍💻 Author

**👨‍💻 Klint**
📘 C Language Student Developer
💡 Passionate about learning data structures through real-world simulations

---

## 📜 License

This project is open source under the [MIT License](LICENSE).

