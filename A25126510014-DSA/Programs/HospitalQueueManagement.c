
#include <stdio.h>

int main()
{
    int a[100], n, i, j, min, temp, key;
    int low, high, mid, found = 0;

    printf("Enter number of patients: ");
    scanf("%d", &n);

    printf("Enter patient registration IDs:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Selection Sort
    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("Sorted patient IDs:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Binary Search
    printf("\nEnter patient ID to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
        {
            printf("Patient found at position %d",
                   mid + 1);
            found = 1;
            break;
        }
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found == 0)
        printf("Patient not found");

    return 0;
}
