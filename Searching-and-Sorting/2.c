// Online Marketplace Product Listings: Design a system for sorting and displaying products on an online marketplace. Use sorting algorithms to arrange products based on factors like popularity, price, and ratings.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int productID;
    char name[100];
    float price;
    float ratings;
    int popularity;
} Product;

// Sorting functions
void bubbleSort(Product *products, int n, int (*compare)(const Product *, const Product *));
void quickSort(Product *products, int low, int high, int (*compare)(const Product *, const Product *));
int partition(Product *products, int low, int high, int (*compare)(const Product *, const Product *));
void mergeSort(Product *products, int left, int right, int (*compare)(const Product *, const Product *));
void merge(Product *products, int left, int mid, int right, int (*compare)(const Product *, const Product *));

// Comparison functions for different sorting criteria
int compareByPopularity(const Product *a, const Product *b);
int compareByPrice(const Product *a, const Product *b);
int compareByRatings(const Product *a, const Product *b);

// Display function
void displayProducts(Product *products, int numProducts);

// Comparison functions for different sorting criteria
int compareByPopularity(const Product *a, const Product *b)
{
    return b->popularity - a->popularity;
}

int compareByPrice(const Product *a, const Product *b)
{
    return (int)((a->price - b->price) * 100); // Multiplying by 100 to handle floating-point precision
}

int compareByRatings(const Product *a, const Product *b)
{
    return (int)((b->ratings - a->ratings) * 100);
}

// Display function
void displayProducts(Product *products, int numProducts)
{
    printf("\nProduct ID\tName\t\tPrice\t\tRatings\t\tPopularity\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < numProducts; ++i)
    {
        printf("%d\t\t%s\t\t%.2f\t\t%.2f\t\t%d\n", products[i].productID, products[i].name,
               products[i].price, products[i].ratings, products[i].popularity);
    }
}

int main()
{
    // Example usage of sorting algorithms with product data
    int numProducts = 10;
    Product products[10]; // Assuming an array of products

    // Populate product data (initialize with your own data)
    for (int i = 0; i < numProducts; ++i)
    {
        products[i].productID = i + 1;
        sprintf(products[i].name, "Product %d", i + 1);
        products[i].price = rand() % 100 + 1;              // Random price between 1 and 100
        products[i].ratings = (float)(rand() % 50) / 10.0; // Random ratings between 0.0 and 5.0
        products[i].popularity = rand() % 1000;            // Random popularity
    }

    // Sort products based on popularity
    bubbleSort(products, numProducts, compareByPopularity);
    printf("\nSorted by Popularity:\n");
    displayProducts(products, numProducts);

    // Sort products based on price
    quickSort(products, 0, numProducts - 1, compareByPrice);
    printf("\nSorted by Price:\n");
    displayProducts(products, numProducts);

    // Sort products based on ratings
    mergeSort(products, 0, numProducts - 1, compareByRatings);
    printf("\nSorted by Ratings:\n");
    displayProducts(products, numProducts);

    return 0;
}

void bubbleSort(Product *products, int n, int (*compare)(const Product *, const Product *))
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (compare(&products[j], &products[j + 1]) > 0)
            {
                // Swap products[j] and products[j + 1]
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void quickSort(Product *products, int low, int high, int (*compare)(const Product *, const Product *))
{
    if (low < high)
    {
        // Partition the array, products[pivot] is now at the correct place
        int pivot = partition(products, low, high, compare);

        // Recursively sort the subarrays
        quickSort(products, low, pivot - 1, compare);
        quickSort(products, pivot + 1, high, compare);
    }
}

int partition(Product *products, int low, int high, int (*compare)(const Product *, const Product *))
{
    Product pivot = products[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
    {
        if (compare(&products[j], &pivot) <= 0)
        {
            i++;
            // Swap products[i] and products[j]
            Product temp = products[i];
            products[i] = products[j];
            products[j] = temp;
        }
    }

    // Swap products[i + 1] and pivot
    Product temp = products[i + 1];
    products[i + 1] = products[high];
    products[high] = temp;

    return i + 1;
}

void mergeSort(Product *products, int left, int right, int (*compare)(const Product *, const Product *))
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(products, left, mid, compare);
        mergeSort(products, mid + 1, right, compare);

        // Merge the sorted halves
        merge(products, left, mid, right, compare);
    }
}

void merge(Product *products, int left, int mid, int right, int (*compare)(const Product *, const Product *))
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    Product *L = (Product *)malloc(n1 * sizeof(Product));
    Product *R = (Product *)malloc(n2 * sizeof(Product));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = products[left + i];
    for (j = 0; j < n2; j++)
        R[j] = products[mid + 1 + j];

    // Merge the temporary arrays back into products[left..right]
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (compare(&L[i], &R[j]) <= 0)
        {
            products[k] = L[i];
            i++;
        }
        else
        {
            products[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        products[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        products[k] = R[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(L);
    free(R);
}
