/*
 * device_sn.c
 *
 *  Created on: Jan 30, 2021
 *      Author: sam
 */

#include "device_sn.h"

/* use the 96bit unique device ID to calculate a device SN for use with SSID unique name */
uint32_t calc_sn(void) {
	uint32_t uid[] = {HAL_GetUIDw0(), HAL_GetUIDw1(), HAL_GetUIDw2()};

	selectionSort(uid, 3);
	uint32_t sn = uid[2] - uid[1] - uid[0];

	return sn;
}

/* below functions modified from https://www.geeksforgeeks.org/c-program-to-sort-an-array-in-ascending-order/ */
void swap(uint32_t* xp, uint32_t* yp) {
	uint32_t temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform Selection Sort
void selectionSort(uint32_t arr[], uint32_t n) {
	uint32_t i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
