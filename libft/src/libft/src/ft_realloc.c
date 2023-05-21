#include "../../../include/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	len;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(size));
	
	new_ptr = malloc(size);
	len = ft_strlen(ptr) + 1;
	if (len > size)
		len = size;
	ft_memcpy(new_ptr, ptr, len);
	free(ptr);
	return (new_ptr);
}
