#include <math.h>


int YPoint(int x, double* w, int carpan = 1)
{

	return (int)((double)(1 * (double)carpan * w[2] - w[0] * x) / (double)(w[1]));

}
int sgn(float net)
{
	if (net < 0)
		return -1;
	else
		return 1;
}
float SigmoidFunc(float net)
{
	return 2 / (1 + exp(-net)) - 1;
}
int Sum(int* vec, int length)
{
	int sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		sum += abs(vec[i]);
	}
	return sum;
}

float Sum(float* vec, int length)
{
	float sum = 0.0;
	for (size_t i = 0; i < length; i++)
	{
		/*sum += fabs(vec[i]);*/
		sum += vec[i];
	}
	return sum;
}
