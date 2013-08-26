#include <stdio.h>

int paste_required(int n){
	int  i = 1;
	int paste = 0;
	while (i < n)
	{
		paste++;
		i = i << 1;
	}
	return paste;
}

int main(int argc, char const *argv[])
{
	int n_lines;
	int line_number = 1;
	while(scanf("%d", &n_lines) != EOF || line_number > 2000)
	{
		/* Input is terminated by negative integer */
		if (n_lines < 0)
			return 0;
		if (n_lines > 0 && n_lines < 10001)
		{
	 		printf("Case %d: %d\n", line_number, paste_required(n_lines));
		}
		line_number++;
	}
	return 0;
}