

#define MAX_ITEMS 100  // max allowed items

// Function to calculate total cost with discounts
float calculateTotalCost(int numItems, float itemCosts[], int itemQuantities[], char couponCode[], int isSenior) {
    float totalCost = 0.0;

    // Calculate total cost
    for (int i = 0; i < numItems; i++) {
        totalCost += itemQuantities[i] * itemCosts[i];
    }

    // Apply discount for select coupon codes
    if (strcmp(couponCode, "SAVE10") == 0) {
        totalCost *= 0.9; // 10% discount
    } else if (strcmp(couponCode, "FREESHIP") == 0) {
        // Free shipping code, do nothing for now
    } else if(strcmp(couponCode, "0") == 0){
        totalCost *= 1; // no discount
    }

    // Apply discount for senior citizens
    if (isSenior) {
        totalCost *= 0.8; // 20% discount for seniors
    }

    return totalCost;
}

int main() {
    int numItems;
    float itemCosts[MAX_ITEMS];
    int itemQuantities[MAX_ITEMS];
    char couponCode[20];
    int isSenior;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    if (numItems < 1 || numItems > MAX_ITEMS) {
        printf("Invalid number of items. Please enter between 1 and %d.\n", MAX_ITEMS);
        return 1;
    }

    for (int i = 0; i < numItems; i++) {
        printf("Enter cost of item %d: ", i + 1);
        scanf("%f", &itemCosts[i]);

        printf("Enter quantity of item %d: ", i + 1);
        scanf("%d", &itemQuantities[i]);
    }

    printf("Enter coupon code (or press 0 for no coupon): ");
    scanf("%s", couponCode);

    printf("Are you a senior citizen? (1 for yes, 0 for no): ");
    scanf("%d", &isSenior);

    float totalCost = calculateTotalCost(numItems, itemCosts, itemQuantities, couponCode, isSenior);

    printf("Total cost after discounts: $%.2f\n", totalCost);

    return 0;
}
