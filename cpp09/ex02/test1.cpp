#include <iostream>
#include <vector>

// Fonction pour fusionner deux sous-tableaux triés
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fonction de tri fusion-insertion
void mergeInsertionSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        if (right - left + 1 <= 5) {
            // Si le sous-tableau est assez petit, effectuer un tri par insertion
            for (int i = left + 1; i <= right; i++) {
                int key = arr[i];
                int j = i - 1;
                while (j >= left && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
        } else {
            int mid = left + (right - left) / 2;
            mergeInsertionSort(arr, left, mid);
            mergeInsertionSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "Veuillez fournir une liste d'entiers positifs en tant qu'arguments de la ligne de commande." << std::endl;
        return 0;
    }

    std::vector<int> input;
    for (int i = 1; i < argc; i++) {
        int num = std::atoi(argv[i]);
        if (num >= 0) {
            input.push_back(num);
        }
    }

    mergeInsertionSort(input, 0, input.size() - 1);

    std::cout << "Liste triée : ";
    for (int num : input) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

