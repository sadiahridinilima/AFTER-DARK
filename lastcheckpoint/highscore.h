
#ifndef HIGHSCORE_H_INCLUDED
#define HIGHSCORE_H_INCLUDED




void highscore()
{

FILE file = fopen("highScore.txt","r");

	for(int i = 0 ; i < 10 ; i ++)
	{
		fscanf(file , "%s %d" , &highScoreArray[i].name  , &highScoreArray[i].point);
	}

	fclose(file);

	for (int i = 0 ; i<5 ; i++)
		for(int j = 5 ; j>i ; j--)
		{
			if( highScoreArray[j].point > highScoreArray[j-1].point )
			{
				dScore = highScoreArray[j-1].point;
				highScoreArray[j-1].point = highScoreArray[j].point;
				highScoreArray[j].point = dScore;

			/*	strcpy( tempName , scoreArr[j-1].name);
				strcpy( ssf[j-1].playerName , ssf[j].playerName);
				strcpy( ssf[j].playerName , tempName);*/
			}
		}


	file = fopen("highScore.txt", "w");

	for(int i = 0; i<10 ; i++)
	{
		fprintf(file , "%s\t%d\r\n" , highScoreArray[i].name  , highScoreArray[i].point);
	}

	fclose(file);
}

void showScores()
{

		iSetColor(251,160,38);
			iText(435,520, "Name ",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(650,520, "Score ",GLUT_BITMAP_TIMES_ROMAN_24);
			file = fopen("highScore.txt","a+");

			for(int i = 0 ; i < 5 ; i ++)
			{
				fscanf(file , "%s %d" , &highScoreArray[i].name , &highScoreArray[i].point);
			}


			fclose(file);

			iSetColor(225,220,30);

			iText( 440 , 450  , "1. " , GLUT_BITMAP_TIMES_ROMAN_24 );
			iText( 440 , 410  , "2. " , GLUT_BITMAP_TIMES_ROMAN_24 );
			iText( 440 , 370  , "3. " , GLUT_BITMAP_TIMES_ROMAN_24 );
			iText( 440 , 330  , "4. " , GLUT_BITMAP_TIMES_ROMAN_24 );
			iText( 440 , 290  , "5. " , GLUT_BITMAP_TIMES_ROMAN_24 );


			iSetColor(53,204,236);

			for(int i = 0 ; i < 5 ; i++)
			{

				iText( 470 , 450 - i *40 , highScoreArray[i].name , GLUT_BITMAP_TIMES_ROMAN_24 );
				itoa(highScoreArray[i].point , highScoreString , 10);
				iText( 650 , 450 - i *40 , highScoreString , GLUT_BITMAP_TIMES_ROMAN_24 );

			}


}


#endif // !MYHEADER_H_INCLUDED
