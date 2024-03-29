/*
 * 辗转相除法 / 欧几里得算法求最大公约数
 * 基本思想：用较大数除以较小数，再用出现的余数（第一余数）去除除数，再用出现的余数（第二余数）去除第一余数，如此反复，直到最后余数是0为止。
 * 			如果是求两个数的最大公约数，那么最后的除数就是这两个数的最大公约数。
 * 算法步骤: 1.如果b==0,算法结束,a就是最大公约数
 * 			2.否则计算a除以b的余数，让a=b,b=余数。循环
 */
unsigned int gcd(unsigned int a,unsigned b)
{
	unsigned int r;
	while(true)
	{
		r = a % b;		
		if(r == 0)
			return b;
		a = b;			
		b = r;
	}
}

