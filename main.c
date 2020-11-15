/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <ppipes@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:38:59 by ppipes            #+#    #+#             */
/*   Updated: 2020/11/11 23:25:04 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	main()
{
	char	*line = "fus ro dah";
	char	*empty_line = "";
	char	*long_line = "Dovahkiin Dovahkiin Naal ok zin los vahriin wah dein vokul mahfaeraak ahst vaal ahrk fin norok paal graan fod nust hon zindro zaan Dovahkiin fah hin kogaan mu draal";
	int		result;
	char 	buf[170];
	char	*s;
	

	printf("\n TESTING STRLEN \n\n");

	printf("MY__STRLEN line len is %d\n", (int)ft_strlen(line));
	printf("SYS_STRLEN line len is %d\n", (int)strlen(line));
	printf("MY__STRLEN empty_line len is %d\n", (int)ft_strlen(empty_line));
	printf("SYS_STRLEN empty_line len is %d\n", (int)strlen(empty_line));
	printf("MY__STRLEN long_line len is %d\n", (int)ft_strlen(long_line));
	printf("SYS_STRLEN long_line len is %d\n", (int)strlen(long_line));

	printf("\n TESTING STRCPY \n\n");

	memset(buf, 0, 160);
	printf("%s\n", ft_strcpy(buf, line));
	memset(buf, 0, 160);
	printf("%s\n", ft_strcpy(buf, ""));
	memset(buf, 0, 160);
	printf("%s\n", ft_strcpy(buf, long_line));
	
	printf("\n TESTING STRCMP \n\n");

	printf("two equal: MY %d, SYS %d\n", ft_strcmp("fus", "fus"), strcmp("fus", "fus"));
	printf("two empty: MY %d, SYS %d\n", ft_strcmp("", ""), strcmp("", ""));
	printf("fus and fus ro dah : MY %d, SYS %d\n", ft_strcmp("fus", "fus ro dah"), strcmp("fus", "fus ro dah"));
	printf("empty as first : MY %d, SYS %d\n", ft_strcmp("", "fus"), strcmp("", "fus"));
	printf("fus and fusro : MY %d, SYS %d\n", ft_strcmp("fus", "fusro"), strcmp("fus", "fusro"));
	printf("fus and f : MY %d, SYS %d\n", ft_strcmp("fus", "f"), strcmp("fus", "f"));
	printf("empty as second : MY %d, SYS %d\n", ft_strcmp("fus", ""), strcmp("fus", ""));
	printf("fusro and fus : MY %d, SYS %d\n", ft_strcmp("fusro", "fus"), strcmp("fusro", "fus"));
	
	printf("\n TESTING STRDUP \n\n");

	printf("line: %s\n", (s = ft_strdup(line)));
	free(s);
	printf("new_line: %s\n", (s = ft_strdup("\n")));
	free(s);
	printf("empty_line: %s\n", (s = ft_strdup("")));
	free(s);
	printf("long_line: %s\n", (s = ft_strdup(long_line)));
	free(s);

	printf("\n TESTING WRITE \n\n");

	int		fd = open("write.txt", O_CREAT | O_RDWR, 0755);

	errno = 0;
	result = ft_write(1, "Hello\n", 6);
	printf("return value is %d\n", result);
	printf("errno: %d\n\n", errno);

	errno = 0;
	result = ft_write(567, "Hello\n", 6);
	printf("return value is %d\n", result);
	printf("errno: %d\n\n", errno);

	errno = 0;
	result = ft_write(1, "fus ro dah\n", 11);
	printf("return value is %d\n", result);
	printf("errno: %d\n\n", errno);

	errno = 0;
	result = ft_write(fd, "Dovahkiin Dovahkiin Naal ok zin los vahriin wah dein vokul mahfaeraak ahst vaal ahrk fin norok paal graan fod nust hon zindro zaan Dovahkiin fah hin kogaan mu draal\n", 165);
	printf("return value is %d\n", result);
	printf("errno: %d\n\n", errno);

	close (fd);

	printf("\n TESTING READ \n\n");

	int fd2 = open("write.txt", O_RDONLY);
	
	errno = 0;
	memset(buf, 0, 160);
	result = ft_read(0, buf, 100);
	printf("return value is %d, read this: %s", result, buf);
	printf("errno: %d\n\n", errno);

	errno = 0;
	memset(buf, 0, 160);
	result = ft_read(567, buf, 100);
	printf("return value is %d, read this: %s\n", result, buf);
	printf("errno: %d\n\n", errno);

	errno = 0;
	memset(buf, 0, 160);
	result = ft_read(fd2, buf, 30);
	printf("return value is %d, read this: %s\n", result, buf);
	printf("errno: %d\n\n", errno);

	return 0;
}