#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define n 10
#define m 20
#define BOR '%'
#define LEFT 'a'
#define RIGHT 'd'
#define CR 'e'
#define CCR 'q'
#define THROW ' '
#define DOWN 's'
#define tetramino 'O'

char imcup [m+2][n+2];
char incup [m+2][n+2];
char cup [m+2][n+2];
char fig [7][4][4][4];
char numt,rot,ii,jj;
char nu,ro;
int beg,och=0,end;
int poi[8]={0, 100, 300, 700, 1500, 3100, 6300, 12700};
int endi[6][2]={{0, 1000}, {1000, 900}, {2000, 700}, {4000, 500}, {7000, 300}, {10000, 100}};

void initfigi() {     /* инициализация фигур */
    char i,j,x,y;
    for (x=0;x<7;x++)
        for (y=0;y<4;y++)
            for (i=0;i<4;i++)
                for (j=0;j<4;j++)
                    fig[x][y][i][j]=0;
    x=0;
    fig[x][0][0][0]=tetramino; fig[x][0][0][1]=tetramino; fig[x][0][0][2]=tetramino; fig[x][0][0][3]=tetramino;
    fig[x][1][0][1]=tetramino; fig[x][1][1][1]=tetramino; fig[x][1][2][1]=tetramino; fig[x][1][3][1]=tetramino;
    fig[x][2][0][0]=tetramino; fig[x][2][0][1]=tetramino; fig[x][2][0][2]=tetramino; fig[x][2][0][3]=tetramino;
    fig[x][3][0][1]=tetramino; fig[x][3][1][1]=tetramino; fig[x][3][2][1]=tetramino; fig[x][3][3][1]=tetramino;
    x=1;
    fig[x][0][0][1]=tetramino; fig[x][0][0][2]=tetramino; fig[x][0][1][1]=tetramino; fig[x][0][1][2]=tetramino;
    fig[x][1][0][1]=tetramino; fig[x][1][0][2]=tetramino; fig[x][1][1][1]=tetramino; fig[x][1][1][2]=tetramino;
    fig[x][2][0][1]=tetramino; fig[x][2][0][2]=tetramino; fig[x][2][1][1]=tetramino; fig[x][2][1][2]=tetramino;
    fig[x][3][0][1]=tetramino; fig[x][3][0][2]=tetramino; fig[x][3][1][1]=tetramino; fig[x][3][1][2]=tetramino;
    x=2;
    fig[x][0][0][1]=tetramino; fig[x][0][0][2]=tetramino; fig[x][0][1][2]=tetramino; fig[x][0][2][2]=tetramino;
    fig[x][1][0][2]=tetramino; fig[x][1][1][0]=tetramino; fig[x][1][1][1]=tetramino; fig[x][1][1][2]=tetramino;
    fig[x][2][0][1]=tetramino; fig[x][2][1][1]=tetramino; fig[x][2][2][1]=tetramino; fig[x][2][2][2]=tetramino;
    fig[x][3][0][0]=tetramino; fig[x][3][0][1]=tetramino; fig[x][3][0][2]=tetramino; fig[x][3][1][0]=tetramino;
    x=3;
    fig[x][0][0][1]=tetramino; fig[x][0][0][2]=tetramino; fig[x][0][1][1]=tetramino; fig[x][0][2][1]=tetramino;
    fig[x][1][0][0]=tetramino; fig[x][1][0][1]=tetramino; fig[x][1][0][2]=tetramino; fig[x][1][1][2]=tetramino;
    fig[x][2][0][2]=tetramino; fig[x][2][1][2]=tetramino; fig[x][2][2][1]=tetramino; fig[x][2][2][2]=tetramino;
    fig[x][3][0][0]=tetramino; fig[x][3][1][0]=tetramino; fig[x][3][1][1]=tetramino; fig[x][3][1][2]=tetramino;
    x=4;
    fig[x][0][0][0]=tetramino; fig[x][0][0][1]=tetramino; fig[x][0][0][2]=tetramino; fig[x][0][1][1]=tetramino;
    fig[x][1][0][2]=tetramino; fig[x][1][1][2]=tetramino; fig[x][1][1][1]=tetramino; fig[x][1][2][2]=tetramino;
    fig[x][2][0][1]=tetramino; fig[x][2][1][0]=tetramino; fig[x][2][1][1]=tetramino; fig[x][2][1][2]=tetramino;
    fig[x][3][0][1]=tetramino; fig[x][3][1][1]=tetramino; fig[x][3][1][2]=tetramino; fig[x][3][2][1]=tetramino;
    x=5;
    fig[x][0][0][2]=tetramino; fig[x][0][1][1]=tetramino; fig[x][0][1][2]=tetramino; fig[x][0][2][1]=tetramino;
    fig[x][1][0][0]=tetramino; fig[x][1][0][1]=tetramino; fig[x][1][1][1]=tetramino; fig[x][1][1][2]=tetramino;
    fig[x][2][0][2]=tetramino; fig[x][2][1][1]=tetramino; fig[x][2][1][2]=tetramino; fig[x][2][2][1]=tetramino;
    fig[x][3][0][0]=tetramino; fig[x][3][0][1]=tetramino; fig[x][3][1][1]=tetramino; fig[x][3][1][2]=tetramino;
    x=6;
    fig[x][0][0][1]=tetramino; fig[x][0][1][1]=tetramino; fig[x][0][1][2]=tetramino; fig[x][0][2][2]=tetramino;
    fig[x][1][0][1]=tetramino; fig[x][1][0][2]=tetramino; fig[x][1][1][0]=tetramino; fig[x][1][1][1]=tetramino;
    fig[x][2][0][1]=tetramino; fig[x][2][1][1]=tetramino; fig[x][2][1][2]=tetramino; fig[x][2][2][2]=tetramino;
    fig[x][3][0][1]=tetramino; fig[x][3][0][2]=tetramino; fig[x][3][1][0]=tetramino; fig[x][3][1][1]=tetramino;
}

void draw() {     /* отрисовка */
    int i,j;
    for (i=0;i<m+2;i++)
        for (j=0;j<n+2;j++) {
            imcup[i][j]=cup[i][j];
            if (!imcup[i][j]) imcup[i][j]=' ';
        }
    for (i=0;i<4 && i+ii<m+1;i++)
        for (j=0;j<4;j++)
            if ((j+jj>0) && (j+jj<n+1) && (fig[numt][rot][i][j]!=0))
            imcup[ii+i][jj+j]=fig[numt][rot][i][j];
    system("cls");
    for (i=1;i<m+2;i++)
    {
        for (j=0;j<n+2;j++)
            printf("%c",imcup[i][j]);
        printf("\n");
    }
    printf("\n%c%c%c%c%c%c   %d\n",BOR,BOR,BOR,BOR,BOR,BOR,och);
    for (i=0;i<4;i++)
    {
        printf("%c",BOR);
        for (j=0;j<4;j++)
            printf("%c", fig[nu][ro][i][j]==0?' ':fig[nu][ro][i][j] );
        printf("%c\n",BOR);
    }
    printf("%c%c%c%c%c%c\n",BOR,BOR,BOR,BOR,BOR,BOR);
}

void drawn() {     /* отрисовка */
    int i,j;
    for (i=0;i<m+2;i++)
        for (j=0;j<n+2;j++) {
            imcup[i][j]=cup[i][j];
            if (!imcup[i][j]) imcup[i][j]=' ';
        }
    for (i=0;i<m+2;i++)
        for (j=0;j<n+2;j++)
            if (incup[i][j])
                imcup[i][j]=incup[i][j];
    system("cls");
    for (i=1;i<m+2;i++)
    {
        for (j=0;j<n+2;j++)
            printf("%c",imcup[i][j]);
        printf("\n");
    }
    printf("\n%c%c%c%c%c%c   %d\n",BOR,BOR,BOR,BOR,BOR,BOR,och);
    for (i=0;i<4;i++)
    {
        printf("%c",BOR);
        for (j=0;j<4;j++)
            printf("%c", fig[nu][ro][i][j]==0?' ':fig[nu][ro][i][j] );
        printf("%c\n",BOR);
    }
    printf("%c%c%c%c%c%c\n",BOR,BOR,BOR,BOR,BOR,BOR);
}

void dele(int i, int j) {     /* помощь sbrosim */
    incup[i][j]=0;
    if ((incup[i-1][j]!=0) && (incup[i-1][j]!=BOR)) dele(i-1,j);
    if ((incup[i+1][j]!=0) && (incup[i+1][j]!=BOR)) dele(i+1,j);
    if ((incup[i][j-1]!=0) && (incup[i][j-1]!=BOR)) dele(i,j-1);
    if ((incup[i][j+1]!=0) && (incup[i][j+1]!=BOR)) dele(i,j+1);
}

void sbrosim(int str) {     /* падение блоков */
    int i,j,k=1;
    for (i=0;i<m+2;i++)
        for (j=0;j<n+2;j++)
            incup[i][j]=cup[i][j];
    for (j=1;j<n+1;j++)
        if (incup[m][j])
            dele(m,j);
    if (str==1)
        for (i=0;i<4 && i+ii<m+1;i++)
            for (j=0;j<4;j++)
                if ((j+jj>0) && (j+jj<n+1) && (fig[numt][rot][i][j]!=0))
                    incup[ii+i][jj+j]=fig[numt][rot][i][j];
    for (i=1;i<m+1;i++)
        for (j=1;j<n+1;j++)
            if (incup[i][j])
                k=0;
    if (k==0)
    {
        while (k==0)
        {
            drawn();
            Sleep(500);
            for (i=1;i<m+1;i++)
                for (j=1;j<n+1;j++)
                    if (incup[i][j])
                        cup[i][j]=0;
            for (i=m;i>0;i--)
                for (j=1;j<n+1;j++)
                    incup[i+1][j]=incup[i][j];
            for (j=1;j<n+1;j++)
                incup[1][j]=0;
            for (i=1;i<=m+1;i++)
                for (j=1;j<n+1;j++)
                    if (cup[i][j] && incup[i][j] && incup[i][j]!=BOR)
                        k++;
        }
        for (i=1;i<m+1;i++)
            for (j=1;j<n+1;j++)
                incup[i][j]=incup[i+1][j];
        for (j=1;j<n+1;j++)
            incup[m+1][j]=0;
        for (i=0;i<m+2;i++)
            for (j=0;j<n+2;j++)
                if (incup[i][j])
                    cup[i][j]=incup[i][j];
        draw();
        sbrosim(0);
    }
}

char pus (int i) {  // строка заполнена == 1
    int j,k=1;
    for (j=1;j<n+1;j++)
        if (cup[i][j]==0)
          k=0;
    return k;
}

char stroki() { /* чистка строк */ // строку почистили == 1
    int i,j,k=0;
    for (i=m;i>0;i--)
        if (pus(i)!=0)
        {
            for (j=1;j<n+1;j++)
                cup[i][j]=0;
            k++;
        }
    return k;
}

char vmeste() { // пересекаются == 1
    int i,j,k=0;
    for (i=0;i<4 && i+ii<m+2;i++)
        for (j=0;j<4;j++)
            if ((j+jj>=0) && (j+jj<=n+1) && (fig[numt][rot][i][j] && cup[i+ii][j+jj]))
                k=1;
    return k;
}

int main() {
    int i,j;
    char c;
    initfigi();
    for (i=0; i<m+2; i++)
        for (j=0; j<n+2; j++)
            cup[i][j]=0;
    for (i=0; i<m+2; i++) {
        cup[i][0]=BOR;
        cup[i][n+1]=BOR;
    }
    for (j=0; j<n+2; j++) {
        cup[0][j]=BOR;
        cup[m+1][j]=BOR;
    }
    srand(time(NULL));
    rot=rand()%4;
    numt=rand()%7;
    ro=rand()%4;
    nu=rand()%7;
    ii=1;
    jj=n/2-1;
    while (1) {
        c=0;
        while ( (c<6) && (och>=endi[c][0]) ) c++;
        end=endi[c][1];

        beg=clock();
        while (clock()-beg<end) {
            if (kbhit()) {
                c=getch();
                if (c==RIGHT) {
                    if (jj>n) {
                        printf("loser program :  jj>n");
                        Sleep(5000);
                        exit(1);
                    }
                    jj++;
                    if (vmeste())
                        jj--;
                }
                if (c==LEFT) {
                    if (jj<-3) {
                        printf("loser program : jj<-3");
                        Sleep(1000);
                        exit(2);
                    }
                    jj--;
                    if (vmeste())
                        jj++;
                }
                if (c==CR) {
                    rot=(rot+1)%4;
                    if (vmeste())
                        rot=(rot+3)%4;
                }
                if (c==CCR) {
                    rot=(rot+3)%4;
                    if (vmeste())
                        rot=(rot+1)%4;
                }
                if (c==THROW) {
                    sbrosim(1);
                    goto novy;
                }
                if (c==DOWN)
                    goto dow;
                draw();
            }
        }
dow:
        ii++;
        if (vmeste()==1) {
            ii--;
            for (i=0;i<4 && i+ii<m+1;i++)
                for (j=0;j<4;j++)
                    if (fig[numt][rot][i][j]!=0 && j+jj>0 && j+jj<n+1)
                        cup[ii+i][jj+j]=fig[numt][rot][i][j];
novy:
            draw();
            c=stroki();
            while (c!=0) {
                och+=poi[c];
                sbrosim(0);
                c=stroki();
            }
            rot=ro;
            numt=nu;
            ro=rand()%4;
            nu=rand()%7;
            ii=1;
            jj=n/2-2;
            draw();
            if (vmeste()==1) {
                printf("GAME OVER");
                break;
            }
        }
        else
            draw();
    }
    return 0;
}
