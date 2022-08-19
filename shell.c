#include "types.h"
#include "user.h"
#include "fcntl.h"
#define charr 100


int
getcmd(char line[],char *args[])
{
    printf(2, "MyShell>");

    int p=0;
    gets(line,charr);
    //printf(2,"%s",line);
    for(int i=0;i<30;i++)
    {
        args[i]='\0';
    }
    int ip=0,op=0;
    if( line[0] == 'e'&&line[1]=='x'&&line[2]=='i'&&line[3]=='t')
      {
          exit(0);
      }
      
    int lenn;
    lenn=strlen(line);
    int c=0;
    //char line1[charr];
    int flag=0;
    while(c<lenn)
    {
        if(line[c]==' ' && (line[c+1]==' ' || line[c-1]==' '))
        {
            for(int e=c;e<lenn;e++)
            {
                line[e]=line[e+1];
                
            }
            lenn--;
        }
        else
        {
            c++;
        }
    }

    int g=0;
    while (line[g] != '\n')
    {
        g++;
    }
    line[g]='\0';
    
    int x=0;
    int y=0;
    int loop=0;
    int len=strlen(line);
    //printf(2,"%d",len);
    for(int i=0;i<len;i++)
    {

        if(line[i]=='|' && line[i+1]!='|' && line[i-1]!='|')
        {
            char args2[30][30];
            int pipefd[2];
           //int error=0;


            char argsss[30][30];
            char argssss[30][30];
            char *args[30];
            char *left[20];
            char *right[20];
            memset(left,0,sizeof(left));
            memset(right,0,sizeof(right));
            memset(args,0,sizeof(args));
            
            memset(args2,0,sizeof(args2));
            memset(argsss,0,sizeof(argsss));
            memset(argssss,0,sizeof(argssss));
            int loop1=0;
                
            int p1=0,x1=0,y1=0;

            //printf(2,"in breakbypipe");
            //printf(2,"%s",line);
            for(int i=0;i<strlen(line);i++)
            {
                //printf(2,"in for loop");
                if(!(line[i]=='|'))
                {
                    args2[x1][y1]=line[i];
                    y1++;
                }
                else
                {
                    args2[x1][y1]='\0';
                    args[p1]=args2[x1];
                    p1++;
                    x1++;
                    y1=0;
                    
                }
                
            }
            args2[x1][y1]='\0';
            args[p1]=args2[x1];
            //printf(2,"%d",p1);
            /*printf(2,"outside for loop");
            printf(2,"before %s",args[0]);
            printf(2,"before %s",args[1]);

            printf(2,"otuside");*/
            int i,j;

            for(int lennn=0;lennn<=p1;lennn++)
            {
                for(i=0;args[lennn][i]==' '||args[lennn][i]=='\t';i++);
                
                for(j=0;args[lennn][i];i++)
                {
                        args[lennn][j++]=args[lennn][i];
                }
                args[lennn][j]='\0';
                for(i=0;args[lennn][i]!='\0';i++)
                {
                        if(args[lennn][i]!=' ' && args[lennn][i]!='\t')
                        {
                            j=i;
                        }
                }
                args[lennn][j+1]='\0';


                //printf(2,"after%s",args[lennn]);
            }
            x1=0;
            y1=0;
            p1=0;
            //printf(2,"args[0] value %s",args[0]);
            for(int i=0;i<strlen(args[0]);i++)
            {
                //printf(2,"in space for loop");
                if(!(args[0][i]==' '))
                {
                    argsss[x1][y1]=args[0][i];
                    //printf(2,"%s \n",argss[x]);
                    y1++;
                }
                else
                {
                    argsss[x1][y1]='\0';
                    left[p1]=argsss[x1];
                    p1++;
                    x1++;
                    y1=0;
                    
                }
                
            }
            argsss[x1][y1]='\0';
            left[p1]=argsss[x1];
            char d[20];
            char e[20];
            memset(d,0,sizeof(d));
            memset(e,0,sizeof(e));
         for(int i=0;i<=p1;i++)
            {
            


            if(*left[i]=='<')
            {
                //printf(2,"index:%d",i);
                //printf(2,"hellllloooooo");
                for(int j=0;j<strlen(left[i+1]);j++)
                {
                    d[j]=left[i+1][j];   
                    //printf(2,"%c value:\n",d[j]);
                }

                for(int i=0;i<=p1;i++)
                {
                    
                    if(*left[i]=='>')
                    {
                        //printf(2,"index:%d",i);
                        
                        //printf(2,"hellllloooooo");
                        for(int j=0;j<strlen(left[i+1]);j++)
                        {
                            e[j]=left[i+1][j];   
                            //printf(2,"%c value:\n",e[j]);
                        }
                        left[i]='\0';
                        left[i+1]='\0';
                        op=1;
                        loop1=1;
                    }
                }
                left[i]='\0';
                left[i+1]='\0';
                ip=1;
            }
        }

        if(loop1==0)
        {

        
        for(int i=0;i<=p1;i++)
        {
            
            if(*left[i]=='>')
            {
                //printf(2,"index:%d",i);
                
                //printf(2,"hellllloooooo");
                for(int j=0;j<strlen(left[i+1]);j++)
                {
                    e[j]=left[i+1][j];   
                    printf(2,"%c value:\n",e[j]);
                }
                left[i]='\0';
                left[i+1]='\0';
                op=1;
            }
        }
        
        }
        

        x1=0,y1=0,p1=0;

            for(int i=0;i<strlen(args[1]);i++)
            {
                //printf(2,"in space for loop\n");
                if(!(args[1][i]==' '))
                {
                    argssss[x1][y1]=args[1][i];
                    y1++;
                }
                else
                {
                    argssss[x1][y1]='\0';
                    right[p1]=argssss[x1];
                    p1++;
                    x1++;
                    y1=0;
                    
                }
                
            }
            argssss[x1][y1]='\0';
            right[p1]=argssss[x1];


            char f[20];
            char g[20];
            memset(f,0,sizeof(f));
            memset(g,0,sizeof(g));
            int ip1=0,op1=0,loop2=0;
         for(int i=0;i<=p1;i++)
            {
            


            if(*right[i]=='<')
            {
                //printf(2,"index:%d",i);
                //printf(2,"hellllloooooo");
                for(int j=0;j<strlen(right[i+1]);j++)
                {
                    f[j]=right[i+1][j];   
                    //printf(2,"%c value:\n",f[j]);
                }

                for(int i=0;i<=p1;i++)
                {
                    
                    if(*right[i]=='>')
                    {
                        //printf(2,"index:%d",i);
                        
                        //printf(2,"hellllloooooo");
                        for(int j=0;j<strlen(right[i+1]);j++)
                        {
                            g[j]=right[i+1][j];   
                            //printf(2,"%c value:\n",g[j]);
                        }
                        right[i]='\0';
                        right[i+1]='\0';
                        op1=1;
                        loop2=1;
                    }
                }
                right[i]='\0';
                right[i+1]='\0';
                ip1=1;
            }
        }

        if(loop2==0)
        {

        
        for(int i=0;i<=p1;i++)
        {
            
            if(*right[i]=='>')
            {
                //printf(2,"index:%d",i);
                
                //printf(2,"hellllloooooo");
                for(int j=0;j<strlen(right[i+1]);j++)
                {
                    g[j]=right[i+1][j];   
                    //printf(2,"%c value:\n",g[j]);
                }
                right[i]='\0';
                right[i+1]='\0';
                op1=1;
            }
        }
        
        }



            


            /*printf(2,"outside for loop");
            printf(2,"before %s\t",left[0]);
            printf(2,"before %s \n",left[1]);
            printf(2,"before %s",right[0]);
            printf(2,"before %s",right[1]);*/



            if(pipe(pipefd) < 0)
      printf(2,"pipe fail");

    if(fork()==0)
    {
        close(1);

       dup(pipefd[1]);

       close(pipefd[0]);

       close(pipefd[1]);

       if(ip)
        {

        
        close(0);

        if(open(d, O_RDONLY) < 0){
        printf(2, "open %s failed\n", d);
        exit(0);
        }
        }

        if(op)
        {

        
        close(1);

        if(open(e, O_WRONLY|O_CREATE) < 0){
        printf(2, "open %s failed\n", e);
        exit(0);
        }
        }

       exec(left[0],left);
       exit(0);
        
    }
    if(fork()==0)
    {
        close(0);
        dup(pipefd[0]);
        close(pipefd[0]);
        close(pipefd[1]);

        if(ip1)
        {

        
        close(0);

        if(open(f, O_RDONLY) < 0){
        printf(2, "open %s failed\n", f);
        exit(0);
        }
        }

        if(op1)
        {

        
        close(1);

        if(open(g, O_WRONLY|O_CREATE) < 0){
        printf(2, "open %s failed\n", g);
        exit(0);
        }
        }



        exec(right[0],right);
        exit(0);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    wait(0);
    wait(0);




            /*left[0]='\0';
            right[1]='\0';
            left[0]='\0';
            right[1]='\0';*/
            flag=1;
            
        }

        if(line[i]==';')
        {

            char args2[30][30];


            char argsss[30][30];
            char argssss[30][30];
            char *args[30];
            char *left[20];
            char *right[20];
            memset(left,0,sizeof(left));
            memset(right,0,sizeof(right));
            memset(args,0,sizeof(args));
            
            memset(args2,0,sizeof(args2));
            memset(argsss,0,sizeof(argsss));
            memset(argssss,0,sizeof(argssss));
            int loop1=0;
                
            int p1=0,x1=0,y1=0;

            //printf(2,"in breakbypipe");
            //printf(2,"%s",line);
            for(int i=0;i<strlen(line);i++)
            {
                //printf(2,"in for loop");
                if(!(line[i]==';'))
                {
                    args2[x1][y1]=line[i];
                    y1++;
                }
                else
                {
                    args2[x1][y1]='\0';
                    args[p1]=args2[x1];
                    p1++;
                    x1++;
                    y1=0;
                    
                }
                
            }
            args2[x1][y1]='\0';
            args[p1]=args2[x1];
            //printf(2,"%d",p1);
            /*printf(2,"outside for loop");
            printf(2,"before %s",args[0]);
            printf(2,"before %s",args[1]);

            printf(2,"otuside");*/
            int i,j;

            for(int lennn=0;lennn<=p1;lennn++)
            {
                for(i=0;args[lennn][i]==' '||args[lennn][i]=='\t';i++);
                
                for(j=0;args[lennn][i];i++)
                {
                        args[lennn][j++]=args[lennn][i];
                }
                args[lennn][j]='\0';
                for(i=0;args[lennn][i]!='\0';i++)
                {
                        if(args[lennn][i]!=' ' && args[lennn][i]!='\t')
                        {
                            j=i;
                        }
                }
                args[lennn][j+1]='\0';


                //printf(2,"after%s",args[lennn]);
            }
            x1=0;
            y1=0;
            p1=0;
            //printf(2,"args[0] value %s",args[0]);
            for(int i=0;i<strlen(args[0]);i++)
            {
                //printf(2,"in space for loop");
                if(!(args[0][i]==' '))
                {
                    argsss[x1][y1]=args[0][i];
                    //printf(2,"%s \n",argss[x]);
                    y1++;
                }
                else
                {
                    argsss[x1][y1]='\0';
                    left[p1]=argsss[x1];
                    p1++;
                    x1++;
                    y1=0;
                    
                }
                
            }
            argsss[x1][y1]='\0';
            left[p1]=argsss[x1];
            char d[20];
            char e[20];
            memset(d,0,sizeof(d));
            memset(e,0,sizeof(e));
         
            for(int i=0;i<=p1;i++)
                {
                


                if(*left[i]=='<')
                {
                    //printf(2,"index:%d",i);
                    //printf(2,"hellllloooooo");
                    for(int j=0;j<strlen(left[i+1]);j++)
                    {
                        d[j]=left[i+1][j];   
                        //printf(2,"%c value:\n",d[j]);
                    }

                    for(int i=0;i<=p1;i++)
                    {
                        
                        if(*left[i]=='>')
                        {
                            //printf(2,"index:%d",i);
                            
                            //printf(2,"hellllloooooo");
                            for(int j=0;j<strlen(left[i+1]);j++)
                            {
                                e[j]=left[i+1][j];   
                                //printf(2,"%c value:\n",e[j]);
                            }
                            left[i]='\0';
                            left[i+1]='\0';
                            op=1;
                            loop1=1;
                        }
                    }
                    left[i]='\0';
                    left[i+1]='\0';
                    ip=1;
                }
            }

            if(loop1==0)
            {

            
            for(int i=0;i<=p1;i++)
            {
                
                if(*left[i]=='>')
                {
                    //printf(2,"index:%d",i);
                    
                    //printf(2,"hellllloooooo");
                    for(int j=0;j<strlen(left[i+1]);j++)
                    {
                        e[j]=left[i+1][j];   
                        //printf(2,"%c value:\n",e[j]);
                    }
                    left[i]='\0';
                    left[i+1]='\0';
                    op=1;
                }
            }
            
            }
        

        x1=0,y1=0,p1=0;

            for(int i=0;i<strlen(args[1]);i++)
            {
                //printf(2,"in space for loop\n");
                if(!(args[1][i]==' '))
                {
                    argssss[x1][y1]=args[1][i];
                    y1++;
                }
                else
                {
                    argssss[x1][y1]='\0';
                    right[p1]=argssss[x1];
                    p1++;
                    x1++;
                    y1=0;
                    
                }
                
            }
            argssss[x1][y1]='\0';
            right[p1]=argssss[x1];


            char f[20];
            char g[20];
            memset(f,0,sizeof(f));
            memset(g,0,sizeof(g));
         
            int ip1=0,op1=0,loop2=0;
         for(int i=0;i<=p1;i++)
            {
            


            if(*right[i]=='<')
            {
                //printf(2,"index:%d",i);
                //printf(2,"hellllloooooo");
                for(int j=0;j<strlen(right[i+1]);j++)
                {
                    f[j]=right[i+1][j];   
                    //printf(2,"%c value:\n",f[j]);
                }

                for(int i=0;i<=p1;i++)
                {
                    
                    if(*right[i]=='>')
                    {
                        //printf(2,"index:%d",i);
                        
                        //printf(2,"hellllloooooo");
                        for(int j=0;j<strlen(right[i+1]);j++)
                        {
                            g[j]=right[i+1][j];   
                            //printf(2,"%c value:\n",g[j]);
                        }
                        right[i]='\0';
                        right[i+1]='\0';
                        op1=1;
                        loop2=1;
                    }
                }
                right[i]='\0';
                right[i+1]='\0';
                ip1=1;
            }
        }

        if(loop2==0)
        {

        
        for(int i=0;i<=p1;i++)
        {
            
            if(*right[i]=='>')
            {
                //printf(2,"index:%d",i);
                
                //printf(2,"hellllloooooo");
                for(int j=0;j<strlen(right[i+1]);j++)
                {
                    g[j]=right[i+1][j];   
                    //printf(2,"%c value:\n",g[j]);
                }
                right[i]='\0';
                right[i+1]='\0';
                op1=1;
            }
        }
        
        }



            


    /*printf(2,"outside for loop");
    printf(2,"before %s\t",left[0]);
    printf(2,"before %s \n",left[1]);
    printf(2,"before %s",right[0]);
    printf(2,"before %s",right[1]);*/



           
    if(fork()==0)
    {
       
       if(ip)
        {

        
        close(0);

        if(open(d, O_RDONLY) < 0){
        printf(2, "open %s failed\n", d);
        exit(0);
        }
        }

        if(op)
        {

        
        close(1);

        if(open(e, O_WRONLY|O_CREATE) < 0){
        printf(2, "open %s failed\n", e);
        exit(0);
        }
        }

       exec(left[0],left);
       exit(0);
        
    }
    if(fork()==0)
    {
    
        if(ip1)
        {

        
        close(0);

        if(open(f, O_RDONLY) < 0){
        printf(2, "open %s failed\n", f);
        exit(0);
        }
        }

        if(op1)
        {

        
        close(1);

        if(open(g, O_WRONLY|O_CREATE) < 0){
        printf(2, "open %s failed\n", g);
        exit(0);
        }
        }



        exec(right[0],right);
        exit(0);
    }
    wait(0);
    wait(0);




            /*left[0]='\0';
            right[1]='\0';
            left[0]='\0';
            right[1]='\0';*/
            flag=1;
        }


        if(line[i]=='&' && line[i+1]=='&')
        {

            char args2[30][30];


            char argsss[30][30];
            char argssss[30][30];
            char *args[30];
            char *left[20];
            char *right[20];
            memset(left,0,sizeof(left));
            memset(right,0,sizeof(right));
            memset(args,0,sizeof(args));
            
            memset(args2,0,sizeof(args2));
            memset(argsss,0,sizeof(argsss));
            memset(argssss,0,sizeof(argssss));
            int loop1=0;
                
            int p1=0,x1=0,y1=0;

            //printf(2,"in breakbypipe");
            //printf(2,"%s",line);
            for(int i=0;i<strlen(line);i++)
            {
                //printf(2,"in for loop");
                if((line[i]=='&') && (line[i+1]=='&'))
                {

                    args2[x1][y1]='\0';
                    args[p1]=args2[x1];
                    p1++;
                    x1++;
                    i++;
                    y1=0;
                    
                }
                else
                {
                    
                    args2[x1][y1]=line[i];
                    y1++;
               
                }
                
            }
            args2[x1][y1]='\0';
            args[p1]=args2[x1];
            /*printf(2,"%d",p1);
            printf(2,"outside for loop");
            printf(2,"before %s",args[0]);
            printf(2,"before %s",args[1]);

            printf(2,"otuside");*/
            int i,j;

            for(int lennn=0;lennn<=p1;lennn++)
            {
                for(i=0;args[lennn][i]==' '||args[lennn][i]=='\t';i++);
                
                for(j=0;args[lennn][i];i++)
                {
                        args[lennn][j++]=args[lennn][i];
                }
                args[lennn][j]='\0';
                for(i=0;args[lennn][i]!='\0';i++)
                {
                        if(args[lennn][i]!=' ' && args[lennn][i]!='\t')
                        {
                            j=i;
                        }
                }
                args[lennn][j+1]='\0';


                //printf(2,"after%s",args[lennn]);
            }
            x1=0;
            y1=0;
            p1=0;
            //printf(2,"args[0] value %s",args[0]);
            for(int i=0;i<strlen(args[0]);i++)
            {
                //printf(2,"in space for loop");
                if(!(args[0][i]==' '))
                {
                    argsss[x1][y1]=args[0][i];
                    //printf(2,"%s \n",argss[x]);
                    y1++;
                }
                else
                {
                    argsss[x1][y1]='\0';
                    left[p1]=argsss[x1];
                    p1++;
                    x1++;
                    y1=0;
                    
                }
                
            }
            argsss[x1][y1]='\0';
            left[p1]=argsss[x1];
            char d[20];
            char e[20];
            memset(d,0,sizeof(d));
            memset(e,0,sizeof(e));
         
            for(int i=0;i<=p1;i++)
                {
                


                if(*left[i]=='<')
                {
                    //printf(2,"index:%d",i);
                    //printf(2,"hellllloooooo");
                    for(int j=0;j<strlen(left[i+1]);j++)
                    {
                        d[j]=left[i+1][j];   
                        //printf(2,"%c value:\n",d[j]);
                    }

                    for(int i=0;i<=p1;i++)
                    {
                        
                        if(*left[i]=='>')
                        {
                            //printf(2,"index:%d",i);
                            
                            //printf(2,"hellllloooooo");
                            for(int j=0;j<strlen(left[i+1]);j++)
                            {
                                e[j]=left[i+1][j];   
                                //printf(2,"%c value:\n",e[j]);
                            }
                            left[i]='\0';
                            left[i+1]='\0';
                            op=1;
                            loop1=1;
                        }
                    }
                    left[i]='\0';
                    left[i+1]='\0';
                    ip=1;
                }
            }

            if(loop1==0)
            {

            
            for(int i=0;i<=p1;i++)
            {
                
                if(*left[i]=='>')
                {
                    //printf(2,"index:%d",i);
                    
                    //printf(2,"hellllloooooo");
                    for(int j=0;j<strlen(left[i+1]);j++)
                    {
                        e[j]=left[i+1][j];   
                        //printf(2,"%c value:\n",e[j]);
                    }
                    left[i]='\0';
                    left[i+1]='\0';
                    op=1;
                }
            }
            
            }
        

        x1=0,y1=0,p1=0;

            for(int i=0;i<strlen(args[1]);i++)
            {
                //printf(2,"in space for loop\n");
                if(!(args[1][i]==' '))
                {
                    argssss[x1][y1]=args[1][i];
                    y1++;
                }
                else
                {
                    argssss[x1][y1]='\0';
                    right[p1]=argssss[x1];
                    p1++;
                    x1++;
                    y1=0;
                    
                }
                
            }
            argssss[x1][y1]='\0';
            right[p1]=argssss[x1];


            char f[20];
            char g[20];
            memset(f,0,sizeof(f));
            memset(g,0,sizeof(g));
         
            int ip1=0,op1=0,loop2=0;
         for(int i=0;i<=p1;i++)
            {
            


            if(*right[i]=='<')
            {
                //printf(2,"index:%d",i);
                //printf(2,"hellllloooooo");
                for(int j=0;j<strlen(right[i+1]);j++)
                {
                    f[j]=right[i+1][j];   
                    //printf(2,"%c value:\n",f[j]);
                }

                for(int i=0;i<=p1;i++)
                {
                    
                    if(*right[i]=='>')
                    {
                        //printf(2,"index:%d",i);
                        
                        //printf(2,"hellllloooooo");
                        for(int j=0;j<strlen(right[i+1]);j++)
                        {
                            g[j]=right[i+1][j];   
                            //printf(2,"%c value:\n",g[j]);
                        }
                        right[i]='\0';
                        right[i+1]='\0';
                        op1=1;
                        loop2=1;
                    }
                }
                right[i]='\0';
                right[i+1]='\0';
                ip1=1;
            }
        }

        if(loop2==0)
        {

        
        for(int i=0;i<=p1;i++)
        {
            
            if(*right[i]=='>')
            {
                //printf(2,"index:%d",i);
                
                //printf(2,"hellllloooooo");
                for(int j=0;j<strlen(right[i+1]);j++)
                {
                    g[j]=right[i+1][j];   
                    //printf(2,"%c value:\n",g[j]);
                }
                right[i]='\0';
                right[i+1]='\0';
                op1=1;
            }
        }
        
        }



            


    /*printf(2,"outside for loop");
    printf(2,"before %s\t",left[0]);
    printf(2,"before %s \n",left[1]);
    printf(2,"before %s",right[0]);
    printf(2,"before %s",right[1]);*/


           
    if(fork()==0)
    {
       
       if(ip)
        {

        
        close(0);

        if(open(d, O_RDONLY) < 0){
        printf(2, "open %s failed\n", d);
        exit(0);
        }
        }

        if(op)
        {

        
        close(1);

        if(open(e, O_WRONLY|O_CREATE) < 0){
        printf(2, "open %s failed\n", e);
        exit(0);
        }
        }

       exec(left[0],left);
       exit(0);
        
    }
    int status;
    wait(&status);
    //printf(2,"status:%d",status);
    
    if(status==0 && fork()==0)
    {
    
        if(ip1)
        {

        
        close(0);

        if(open(f, O_RDONLY) < 0){
        printf(2, "open %s failed\n", f);
        exit(0);
        }
        }

        if(op1)
        {

        
        close(1);

        if(open(g, O_WRONLY|O_CREATE) < 0){
        printf(2, "open %s failed\n", g);
        exit(0);
        }
        }



        exec(right[0],right);
        exit(0);
    }
    
    
    wait(0);




            /*left[0]='\0';
            right[1]='\0';
            left[0]='\0';
            right[1]='\0';*/
            flag=1;
        }



        if(line[i]=='|' && line[i+1]=='|')
        {
            char args2[30][30];
            char argsss[30][30];
            char argssss[30][30];
            char *args[30];
            char *left[20];
            char *right[20];


            int loop1=0;
                
            int p1=0,x1=0,y1=0;
            memset(left,0,sizeof(left));
            memset(right,0,sizeof(right));
            memset(args,0,sizeof(args));
                    
            memset(args2,0,sizeof(args2));
            memset(argsss,0,sizeof(argsss));
            memset(argssss,0,sizeof(argssss));
            


            //printf(2,"in breakbypipe");
            //printf(2,"%s",line);
            for(int i=0;i<strlen(line);i++)
            {
                //printf(2,"in for loop");
                if((line[i]=='|') && (line[i+1]=='|'))
                {

                    args2[x1][y1]='\0';
                    args[p1]=args2[x1];
                    p1++;
                    x1++;
                    i++;
                    y1=0;
                    
                }
                else
                {
                    
                    args2[x1][y1]=line[i];
                    y1++;
               
                }
                
            }
            args2[x1][y1]='\0';
            args[p1]=args2[x1];
            //printf(2,"%d",p1);
            /*printf(2,"outside for loop");
            printf(2,"before %s",args[0]); 
            printf(2,"before %s",args[1]);

            printf(2,"otuside");*/
            int i,j;

            for(int lennn=0;lennn<=p1;lennn++)
            {
                for(i=0;args[lennn][i]==' '||args[lennn][i]=='\t';i++);
                
                for(j=0;args[lennn][i];i++)
                {
                        args[lennn][j++]=args[lennn][i];
                }
                args[lennn][j]='\0';
                for(i=0;args[lennn][i]!='\0';i++)
                {
                        if(args[lennn][i]!=' ' && args[lennn][i]!='\t')
                        {
                            j=i;
                        }
                }
                args[lennn][j+1]='\0';


                //printf(2,"after%s",args[lennn]);
            }
            x1=0;
            y1=0;
            p1=0;
            //printf(2,"args[0] value %s",args[0]);
            for(int i=0;i<strlen(args[0]);i++)
            {
                //printf(2,"in space for loop");
                if(!(args[0][i]==' '))
                {
                    argsss[x1][y1]=args[0][i];
                    //printf(2,"%s \n",argss[x]);
                    y1++;
                }
                else
                {
                    argsss[x1][y1]='\0';
                    left[p1]=argsss[x1];
                    p1++;
                    x1++;
                    y1=0;
                    
                }
                
            }
            argsss[x1][y1]='\0';
            left[p1]=argsss[x1];
            char d[20];
            char e[20];
            memset(d,0,sizeof(d));
            memset(e,0,sizeof(e));
         
            for(int i=0;i<=p1;i++)
                {
                


                if(*left[i]=='<')
                {
                    //printf(2,"index:%d",i);
                    //printf(2,"hellllloooooo");
                    for(int j=0;j<strlen(left[i+1]);j++)
                    {
                        d[j]=left[i+1][j];   
                        //printf(2,"%c value:\n",d[j]);
                    }

                    for(int i=0;i<=p1;i++)
                    {
                        
                        if(*left[i]=='>')
                        {
                            //printf(2,"index:%d",i);
                            
                            //printf(2,"hellllloooooo");
                            for(int j=0;j<strlen(left[i+1]);j++)
                            {
                                e[j]=left[i+1][j];   
                                //printf(2,"%c value:\n",e[j]);
                            }
                            left[i]='\0';
                            left[i+1]='\0';
                            op=1;
                            loop1=1;
                        }
                    }
                    left[i]='\0';
                    left[i+1]='\0';
                    ip=1;
                }
            }

            if(loop1==0)
            {

            
            for(int i=0;i<=p1;i++)
            {
                
                if(*left[i]=='>')
                {
                    //printf(2,"index:%d",i);
                    
                    //printf(2,"hellllloooooo");
                    for(int j=0;j<strlen(left[i+1]);j++)
                    {
                        e[j]=left[i+1][j];   
                        //printf(2,"%c value:\n",e[j]);
                    }
                    left[i]='\0';
                    left[i+1]='\0';
                    op=1;
                }
            }
            
            }
        

        x1=0,y1=0,p1=0;

            for(int i=0;i<strlen(args[1]);i++)
            {
                //printf(2,"in space for loop\n");
                if(!(args[1][i]==' '))
                {
                    argssss[x1][y1]=args[1][i];
                    y1++;
                }
                else
                {
                    argssss[x1][y1]='\0';
                    right[p1]=argssss[x1];
                    p1++;
                    x1++;
                    y1=0;
                    
                }
                
            }
            argssss[x1][y1]='\0';
            right[p1]=argssss[x1];


            char f[20];
            char g[20];
            memset(f,0,sizeof(f));
            memset(g,0,sizeof(g));
         
            int ip1=0,op1=0,loop2=0;
            for(int i=0;i<=p1;i++)
            {
            


            if(*right[i]=='<')
            {
                //printf(2,"index:%d",i);
                //printf(2,"hellllloooooo");
                for(int j=0;j<strlen(right[i+1]);j++)
                {
                    f[j]=right[i+1][j];   
                    //printf(2,"%c value:\n",f[j]);
                }

                for(int i=0;i<=p1;i++)
                {
                    
                    if(*right[i]=='>')
                    {
                        //printf(2,"index:%d",i);
                        
                        //printf(2,"hellllloooooo");
                        for(int j=0;j<strlen(right[i+1]);j++)
                        {
                            g[j]=right[i+1][j];   
                            //printf(2,"%c value:\n",g[j]);
                        }
                        right[i]='\0';
                        right[i+1]='\0';
                        op1=1;
                        loop2=1;
                    }
                }
                right[i]='\0';
                right[i+1]='\0';
                ip1=1;
            }
        }

        if(loop2==0)
        {

        
        for(int i=0;i<=p1;i++)
        {
            
            if(*right[i]=='>')
            {
                //printf(2,"index:%d",i);
                
                //printf(2,"hellllloooooo");
                for(int j=0;j<strlen(right[i+1]);j++)
                {
                    g[j]=right[i+1][j];   
                    //printf(2,"%c value:\n",g[j]);
                }
                right[i]='\0';
                right[i+1]='\0';
                op1=1;
            }
        }
        
        }



            


    /*printf(2,"outside for loop");
    printf(2,"before %s\t",left[0]);
    printf(2,"before %s \n",left[1]);
    printf(2,"before %s",right[0]);
    printf(2,"before %s",right[1]);*/



           
    if(fork()==0)
    {
       
       if(ip)
        {

        
        close(0);

        if(open(d, O_RDONLY) < 0){
        printf(2, "open %s failed\n", d);
        exit(0);
        }
        }

        if(op)
        {

        
        close(1);

        if(open(e, O_WRONLY|O_CREATE) < 0){
        printf(2, "open %s failed\n", e);
        exit(0);
        }
        }

       exec(left[0],left);
       exit(0);
        
    }
    int status;
    wait(&status);
    //printf(2,"status:%d",status);
    
    if(status!=0 && fork()==0)
    {
    
        if(ip1)
        {

        
        close(0);

        if(open(f, O_RDONLY) < 0){
        printf(2, "open %s failed\n", f);
        exit(0);
        }
        }

        if(op1)
        {

        
        close(1);

        if(open(g, O_WRONLY|O_CREATE) < 0){
        printf(2, "open %s failed\n", g);
        exit(0);
        }
        }



        exec(right[0],right);
        exit(0);
    }
    
    
    wait(0);




            /*left[0]='\0';
            right[1]='\0';
            left[0]='\0';
            right[1]='\0';*/
            flag=1;
            //free(&status);
        }
    }
    if(flag==0)
    {

    char argss[30][30];
    memset(argss,0,sizeof(argss));

    char a1[20];
        
    for(int i=0;i<strlen(line);i++)
    {
        a1[i]=line[i];
    }
    int x1,y1;
    for(x1=0;a1[x1]==' '||a1[x1]=='\t';x1++)
    {

    }
 
	for(y1=0;a1[x1];x1++)
	{
		a1[y1++]=a1[x1];
	}
	a1[y1]='\0';

    
    for(int i=0;i<len;i++)
    {

        if(!(a1[i]==' '))
        {
            argss[x][y]=a1[i];
            y++;
        }
        else
        {
            argss[x][y]='\0';
            args[p]=argss[x];
            p++;
            x++;
            y=0;
            
        }
        
    }
    argss[x][y]='\0';
    args[p]=argss[x];
            
    /*int error=0;
    char *check[10]={"echo","grep","cat","ls","wc"};
    if(args[0]!=check[0] && args[0]!=check[1] && args[0]!=check[2] && args[0]!=check[3] && args[0]!=check[4])
    {
        printf(2,"%s",args[0]);
        printf(2,"%s",check[0]);
        printf(2,"%d",strlen(args[0]));
                printf(2,"%d",strlen(check[0]));

        printf(2,"Illegal command or arguments\n");
        error=1;
    }*/
    //printf(2,"%d",p);

    //printf(2,"2nd value:%s",args[1]);
    
    char b[20];
    memset(b,0,sizeof(b));
    /*if(p==0)
    {
        for(int i=0;i<strlen(args[p]);i++)
        {
            if(args[p][i]=='<')
            {
                int t=0;
                for(int j=i+1;j<strlen(args[p]);j++)
                {
                    b[t]=args[p][j];
                    t++;
             
                }
                args[p][i]='\0';

            }
        }
    }*/
    //printf(2,"imP:%c",*(args[2]));
    char c[30];
    memset(c,0,sizeof(c));
    
    for(int i=0;i<=p;i++)
    {
        


        if(*args[i]=='<')
        {
            //printf(2,"index:%d",i);
            //printf(2,"hellllloooooo");
            for(int j=0;j<strlen(args[i+1]);j++)
            {
                 b[j]=args[i+1][j];   
                 //printf(2,"%c value:\n",b[j]);
            }

            for(int i=0;i<=p;i++)
            {
                
                if(*args[i]=='>')
                {
                    //printf(2,"index:%d",i);
                    
                    //printf(2,"hellllloooooo");
                    for(int j=0;j<strlen(args[i+1]);j++)
                    {
                        c[j]=args[i+1][j];   
                        //printf(2,"%c value:\n",c[j]);
                    }
                    args[i]='\0';
                    args[i+1]='\0';
                    op=1;
                    loop=1;
                }
            }
            args[i]='\0';
            args[i+1]='\0';
            ip=1;
        }
    }

    if(loop==0)
    {

    
    for(int i=0;i<=p;i++)
    {
        
        if(*args[i]=='>')
        {
            //printf(2,"index:%d",i);
            
            //printf(2,"hellllloooooo");
            for(int j=0;j<strlen(args[i+1]);j++)
            {
                 c[j]=args[i+1][j];   
                 //printf(2,"%c value:\n",c[j]);
            }
            args[i]='\0';
            args[i+1]='\0';
            op=1;
        }
    }
    
    }
    /*printf(2,"file:%s",b);
    printf(2,"arguement:%s",args[0]);
    printf(2,"hello");*/

    

    //args[p+1]="0";

    //printf(2,"in getcmd %s",(args[0]));
    

    if(fork()==0)
    {
        if(ip)
        {

        
        close(0);

        if(open(b, O_RDONLY) < 0){
        printf(2, "open %s failed\n", b);
        exit(0);
        }
        }

        if(op)
        {

        
        close(1);

        if(open(c, O_WRONLY|O_CREATE) < 0){
        printf(2, "open %s failed\n", c);
        exit(0);
        }
        }

        exec(args[0],args);
    }
    wait(0);
    }
    if(line[0]==0)
    {
        return -1;
    }
    
    return 0;
}

int
main(void)
{
  char line[charr];
  char *args[30];  
  // Ensure that three file descriptors are open.
   int fd;
    memset(line, 0, sizeof(line));
    memset(args,0,sizeof(args));

    

  // Ensure that three file descriptors are open.
  while((fd = open("console", O_RDWR)) >= 0){
    if(fd >= 3){
      close(fd);
      break;
    }
  }

  do
  {
      
  } while (getcmd(line,args)>=0);


    
  
exit(0);
}
