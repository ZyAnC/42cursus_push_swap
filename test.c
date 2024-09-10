#include <stdio.h>

#define MAX_N 1000 // 假设最大排序数组大小为 1000

int stack_a[MAX_N];
int stack_b[MAX_N];
int top_a = -1;
int top_b = -1;

void ra() {
    // 栈 A 旋转操作，将栈顶元素移至栈底
    if (top_a > 0) {
        int temp = stack_a[0];
        for (int i = 0; i < top_a; i++) {
            stack_a[i] = stack_a[i + 1];
        }
        stack_a[top_a] = temp;
    }
}

void pb() {
    // 从栈 A 弹出并压入栈 B
    if (top_a >= 0) {
        stack_b[++top_b] = stack_a[0];
        for (int i = 0; i < top_a; i++) {
            stack_a[i] = stack_a[i + 1];
        }
        top_a--;
    }
}


void pa() {
    // 从栈 B 弹出并压入栈 A
    if (top_b >= 0) {
        // 先将栈 A 的所有元素向后移动一位，为插入的元素腾出位置
        for (int i = top_a + 1; i > 0; i--) {
            stack_a[i] = stack_a[i - 1];
        }
        // 将栈 B 的最后一个元素移到栈 A 的顶部
        stack_a[0] = stack_b[top_b--];
        // 更新栈 A 的栈顶指针
        top_a++;
    }
}


void radix_sort(int *a, int n) {
    int max_index;
    int bits;
    int i;
    int j;
    int x;
    int num;
    
    bits = 0;
    max_index = n - 1;
    while (max_index >> bits)
        bits++;
    x = 0;
    while (x < n)
        stack_a[++top_a] = a[x++];
    i = 0;

    
    
    while (i < bits) 
    {
        j = 0;
        while (j < n) 
        {
            num = stack_a[0];
            if (((num >> i) & 1) == 1)
                ra();
            else
                pb();
            j++;
        }
        printf("\n");
 
         
        while (top_b >= 0) {
            pa(); 
        }
       for (int i = 0; i < n; ++i) {
            printf("%d ",stack_a[i]);
             }
               printf("\n");
        i++;
    }
   
  
}

int main() {
    int arr[] = {4, 0, 6, 1, 5, 2, 3};
  

    radix_sort(arr, 7); // 调用基数排序

    return 0;
}
