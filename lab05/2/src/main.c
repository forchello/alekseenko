int main()
{
 int a = 100;
 int b = 1;							// если b = 1, то число простое

	for ( int i = 2; i < a; i++ ) 
	{

		if ( a % i == 0 ) 
		{
			b = 0; 					// если b = 0, то число не простое
			break; 
		}
	}
}