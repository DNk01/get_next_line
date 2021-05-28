#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 20
char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *) malloc ((sizeof(char) * (i + 1)));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *string, int symbol)
{
	int	i;

	i = 0;
	while (string[i] != (char)symbol)
		if (!string[i++])
			return (NULL);
	return ((char *)&string[i]);
}
size_t	ft_strlen (const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}
char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		s3[i] = s2[y];
		i++;
		y++;
	}
	s3[i] = '\0';
	return (s3);
}
char *ft_remainder(char *arr, char **line, int*flag)
{
	char	*rem;
	char *ptr;

	rem = NULL;
	if(arr)
	{
		if((ptr = ft_strchr(arr, '\n')))
		{
			*ptr = '\0';
			//printf("%s\n", ptr + 1);
			*flag = 1;
			rem = ft_strdup(ptr++);
		}
	}
	*line = ft_strdup(arr);
	free(arr);
	return (rem);

}
void ft_input(int fd, char **arr)
{
	char buf[BUFFER_SIZE + 1];
	int bytes;
	char *tmp;

	while((bytes = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bytes] = '\0';
		tmp = *arr;
		*arr = ft_strjoin(*arr, buf);
		free(tmp);
		if(ft_strchr(*arr, '\n'))
			break;
	}
}
int get_next_line(int fd, char **line)
{
	static char *arr;
	int flag;

	flag = 0;
	if(!line || fd < 0 || read(fd, arr, 0) || BUFFER_SIZE <= 0)
		return (-1);
	if(!arr)
		arr = ft_strdup("");
	ft_input(fd, &arr);
	arr = ft_remainder(arr, line, &flag);
	return (flag);	
}
int main()
{
	char *line;
	int fd;
fd = open("a.txt", O_RDONLY);
get_next_line(fd, &line);
printf("%s\n", line);
get_next_line(fd, &line);
printf("%s\n", line);
		/* get_next_line(fd, &line);
	 printf("%s\n", line);
	  get_next_line(fd, &line);
	 printf("%s\n", line);
	  get_next_line(fd, &line);
	 printf("%s\n", line);
	  get_next_line(fd, &line);
	 printf("%s\n", line);
	  get_next_line(fd, &line);
	 printf("%s\n", line);
	  get_next_line(fd, &line);
	 printf("%s\n", line);*/

}
