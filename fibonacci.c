#include<stddef.h>

#include "fibonacci.h"

size_t fibonacci(size_t n) {

    size_t array[] = {0, 1}; // {f[0], f[1]}

    for (size_t i = 0; i < n / 2; i++) { //we already have one batch cooked initially, so we go i < n / 2 (instead of i <= n / 2).

        array[0] += array[1]; //array[0] = f[k], and array[0] turns to f[k] + f[k + 1] i.e f[k + 2]
        array[1] += array[0]; //array[1] = f[k + 1] and array[1] turns to f[k + 1] + f[k + 2] i.e. f[k + 3] //note that array[0] turned tp f[k + 2] just a while before.

        //this is clearly batch updation + sliding window technique.
    }

    //after m iterations, array = {f[2 * m], f[2 * m + 1]}

    //if n is even, we perform n / 2 iterations. //array = {f[n] + f[n + 1]}
    //if k is odd, we perform (n - 1) / 2 iterations. //array = {f[n - 1], f[n]}

    return array[n % 2]; //if n is even, f[n] is at 0 index and if n is odd, f[n] is at 1 index. //simply (n % 2) index.
}
