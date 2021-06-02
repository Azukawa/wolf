/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:58:16 by eniini            #+#    #+#             */
/*   Updated: 2021/06/02 23:14:47 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_gfx.h"

t_gfxinfo	*ft_load_bmp(const char *imagepath)
{
	t_gfxinfo		*i;
	unsigned char	header[54];
	unsigned int	imgsize;
	//unsigned int	imgidx;
	int				fd;
	//unsigned char	*temp;

	i = malloc(sizeof(t_gfxinfo));
	if (!i)
		return (NULL);
	//imgidx = 0;
	
	
	
	fd = open(imagepath, O_RDONLY);
	if (fd < 0)
		return (NULL);


	//READING ONLY THE HEADER OF THE BMP FILE TO CHECK CORRECT FILE TYPE
	//AND CRITICAL IMAGE INFORMATION. THE REVERSE AND SPECIFIC BYTE POSITIONS
	//CAN BE CROSS-REFERENCED FROM FT_CREATE_BMP().
	if (read(fd, header, 54) != 54)
	{
		ft_putendl("not a BMP file");
		return (NULL);
	}
	if (header[0] != 'B' || header[1] != 'M')
	{
		ft_putendl("not a BMP file");
		return (NULL);
	}
	//AVOIDING TYPE PUNNING FORBIDDEN BLACK MAGIC - INSTEAD BYTESHIFT ALL
	//ALLOCATED POSITIONS WHERE ONE ELEMENT IS WRITEN TO A SINGLE VALUE
	//
	//imgsize = *(int *)&header[0x22];
	imgsize = header[0x22] | (header[0x23] << 8) | (header[0x24] << 16) | (header[0x25] << 24);
	//i->img_width = *(int *)&header[0x12];
	i->img_width = header[0x12] | (header[0x13] << 8) | (header[0x14] << 16) | (header[0x15] << 24);
	//i->img_height = *(int *)&header[0x16];
	i->img_height = header[0x16] | (header[0x17] << 8) | (header[0x18] << 16) | (header[0x19] << 24);
	//SOMETIMES THIS IS MISSING (LIKE WITH THE IMGS CREATE_BMP MAKES) SO WE
	//DEDUCE IT FROM X/Y DIMENSIONS AND HOPE FOR THE BEST.
	if (!imgsize)
	{
		ft_putendl("imgsize missing, defaulting");
		imgsize = i->img_width * i->img_height * 3;
	}
	
	ft_printf("imgsize=%u|width=%d|height=%d\n", imgsize, i->img_width, i->img_height);
	
	i->one_d_addr = malloc(sizeof(unsigned char) * imgsize);
	if (!i->one_d_addr)
		return (NULL);
	//LAST READING WENT THROUGH ALL THE STANDARD (ASSUMED) METADATA, FROM THIS
	//POINT ON ITS ALL RAW COLOR DATA
	ft_putnbr(read(fd, i->one_d_addr, imgsize)), ft_putchar('\n');
	close(fd);
	/*while (imgidx < imgsize)
	{
		imgidx += 3;
		temp = &i->one_d_addr[imgidx];
		i->one_d_addr[imgidx] = i->one_d_addr[imgidx + 2];
		i->one_d_addr[imgidx + 2] = *temp;
	}
	//ATM IMAGE IS LOADED INTO MEMORY FROM TOP TO BOTTOM DUE TO BMP FORMAT -
	//WE NEED TO FLIP THE CHARRAY WITHOUT CHANGING ANY OF THE RGB VALUES
	int	len = i->img_height * i->img_width;
	int	ii = 0;
	while (ii < len / 2)
	{
		//ft_swap(&i->one_d_addr[ii], &i->one_d_addr[len - ii - 1], sizeof(unsigned char));
		unsigned char ch = i->one_d_addr[ii];
		i->one_d_addr[ii] = i->one_d_addr[len - ii - 1];
		i->one_d_addr[len - ii - 1] = ch;
		ii++;
	}*/
	//THIS WOULD PROBABLY BE USEFUL TO GET FROM THE HEADER - IN CASE WE
	//WANT TO STORE/GET TRANSPARENCY AS WELL FROM FILES
	i->bpp = 24;
	i->two_d_addr = NULL;
	return (i);
}
