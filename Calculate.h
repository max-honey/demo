#include <sstream>
//#include <opencv2/highgui/highgui.hpp>  
//#include <opencv2/imgproc/imgproc.hpp>  
//#include <opencv2/core/core.hpp>  
#include <vector>
#include <math.h>
#include<iostream>
//using namespace cv;
using namespace std;
class Calculate {
	private:
		double x = 100, y = 100, p = 45,xi,yi,pi,xj,yj,pj;//机器的全局坐标x,y；xi=x(k) xj=x(k+1);
		double zi_p = 3, zi_dis = 15;//传进来的角度和距离
		//double zi_x, zi_y;//特征点的局部坐标
		double g_x, g_y,g_p;//特征点的全局坐标

		double zi_x[5], zi_y[5];
		double gi_x[5], gi_y[5];
		double Distance_min = 100, Distance_max = 150; //最大距离里，最小距离
		double nearest_x = 110, nearest_y = 120;//每一条曲线c与g的最近距离
		double Nearest_x = 110, Nearest_y = 120;//最近点的坐标，全局坐标
		double Fg = 0;//函数F(g)
		double dx, dy, dp;
		double  V_x_y_p=0;//函数V（x,y,p);
		double W_x_y_p = 0;//函数W(x,y,p);
		double step_max, step_min;
		int MaxIterater,n=2;
	public:
		double Calculate_Globle_Point(double a,double b,double c);
		double Calculate_Globle_Point_y(double a, double b, double c);
		double Calculate_Fg(double a,double b,double c);
		double Calculate_Vg(double a,double b,double c);
		void Calculate_TiDu();
	    void Calculate_d_x_y_p(double a,double b,double c);
		double getdx();
		double getdy();
		double getdp();
		double getxi();
		double getyi();
		double getpi();

};
