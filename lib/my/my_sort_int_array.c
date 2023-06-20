/*
** EPITECH PROJECT, 2022
** sort_int_array
** File description:
** sort array
*/

void my_compare(int *array,int i)
{
    if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int i = 0; i < size - 1; i++) {
            my_compare(array,i);
        }
    }
}
