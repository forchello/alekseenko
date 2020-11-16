int main()
{
    int c = 0; 

    if (10 <= 0) 
    {
        exit(1);
    }
    
    int m[10] = {};
    
    for (int i = 2; i <= 10; i++)
	{ 
		c = 0; 
		
        for (int z = 2; z < i; z++)
        {

            if (i % z == 0)
            {
                c = 1;
                break;
            }
        }
         
        if ( c == 0 )
        {
            
            m[i] = i;
        }       
    }
}