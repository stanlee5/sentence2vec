#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

void label_text (string labelf, string textf, string outf)
{
	FILE *inlabel = fopen (labelf.c_str(),"r");
	FILE *invec = fopen (textf.c_str(),"r");
	FILE *out = fopen (outf.c_str(),"w");

	printf ("%d %d %d\n",inlabel!=NULL, invec!=NULL, out!=NULL);

	int label,cnt=0;
	int n,d;
	char temp[100];

	fscanf (invec,"%d%d",&n,&d);
	printf ("num:%d, dimension:%d\n",n,d);
	for (int i=0;i<n;i++)
	{
		fscanf (inlabel, "%d",&label);

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
	printf (">> finish : %s \n",outf.c_str());

	fclose (inlabel);
	fclose (invec);
	fclose (out);
}

int main ()
{
	label_text ("review_music_train_label.txt", "review_music_train_text.txt.svec", "music_train.txt");
	label_text ("review_music_test_label.txt" , "review_music_test_text.txt.svec" , "music_test.txt" );
}