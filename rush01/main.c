#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void throw_error(void);
int ft_strlen(char *str);
void ft_putchar(char n);
void print_result(int *nums, int size);
void resolver(int *result, int *nums, int col, int row, int size);
int check(int *result, int *nums, int size);
int *check_view(int *nums, int size);

int main(int argc, char *argv[])
{
    int i;
    int argv_len;
    int size;
    int count;
    int *nums;
    int *result;

    if (argc != 2)
        throw_error();
    else
    {
        i = 0;
        argv_len = ft_strlen(argv[1]);
        if ((argv_len + 1) % 8 != 0)
        {
            throw_error();
            return (0);
        }
        size = (argv_len + 1) / 8;
        nums = (int *)malloc(size * 4 * 4);
        result = (int *)malloc(size * size * 4);
        count = 0;
        while (i < argv_len)
        {
            if (argv[1][i] > '0' && argv[1][i] <= size + '0' && (argv[1][i + 1] == ' ' || i == argv_len - 1))
            {
                nums[count++] = argv[1][i] - '0';
                i += 2;
            }
            else
            {
                throw_error();
                return (0);
            }
        }

        i = 0;
        while (i < size * size)
            result[i++] = 0;
    }

    resolver(result, nums, 0, 0, size);

    return (0);
}

void throw_error(void)
{
    write(1, "Error\n", 6);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

void print_result(int *nums, int size)
{
    int row = 0;
    int col;

    while (row < size)
    {
        col = 0;
        while (col < size - 1)
        {
            ft_putchar(nums[row * size + col] + '0');
            ft_putchar(' ');
            col++;
        }
        ft_putchar(nums[row * size + col] + '0');
        ft_putchar('\n');
        row++;
    }
    ft_putchar('\n');
}

void resolver(int *result, int *nums, int col, int row, int size)
{
    int next_col;
    int next_row;
    int i;

    next_col = col;
    next_row = row;

    if (result[row * size + col] == 0)
        result[row * size + col] = 1;
    if (check(result, nums, size) == 1)
    {
        if (col == size - 1 && row == size - 1)
            {
                print_result(result, size);
                return;
            }
        if (col == size - 1)
        {
            next_row++;
            next_col = 0;
        }
        else
            next_col++;
    }
    else
    {
        if (result[row * size + col] == size)
        {
            result[(row * size + col)] = 0;
            i = 1;
            if (row == 0 && col == 1)
            {
                throw_error();
                return ;
            }
            while (result[(row * size + col) - i] == size)
            {
                result[(row * size + col) - i] = 0;
                if (next_col == 0)
                {
                    next_row--;
                    next_col = size - 1;
                }
                else
                    next_col--;
                i++;
            }
            result[(row * size + col) - i] += 1;

            if (next_col == 0)
                {
                    next_row--;
                    next_col = size - 1;
                }
            else
                next_col--;
        }
        else
            result[row * size + col] += 1;
    }
    resolver(result, nums, next_col, next_row, size);
}

int check(int *result, int *views, int size)
{
    int row;
    int col;
    int *count_n_row;
    int *count_n_col;
    int *count_v_col;
    int num;
    int *a;

    count_n_row = (int *)malloc(size * size * 4);
    count_n_col = (int *)malloc(size * size * 4);
    count_v_col = (int *)malloc(size * size * 4);
    col = 0;
    while (col < size * size)
    {
        count_n_row[col] = 0;
        count_n_col[col] = 0;
        col++;
    }

    row = 0;
    while (row < size)
    {
        col = 0;
        while (col < size)
        {
            if (result[row * size + col] > 0)
            {
                num = result[row * size + col] - 1;
                count_n_row[row * size + num] += 1;
                count_n_col[col * size + num] += 1;
            }
            count_v_col[col * size + row] = result[row * size + col];
            col++;
        }
        a = check_view(&result[row * size], size);
        if ((a[0] != -1 && a[0] != views[2 * size + row])
            || (a[1] != -1 && a[1] !=  views[3 * size + row]))
            {
                free(count_n_col);
                free(count_n_row);
                free(count_v_col);
                return (0);
            }
        row++;
    }

    col = 0;
    while (col < size)
    {
        a = check_view(&count_v_col[col * size], size);
        if ((a[0] != -1 && a[0] != views[0 * size + col])
            || (a[1] != -1 && a[1] != views[1 * size + col]))
            {
                free(count_n_col);
                free(count_n_row);
                free(count_v_col);
                return (0);
            }
        col++;
    }

    col = 0;
    while (col < size * size)
    {
        if (count_n_col[col] > 1 || count_n_row[col] > 1)
            {
                free(count_n_col);
                free(count_n_row);
                free(count_v_col);
                return (0);
            }
        col++;
    }
    free(count_n_col);
    free(count_n_row);
    free(count_v_col);
    return (1);
}

int *check_view(int *nums, int size)
{
    static int result[2];
    int max;
    int i;
    int count;

    i = 0;
    count = 1;
    max = nums[0];
    while (i < size)
    {
        if (nums[i] == 0)
        {
            count = -1;
            break;
        }
        else if (nums[i] > max)
        {
            max = nums[i];
            count++;
        }
        i++;
    }
    result[0] = count;
    count = 1;
    max = nums[size - 1];
    i = size - 1;
    while (i >= 0)
    {
        if (nums[i] == 0)
        {
            count = -1;
            break;
        }
        else if (nums[i] > max)
        {
            max = nums[i];
            count++;
        }
        i--;
    }
    result[1] = count;
    return result;
}