#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////4////////////////////////////////////////////////////////////////////////////
int kw_rec(char lex[20]);
int id_rec(char lex[20]);
int sp_rec(char lex[20]);
int op_rec(char lex[20]);
int p_rec(char lex[20]);
int num_rec(char lex[20]);

bool check1();
char getNext();
void slash();
void asterisk();

void f1();
void f2();

bool insert_row();
void display1();

void line_number();

string name, var_func, d_type, g_l, rowNo, scope1, sym_table[50][5];
bool check, v_check = false, sp = false, ie = false, kw = false, m = false;
char c, lex[20];
int line_no = 1, p1Line[1000], p2Line[1000], p3Line[1000], pp1 = 0, pp2 = 0, pp3 = 0, i, j, s = 0, r = 1, error_count = 1,error_flag=0;
FILE *input, *output;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////2/////////////////////////////////////////////////////////////////////////////
bool keyword(char *arr);
bool op(char *arr);
bool sep(char *arr);
bool par(char *arr);
bool num(char *arr,int len);
bool id(char *arr,int len);
////////////////////////////////////////////////////////////////////
/////////////////////////////////////////3//////////////////////////
char a3[10000],b3[10000],temp3[10000],c3[1000][100];
int inde[10000];
int cur = 0;
struct data
{
    char * name;
    char * idType;
    char* dataType;
    char* scope;
    char* value;

}v[100];

void insert(int ind,char* _name, char* _id,char* _dat,char* _scope,char* _value)
{
    v[ind].name  =_name;
    v[ind].idType= _id;
    v[ind].dataType = _dat;
    v[ind].scope  =_scope;
    v[ind].value  =_value;
}

void display()
{
    int i=0;
    printf("\nSl. No.\t\tName\t\tId Type\t\tData Type\tScope\t\tValue\n");
    for(i=0;i<cur;i++)
    {
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",i+1,v[i].name,v[i].idType,v[i].dataType,v[i].scope,v[i].value);
    }
}



int search(char* _name,char* _id,char* _scope)
{
    int i=0;

    for(i=0;i<cur;i++)
    {
        if(strcmp(v[i].name,_name)==0 && strcmp(v[i].idType,_id)==0 && strcmp(v[i].scope,_scope)==0 )
        {
            return i;
        }
    }
    return -1;
}

char* modify(char * x)
{
    if(strlen(x)==0)
        return x;
    if(x[0]>='0' && x[0]<='9')
        return x;
    return "";
}

void update(int cur,char* val)
{
    v[cur].value  = val;
}


/*
int keyword(char *arr)
{
    if(strcmp("char", arr)==0||strcmp("int", arr)==0||strcmp("float", arr)==0||strcmp("string", arr)==0||strcmp("include", arr)==0
            ||strcmp("if", arr)==0||strcmp("else", arr)==0||strcmp("for", arr)==0||strcmp("while", arr)==0||strcmp("do", arr)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int op(char *arr)
{
    if(strcmp("=", arr)==0||strcmp("+", arr)==0||strcmp("-", arr)==0||strcmp("*", arr)==0||strcmp("/", arr)==0
            ||strcmp("<=", arr)==0||strcmp(">=", arr)==0||strcmp("<", arr)==0||strcmp(">", arr)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int sep(char *arr)
{
    if(strcmp(",", arr)==0||strcmp(";", arr)==0||strcmp("\'", arr)==0||strcmp("\"", arr)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int par(char *arr)
{
    //printf("%c",arr);
    if(strcmp("(", arr)==0||strcmp(")", arr)==0||strcmp("{", arr)==0||strcmp("}", arr)==0||strcmp("[", arr)==0||strcmp("]", arr)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int num(char *arr,int len)
{
    int flag=0;
    for(int i=0; i<len; i++)
    {
        if(isdigit(arr[i])!=0||arr[i]=='.')
        {
            continue;
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int id(char *arr,int len)
{
    int flag=0;
    if(arr[0]=='_'||isalpha(arr[0])!=0)
    {
        for(int i=1; i<len; i++)
        {
            if(isdigit(arr[i])!=0||isalpha(arr[i])!=0||arr[i]=='_')
                continue;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            return 0;
        }
        else
        {
            return 1;
        }

    }
    else
    {
        return 0;
    }

}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    FILE *input,*temp,*output;
    input=fopen("input1.c","r");
    temp=fopen("temp.txt","w");
    char c;
    cout<<"Original:"<<endl;
    while((c=fgetc(input))!=EOF)
    {
        cout<<c;
    }
    fclose(input);
    input=fopen("input1.c","r");
    if(!input)
        cout<<"File not found";
    else
    {
        while((c=fgetc(input))!=EOF)
        {
            if(c=='\n')
                fputc(' ',temp);
            else if(c=='"')
            {
                do
                {
                    fputc(c,temp);
                }
                while((c=fgetc(input))!='"');
                fputc(c,temp);
            }
            else if(c==' ')
            {
                while((c=fgetc(input))==' ');
                fputc(' ',temp);
                if(c!='/')
                    fputc(c,temp);
                else
                {
                    char c1;
                    c1=fgetc(input);
                    if(c1=='/')
                    {
                        while((c=fgetc(input))!='\n');
                    }
                    else if(c1=='*')
                    {
                        while((c=fgetc(input))!='*');
                        if((c=fgetc(input))=='/')
                            continue;
                    }
                    else
                    {
                        fputc('/',temp);
                        fputc(c1,temp);
                    }
                }
            }
            else if(c=='/')
            {
                char c1;
                c1=fgetc(input);
                if(c1=='/')
                {
                    while((c=fgetc(input))!='\n');
                }
                else if(c1=='*')
                {
                    while((c=fgetc(input))!='*');
                    if((c=fgetc(input))=='/')
                        continue;
                }
                else
                {
                    fputc('/',temp);
                    fputc(c1,temp);
                }
            }
            else
                fputc(c,temp);

        }
    }
    fclose(input);
    fclose(temp);
    temp=fopen("temp.txt","r");
    output=fopen("output.txt","w");
    while((c=fgetc(temp))!=EOF)
    {
        if(c==' ')
        {
            while((c=fgetc(temp))==' ');
            fputc(' ',output);
            if(c!='/')
                fputc(c,output);
            else
            {
                char c1;
                c1=fgetc(temp);
                if(c1=='/')
                {
                    while((c=fgetc(temp))!='\n');
                }
                else if(c1=='*')
                {
                    while((c=fgetc(temp))!='*');
                    if((c=fgetc(temp))=='/')
                        continue;
                }
                else
                {
                    fputc('/',output);
                    fputc(c1,output);
                }
            }
        }
        else
        {
            fputc(c,output);
        }
    }
    fclose(temp);
    fclose(output);
    output=fopen("output.txt","r");
    cout<<"\n\nAfter changes:\n";
    while((c=fgetc(output))!=EOF)
    {
        cout<<c;
    }
    fclose(output);
    cout<<endl;

    /////////////////////////////////////////////////////////     2     ////////////////////////////////////////////////
    FILE *p1,*p2,*p3,*p4;
    p1=fopen("output.txt","r");
    //char c;
    printf("Original:\n");
    while((c=fgetc(p1))!=EOF)
    {
        printf("%c",c);
    }
    fclose(p1);
    p1=fopen("output.txt","r");
    p2=fopen("temp.txt","w");
    while((c=fgetc(p1))!=EOF)
    {
        if(c==';'||c==','||c=='('||c==')'||c=='{'||c=='}'||c=='['||c==']'||c=='+'||c=='-'||c=='*'||c=='/')
        {
            fputc(' ',p2);
            fputc(c,p2);
            fputc(' ',p2);
        }
        else if(c=='\''||c=='\"')
        {
            fputc(' ',p2);
            fputc(c,p2);
            fputc(' ',p2);
        }
        else if(c=='=')
        {
            if((c=fgetc(p1))=='=')
            {
                fputc(' ',p2);
                fputc(c,p2);
                fputc(c,p2);
                fputc(' ',p2);
            }
            else
            {
                fputc(' ',p2);
                fputc('=',p2);
                fputc(' ',p2);
                if(c=='\''||c=='\"')
                {
                    fputc(c,p2);
                    fputc(' ',p2);
                }
                else
                    fputc(c,p2);
            }
        }
        else if(c=='!')
        {
            if((c=fgetc(p1))=='=')
            {
                fputc(' ',p2);
                fputc('!',p2);
                fputc(c,p2);
                fputc(' ',p2);
            }
        }
        else if(c=='<'||c=='>')
        {
            char prev=c;
            if((c=fgetc(p1))=='=')
            {
                fputc(' ',p2);
                fputc(prev,p2);
                fputc(c,p2);
                fputc(' ',p2);
            }
            else
            {
                fputc(' ',p2);
                fputc(prev,p2);
                fputc(' ',p2);
                fputc(c,p2);
            }
        }
        else
        {
            fputc(c,p2);
        }

    }
    fclose(p1);
    fclose(p2);
    p2=fopen("temp.txt","r");
    p3=fopen("temp2.txt","w");
    while((c=fgetc(p2))!=EOF)
    {
        if(c==' ')
        {
            while((c=fgetc(p2))==' ');
            fputc(' ',p3);
            fputc(c,p3);
        }
        else
            fputc(c,p3);
    }
    fclose(p2);
    fclose(p3);


    p3=fopen("temp2.txt","r");
    printf("\n\nAfter Step 1:\n");
    while((c=fgetc(p3))!=EOF)
    {
        printf("%c",c);
    }
    fclose(p3);

    p3=fopen("temp2.txt","r");
    p4=fopen("final.txt","w");
    char ar[100];
    int index=0;
    while((c=fgetc(p3))!=EOF)
    {
        ar[index++]=c;
        while((c=fgetc(p3))!=' ') // ekta word kina
        {
            ar[index++]=c;
        }
        ar[index]='\0'; //end of array

        fputc('[',p4);
        bool state=keyword(ar);
        if(!state)
        {
            state=op(ar);
            if(!state)
            {
                state=sep(ar);
                if(!state)
                {
                    state=par(ar);
                    if(!state)
                    {
                        state=num(ar,index);
                        if(!state)
                        {
                            state=id(ar,index);
                            if(!state)
                            {
                                fputs("unkn",p4);
                            }
                            else
                                fputs("id",p4);

                        }
                        else
                            fputs("num",p4);
                    }
                    else
                        fputs("par",p4);
                }
                else
                    fputs("sep",p4);
            }
            else
                fputs("op",p4);
        }
        else
            fputs("kw",p4);

        fputc(' ',p4);
        fputs(ar,p4);
        fputc(']',p4);
        index=0;
        memset(ar, 0, sizeof(ar));

    }
    fclose(p3);
    fclose(p4);
    p4=fopen("final.txt","r");
    printf("\n\nAfter Step 2:\n");
    while((c=fgetc(p4))!=EOF)
    {
        printf("%c",c);
    }
    fclose(p4);

    ////////////////////////////////////////////////////////////////           3            ////////////////////////////////////////////
    /*
    FILE *p0;//*p1,*p2,*p3,*p4;
    //char d;
    char t[9999];
    int i=0;
    int f = 0;
    p0=fopen("a1.txt","w");
    while(scanf("%c",&d))
    {
        if(d == '$')
        {
            break;
        }
        else{
            fputc(d,p0);
            t[i] = d;
            i++;
            f++;
        }

    }
    fclose(p0);
    char nt[9999];
    int b = 0;

    for(int i=0; i<f; i++) //remove all comments
    {
        if(t[i] == '/' && t[i+1] == '/')
        {
            while(t[i] != '\n')
            {
                i++;
            }
        }

        if(t[i] == '/' && t[i+1] == '*')
        {
            i=i+2;
            while(1)
            {
                if(t[i]=='*'&&t[i+1]=='/')
                {
                    break;
                }
                i++;
            }
            i=i+2;
        }
        nt[b]=t[i];
        b++;
    }

    char nt1[b];
    int cnt = 0;
    for(int i=0; i<b; i++) // remove all new lines
    {
        if(nt[i] != '\n')
        {
            nt1[cnt] = nt[i];
            cnt++;
        }

    }
    p1=fopen("a2.txt","w"); // aage nt1 array te value gula chilo..ogulo akhon txt file e rakhtesi
    int k=0;
    while(k<cnt)
    {
        fputc(nt1[k],p1);
        k++;
    }
    fclose(p1);

    p1=fopen("a2.txt","r");
    //char c;

    p1=fopen("a2.txt","r");
    p2=fopen("temp.txt","w");
    while((c=fgetc(p1))!=EOF)
    {
        if(c==';'||c==','||c=='('||c==')'||c=='{'||c=='}'||c=='['||c==']'||c=='+'||c=='-'||c=='*'||c=='/')
        {
            fputc(' ',p2);
            fputc(c,p2);
            fputc(' ',p2);
        }
        else if(c=='\''||c=='\"')
        {
            fputc(' ',p2);
            fputc(c,p2);
            fputc(' ',p2);
        }
        else if(c=='=')
        {
            if((c=fgetc(p1))=='=')
            {
                fputc(' ',p2);
                fputc(c,p2);
                fputc(c,p2);
                fputc(' ',p2);
            }
            else
            {
                fputc(' ',p2);
                fputc('=',p2);
                fputc(' ',p2);
                if(c=='\''||c=='\"')
                {
                    fputc(c,p2);
                    fputc(' ',p2);
                }
                else
                    fputc(c,p2);
            }
        }
        else if(c=='!')
        {
            if((c=fgetc(p1))=='=')
            {
                fputc(' ',p2);
                fputc('!',p2);
                fputc(c,p2);
                fputc(' ',p2);
            }
        }
        else if(c=='<'||c=='>')
        {
            char prev=c;
            if((c=fgetc(p1))=='=')
            {
                fputc(' ',p2);
                fputc(prev,p2);
                fputc(c,p2);
                fputc(' ',p2);
            }
            else
            {
                fputc(' ',p2);
                fputc(prev,p2);
                fputc(' ',p2);
                fputc(c,p2);
            }
        }
        else
        {
            fputc(c,p2);
        }

    }
    fclose(p1);
    fclose(p2);
    p2=fopen("temp.txt","r");
    p3=fopen("temp2.txt","w");
    while((c=fgetc(p2))!=EOF)
    {
        if(c==' ')
        {
            while((c=fgetc(p2))==' ');
            fputc(' ',p3);
            fputc(c,p3);
        }
        else
            fputc(c,p3);
    }
    fclose(p2);
    fclose(p3);



    p3=fopen("temp2.txt","r");
    p4=fopen("final.txt","w");
    char ar[100];
    int index=0;
    while((c=fgetc(p3))!=EOF)
    {
        ar[index++]=c;
        while((c=fgetc(p3))!=' ')
        {
            ar[index++]=c;
        }
        ar[index]='\0';

        fputc('[',p4);
        int state=keyword(ar);
        if(!state)
        {
            state=op(ar);
            if(!state)
            {
                state=sep(ar);
                if(!state)
                {
                    state=par(ar);
                    if(!state)
                    {
                        state=num(ar,index);
                        if(!state)
                        {
                            state=id(ar,index);
                            if(!state)
                            {
                                fputs("unkn",p4);
                            }
                            else
                                fputs("id",p4);

                        }
                        else
                            fputs("num",p4);
                    }
                    else
                        fputs("par",p4);
                }
                else
                    fputs("sep",p4);
            }
            else
                fputs("op",p4);
        }
        else
            fputs("kw",p4);

        fputc(' ',p4);
        fputs(ar,p4);
        fputc(']',p4);
        index=0;
        memset(ar, 0, sizeof(ar));

    }
    fclose(p3);
    fclose(p4);
    //p4=fopen("final.txt","r");

    */


    FILE* fp = fopen("final.txt","r");
    int i =0;
    while(fscanf(fp,"%c",&a3[i])!=EOF)
    {
        i++;
    }
    a3[i]  = '\0';
    fclose(fp);
    printf("Processed Input: \n");
    puts(a3);

    //s1
    int j;
    int k  =0;
    for(i=0;i<strlen(a3);i++)
    {
        if(a3[i]=='[')
        {
            b3[k++]  = a3[i++];
            j = 0;
            while(a3[i]!=' ')
            {
                temp3[j++]  = a3[i];
                i++;

            }
            temp3[j]  = '\0';
            if(strcmp(temp3,"id")==0)
            {
                b3[k++]  = 'i';
                b3[k++]  = 'd';
                b3[k++]  = ' ';
            }
            i++;
            while(a3[i]!=']')
            {
                b3[k++]  = a3[i];
                i++;

            }
            b3[k++] =  a3[i];

        }
    }
    b3[k]  = '\0';



    printf("\nStep 1: \n");
    puts(b3);
    fp = fopen("A3_O1.txt","w");
    fputs(b3,fp);
    fclose(fp);

    k = 0;
    for(i=0;i<strlen(b3);i++)
    {
        if(b3[i]=='[')
        {
            j= 0;
            i++;
            while(b3[i]!=']' && b3[i]!=' ')
            {
                c3[k][j++]  = b3[i++];
            }
            c3[k][j]  = '\0';
            k++;
            if(b3[i]==' ')
            {
                j= 0;
                i++;
                while(b3[i]!=']')
                {
                    c3[k][j++]  = b3[i++];
                }
                c3[k][j]  = '\0';
                k++;
            }

        }
    }
    printf("\nStep 2: \n");
    int it = 0;
    char * scope = "global";
    for(i=0;i<k;i++)
    {
        if(strcmp(c3[i],"id")==0)
        {
            if(strcmp(c3[i+2],"(")==0)
            {
                if(strcmp(c3[i-1],"int")==0 || strcmp(c3[i-1],"double")==0 || strcmp(c3[i-1],"float")==0 || strcmp(c3[i-1],"char")==0 )
                {
                    inde[it++]  = cur;
                    insert(cur++,c3[i+1],"func",c3[i-1],scope,"");
                    scope = c3[i+1];
                    i+= 2;
                }
                else
                {
                    int pq  = search(c3[i+1],"func","global");
                    if(pq!=-1)
                        inde[it++] = pq;
                    else //printf("\nID %s is not declared in global scope\n",c3[i+1]);
                    i+= 2;
                }
            }
            else if(strcmp(c3[i+2],"=")==0)
            {
                if(strcmp(c3[i-1],"int")==0 || strcmp(c3[i-1],"double")==0 || strcmp(c3[i-1],"float")==0 || strcmp(c3[i-1],"char")==0 )
                {
                    if(search(c3[i+1],"var",scope)==-1)
                    {
                        inde[it++]  = cur;
                        insert(cur++,c3[i+1],"var",c3[i-1],scope,modify(c3[i+3]));
                    }
                    else
                    {
                        //printf("\nID %s already declared in %s scope\n",c3[i+1],scope);
                    }
                }
                else
                {
                    int pq = search(c3[i+1],"var",scope);
                    if(pq==-1)
                    {
                        //printf("\nID %s is not declared in %s scope\n",c3[i+1],scope);
                    }
                    else
                    {
                        update(pq,modify(c3[i+3]));
                        inde[it++]  = pq;
                    }
                }
                i+=2;
            }
            else if(strcmp(c3[i+2],";")==0 || strcmp(c3[i+2],",")==0 || strcmp(c3[i+2],")")==0 )
            {
                if(strcmp(c3[i-1],"int")==0 || strcmp(c3[i-1],"double")==0 || strcmp(c3[i-1],"float")==0 || strcmp(c3[i-1],"char")==0 )
                {
                    if(search(c3[i+1],"var",scope)==-1)
                    {
                        inde[it++]  = cur;
                        insert(cur++,c3[i+1],"var",c3[i-1],scope,"");
                    }
                    else //printf("\nID %s already declared in %s scope\n",c3[i+1],scope);
                    i+= 2;
                }
                else
                {
                    if(search(c3[i+1],"var",scope)==-1)
                    {
                        //printf("\nID %s is not declared in %s scope\n",c3[i+1],scope);
                    }
                    else inde[it++]  = search(c3[i+1],"var",scope);
                    i+= 2;
                }
            }
        }
        else if(strcmp(c3[i],"}")==0)
        {
            scope = "global";
        }
    }
    display();
    printf("\nStep 4: \n");

    fp = fopen("A3_O2.txt","w");
    it =0;
    for(i=0;i<strlen(b3);i++)
    {
        if(b3[i]=='[')
        {
            printf("%c",b3[i]);
            fputc(b3[i],fp);
            i++;
            while(b3[i]!=']' && b3[i]!=' ')
            {
                printf("%c",b3[i]);
                fputc(b3[i],fp);
                i++;
            }
            if(b3[i]==' ')
            {
                printf("%c",b3[i]);
                fputc(b3[i],fp);
                j= 0;
                i++;
                while(b3[i]!=']')
                {
                    i++;
                }
                fputc(inde[it]+1+48,fp);
                printf("%d",inde[it++]+1);
            }
            printf("%c",b3[i]);
            fputc(b3[i],fp);

        }
        else
        {
            printf("%c",b3[i]);
        }
    }
    fclose(fp);

    ////////////////////////////////////////////////        4          //////////////////////////////////////////////////////////////////////

    f1();
    f2();

    input = fopen("scanned3.txt", "r");
    if(!input) {
        cout<<"File can't be opened!";
    } else {

        c = fgetc(input);
        line_number();
        while(c != EOF) {

            i = 0;

            while(c != ' ' && c != EOF && c != '\n') {
                lex[i] = c;
                i++;
                c = fgetc(input);
                line_number();
            }

            lex[i] = '\0';

            if (kw_rec(lex)) {

                sp = false;

                if(!strcmp(lex, "if")) {
                    ie = true;
                }
                if(!strcmp(lex, "else")) {
                    if(!ie) {
                        cout<<error_count<<". Unmatched 'else' at line "<<line_no<<endl<<endl;
                        error_count++;
                        error_flag = 1;
                    }
                    ie = false;
                }

                if(kw) {
                    cout<<error_count<<". Multiple data type declaration at line "<<line_no<<" for "<<"'"<<d_type<<"'"<<endl<<endl;
                    error_count++;
                    kw = false;
                    error_flag = 1;
                }

                if(!strcmp(lex, "int") || !strcmp(lex, "char") || !strcmp(lex, "float") || !strcmp(lex, "double")) {//do not insert 'if' as a scope
                    kw = true;//int x, x has a data type of int it's true
                    d_type = lex;
                } else {
                    d_type = "empty";
                }

            } else if(id_rec(lex)) {

                sp = false;

                name = lex;

                if(c == ' ') {
                    c = fgetc(input);
                    line_number();
                    if(c == '(' ) {
                        var_func = "func";
                        if(!v_check) {
                            scope1 = name;
                        }
                        g_l = "global";
                        v_check = true;
                    } else {
                        var_func = "var";
                        if(v_check) {
                            g_l = scope1;
                        } else {
                            g_l = "global";
                        }
                    }
                }

                if(kw) {
                    insert_row();
                    //kw = false;
                }

                continue;

            } else if(sp_rec(lex)) {

                kw = false;

                if(sp && lex[0] == ';') {

                    cout<<error_count<<". Multiple Statement Separator at line "<<line_no<<endl<<endl;
                    error_count++;
                    error_flag = 1;
                }

                if(lex[0] == ';') {
                    sp = true;
                }

            } else if(op_rec(lex)) {
                sp = false;
                kw = false;

            } else if(p_rec(lex)) {
                sp = false;
                kw = false;

                if(lex[0] == '(') {
                    p1Line[pp1] = line_no;
                    pp1++;

                } else if(lex[0] == '{') {
                    p2Line[pp2] = line_no;
                    pp2++;
                }
                if(lex[0] == '[') {
                    p3Line[pp3] = line_no;
                    pp3++;
                } else if(lex[0] == ')') {
                    pp1--;
                    if(pp1 < 0) {
                        cout<<error_count<<". Misplaced ')' at line "<<line_no<<endl<<endl;
                        error_count++;
                        pp1 = 0;
                        error_flag = 1;
                    }
                }
                if(lex[0] == '}') {
                    pp2--;
                    if(pp2 < 0) {
                        cout<<error_count<<". Misplaced '}' at line "<<line_no<<endl<<endl;
                        error_count++;
                        pp2 = 0;
                        error_flag = 1;
                    }
                } else if(lex[0] == ']') {
                    pp3--;
                    if(pp3 < 0) {
                        cout<<error_count<<". Misplaced ']' at line "<<line_no<<endl<<endl;
                        error_count++;
                        pp3 = 0;
                        error_flag = 1;
                    }
                }

            } else if(num_rec(lex)) {
                sp = false;
                kw = false;

            } else {
                sp = false;
                kw = false;
            }

            c = fgetc(input);
            line_number();
        }

        for(j = 0; j < pp1; j++) {
            cout<<error_count<<". Misplaced '(' at line "<<p1Line[j]<<endl<<endl;
            error_count++;
            error_flag = 1;
        }
        for(j = 0; j < pp2; j++) {
            cout<<error_count<<". Misplaced '{' at line "<<p2Line[j]<<endl<<endl;
            error_count++;
            error_flag = 1;
        }
        for(j = 0; j < pp3; j++) {
            cout<<error_count<<". Misplaced '[' at line "<<p3Line[j]<<endl<<endl;
            error_count++;
            error_flag = 1;
        }
    }


    fclose(input);

    cout<<endl<<endl;

    display1();

    cout<<endl<<endl;
    if(error_flag = 1)
        cout<<"Rejected by grammer"<<endl;
    else
        cout<<"Accepted by grammer"<<endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void line_number() {
    if(c == '\n') {
        line_no++;
    }
}

bool check1() {

    if(c == ' ') {
        m = true;
        getNext();
        check1();
    } else if(c == '/') {
        slash();
    } else if(c == EOF) {
        return false;
    } else {
        if(m) {
            fputc(' ', output);
        }

        fputc(c, output);
        m = false;
    }
}

void slash() {

    getNext();

    if(c == '/') {
        while(getNext() != '\n');
        getNext();
        check1();
    } else if(c == '*') {
        asterisk();
    } else {
        fputc('/', output);
        fputc(c, output);
    }
}

void asterisk() {

    while(getNext() != '*');

    getNext();

    if(c == '/') {
        getNext();
        check1();
    } else {
        asterisk();
    }
}

char getNext() {

    c = fgetc(input);
    return c;
}


void f1() {

    input = fopen("input1.c", "r");
    output = fopen("scanned1.txt", "w");
    if(!input) {
        printf("File can't be opened!");
    } else {
        while(getNext() != EOF) {
            check1();
        }
    }

    fclose(input);
    fclose(output);
}

void f2() {

    input = fopen("scanned1.txt", "r");
    output = fopen("scanned2.txt", "w");

    if(!input) {
        printf("\nFile can't be opened!");
    } else {
        while((c = fgetc(input)) != EOF) {
            if(!isalnum(c) && c != ' ' && c != '_' && c != '.') {
                fputc(' ', output);
            }
            fputc(c, output);
            if(c == '>' || c == '<'|| c == '=' || c == '!') {
                char ch;
                if((ch = fgetc(input)) == '=') {
                    fputc(ch, output);
                    if(!isalnum(ch) && ch != ' ' && ch != '_' && ch != '.') {
                        fputc(' ', output);
                    }
                } else {
                    fputc(' ', output);
                    fputc(ch, output);
                    if(!isalnum(ch) && ch != ' ' && ch != '_' && ch != '.') {
                        fputc(' ', output);
                    }
                }
            } else if(!isalnum(c) && c != ' ' && c != '_' && c != '.') {
                fputc(' ', output);
            }
        }
    }

    fclose(input);
    fclose(output);

    input = fopen("scanned2.txt", "r");
    output = fopen("scanned3.txt", "w");

    if(!input) {
        printf("\nFile can't be opened!");
    } else {
        while((c = fgetc(input)) != EOF) {
            if(c == ' '||c == '\t') {
                fputc(' ', output);
                while((c = fgetc(input)) == ' ');
                if(c != EOF) {
                    fputc(c, output);
                }
            } else {
                fputc(c, output);
            }
        }
    }

    fclose(input);
    fclose(output);
}

bool insert_row() {

    for(j = 0; j < s; j++) {    //1st iteration j,s=0, so loop doesn't execute

        if(!name.compare(sym_table[j][1])) {    //if names are same
            if(d_type.compare("empty") && !g_l.compare(sym_table[j][4])) {
                cout<<error_count<<". Multiple variable declaration at line "<<line_no<<" for "<<name<<endl<<endl;
                error_count++;
            }
            if(!g_l.compare(sym_table[j][4]) || !var_func.compare("func")) {    //if scopes are same(useful for var repeatation) or if they are function means trying to insert same function twice
                check = false;
                break;
            }
        } else if(d_type.compare("empty")) {
            check = true;
        }
    }
    if(check || sym_table[0][0] == "") {
        if(d_type != "") { // if we a var in the beginning of the program without data type then it should not be inserted, at first d_type will be empty so don;t insert
            ostringstream str1;
            str1<<r;
            rowNo = str1.str();
            sym_table[s][0] = rowNo;
            sym_table[s][1] = name;
            sym_table[s][2] = var_func;
            sym_table[s][3] = d_type;
            sym_table[s][4] = g_l;
            s++;
            r++;
            check = false;
            return true;
        }
    }
    return false;
}

void display1() {
    cout<<"\t\t\t  Symbol Table"<<endl<<"\t-------------------------------------------------"<<endl;
    cout<<"\tserial\tname\tvar/func\ttype\t   scope"<<endl<<endl;

    for(j = 0; j < s; j++) {
        cout<<"\t  "<<sym_table[j][0]<<"\t "<<sym_table[j][1]<<"\t  "<<sym_table[j][2]<<"\t\t"<<sym_table[j][3]<<"\t   "<<sym_table[j][4]<<endl;
    }
}

int kw_rec(char lex[20]) {

    if(!strcmp(lex, "int") || !strcmp(lex, "char") || !strcmp(lex, "float") || !strcmp(lex, "double") || !strcmp(lex, "void") || !strcmp(lex, "if") || !strcmp(lex, "else") || !strcmp(lex, "return")) {
        return 1;
    } else {
        return 0;
    }
}

int id_rec(char lex[20]) {

    int s = 0, i;

    if(isalpha(lex[0]) || lex[0] == '_') {

        s = 1;

        for(i = 1; i < strlen(lex); i++) {
            if(!isalnum(lex[i]) && lex[i] != '_') {
                s = 0;
                break;
            }
        }
    }

    return s;
}

int sp_rec(char lex[20]) {

    if(!strcmp(lex, ",") || !strcmp(lex, ";") || !strcmp(lex, "'")) {
        return 1;
    } else {
        return 0;
    }
}

int op_rec(char lex[20]) {

    if(!strcmp(lex, "+") || !strcmp(lex, "-") || !strcmp(lex, "*") ||!strcmp(lex, "/") || !strcmp(lex, "=") || !strcmp(lex, "<") || !strcmp(lex, ">") || !strcmp(lex, "<=") || !strcmp(lex, ">=") || !strcmp(lex, "!")) {
        return 1;
    } else {
        return 0;
    }
}

int p_rec(char lex[20]) {

    if(!strcmp(lex, "(") || !strcmp(lex, ")") || !strcmp(lex, "{") || !strcmp(lex, "[") || !strcmp(lex, "]")) {
        return 1;
    } else if(!strcmp(lex, "}")) {
        v_check = false;
        return 1;
    } else {
        return 0;
    }
}

int num_rec(char lex[20]) {

    int i = 0, l, s;

    if(isdigit(lex[i])) {
        s = 1;
        i++;
    } else if(lex[i] == '.') {
        s = 2;
        i++;
    } else {
        s = 0;
    }

    l = strlen(lex);

    if(s == 1) {
        for(; i < l; i++) {
            if(isdigit(lex[i])) {
                s = 1;
            } else if(lex[i] == '.') {
                s = 2;
                i++;
                break;
            } else {
                s = 0;
                break;
            }
        }
    }
    if(s == 2) {
        if(isdigit(lex[i])) {
            s = 3;
            i++;
        } else {
            s = 0;
        }
    }
    if(s == 3) {
        for(; i < l; i++) {
            if(isdigit(lex[i])) {
                s = 3;
            } else {
                s = 0;
                break;
            }
        }
    }

    if(s == 3) {
        s = 1;
    }

    return s;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool keyword(char *arr)
{
    if(strcmp("char", arr)==0||strcmp("int", arr)==0||strcmp("float", arr)==0||strcmp("string", arr)==0||strcmp("include", arr)==0
            ||strcmp("if", arr)==0||strcmp("else", arr)==0||strcmp("for", arr)==0||strcmp("while", arr)==0||strcmp("do", arr)==0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool op(char *arr)
{
    if(strcmp("=", arr)==0||strcmp("+", arr)==0||strcmp("-", arr)==0||strcmp("*", arr)==0||strcmp("/", arr)==0
            ||strcmp("<=", arr)==0||strcmp(">=", arr)==0||strcmp("<", arr)==0||strcmp(">", arr)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool sep(char *arr)
{
    if(strcmp(",", arr)==0||strcmp(";", arr)==0||strcmp("\'", arr)==0||strcmp("\"", arr)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool par(char *arr)
{
    if(strcmp("(", arr)==0||strcmp(")", arr)==0||strcmp("{", arr)==0||strcmp("}", arr)==0||strcmp("[", arr)==0||strcmp("]", arr)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool num(char *arr,int len)
{
    int flag=0;
    for(int i=0; i<len; i++)
    {
        if(isdigit(arr[i])!=0||arr[i]=='.')
            continue;
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool id(char *arr,int len)
{
    int flag=0;
    if(arr[0]=='_'||isalpha(arr[0])!=0)
    {
        for(int i=1; i<len; i++)
        {
            if(isdigit(arr[i])!=0||isalpha(arr[i])!=0||arr[i]=='_')
                continue;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            return false;
        }
        else
        {
            return true;
        }

    }
    else
    {
        return false;
    }

}
