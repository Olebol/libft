// #include <stdio.h>
// #include <stdlib.h>
 
// //	Returns an array of two ints, containing the minimum and maximum int from 
// //	given parameter int_arr, with the values being placed at index 1 and 2 resp-
// //	ectively.

// int	*ft_minmax(int *int_arr, size_t size)
// {
// 	int *minmax		= malloc(size * sizeof(int));
// 	minmax[0]		= int_arr[0];
// 	minmax[1]		= int_arr[0];

// 	for (int i = 0; i < size; i++) 
// 	{
// 		if (minmax[0] > int_arr[i])
// 			minmax[0] = int_arr[i];
// 	}
	
// 	for (int i = 0; i < size; i++) 
// 	{
// 		if (minmax[1] < int_arr[i])
// 			minmax[1] = int_arr[i];
// 	}

// 	return (minmax);
// }

// int	main(void)
// {
// 	int arr[5] = {1, 4, 56, 1000003, -5626375};
// 	int *minmax = ft_minmax(arr, 5);
// 	printf("%d \n %d", minmax[0], minmax[1]);
// }