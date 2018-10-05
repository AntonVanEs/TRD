#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

bool eq (double a, double b, int prec) {
	double err = abs(a-b);
	return err < pow(10, prec) && err < pow(10, prec)*a;
}

int main (int argc, char *argv[]) {
	FILE *fa, *fb;
	char ba[256], bb[256];
	double da, db;
	unsigned la, lb;

	bool y;
	int prec;
	unsigned count = 0;

	if (argc < 4) {
		cerr << "Too few arguments" << endl;
		return 1;
	}

	fa = fopen (argv[1], "r");
	fb = fopen (argv[2], "r");
	prec = atoi (argv[3]);

	if (argc > 4) {
		y = (argv[4][0] == 'y');
	} else {
		y = false;
	}

	if (!fa || !fb) {
		cerr << "Could not open one of files" << endl;
	}

	while (!feof (fa) && !feof (fb)) {
		fgets (ba, sizeof ba, fa);
		fgets (bb, sizeof bb, fb);

		sscanf (ba, "%lf", &da);
		sscanf (bb, "%lf", &db);

		la = strlen (ba);
		lb = strlen (bb);

		if (la && ba[la-1] == '\n') {
			ba[la-1] = '\0';
		}
		if (lb && bb[lb-1] == '\n') {
			bb[lb-1] = '\0';
		}

		if (eq (da, db, prec)) {
			if (strcmp (ba, bb) == 0) {
				if (y) printf ("%-39s %-39s\n", ba, bb);
			} else {
				if (y) printf ("%-39s|%-39s\n", ba, bb);
			}
		} else {
			printf ("%-39s#%-39s\n", ba, bb);
			count++;
		}
	}
	while (!feof (fa)) {
		fgets (ba, sizeof ba, fa);
		sscanf (ba, "%lf", &da);
		la = strlen (ba);
		if (la && ba[la-1] == '\n') {
			ba[la-1] = '\0';
		}
		printf ("%-39s<                                     \n", ba);
		count++;
	}
	while (!feof (fb)) {
		fgets (bb, sizeof bb, fb);
		sscanf (bb, "%lf", &db);
		lb = strlen (bb);
		if (lb && bb[lb-1] == '\n') {
			bb[lb-1] = '\0';
		}
		printf ("                                     >%-39s\n", bb);
		count++;
	}

	fclose (fa);
	fclose (fb);

	if (count == 0) {
		printf ("Bestanden zijn equivalent.\n");
	}
	return (count == 0) ? 0 : 1;
}
