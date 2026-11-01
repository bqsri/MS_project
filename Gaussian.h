#ifndef Gaussian_H
#define Gaussian_H

double Gaussian()
{
	static double var1,var2,fac;
	static int phase = 0;
	static double rand1,rand2;
	double random_num,var_sum;
	if(phase == 0)
	{
		do
		{
			rand1 = (double)rand()/ (RAND_MAX);
			rand2 = (double)rand()/ (RAND_MAX);
			var1 = 1 - 2 * rand1;
			var2 = 1 - 2 * rand2;
			var_sum = var1 * var1 + var2 * var2;
		}while(var_sum >= 1 || var_sum <= 0);
		
		fac = sqrt(-2.0 * log(var_sum)/var_sum);
		random_num = var1 * fac;
	}
	else
	{
		random_num = var2 * fac;
	}
	
	phase = 1 - phase;
	return random_num;          //返回随机数，每次调用高斯函数都返回一个值
}

#endif