#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *convertHexaToBinary(char *input, char *target, int b);
char *convertBinaryToHexa(char *input, char *target, int b);

void *F_function(char *target, char *key, char *plaintext);

void *rotateTextLeft(char *plaintext, char *target, int type);
void *rotateTextRight(char *plaintext, char *target, int type);
void *shiftTextLeft(char text[]);

void *Sboxes(char *target, char *text);
void *operateXOR(char *target, char *a, char *b);

void *permutate(char *item, char *target);

void *getFeistelCipherdText(char *key, char *plaintext, char *result);
void *mergeTexts(char *a, char *b, char *target, int c);

void *printBinaryText(char *name, char *text, int type);
void *getBinaryText(int a, int *array);

int main(void)
{

	//////////////////////////////////////////////////
	/*
	char name[] = "E4E8EF2E";
	char name2[] = "11100100111010001110111100101110";
	
	char* test = name;
	int store[4];

	int a = 2;
	int* BTest = getBinaryText(a,store);
	for (a = 0; a < 4; a++)
	{
		printf("%d", BTest[a]);
	}
	printf("\n");

	test = convertHexaToBinary(test, 8);
	
	
	printf("%s\n", test);
	printf("%s\n", permutate(test));

	///////////////////////////////////////////////////

	char key2[] = "0434EF71";
	char plaintext[] = "1024AA9F473C58C1";
	char cipher[] = "4FC83760C78F6EF0";

	*/
	//1AC00000
	char key2[] = "00000000";
	char plaintext[] = "40FF24330947F610";
	char cipher[] = "EC2DE1305B5F5B02";
	//EC2DE1305B5F5B02

	char *FK = (char *)malloc(sizeof(char) * 9);

	char *FP = (char *)malloc(sizeof(char) * 17);

	char *PlainT = (char *)malloc(sizeof(char) * 65);
	char *KeyT = (char *)malloc(sizeof(char) * 33);

	char *result = (char *)malloc(sizeof(char) * 65);

	char *answer = cipher;
	char *Test = (char *)malloc(sizeof(char) * 9);

	memset(FK, 0, sizeof(char) * 9);
	memset(FP, 0, sizeof(char) * 17);
	memset(PlainT, 0, sizeof(char) * 65);
	memset(KeyT, 0, sizeof(char) * 33);
	memset(result, 0, sizeof(char) * 65);
	memset(Test, 0, sizeof(char) * 9);

	long long a = 0;
	long long startpoint = 0;

	char key3[] = "0434EF71";
	char plaintext2[] = "1024AA9F473C58C1";

	printf("TEST: 1 NO: 0\n");
	scanf("%lld", &startpoint);

	if (startpoint == 1)
	{
		convertHexaToBinary(key3, KeyT, 8);
		convertHexaToBinary(plaintext2, PlainT, 16);
		getFeistelCipherdText(KeyT, PlainT, result);
		convertBinaryToHexa(result, FP, 64);
		printf("Plaintext : %s\n", plaintext2);
		printf("Key : %s\n", key3);
		printf("Ciphertext: %s\n", FP);
	}

	printf("What number do you want to start from?\n");
	scanf("%s", key2);
	printf("\nBrute Force Start From : %s", key2);

	strcpy_s(Test, sizeof(char) * 9, key2);
	strcpy_s(FK, sizeof(char) * 9, key2);

	while (1)
	{
		a++;

		/*
		printf("\n%s\n", KeyT);
		printf("\n%s\n", PlainT);
		printf("\n%s\n", FP);
		printf("\n%s\n", result);
		printf("\n%s\n", answer);
		*/

		convertHexaToBinary(Test, KeyT, 8);			// Key T : 32��Ʈ Ű
		convertHexaToBinary(plaintext, PlainT, 16); // PlainT  64��Ʈ �ؽ�Ʈ

		getFeistelCipherdText(KeyT, PlainT, result); // result : 64��Ʈ ��ȣ��
		convertBinaryToHexa(result, FP, 64);		 // FP : 16��Ʈ ��ȣ��

		if (strcmp(FP, answer) == 0)
		{ // FP �� �־��� ��ȣ�� ��
			printf("Key is .. : %s\n", KeyT);
			convertBinaryToHexa(KeyT, FK, 32);
			printf("Key is .. : %s\n", FK);
			break;
		}
		convertBinaryToHexa(KeyT, FK, 32);
		if (a % 100000 == 0)
		{
			printf("Try Key : %s\n", FK);
			printf("Plain  :  %s\n", plaintext);
			printf("Correct : %s\n", answer);
			printf("Cipher :  %s\n\n", FP);
		}

		FK[7]++;

		if (FK[7] == 'G')
		{
			FK[7] = '0';
			FK[6]++;
		}
		if (FK[6] == 'G')
		{
			FK[6] = '0';
			FK[5]++;
		}
		if (FK[5] == 'G')
		{
			FK[5] = '0';
			FK[4]++;
		}
		if (FK[4] == 'G')
		{
			FK[4] = '0';
			FK[3]++;
		}
		if (FK[3] == 'G')
		{
			FK[3] = '0';
			FK[2]++;
		}
		if (FK[2] == 'G')
		{
			FK[2] = '0';
			FK[1]++;
		}
		if (FK[1] == 'G')
		{
			FK[1] = '0';
			FK[0]++;
		}
		if (FK[0] == 'G')
		{
			printf("Error, reach to the last number %s\n", FK);
			break;
		}

		strcpy_s(Test, sizeof(char) * 9, FK);
	}
	printf("terminate\n");
	scanf("%d", &startpoint);
	free(PlainT);
	free(KeyT);
	free(FK);
	free(FP);
	free(result);
	return 0;
}

void *printBinaryText(char *name, char *text, int type)
{
	printf("%s ++ ", name);
	for (int a = 0; a < type + 1; a++)
	{
		printf("%c", text[a]);

		if ((a + 1) % 4 == 0 && a > 0)
		{
			printf(" ");
		}
	}
	printf("++ ");
	return 0;
}
void *operateXOR(char *target, char *a, char *b)
{
	char result[33] = {0};

	char buffa[1] = {0};
	char buffb[1] = {0};
	int cnt = 0;
	int length = strlen(a);
	for (cnt = 0; cnt < length; cnt++)
	{
		buffa[0] = a[cnt];
		buffb[0] = b[cnt];
		if (buffa[0] == buffb[0])
		{
			result[cnt] = '0';
		}
		else
		{
			result[cnt] = '1';
		}
	}
	result[cnt] = '\0';

	strcpy_s(target, sizeof(char) * 33, result);

	return;
}
void *mergeTexts(char *a, char *b, char *target, int c)
{
	char result1[65] = {0};
	char result2[33] = {0};
	int cnt = 0;

	if (c == 16)
	{
		strcpy_s(result2, sizeof(char) * 17, a);

		for (cnt = 0; cnt < 16; cnt++)
		{
			result2[cnt + 16] = b[cnt];
		}
		result2[32] = '\0';

		strcpy_s(target, sizeof(char) * 33, result2);
		return;
	}
	else if (c == 32)
	{
		strcpy_s(result1, sizeof(char) * 33, a);
		for (cnt = 0; cnt < 32; cnt++)
		{
			result1[cnt + 32] = b[cnt];
		}
		result1[64] = '\0';

		strcpy_s(target, sizeof(char) * 65, result1);
		return;
	}
}
void *getFeistelCipherdText(char *key, char *plaintext, char *result)
{ /*
	char * LText = (char*)malloc(sizeof(char) * 33);
	char * RText = (char*)malloc(sizeof(char) * 33);
	char* LKey = (char*)malloc(sizeof(char) * 17);
	char* RKey = (char*)malloc(sizeof(char) * 17);
	char* mergeTextsK = (char*)malloc(sizeof(char) * 33);
	char* mergeTextsT = (char*)malloc(sizeof(char) * 65);
	char* temp = (char*)malloc(sizeof(char)* 33);
	char* A_RText = (char*)malloc(sizeof(char)*33);
	*/
	char LText2[33] = {0};
	char RText2[33] = {0};
	char LKey2[17] = {0};
	char RKey2[17] = {0};
	char mergeTextsT2[65] = {0};
	char temp3[33] = {0};
	char A_RText2[33] = {0};
	char TempKey[33] = {0};

	char *LText = LText2;
	char *RText = RText2;
	char *LKey = LKey2;
	char *RKey = RKey2;
	char *mergeTextsT = mergeTextsT2;
	char *temp4 = temp3;
	char *A_RText = A_RText2;

	char *key2 = TempKey;

	strcpy_s(key2, sizeof(char) * 33, key);

	rotateTextLeft(plaintext, LText, 64);
	rotateTextRight(plaintext, RText, 64);

	int i = 0;
	for (i = 1; i < 11; i++)
	{
		//printf("\n*--------------------------------------------------------Round %d--------------------------------------------------*\n", i);

		//printf("L%d Text :", i - 1, LText);
		//printBinaryText("", LText, 32);
		//printf("R%d Text :", i - 1, RText);
		//printBinaryText("", RText, 32);

		rotateTextLeft(key2, LKey, 32);
		rotateTextRight(key2, RKey, 32);

		//printf("\n*-----------------------------------------------------------------------------------------------------------------*\n");

		//printf("\n                             LKey : %s\n", LKey);
		//printf("                             RKey : %s\n", RKey);

		//printf("**%s %d\n", LKey, &LKey);
		//printf("**%s %d\n", RKey, &RKey);

		shiftTextLeft(LKey);
		shiftTextLeft(RKey);

		//printf("()%s %d\n", LKey,&LKey);
		//printf("()%s %d\n", RKey,&RKey);

		mergeTexts(LKey, RKey, key2, 16);

		//printf("                             Shifted LKey : %s\n", LKey);
		//printf("                             Shifted RKey : %s\n", RKey);
		//printf("\n*                         ---------------------------------------------------------------                         *\n");
		//printf("                             Key%d :%s",i,key2 );
		//printf("\n*                         ---------------------------------------------------------------                         *\n");

		strcpy_s(temp4, sizeof(char) * 33, RText);

		F_function(A_RText, key2, RText);

		operateXOR(RText, LText, A_RText);

		//printf("\n                             R_Text  :");
		//printBinaryText("", A_RText, 32);
		//printf("\n                             L%dText  :",i);
		//printBinaryText("", LText, 32);
		//printf("\n*                         ---------------------------------------------------------------                         *\n");

		strcpy_s(LText, sizeof(char) * 33, temp4);

		//printf("\n*-----------------------------------------------------------------------------------------------------------------*\n");
		//printf("L%d TexT :", i);
		//printBinaryText("", LText, 32);
		//printf("R%d Text :", i);
		//printBinaryText("", RText, 32);
		//printf("\n*-----------------------------------------------------------------------------------------------------------------*\n");
	}

	//
	strcpy_s(temp4, sizeof(char) * 33, RText);
	strcpy_s(RText, sizeof(char) * 33, LText);
	strcpy_s(LText, sizeof(char) * 33, temp4);

	mergeTexts(LText, RText, mergeTextsT, 32);

	strcpy_s(result, sizeof(char) * 65, mergeTextsT);

	/*
	free(A_RText);

	free(temp);

	free(mergeTextsT);

	free(mergeTextsK);
	
	free(LKey);

	free(RText);

	free(LText);
	*/

	return;
}
void *Sboxes(char *target, char *text)
{

	char temp1[9] = {0};
	char temp2[33] = {0};
	char temp3[9] = {0};

	char *result = temp1;
	char *output = temp2;
	char *temp = temp3;

	convertBinaryToHexa(text, result, 32); // getBinaryText to Hexa

	int a = 0;
	char s1[] = "E4D12FB83A6C5907";
	char s2[] = "56CF8A04B37DE129";

	//printf("%s\n",text);
	for (a = 0; a < 8; a++)
	{
		if ((a + 1) % 2 == 1)
		{
			if ('0' <= result[a] && result[a] <= '9')
			{
				temp[a] = s1[result[a] - 48];
			}
			else if ('A' <= result[a] && result[a] <= 'F')
			{
				temp[a] = s1[result[a] - 55];
			}
		}
		else
		{
			if ('0' <= result[a] && result[a] <= '9')
			{
				temp[a] = s2[result[a] - 48];
			}
			else if ('A' <= result[a] && result[a] <= 'F')
			{
				temp[a] = s2[result[a] - 55];
			}
		}
	}
	temp[a] = '\0';

	convertHexaToBinary(temp, output, 8);

	strcpy_s(target, sizeof(char) * 33, output);

	// printf("%s\n",result);
	return;
}

void *rotateTextLeft(char *plaintext, char *target, int type)
{
	char rotateTextLeft1[33] = {0};
	char rotateTextLeft[17] = {0};

	int a = 0;
	if (type == 64)
	{
		for (a = 0; a < 32; a++)
		{

			rotateTextLeft1[a] = plaintext[a];
		}
		rotateTextLeft1[a] = '\0';

		strcpy_s(target, sizeof(char) * 33, rotateTextLeft1);
	}
	else
	{
		for (a = 0; a < 16; a++)
		{
			rotateTextLeft[a] = plaintext[a];
		}
		rotateTextLeft[a] = '\0';
		strcpy_s(target, sizeof(char) * 17, rotateTextLeft);
	}
	return;
}
void *rotateTextRight(char *plaintext, char *target, int type)
{
	char rotateTextRight[33] = {0};
	char rotateTextRight2[17] = {0};
	int a = 0;

	if (type == 64)
	{
		for (a = 0; a < 32; a++)
		{
			rotateTextRight[a] = plaintext[a + 32];
		}
		rotateTextRight[a] = '\0';

		strcpy_s(target, sizeof(char) * 33, rotateTextRight);
	}
	else
	{
		for (a = 0; a < 16; a++)
		{
			rotateTextRight2[a] = plaintext[a + 16];
		}
		rotateTextRight2[a] = '\0';
		strcpy_s(target, sizeof(char) * 17, rotateTextRight2);
	}

	return;
}
void *shiftTextLeft(char text2[])
{
	//printf("%s %d\n", text2, &text2);
	//printf("\n");

	char temp[2] = {0};

	temp[0] = text2[0];
	temp[1] = '\0';
	int a = 0;

	for (a = 0; a < 31; a++)
	{
		text2[a] = text2[a + 1];
	}
	strcat(text2, temp);
	return;
}
void *permutate(char *item, char *target)
{
	char temp[33] = {0};

	int same[] = {29, 1, 17, 8, 30, 22, 28, 6, 18, 4, 12, 19, 21, 26, 2, 20, 31, 10, 9, 25, 13, 0, 23, 15, 3, 27, 5, 11, 7, 14, 24, 16};
	int a = 0;
	for (a = 0; a < 32; a++)
	{
		temp[same[a]] = item[a];
	}

	temp[a] = '\0';

	strcpy_s(target, sizeof(char) * 33, temp);

	return;
}
void *F_function(char *target, char *key, char *plaintext)
{
	char temp[33] = {0};
	char Sbox[33] = {0};

	char temp2[9] = {0};

	char *result2 = temp2;
	char *result = temp;
	char *sboxes = Sbox;

	operateXOR(result, key, plaintext);

	//printBinaryText("                             K XOR   :", result, 32);

	convertBinaryToHexa(result, result2, 32);

	//printf("\n                             Hexa    :%s", result2);

	convertHexaToBinary(result2, result, 8);

	Sboxes(sboxes, result);

	//printBinaryText("\n                             SBox    :", sboxes, 32);

	permutate(sboxes, result);

	//printBinaryText("\n                             Permute :", result, 32);

	strcpy_s(target, sizeof(char) * 33, result);

	return;
}
char *convertBinaryToHexa(char *input, char *target, int b)
{

	char *a = input;
	int strleng = strlen(a);
	int type = 0;

	int result[16] = {0};
	char result2[17] = {0};

	int result3[8] = {0};
	char result4[9] = {0};

	char buff[1] = {0};
	int buff2[4];
	int *buff3;

	int cnt = 0;
	int cnt2 = 0;
	int renum = 0;

	int numa = 0;
	int numb = 0;
	if (b == 64)
	{
		for (cnt = 0; cnt < strleng; cnt++)
		{
			if (cnt % 4 == 0)
			{
				buff2[cnt % 4] = a[cnt] - 48;
				buff2[(cnt + 1) % 4] = a[cnt + 1] - 48;
				buff2[(cnt + 2) % 4] = a[cnt + 2] - 48;
				buff2[(cnt + 3) % 4] = a[cnt + 3] - 48;

				cnt2 = buff2[cnt % 4] * 8 + buff2[(cnt + 1) % 4] * 4 + buff2[(cnt + 2) % 4] * 2 + buff2[(cnt + 3) % 4] * 1;

				result[numa] = cnt2;
				numa++;
			}
		}
		for (cnt = 0; cnt < strlen(a) / 4; cnt++)
		{
			if (result[cnt] > 9)
			{
				result2[cnt] = result[cnt] + 55;
			}
			else
			{
				result2[cnt] = result[cnt] + 48;
			}
		}
		result2[cnt] = '\0';
		strcpy_s(target, sizeof(char) * 17, result2);
		return target;
	}
	else if (b == 32)
	{
		for (cnt = 0; cnt < strleng; cnt++)
		{
			if (cnt % 4 == 0)
			{
				buff2[cnt % 4] = a[cnt] - 48;
				buff2[(cnt + 1) % 4] = a[cnt + 1] - 48;
				buff2[(cnt + 2) % 4] = a[cnt + 2] - 48;
				buff2[(cnt + 3) % 4] = a[cnt + 3] - 48;

				cnt2 = buff2[cnt % 4] * 8 + buff2[(cnt + 1) % 4] * 4 + buff2[(cnt + 2) % 4] * 2 + buff2[(cnt + 3) % 4] * 1;

				result3[numa] = cnt2;
				numa++;
			}
		}
		for (cnt = 0; cnt < strlen(a) / 4; cnt++)
		{
			if (result3[cnt] > 9)
			{
				result4[cnt] = result3[cnt] + 55;
			}
			else
			{
				result4[cnt] = result3[cnt] + 48;
			}
		}
		result4[cnt] = '\0';
		strcpy_s(target, sizeof(char) * 9, result4);
		return target;
	}
}

void *convertHexaToBinary(char *input, char *target, int b)
{
	// if(a==NULL)
	//    return;

	char *a = input;
	int strleng = strlen(a);
	int type = 0;

	int result[32] = {0};
	char result2[33] = {0};

	int result3[65] = {0};
	char result4[65] = {0};

	char buff[1] = {0};

	int buff4[4] = {0};

	int cnt = 0;
	int cnt2 = 0;
	int renum = 0;

	int numa = 0;
	int numb = 0;

	if (b == 8)
	{
		for (cnt = 0; cnt < strleng; cnt++)
		{
			buff[0] = a[cnt];
			if (buff[0] != ' ')
			{
				if (buff[0] > 64)
				{
					cnt2 = buff[0] - 55;
				}
				else
				{
					cnt2 = buff[0] - 48;
				}

				getBinaryText(cnt2, buff4);

				for (numa = numb; numa < numb + 4; numa++)
				{
					result[numa] = buff4[numa - numb];
				}
				numb += 4;
			}
		}
		for (cnt = 0; cnt < strleng * 4; cnt++)
		{
			result2[cnt] = result[cnt] + 48;
		}
		result2[cnt] = '\0';
		strcpy_s(target, sizeof(char) * 33, result2);

		return;
	}
	else if (b == 16)
	{
		for (cnt = 0; cnt < strleng; cnt++)
		{
			buff[0] = a[cnt];
			if (buff[0] != ' ')
			{
				if (buff[0] > 64)
				{
					cnt2 = buff[0] - 55;
				}
				else
				{
					cnt2 = buff[0] - 48;
				}

				getBinaryText(cnt2, buff4);

				for (numa = numb; numa < numb + 4; numa++)
				{
					result3[numa] = buff4[numa - numb];
				}
				numb += 4;
			}
		}
		for (cnt = 0; cnt < strleng * 4; cnt++)
		{
			result4[cnt] = result3[cnt] + 48;
		}
		result4[cnt] = '\0';

		strcpy_s(target, sizeof(char) * 65, result4);
		return;
	}
}

void *getBinaryText(int a, int *array)
{
	int cnt = a;
	int number = 0;
	int remainder = 0;
	int temp = 0;

	int *pointer = array;

	memset(pointer, 0, 16);

	while (1)
	{
		pointer[number] = cnt % 2;
		cnt = cnt / 2;

		number += 1;
		if (cnt == 0)
			break;
	}

	for (cnt = 0; cnt < 2; cnt++)
	{
		temp = pointer[cnt];
		pointer[cnt] = pointer[3 - cnt];
		pointer[3 - cnt] = temp;
	}

	/*
	for (cnt = 0; cnt < 4; cnt++)
	{
		printf("%d\n", pointer[cnt]);
	}
	printf("\n");*/
	return;
}
