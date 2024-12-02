//#define MAX 20
//
//void XuatDay(int a[MAX], int n)
//{
//	for (int i = 1; i <= n; i++)
//		cout << a[i] << '\t';
//}

int Part(int m, int n)
{
	int s;
	if (m == 0)
	{
		s = 1;
	}
	else
	{
		if (n == 0)
		{
			s = 0;
		}
		else
		{
			if (n == 1)
			{
				s = 1;
			}
			else
			{
				if (m < n)
				{
					s = Part(m, m);
				}
				else
				{
					s = Part(m, n - 1) + Part(m - n, n);
				}
			}
		}
	}
	return s;
}