#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#define MAX_VEC 10

struct simple_list {
    int vector[MAX_VEC]; // initialize the vector with the size of global variable
    int control;
};

void create_list(struct simple_list *list){
    list->control = -1;
}

int is_empty(struct simple_list *list){
    return list->control == -1;
}

int is_full(struct simple_list *list){
    return list->control == MAX_VEC-1;
}

void clean_list(struct simple_list *list){
    create_list(list);
}

void insert_init(struct simple_list *list, int x){
    if(!is_full(list)){
        for(int i = list->control; i >= 0; --i){
            list->vector[i + 1] = list->vector[i];
        }
        list->vector[0] = x;
        ++list->control;
    }
}

void remove_final(struct simple_list *list){
    if(!is_empty(list)){
        --list->control;
    }
}

void remove_initial(struct simple_list *list){
    if(!is_empty(list)){
        --list->control;
        for(int i = 0; i <= list->control; ++i){
            list->vector[i] = list->vector[i + 1];
        }
    }
}

void print_list(struct simple_list *list){
    for(int i = 0; i <= list->control; ++i){
        printf("%d ", list->vector[i]);
    }
    printf("\n");
}

void insert_final(struct simple_list *list, int x){
    printf("Control: %d\n", list->control);

    if(!is_full(list)){
        printf("Inserting %d\n", x);
        list->vector[list->control + 1] = x;
        print_list(list);
        ++list->control;
    }
    else {
        printf("List is full\n");
    }
}

void remove_in(struct simple_list *list, int position){
    if(position == 0){
        remove_initial(list);
    }
    else if(position == list->control){
        remove_final(list);
    }
    else if(!is_empty(list) && position <= list->control){
        --list->control;
        for(int i = position; i <= list->control; ++i){
            list->vector[i] = list->vector[i + 1];
        }
    }
   
}

void insert_in(struct simple_list *list, int position, int x){
    if(position == 0){
        insert_init(list, x);
    }
    else if(position == list->control + 1){
        insert_final(list, x);
    }
    else if(!is_full(list) && position <= list->control + 1){
        for(int i= list->control; i>= position; --i){
            list->vector[i + 1] = list->vector[i];
        }
        list->vector[position] = x;
        ++list->control;
    }
}

// quick sort
void change(int vet[], int i, int j){
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

int partition(int vet[], int start, int end){
    int pivot = vet[end]; // pivot is the last element
    int pivot_index = start;

    for(int i = start; i < end; ++i){
        if(vet[i] <= pivot){
            change(vet, i, pivot_index); // change the positions
            pivot_index++; // increment pivot
        }
    }

    change(vet, pivot_index, end);

    return pivot_index;
}

int random_partition(int vec[], int start, int end){
    int pivot_index = (rand() % (end - start + 1)) + start;

    change(vec, pivot_index, end);
    return partition(vec, start, end);

}

void quick_sort(int vec[], int start, int end){
    if(start < end){
        int pivot_index = random_partition(vec, start, end);
        quick_sort(vec, start, pivot_index - 1);
        quick_sort(vec, pivot_index + 1, end);
    }
}

int binary_search(struct simple_list *list, int x){
    int start = 0;
    int end = list->control;
    int middle;

    while(start <= end){
        middle = (start + end) / 2;
        if(list->vector[middle] == x){
            return middle;
        }
        else if(list->vector[middle] < x){
            start = middle + 1;
        }
        else{
            end = middle - 1;
        }
    }
    return -1;
}

int main(void){
    struct simple_list list;
    create_list(&list);
    
    srand(time(NULL)); // random seed

    for(int i = 0; i < MAX_VEC-1; ++i){
        insert_final(&list, rand() % 100);
    }

    printf("List before sorting: ");
    print_list(&list);

    insert_final(&list, 54);

    quick_sort(list.vector, 0, list.control);

    printf("List after sorting: ");

    print_list(&list);

    printf("Binary search for 54: %d\n", binary_search(&list, 54));
    printf("Binary search for 10: %d\n", binary_search(&list, 10));
    
    return 0;
}