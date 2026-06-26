## 👤 Author

- **Saad Ayub** 
  - Computer Science & Engineering Student at UET Lahore
  - GitHub: [@saadayub696](https://github.com/saadayub696)

  
# Grocery Management System

A console-based C++ application designed to simulate an interactive grocery shopping experience. The program allows users to set a budget, browse distinct product categories, manage a virtual shopping cart, and automatically generate a localized text file summary of their purchases upon checkout.

---

## 🚀 Features

- **Categorized Inventory:** Choose from a pre-defined catalog of 90+ items split evenly across three distinct sections:
  - Vegetables 🥕
  - Fruits 🍎
  - Bakery 🍞
- **Dynamic Cart Management:** Add items to your cart, specify custom quantities, review ongoing subtotals, or remove items to restock the shop inventory dynamically.
- **Budget Tracking:** Set a personal spending budget at the start. The system gives real-time warning alerts if your cart's total exceeds your defined limit.
- **Automated Discounts:** Offers a **15% discount** automatically on any final invoice totaling $30 or more.
- **Persistent Invoice Records:** Appends a clean, formatted receipt directly into a local file named `purchase_summary.txt` for every session.

---

## 🛠️ Object-Oriented Design (OOP) Breakdown

The system relies on clean OOP principles leveraging class hierarchy and encapsulation:
- **`Product` (Base Class):** Encapsulates core item characteristics like `name` and `price`.
- **`Item` (Derived Class):** Inherits from `Product` to extend functionality by including inventory tracking (`quantity`).
- **`Cart`:** Manages an internal vector stream tracking selected items, handling conditional quantity adjustments, and rendering console-based tabular interfaces.
- **`Shop`:** Houses the master multi-category inventory arrays and serves as the primary system controller processing customer interactive menus.

---

## 💻 Getting Started

### Prerequisites
Make sure you have a C++ compiler installed (e.g., `g++` via MinGW for Windows).

### Running the Project Locally
1. Clone the repository:
   ```bash
   git clone [https://github.com/saadayub696/Grocery-Management-System.git](https://github.com/saadayub696/Grocery-Management-System.git)
   cd Grocery-Management-System