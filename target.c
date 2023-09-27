#include <stdio.h>
#include <math.h>
int size=720*560;
int red[size],green[size],blue[size],trans[size];
int r[size/2],g[size/2],b[size/2],t[size/2];
typedef struct Image
{
   int red;
   int blue;
   int green;
   int trans;
}a;
void read();
void convert();
void compare();
void main()
{
    for(int i=0;i<2;i++)
    {
        read();//read rgb and transparency values of image
        convert();//converting 2D matrix to 1D
        compare();//store difference in values of adjacent pixels
        //human detection
        int countr=0,countg=0,countb=0,countt=0;
        for(int i=0;i<size/2;i+=2)
        {
            int x=30;//for the required scenario the value of x is predicted to be 30
            if((r[i+1]-r[i])>x||(r[i+1]-r[i])<-x)
                countr++;
            if((g[i+1]-g[i])>x||(g[i+1]-g[i])<-x)
                countg++;
            if((b[i+1]-b[i])>x||(b[i+1]-b[i])<-x)
                countb++;
            if((t[i+1]-t[i])>x||(t[i+1]-t[i])<-x)
                countt++;
        }
        int y=100,z=120;
        /*the value of count if found within the input range y&z for the given scenario
        can be considered to be a human*/
        if((countr>y&&countr<z)||(countg>y&&countg<z)||(countb&&countb<z)||(countt>y&&countt))
            printf("Human Detected\n");
        else
            printf("Human not detected\n");
    }
}
void read()
{
    for(int i=0;i<560;i++)
       for(int j=0;j<720;j++)
       {
           a[i][j].red = Math.rand(0,255);
           a[i][j].blue = Math.rand(0,255);
           a[i][j].green = Math.rand(0,255);
           a[i][j].trans = Math.rand(0,255);
       }
}
void convert()
{
    int k=0;
    for(int i=0;i<560;i++)
       for(int j=0;j<720;j++)
       {
           red[k]=a[i][j].red;
           green[k]=a[i][j].green;
           blue[k]=a[i][j].blue;
           trans[k]=a[i][j].trans;
           k++;
       }
}
void compare()
{
    for(int i=0,j=0;i<size;i+=2,j++)
    {
        r[j] = red[i+1]-red[i];
        g[j] = green[i+1]-green[i];
        b[j] = blue[i+1]-blue[i];
        t[j] = trans[i+1]-trans[i];
    }
}
