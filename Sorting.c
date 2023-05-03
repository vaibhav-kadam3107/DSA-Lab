#include<stdio.h>

struct student{
    char name[100];
    int roll_no;
    int marks;
};

// Swaps two student structs
void swap(struct student *s1 , struct student *s2){
    struct student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

//-------------------------------------------------------------Bubble Sort----------------------------//

// Sorts an array of student structs using bubble sort
void bubble(struct student s[], int *count, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll_no > s[j + 1].roll_no) {
                swap(&s[j], &s[j + 1]);
                (*count)++;
            }
        }
    }
}

//-------------------------------------------------------------Quick Sort----------------------------//

int partition(struct student s[] , int *count , int n , int start , int end){
    int pivot = s[start].roll_no;
    int c=0;
    //calculate the correct position of pivot
    for(int i = start+1; i<= end; i++){
        if(s[i].roll_no <= pivot){
            c++;
        }
    }
    int pivot_index = start + c;
    swap(&s[pivot_index] , &s[start]);
    (*count)++;

    int k = start;
    int l = end;
    while(k < pivot_index && l > pivot_index){
        if(s[k].roll_no <= pivot)
            k++;

        if(s[l].roll_no > pivot)
            l--;

        if(k < pivot_index && l > pivot_index){
            swap(&s[k++] , &s[l--]);
            (*count)++;
        }
    }
    return pivot_index;
}

void quick(struct student s[] , int *count , int n , int start , int end){
    //base condition
    if(start >= end)
        return;

    int pivot_index = partition(s , count , n , start , end);

    quick(s , count , n , start , pivot_index - 1);
    quick(s , count , n , pivot_index + 1 , end);
}

//-------------------------------------------------------------Merge Sort----------------------------//

void merge(struct student s[] , int *count , int start , int end){

    int mid = start+(end-start)/2;
    int length1 = mid - start +1;
    int length2 = end-mid;

    struct student first[length1];
    struct student second[length2];

    int mai = start;
    //copy the first part in first arr
    for(int i = 0; i < length1; i++){
        first[i] = s[mai++];
    }

    mai = mid+1;
    for(int i = 0; i < length2; i++){
        second[i] = s[mai++];
    }

    int i=0 , j=0;
    while(i < length1 && j <length2){
        if(first[i].roll_no < second[j].roll_no)
            s[start++] = first[i++];
        else{
            s[start++] = second[j++];
        }
    }
    while(i < length1){
        s[start++] = first[i++];
    }
    while(j < length2){
        s[start++] = second[j++];
    }

}

void merge_sort(struct student s[] , int *count , int n , int start , int end){
    //base condition
    if(start >= end)
        return;

    int mid = start + (end - start)/2;

    merge_sort(s , count , n , start , mid);
    merge_sort(s , count , n , mid+1 , end);

    merge(s , count , start , end);
}

//-------------------------------------------------------------Insertion Sort----------------------------//

void insertion(struct student s[] , int *count , int n){
    for(int i=1; i < n; i++){
        int j = i;
        while(j > 0 && s[j-1].roll_no > s[j].roll_no){
            swap(&s[j] , &s[j-1]);
            (*count)++;
            j--;
        }
    }
}

//-------------------------------------------------------------Selection Sort----------------------------//

void selection(struct student s[] , int *count , int n){

    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+ 1; j < n; j++){
            if(s[j].roll_no < s[min].roll_no)
                min = j;
        }
        swap(&s[min] , &s[i]);
        (*count)++;
    }
}

int main(){
    struct student s[100]; // define an array of struct student with a maximum size of 100
    int count = 0 , n;
    printf("Enter number of students: ");
    scanf("%d" , &n);
    for(int i = 0 ; i <n ; i++){

        printf("\nEnter the student name of S%d: ", i+1);
        scanf("%s" , s[i].name);

        printf("Enter student roll no of S%d: ",i+1);
        scanf("%d" , &s[i].roll_no);

        printf("Enter student marks of S%d: ",i+1);
        scanf("%d" , &s[i].marks);
    }


    int start = 0;
    int end = n;

    // Bubble Sort
    /*
    printf("\n------Before sorting---------\n");
    printf("roll_no\tStudent_Name \t\tMarks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t%s\t%d\n" , s[i].roll_no , s[i].name , s[i].marks); // print each student struct's data in a separate line
    }
    bubble(s , &count , n);
    printf("\n------After sorting---------\n");
    printf("roll_no\tStudent_Name \t\tMarks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t%s\t%d\n" , s[i].roll_no , s[i].name , s[i].marks);
    }
    printf("\nSwap count = %d" , count);
    */

    //Quick Sort
    /*

    printf("\n------Before sorting---------\n");
    printf("roll_no\tStudent_Name \t\tMarks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t%s\t%d\n" , s[i].roll_no , s[i].name , s[i].marks); // print each student struct's data in a separate line
    }

    quick(s , &count , n , start , end);

    printf("\n------After sorting---------\n");
    printf("roll_no\tStudent_Name \t\tMarks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t%s\t%d\n" , s[i].roll_no , s[i].name , s[i].marks);
    }
    printf("\nSwap count = %d" , count);
    */

    //Merge sort
    /*
    printf("\n------Before sorting---------\n");
    printf("roll_no\tStudent_Name \t\tMarks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t%s\t%d\n" , s[i].roll_no , s[i].name , s[i].marks); // print each student struct's data in a separate line
    }
    merge_sort(s , &count , n , start , end);

    printf("\n------After sorting---------\n");
    printf("roll_no\tStudent_Name \t\tMarks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t%s\t%d\n" , s[i].roll_no , s[i].name , s[i].marks);
    }
    printf("\nSwap count = %d" , count);
    */

    //Insertion sort
    /*
    printf("\n------Before sorting---------\n");
    printf("roll_no\tStudent_Name \t\tMarks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t%s\t%d\n" , s[i].roll_no , s[i].name , s[i].marks); // print each student struct's data in a separate line
    }

    insertion(s , &count , n );

    printf("\n------After sorting---------\n");
    printf("roll_no\tStudent_Name \t\tMarks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t%s\t%d\n" , s[i].roll_no , s[i].name , s[i].marks);
    }
    printf("\nSwap count = %d" , count);
    */

    //selection sort
    printf("\n------Before sorting---------\n");
    printf("roll_no\tStudent_Name \t\tMarks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t%s\t%d\n" , s[i].roll_no , s[i].name , s[i].marks); // print each student struct's data in a separate line
    }

    selection(s , &count , n );

    printf("\n------After sorting---------\n");
    printf("roll_no\tStudent_Name \t\tMarks\n");
    for(int i=0 ; i<n; i++){
        printf("%d\t%s\t%d\n" , s[i].roll_no , s[i].name , s[i].marks);
    }
    printf("\nSwap count = %d" , count);

    return 0;
}























