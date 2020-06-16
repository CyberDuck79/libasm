/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 11:48:39 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/06 13:34:46 by fhenrion         ###   ########.fr       */
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
	t_list		*list;
	t_list		*node;
	const char	src[] = "bla bla bla je sert juste a tester que tout marche bien\n";
	const char	src_cmp[] = "bla bla bla je sert juste a comparer les chaines de charactere\n";
	const char	spd[] = "ajkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeujkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeuilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfeliufchbeiuzfgqusjchbfnzegnfxbvnisuybfnjqhseiuzwbfilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfelifjqdfqsdfdsfdsqfdsqfdsfqsdfsdqqsdfsqfddsqfqsdffsqddqsdfsdqfffffffkjkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeujkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeuilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfeliufchbeiuzfgqusjchbfnzegnfxbvnisuybfnjqhseiuzwbfilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfelifjqdfqsdfdsfdsqfdsqfdsfqsdfsdqqsdfsqfddsqfqsdffsqddqsdfsdqfffffffk";
	const char	spd_cmp[] = "ajkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeujkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeuilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfeliufchbeiuzfgqusjchbfnzegnfxbvnisuybfnjqhseiuzwbfilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfelifjqdfqsdfdsfdsqfdsqfdsfqsdfsdqqsdfsqfddsqfqsdffsqddqsdfsdqfffffffkjkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeujkqhsdgfhqjkghjkgsfhdkgjfgsjhkgdfkjhsgfhjkgqsdhjkfghjksqgfdjkhgsqhjkdfghjksgdqfhjkgsqkjfghekyufgsuykdqgfjkhsdgfkuysegfkjsdhgfykusegfhkjdgfkqsyegfkjdsqgekyusdjhfgkuysefghgskjdhfgqksuyegfkqdsqhjfgqskeyfgskuyegfkqsuygekusgqkduyfgkjyqsegfykugsdfkjygseufygsdkfyuesgfkusdfgkuysgekhjfgqhiusdhflkjsehfhkusdfghqiuegsfsjhkgfhjkqgsdfhjqkgsdkhjfgseyfgsukdygdhjfgseyukfgdskygfkseygkhjsdqgfkjysegykusqgdkjfhgseuygfjkshdqgesykufgskjhgfdyjkgseyfgksjysleuifgliuqsdghfjklgqsdquksdjgqgkjshgdjhkqsdgfhjgkjgesuyfgkyqjsgdfhjgqseykufgqksjygeyufgskqjhgeyufgsqkyuegfhjqlkshfjhdljfkhsqjklhsdfjklhqdsjklfgjksldgfhjkqsgdkjlfglieufhgsldkugdfhjkgsefilugsdjhkfgskdjhfgjshkqdgfkdshjfgdsqkjhfgdshjkfgqkseyugfjhdsgqvhjbdsskhgsefkyugfkugdkhsjfgsjkgfeuyfgqsdkhjfgkseuygfjkysdgfjhdgfkjsygefkuygsdkjfkjefysgdkfhsegfukysdyfkyuegksuygdfqsuilegfslifiueyqkljsdfhlkjhsefilugsdhjkfgsekljhfjklsdhfjklsehfkljsdghfhjgskjfhesfljkshdjkfgsdkjhflseiufgldksjhgfkjqhzeuilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfeliufchbeiuzfgqusjchbfnzegnfxbvnisuybfnjqhseiuzwbfilfsdhjkvbsdbffjkhsbfkluegflesqhfmlslifjddiosqhfelifjqdfqsdfdsfdsqfdsqfdsfqsdfsdqqsdfsqfddsqfqsdffsqddqsdfsdqfffffffm";
	char		dst[4096];
	char		spd_atoi[] = " \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r  \t \n \r -2147483641HJGQGSDHJQ";

	printf("WRITE TESTS\n");
	t = clock();
	write(1, spd, 4096);
	t = clock() - t;
	printf("\n-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("write\n\n");
	t = clock();
	ft_write(1, spd, 4096);
	t = clock() - t;
	printf("\n-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_write\n\n\n");
	t = clock();
	read(0, dst, 4096);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("read\n\n");
	t = clock();
	ft_read(0, dst, 4096);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_read\n\n\n");

	printf("STRLEN TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	len = strlen(src);
	t = clock() - t; 
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("strlen : %lu\n\n", len);
	t = clock();
	len = ft_strlen(src);
	t = clock() - t; 
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_strlen : %lu\n\n\n", len);
	printf("\n\n");

	printf("STRCPY TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	ptr = strcpy(dst, spd);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("strcpy : %p\n\n", ptr);
	t = clock();
	ptr = ft_strcpy(dst, spd);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_strcpy : %p\n\n", ptr);
	printf("\nCOMPARE TESTS\n");
	printf("strcpy : %s", strcpy(dst, src));
	printf("ft_strcpy : %s", ft_strcpy(dst, src));
	printf("strcpy : %s", strcpy(dst, ""));
	printf("ft_strcpy : %s", ft_strcpy(dst, ""));
	printf("\n\n\n");

	printf("STRCMP TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	cmp = strcmp(spd, spd_cmp);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("strcmp : %i\n\n", cmp);
	t = clock();
	cmp = ft_strcmp(spd, spd_cmp);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_strcmp : %i\n\n", cmp);
	printf("\nCOMPARE TESTS\n");
	printf("strcmp : %i\n", strcmp(src, src_cmp));
	printf("ft_strcmp : %i\n", ft_strcmp(src, src_cmp));
	printf("strcmp : %i\n", strcmp(src, src));
	printf("ft_strcmp : %i\n", ft_strcmp(src, src));
	printf("\n\n\n");

	printf("BZERO TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	bzero(dst, 4096);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("bzero\n\n");
	t = clock();
	ft_bzero(dst, 4096);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_bzero\n\n");
	printf("\n\n");

	printf("MEMCPY TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	ptr = memcpy(dst, spd, 4096);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("memcpy : %p\n\n", ptr);
	t = clock();
	ptr = ft_memcpy(dst, spd, 4096);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_memcpy : %p\n\n", ptr);
	printf("\nCOMPARE TESTS\n");
	printf("memcpy : %s", (char*)memcpy(dst, src, 57));
	printf("ft_memcpy : %s", (char*)ft_memcpy(dst, src, 57));
	printf("\n\n\n");

	printf("STRDUP TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	ptr = strdup(spd);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("strdup : %p\n\n", ptr);
	free(ptr);
	t = clock();
	ptr = ft_strdup(spd);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_strdup : %p\n\n", ptr);
	free(ptr);
	printf("\nCOMPARE TESTS\n");
	printf("strdup : %s", strdup(src));
	printf("ft_strdup : %s", ft_strdup(src));
	printf("\n\n\n");

	printf("ATOI TESTS\n");
	printf("\nSPEED TESTS\n");
	t = clock();
	cmp = atoi(spd_atoi);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("atoi : %i\n\n", cmp);
	t = clock();
	cmp = ft_atoi(spd_atoi);
	t = clock() - t;
	printf("-------- exec time : %f\n", ((double)t)/CLOCKS_PER_SEC);
	printf("ft_atoi : %i\n\n", cmp);
	printf("\nCOMPARE TESTS\n");
	printf("atoi(\"   +2147483641z\") : %i\n", atoi("   +2147483641z"));
	printf("ft_atoi(\"   +2147483641z\") : %i\n", atoi("   +2147483641z"));
	printf("atoi(\"\") : %i\n", atoi(""));
	printf("ft_atoi(\"\") : %i\n", atoi(""));
	printf("atoi(\"-\") : %i\n", atoi("-"));
	printf("ft_atoi(\"-\") : %i\n", atoi("-"));
	printf("atoi(\"+\") : %i\n", atoi("+"));
	printf("ft_atoi(\"+\") : %i\n", atoi("+"));
	printf("atoi(\"++4\") : %i\n", atoi("++4"));
	printf("ft_atoi(\"++4\") : %i\n", atoi("++4"));
	printf("atoi(\"--4\") : %i\n", atoi("--4"));
	printf("ft_atoi(\"--4\") : %i\n", atoi("--4"));
	printf("atoi(\"\\n\") : %i\n", atoi("\n"));
	printf("ft_atoi(\"\\n\") : %i\n", atoi("\n"));
	printf("atoi(\"qezzqe\") : %i\n", atoi("qezzqe"));
	printf("ft_atoi(\"qezzqe\") : %i\n", atoi("qezzqe"));
	printf("\n\n");

	printf("FONCTIONS BONUS\n");
	cmp = ft_atoi_base("10010", "01");
	printf("ft_atoi_base(\"10010\", \"01\") : %i\n", cmp);
	cmp = ft_atoi_base(" \t-123y", "0123456789");
	printf("ft_atoi_base(\" \t-123y\", \"0123456789\") : %i\n", cmp);
	cmp = ft_atoi_base("10010", "1");
	printf("ft_atoi_base(\"10010\", \"1\") : %i\n", cmp);
	cmp = ft_atoi_base("10010", "");
	printf("ft_atoi_base(\"10010\", \"\") : %i\n", cmp);
	cmp = ft_atoi_base("zer", "zere");
	printf("ft_atoi_base(\"zer\", \"zere\") : %i\n", cmp);
	cmp = ft_atoi_base("", "0123456789");
	printf("ft_atoi_base(\"\", \"0123456789\") : %i\n", cmp);
	cmp = ft_atoi_base("234", "+0123456789");
	printf("ft_atoi_base(\"234\", \"+0123456789\") : %i\n", cmp);
	cmp = ft_atoi_base("234", "-0123456789");
	printf("ft_atoi_base(\"234\", \"-0123456789\") : %i\n", cmp);
	cmp = ft_atoi_base("234", "\t0123456789");
	printf("ft_atoi_base(\"234\", \"\t0123456789\") : %i\n", cmp);
	
	printf("\n\nLIST FONCTIONS\n");
	list = ft_create_elem("test");
	printf("ft_create_elem(\"test\")\n");
	printf("list : %p, list->data : %p, list->next : %p\n", list, &list->data, &list->next);
	printf("list->data : %s, list->next : %p\n", (char*)list->data, list->next);
	printf("ft_list_push_front(&list, \"test2\")\n");
	ft_list_push_front(&list, "test2");
	printf("list->data : %s, list->next : %p\n", (char*)list->data, list->next);
	printf("ft_list_size(list)\n");
	printf("size : %lu\n", ft_list_size(list));
	printf("ft_list_pop_front(&list)\n");
	ptr = ft_list_pop_front(&list);
	printf("ptr : %s, list->data : %s\n", (char*)ptr, (char*)list->data);

	list = ft_create_elem(ft_strdup("robert"));
	ft_list_push_front(&list, ft_strdup("flavien"));
	ft_list_push_front(&list, ft_strdup("ayuma"));
	ft_list_push_front(&list, ft_strdup("josiane"));
	ft_list_push_front(&list, ft_strdup("jeanne"));
	ft_list_push_front(&list, ft_strdup("julien"));
	ft_list_push_front(&list, ft_strdup("sandra"));
	ft_list_push_front(&list, ft_strdup("marie"));
	ft_list_push_front(&list, ft_strdup("jean"));
	ft_list_push_front(&list, ft_strdup("lea"));
	ft_list_push_front(&list, ft_strdup("hubert"));
	ft_list_push_front(&list, ft_strdup("paul"));
	printf("unsorted :\n");
	node = list;
	while (node)
	{
		printf("%s\n",(char*)node->data);
		node = node->next;
	}
	ft_list_sort(&list, ft_strcmp);
	printf("\nsorted :\n");
	node = list;
	while (node)
	{
		printf("%s\n", (char*)node->data);
		node = node->next;
	}
	printf("remove if -> robert\n");
	ft_list_remove_if(&list, "robert", ft_strcmp, free);
	node = list;
	while (node)
	{
		printf("%s\n", (char*)node->data);
		printf("%p\n", node->next);
		node = node->next;
	}
	return (0);
}
