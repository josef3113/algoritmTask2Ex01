#include<iostream>
#include <vector>
#include <math.h>

using namespace std;

int min(int num1, int num2)
{
	return num1 > num2 ? num2 : num1;
}

int FindMedianPos(vector<int> & arr)
{
	int medianPos;
	if (arr.size() == 1)
	{
		medianPos = 0;
	}
	else
	{
		if (arr.size() % 2 == 0)
		{
			medianPos = (arr.size() / 2) - 1;
		}
		else
		{
			medianPos = arr.size() / 2;
		}

	}
	return medianPos;
}


int FindMedian(vector<int> & arr1, vector<int> &arr2)
{
	int midianToReturn;
	bool toContinue = true;

	while (toContinue)
	{
		int medianPos1,  medianPos2;

		medianPos1 = FindMedianPos(arr1);
		medianPos2 = FindMedianPos(arr2);

		if (arr1[medianPos1] > arr2[medianPos2])
		{
			int toErase;
			toErase = min(arr1.size() - medianPos1 - 1, medianPos2);
		  
		  for (int i = 0; i < toErase; i++)
		  {
			  arr1.erase(--arr1.end());
			  arr2.erase(arr2.begin());
		  }

		  if (toErase == 0 )
		  {
			  vector<int>::iterator mid = arr2.begin() + medianPos2;

			  if (arr1.size() == 1)
			  {
				  if (arr2.size() == 1)
				  {
					  return min(arr1[0], arr2[0]);

				  }
				  if (arr2.size() == 2)
				  {
					  return min(arr1[0], arr2[1]);

				  }
				  else
				  {
					  if (arr1[0] > arr2[medianPos2 +1 ])
					  {
						  mid = arr2.begin() + medianPos2;
						  arr2.insert(++mid, arr1[0]);
						  medianPos2 = FindMedianPos(arr2);
						  return arr2[medianPos2];
					  }
					  else
					  {
						  mid = arr2.begin() + medianPos2;
						  arr2.insert(mid, arr1[0]);
						  medianPos2 = FindMedianPos(arr2);
						  return arr2[medianPos2];
						 
					  }

				  }
			  }
			  if (arr1.size() == 2)
			  {
				  if (arr2.size() == 1)
				  {
					  return arr1[0];

				  }
				  else
				  {
					  arr1.erase(--arr1.end());
					  arr2.erase(arr2.begin());
				  }
			  }
			  else
			  {
				  if (arr2.size() == 1)
				  {
					  if (arr1[medianPos1 -1] > arr2[0])
					  {
						  mid = arr1.begin() + medianPos1;
						  arr1.insert(--mid, arr2[0]);
						  medianPos1 = FindMedianPos(arr1);
						  return arr1[medianPos1];
					  }
					  else
					  {
						  mid = arr1.begin() + medianPos1;
						  arr1.insert(mid, arr2[0]);
						  medianPos1 = FindMedianPos(arr1);
						  return arr1[medianPos1];

					  }

				  }
				  else
				  {
					  arr1.erase(--arr1.end());
					  arr2.erase(arr2.begin());
				  }
			  }
			  








			  /*if (arr1.size() > 2)
			  {
				  if (arr1[medianPos1 - 1] > arr2[medianPos2])
				  {

					  arr1.insert(--mid, arr2[medianPos2]);
					  arr2.erase(arr2.begin());
				  }
				  else
				  {
					  arr1.insert(mid, arr2[medianPos2]);
					  arr2.erase(arr2.begin());
				  }

				  medianPos1 = FindMedianPos(arr1);
				  medianPos2 = FindMedianPos(arr2);
				  mid = arr1.begin() + medianPos1;
				  if (arr1[medianPos1 - 1] > arr2[medianPos2])
				  {

					  arr1.insert(--mid, arr2[medianPos2]);
					  arr2.erase(arr2.begin());
				  }
				  else
				  {
					  arr1.insert(mid, arr2[medianPos2]);
					  arr2.erase(arr2.begin());
				  }
				  
			  }

			  else
			  {
				  arr1.insert(arr1.begin(), arr2[medianPos2]);
				  arr2.erase(arr2.begin());

			  }
			  if (arr2.size() == 0)
			  {
				  medianPos1 = FindMedianPos(arr1);
				  return arr1[medianPos1];
			  }


*/












			  /*if (arr1.size() != 1)
			  {
				  arr1.erase(--arr1.end());
				  arr2.erase(arr2.begin());
				  if (arr1.size() == 0)
				  {
					  medianPos2 = FindMedianPos(arr2);
					  return arr2[medianPos2];;
				  }
				  if (arr2.size() == 0)
				  {
					  medianPos1 = FindMedianPos(arr1);
					  return arr1[medianPos1];;
				  }
			  }
			  else
			  {
				  vector<int>::iterator mid = arr2.begin() +1+ medianPos2 ;
				  if (medianPos2 == 0)
				  {
					  mid = --arr2.end();
				  }
				  else
				  {
					  if (arr1[0] > arr2[1 + medianPos2])
					  {
						  mid = --arr2.end();
					  }

				  }
				  arr2.insert(mid, arr1[0]);
				  toContinue = false;
				  medianPos2 = FindMedianPos(arr2);
				  return arr2[medianPos2];
			  }*/
		  }
		  

		  /*if (arr1.size() == 1 || arr2.size() == 1)
		  {
			  toContinue = false;
			  if (arr1.size() == 1)
			  {
				  arr2.erase(arr2.begin());
				  medianPos2 = FindMedianPos(arr2);
				  midianToReturn = arr2[medianPos2];
			  }

		  }*/


		}
		else
		{
			int toErase = min(medianPos1, arr2.size() - medianPos2 - 1);
			for (int i = 0; i < toErase; i++)
			{
				arr2.erase(--arr2.end());
				arr1.erase(arr1.begin());
			}


			if (toErase == 0)
			{
				vector<int>::iterator mid = arr2.begin() + 1 + medianPos2;
				if (arr2.size() == 1)
				{
					if (arr1.size() == 1)
					{
						return min(arr1[0], arr2[0]);

					}
					if (arr1.size() == 2)
					{
						return min(arr2[0], arr1[1]);

					}
					else
					{
						if (arr2[0] > arr1[medianPos1 + 1])
						{
							mid = arr1.begin() + medianPos1;
							arr1.insert(++mid, arr2[0]);
							medianPos1 = FindMedianPos(arr1);
							return arr1[medianPos1];
						}
						else
						{
							mid = arr1.begin() + medianPos1;
							arr1.insert(mid, arr2[0]);
							medianPos1 = FindMedianPos(arr1);
							return arr1[medianPos1];

						}

					}
				}
				if (arr1.size() == 2)
				{
					if (arr1.size() == 1)
					{
						return arr2[0];

					}
					else
					{
						arr2.erase(--arr2.end());
						arr1.erase(arr1.begin());
					}
				}
				else
				{
					if (arr1.size() == 1)
					{
						if (arr2[medianPos2 - 1] > arr1[0])
						{
							mid = arr2.begin() + medianPos2;
							arr2.insert(--mid, arr1[0]);
							medianPos2 = FindMedianPos(arr2);
							return arr2[medianPos2];
						}
						else
						{
							mid = arr2.begin() + medianPos2;
							arr2.insert(mid, arr1[0]);
							medianPos2 = FindMedianPos(arr2);
							return arr2[medianPos2];

						}

					}
					else
					{
						arr2.erase(--arr2.end());
						arr1.erase(arr1.begin());
					}
				}





























				/*vector<int>::iterator mid = arr2.begin() + medianPos2;
				if (arr2.size() > 2)
				{
					if ( arr2[medianPos2-1 ] > arr1[medianPos1 ] )
					{

						arr2.insert(--mid, arr1[medianPos1]);
						arr1.erase(arr1.begin());
					}
					else
					{
						arr2.insert(mid, arr1[medianPos1]);
						arr1.erase(arr1.begin());
					}

				}

				else
				{
					
						if (arr2[medianPos2] > arr1[medianPos1 + 1])
						{
							arr1.insert(arr1.begin() + medianPos1++, arr2[medianPos2]);
							arr2.erase(arr2.begin());

						}
						else
						{
							arr1.insert((arr1.begin() + medianPos1-1), arr2[medianPos2]);
							arr2.erase(arr2.begin());

						}

					
				}

				if (arr2.size() == 0)
				{
					medianPos1 = FindMedianPos(arr1);
					return arr1[medianPos1];
				}



*/
















			//	if (arr1.size() == 1 && arr2.size() == 1)
			//	{
			//		return min(arr1[0], arr2[0]);
			//	}
			//	if (arr1.size() != 1)
			//	{
			//		arr2.erase(--arr2.end());
			//		arr1.erase(arr1.begin());

			//		if (arr1.size() == 0 )
			//		{
			//			medianPos2 = FindMedianPos(arr2);
			//			return arr2[medianPos2];;
			//		}
			//		if (arr2.size() == 0)
			//		{
			//			medianPos1 = FindMedianPos(arr1);
			//			return arr1[medianPos1];;
			//		}
			//	}
			//	else
			//	{
			//		vector<int>::iterator mid = arr2.begin() + (medianPos2 );
			//		if (medianPos2 == 0)
			//		{
			//			mid = arr2.begin();
			//		}
			//		else
			//		{
			//			if (arr1[0] < arr2[medianPos2 - 1])
			//			{
			//				mid = arr2.begin();
			//				//mid--;

			//			}

			//		}
			//		
			//		arr2.insert(mid, arr1[0]);
			//		toContinue = false;
			//		medianPos2 = FindMedianPos(arr2);
			//		return arr2[medianPos2];
			//	}
			}

		}
	}


	return 0;
		//return midianToReturn;

}

void main()
{
	vector<int> arr1 = { 2,3,5,8 };// {-5,3,6,12,15 };    //{ 2,3,5,8 };   //
	vector<int> arr2 = { 10,12,14,16,18,20 };// { -12,-10,-6,-3,4,10 };  //{ 10,12,14,16,18,20 };  //
	cout << FindMedian(arr1, arr2) << endl;;


}
