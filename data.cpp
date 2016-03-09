#include <cstdio>

int main ()
{
	FILE *inlabel = fopen ("music_review_label.txt","r");
	FILE *invec = fopen ("music_review_text.txt.vec","r");

	FILE *out = fopen ("music_train.txt","w");

	int label,cnt=0;
	int n,d;
	char temp[100];

	fscanf (invec,"%d%d",&n,&d);
	printf ("num:%d, dimension:%d\n",n,d);
	for (int i=0;i<n;i++)
	{
		fscanf (inlabel, "%d",&label);
		if (i%100==0)
			printf ("\r%dc",cnt/100);

		fprintf (out, "%d ",label);
		fscanf (invec, "%s",temp);
		for (int j=1;j<=d;j++)
		{
			float val;
			fscanf (invec, "%f",&val);
			fprintf (out,"%d:%f ",j,val);
		}
		fprintf (out, "\n");
	}

}