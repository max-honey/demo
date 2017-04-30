#include"Calculate.h"

double Calculate::Calculate_Fg(double x,double y,double c)
{
	//g_x = x;
	//g_y = y;
	//g_p = c;
	//该点g_i与曲线集c_i最近的点near；
	g_x = Calculate_Globle_Point(x, y, p);
	g_y = Calculate_Globle_Point_y(x, y, p);
	Fg = 1 - ((g_x - Nearest_x)*(g_x - Nearest_x) + ((g_y - Nearest_y)*(g_y - Nearest_y))) / Distance_max;
	cout << "c++ project" << endl;
	return Fg;
}

double Calculate::Calculate_Globle_Point(double a,double b,double c)
{
	x = a;
	y = b;
	p = c;
	int i = 0;
	zi_x[i] = zi_dis*cos(zi_p);
	zi_y[i] = zi_dis*sin(zi_p);
	g_x = cos(p)*zi_x[i] - sin(p)*zi_y[i] + x;//算出特征点全局坐标
	g_y = sin(p)*zi_x[i] + cos(p)*zi_y[i] + y;//
	return g_x;
}
double Calculate::Calculate_Globle_Point_y(double a, double b, double c)
{
	return g_y;
}
double Calculate::Calculate_Vg(double a,double b,double c)
{
	xi = a;//更新机器自身坐标；
	yi = b;
	pi = c;
	for (int i = 0; i < n; i++)
	{
		 V_x_y_p = V_x_y_p + Calculate_Fg(gi_x[i],gi_y[i],c);
	}
	return V_x_y_p;
}
void Calculate::Calculate_TiDu()
{
	int k = 1, step, flag = 0;
	step_max = 10, step_min = 2,MaxIterater = 10;//最大步长，最小步长，步长，最大迭代次数
	double W;
	while (1)
	{
		Calculate_d_x_y_p(xi, yi, pi);
	    step = step_max;
		while (step >= step_min)
		{
			W = Calculate_Vg(x,y,p);
			dx = getdx();
			dy = getdy();
			dp = getdp();
			x = xi + step*dx;
			y = yi + step*dy;
			p = pi + step*dp;
			if (Calculate_Vg(x,y,p) < W)
			{
				xj = x;
				yj = y;
				pj = p;
				flag = 1;
				break;
			}
			step = step / 2;
		}
		if (flag == 1) { xi = xj; yi = yj; pi = pj; }
		if (k = MaxIterater || step < step_min)
		{
			x = xj;
			y = yj;
			p = pj;
			break;
		}
		else
		{
			Calculate_d_x_y_p(xi,yi,pi);
		}
	}

}

void  Calculate::Calculate_d_x_y_p(double a,double b,double c)
{
	x = a;
	y = b;
	p = c;
	for (int i = 0; i < n; i++)
	{
		dx = dx + (2*(nearest_x + gi_x[i]))/Distance_max;
		dy = dy + (2 * (nearest_y + gi_y[i])) / Distance_max;
		dp = dp + (2*((nearest_x - gi_x[i])*(-sin(zi_p)*zi_x[i] - cos(zi_p)*zi_y[i]) + (nearest_y - gi_y[i])*(cos(zi_p)*zi_x[i] - sin(zi_p)*zi_y[i])))/Distance_max;
	}
}
double Calculate::getdx()
{
	return dx;
}
double Calculate::getdy()
{
	return dy;
}
double Calculate::getdp()
{
	return dp;
}
