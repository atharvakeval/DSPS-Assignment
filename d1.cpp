#include <iostream>
using namespace std;

// Function to find count, first index, and last index of a target element
void findElementDetails(const int arr[], int size, int target, int& count, int& firstIndex, int& lastIndex) 
{
    count = 0;
    firstIndex = -1;
    lastIndex = -1;

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target) 
        {
            if (firstIndex == -1) 
            {
                firstIndex = i; 
            }
            lastIndex = i; 
            count++;
        }
    }
}

int main() 
{
    int n, x, a[100], count, firstIndex, lastIndex;

    cout << "Enter the size of Array: ";
    cin >> n;
    
    // Input array elements
    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    
    // Display array elements
    cout << "The Array elements are:";
    for(int i = 0; i < n; i++) 
    {
        cout << " " << a[i];
    }
    cout << endl;
    
    // Input target element 
    cout << "Enter the target element do you want to find: ";
    cin >> x;
    
    // Call the function to find element details
    findElementDetails(a, n, x, count, firstIndex, lastIndex);
    
    if(count > 0) 
    {
        cout << "The element " << x << " is present at index positions: ";
        for (int i = 0; i < n; i++) 
        {
            if (a[i] == x) 
            {
                cout << i << " ";
            }
        }
        cout << endl;
        
        cout << "The element " << x << " is repeated " << count << " times in the array\n";
        cout << "First index position of target is " << firstIndex << "\n";
        cout << "Last index position of target is " << lastIndex << "\n";
    } 
    else 
    {
        cout << "Element " << x << " is not present in the array.\n";
    }
    
    return 0;
}
