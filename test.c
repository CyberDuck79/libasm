/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 11:48:39 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/03 16:16:13 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>
#include <unistd.h>
#include <time.h>

int		main(void)
{
	clock_t		t;
	size_t		len;
	int			cmp;
	char		*ptr;
	const char	src[] = "bla bla bla je sert juste a tester que tout marche bien\n";
	const char	src_cmp[] = "bla bla bla je sert juste a comparer les chaines de charactere\n";
	const char	spd[] = "ajkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeujkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeuilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfeliufchbeiuzfgqusjchbfnzegnfxbvnisuybfnjqhseiuzwbfilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfelifjqdfqsdfdsfdsqfdsqfdsfqsdfsdqqsdfsqfddsqfqsdffsqddqsdfsdqfffffffkjkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeujkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeuilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfeliufchbeiuzfgqusjchbfnzegnfxbvnisuybfnjqhseiuzwbfilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfelifjqdfqsdfdsfdsqfdsqfdsfqsdfsdqqsdfsqfddsqfqsdffsqddqsdfsdqfffffffk";
	const char	spd_cmp[] = "ajkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeujkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeuilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfeliufchbeiuzfgqusjchbfnzegnfxbvnisuybfnjqhseiuzwbfilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfelifjqdfqsdfdsfdsqfdsqfdsfqsdfsdqqsdfsqfddsqfqsdffsqddqsdfsdqfffffffkjkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeujkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeuilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfeliufchbeiuzfgqusjchbfnzegnfxbvnisuybfnjqhseiuzwbfilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfelifjqdfqsdfdsfdsqfdsqfdsfqsdfsdqqsdfsqfddsqfqsdffsqddqsdfsdqfffffffm";
	char		dst[4096];
	char		spd_atoi[] = " \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r -2147483641HJGQGSDHJQ";

/*
	printf("WRITE TESTS\n");
	t = clock();
	write(1, spd, 4096);
	t = clock() - t;
	printf("\n-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("write\n");
	t = clock();
	ft_write(1, spd, 4096);
	t = clock() - t;
	printf("\n-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_write\n");
	t = clock();
	read(0, dst, 4096);
	t = clock() - t;
	printf("\n-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("read\n");
	t = clock();
	ft_read(0, dst, 4096);
	t = clock() - t;
	printf("\n-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_read\n");
*/

	printf("STRLEN TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	len = strlen(src);
	t = clock() - t; 
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("strlen : %lu\n", len);
	t = clock();
	len = ft_strlen(src);
	t = clock() - t; 
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_strlen : %lu\n", len);
	printf("\n\n");

	printf("STRCPY TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	ptr = strcpy(dst, spd);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("strcpy : %p\n", ptr);
	t = clock();
	ptr = ft_strcpy(dst, spd);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_strcpy : %p\n", ptr);
	printf("\nCOMPARE TESTS\n");
	printf("strcpy : %s", strcpy(dst, src));
	printf("ft_strcpy : %s", ft_strcpy(dst, src));
	printf("strcpy : %s", strcpy(dst, ""));
	printf("ft_strcpy : %s", ft_strcpy(dst, ""));
	printf("\n\n");

	printf("STRCMP TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	cmp = strcmp(spd, spd_cmp);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("strcmp : %i\n", cmp);
	t = clock();
	cmp = ft_strcmp(spd, spd_cmp);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_strcmp : %i\n", cmp);
	printf("\nCOMPARE TESTS\n");
	printf("strcmp : %i\n", strcmp(src, src_cmp));
	printf("ft_strcmp : %i\n", ft_strcmp(src, src_cmp));
	printf("strcmp : %i\n", strcmp(src, src));
	printf("ft_strcmp : %i\n", ft_strcmp(src, src));
	printf("\n\n");

	printf("BZERO TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	bzero(dst, 4096);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("bzero\n");
	t = clock();
	ft_bzero(dst, 4096);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_bzero\n");
	printf("\n\n");

	printf("MEMCPY TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	ptr = memcpy(dst, spd, 4096);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("memcpy : %p\n", ptr);
	t = clock();
	ptr = ft_memcpy(dst, spd, 4096);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_memcpy : %p\n", ptr);
	printf("\nCOMPARE TESTS\n");
	printf("memcpy : %s", memcpy(dst, src, 57));
	printf("ft_memcpy : %s", ft_memcpy(dst, src, 57));
	printf("\n\n");

	printf("STRDUP TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	ptr = strdup(spd);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("strdup : %p\n", ptr);
	free(ptr);
	t = clock();
	ptr = ft_strdup(spd);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_strdup : %p\n", ptr);
	free(ptr);
	printf("\nCOMPARE TESTS\n");
	printf("strdup : %s", strdup(src));
	printf("ft_strdup : %s", ft_strdup(src));
	printf("\n\n");

	printf("ATOI TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	cmp = atoi(spd_atoi);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("atoi : %i\n", cmp);
	t = clock();
	cmp = ft_atoi(spd_atoi);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_atoi : %i\n", cmp);
	printf("\nCOMPARE TESTS\n");
	printf("atoi : %i\n", atoi("   +2147483641z"));
	printf("ft_atoi : %i\n", atoi("   +2147483641z"));
	printf("atoi : %i\n", atoi(""));
	printf("ft_atoi : %i\n", atoi(""));
	printf("atoi : %i\n", atoi("-"));
	printf("ft_atoi : %i\n", atoi("-"));
	printf("atoi : %i\n", atoi("+"));
	printf("ft_atoi : %i\n", atoi("+"));
	printf("atoi : %i\n", atoi("++4"));
	printf("ft_atoi : %i\n", atoi("++4"));
	printf("atoi : %i\n", atoi("--4"));
	printf("ft_atoi : %i\n", atoi("--4"));
	printf("atoi : %i\n", atoi("\n"));
	printf("ft_atoi : %i\n", atoi("\n"));
	printf("atoi : %i\n", atoi("qezzqe"));
	printf("ft_atoi : %i\n", atoi("qezzqe"));
	printf("\n\n");

	printf("FONCTIONS PERSO\n");
	printf("ft_checkset(\"*^!&[]()\", \")xe\") : %i\n", ft_checkset("*^!%&[]()", ")xe"));
	printf("ft_checkset(\"*^!&()[]\", \"zr)\") : %i\n", ft_checkset("*^!%&()[]", "zr)"));
	printf("ft_checkset(\"*^!&()[]\", \"xte\") : %i\n", ft_checkset("*^!%&()[]", "xte"));
	printf("ft_checkset(\"\", \"xte\") : %i\n", ft_checkset("", "xte"));
	printf("ft_checkset(\"*^!&()[]\", \"\") : %i\n", ft_checkset("*^!%&()[]", ""));
	printf("ft_checkset(\"\", \"\") : %i\n", ft_checkset("", ""));
	printf("ft_checkdup(\"azertyuiop\") : %i\n", ft_checkdup("azertyuiop"));
	printf("ft_checkdup(\"azeratyuiop\") : %i\n", ft_checkdup("azeratyuiop"));
	printf("ft_checkdup(\"\") : %i\n", ft_checkdup(""));
	printf("ft_skipset(\"ataetatBLOB\", \"eat\") : %s\n", ft_skipset("ataetatBLOB", "eat"));
	printf("ft_skipset(\"\", \"eat\") : %s\n", ft_skipset("", "eat"));
	printf("ft_skipset(\"ataetatBLOB\", \"\") : %s\n", ft_skipset("ataetatBLOB", ""));
	printf("ft_setindex(\"0123456789\", '2') : %li\n", ft_setindex("0123456789", '2'));
	printf("ft_setindex(\"0123456789\", '9') : %li\n", ft_setindex("0123456789", '9'));
	printf("ft_setindex(\"0123456789\", '0') : %li\n", ft_setindex("0123456789", '0'));
	printf("ft_setindex(\"0123456789\", 'a') : %li\n", ft_setindex("0123456789", 'a'));
	printf("ft_setindex(\"\", 'a') : %li\n", ft_setindex("", 'a'));
	printf("ft_setindex(\"0123456789\", 0) : %li\n", ft_setindex("0123456789", 0));
	printf("\n\n");

	printf("FONCTIONS BONUS\n");
	cmp = ft_atoi_base("10010", "01");
	printf("ft_atoi_base(\"10010\", \"01\") : %i\n", cmp);
	cmp = ft_atoi_base(" \t-123y", "0123456789");
	printf("ft_atoi_base(\" \t-123y\", \"0123456789\") : %i\n", cmp);
	cmp = ft_atoi_base("10010", "01");
	printf("ft_atoi_base(\"10010\", \"01\") : %i\n", cmp);
	cmp = ft_atoi_base(" \t-123y", "0123456789");
	printf("ft_atoi_base(\" \t-123y\", \"0123456789\") : %i\n", cmp);
	return (0);
}
