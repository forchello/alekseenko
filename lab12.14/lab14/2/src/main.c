#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void line ( int l )
{
	for ( int i = 0; i < l; i++)
	{
		printf(i == l - 1 ? "├── " : "│   ");
	}
}

int tree_result( char *t, int l )
{
    int end;
    char text[100];

    if ( l == 0 )
    {
    	scanf("%s", text );
    	t = text;
    }

    struct stat statbuf;

    DIR *d = opendir( t );

    struct dirent *dp;

    int ddd, fff;

    if ((d = fdopendir((ddd = open( t, O_RDONLY)))) == NULL) 
    {
        fprintf(stderr, "Cannot open %s directory\n", t);
        return 1;
    }

    line(l);
    printf("%s\n", t );

    while ((dp = readdir(d)) != NULL)
    {
        if (dp->d_name[0] == '.')
            continue;


        if ((fff = openat(ddd, dp->d_name, O_RDONLY)) == -1) 
        {
            perror(dp->d_name);
            continue;
        }

        if (fstat(fff, &statbuf) == 0 && (statbuf.st_mode & S_IFDIR)) 
        {          
            end = strlen(t);

            strcat ( t, "/" );
            strcat ( t, dp->d_name );

            tree_result( t, l + 1 );

    		t[end] = 0;
        }
        else
        {
        	line(l + 1);
        	printf("%s\n", dp->d_name );
        }

        close(fff);

      
    }

    closedir(d);



    return 0;

}


int main () 
{   
    
	char input[100];


	scanf("%s", input );

	if ( strcmp ( input, "tree" ) == 0 )
	{
		return tree_result("", 0);
	}

    return 0;
}





