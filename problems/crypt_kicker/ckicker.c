/* #843 - Crypt Kicker
A common but insecure method of encrypting text is to permute the letters of
the alphabet. That is, in the text, each letter of the alphabet is consistently
replaced by some other letter. So as to ensure that the encryption is
reversible, no two letters are replaced by the same letter.

Your task is to decrypt several encoded lines of text, assuming that each line
uses a different set of replacements, and that all words in the decrypted text
are from a dictionary of known words.

The input consists of a line containing an integer n, followed by n lower case
words, one per line, in alphabetical order. These n words comprise the
dictionary of words which may appear in the decrypted text. Following the
dictionary are several lines of input. Each line is encrypted as described
above. 

There are no more than 1000 words in the dictionary. No word exceeds 16 letters.
The encrypted lines contain only lower case letters and spaces and do not exceed
80 characters in length.
*/

#include <stdio.h>

#define WORD 17

int main(int argc, char const *argv[])
{
	/* number of words in the dictionary */
	int n;
	scanf("%d", &n);
	char data[WORD];

	for(i=0; i<n; i++){
		fgets(data, WORD, stdin);
		printf("%c\n", data[0]); 
	}

	return 0;
}