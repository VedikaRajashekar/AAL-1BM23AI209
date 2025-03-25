#include <stdio.h>

int partition(int a[], int p, int q)
{
    int pivot = a[q];
    int j, i = p - 1;

    for (j = p; j < q; j++) {
        if (a[j] <= pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[q];
    a[q] = temp;

    return (i + 1);
}

void quicksort(int a[], int p, int q)
{
    if (p < q) {
        int pi = partition(a, p, q);
        quicksort(a, p, pi - 1);
        quicksort(a, pi + 1, q);
    }
}

int main()
{
    int n;
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    int i, a[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("\nArray after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    return 0;
}

