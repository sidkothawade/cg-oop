#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
using namespace std;
class POLYGON
{
    private:
        int p[10][10],Trans_result[10][10],Trans_matrix[10][10];
        float Rotation_result[10][10],Rotation_matrix[10][10];
        float Scaling_result[10][10],Scaling_matrix[10][10];
        float Shearing_result[10][10],Shearing_matrix[10][10];
        int Reflection_result[10][10],Reflection_matrix[10][10];
    public:
	int accept_poly(int [][10]);
	void draw_poly(int [][10],int);
	void draw_polyfloat(float [][10],int);
	void matmult(int [][10],int [][10],int,int,int,int [][10]);
	void matmultfloat(float [][10],int [][10],int,int,int,float [][10]);
	void shearing(int [][10],int);
	void scaling(int [][10],int);
	void rotation(int [][10],int);
	void translation(int [][10],int);
	void reflection(int [][10],int);
};
int POLYGON :: accept_poly(int p[][10])
{
	int i,n;
	cout<<"\n\nEnter number of vertices : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\n\nEnter (x,y) Co-ordinate of point P"<<i<<" : ";
		cin >> p[i][0] >> p[i][1];
		p[i][2] = 1;
	}
	
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<3;j++)
		{
			cout<<p[i][j]<<"\t\t";
		}
	}
	return n;
}
void POLYGON :: draw_poly(int p[][10], int n)
{
	int i,gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	line(320,0,320,480);
	line(0,240,640,240);
	for(i=0;i<n;i++)
	{
		if(i<n-1)
		{
			line(p[i][0]+320, -p[i][1]+240, p[i+1][0]+320, -p[i+1][1]+240);
			
		}		
		else
			line(p[i][0]+320, -p[i][1]+240, p[0][0]+320, -p[0][1]+240);
	}
	delay(3000);



}
@@ -95,7 +95,7 @@ void POLYGON :: draw_polyfloat(float p[][10], int n)
		else
			line(p[i][0]+320, -p[i][1]+240, p[0][0]+320, -p[0][1]+240);
	}
	//delay(8000);


}

@@ -345,27 +345,27 @@ int main()
		switch(ch)
		{
			case 1:
				//cout<<"case1";

				p1.translation(p,n);
				break;

			case 2:
				//cout<<"case2";

				p1.scaling(p,n);
				break;

			case 3:
				//cout<<"case3";

				p1.rotation(p,n);
				break;

			case 4:
				//cout<<"case4";

				p1.reflection(p,n);
				break;

			case 5:
				//cout<<"case5";

				p1.shearing(p,n);
				break;

