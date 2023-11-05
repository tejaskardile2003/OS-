# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
void main()
{
int i,j,temp=0;
int arr[5];
printf("ENTER ELEMENTS IN ARRAY:\n");
for(i=0;i<5;i++)
{
scanf("%d\t",&(arr[i]));
}
pid_t pid;
pid=fork();
if(pid==0)
{
printf("\n");
printf("\n");
printf("Child class execution:\n");
printf("Child Process Id=%d\n",getpid());
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(arr[i]>arr[j])
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
printf("Sorted array elements in descending order are:\n");
for(i=0;i<5;i++)
{
printf("%d\t",arr[i]);
}
}
else
{
printf("Parent class execution:\n");
printf("Parent Process Id=%d\n",getpid());
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(arr[i]<arr[j])
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
printf("Sorted array elements in ascending order are:\n");
for(i=0;i<5;i++)
{
printf("%d\t",arr[i]);
}
}
}
