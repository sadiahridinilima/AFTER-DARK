

#ifndef MYHEADERFILES_H_INCLUDED
#define MYHEADERFILES_H_INCLUDED

int pic_x, pic_y;
int dp, dq;

void objectChange() {
	pic_x += dp;
	pic_y += dq;

	if (pic_x >= 800 || pic_x <= 0)
		dp = -dp;
	if (pic_y >= 800 || pic_y <= 0)
		dq = -dq;
}

#endif // !MYHEADERFILES_H_INCLUDED
