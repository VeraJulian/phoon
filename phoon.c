/*
 * (c) 2015 Julian Vera
 * this program reports the age or phase of the moon based on an argument-based
 * date using John Conway's mental method for calculating the age
 */

#include<stdio.h>
#include<stdlib.h>


//instance variables that will be used to determine switch and calculation values
int switched;
int i;
int day;
int month;
int century;

//this method determines if the 'a' switch was thrown and determines the month, day, and year accordingly
void parseArgs(int argc, char* argv[]){
  
  if(argc > 1){
    for(i = 1; i < argc; i++){
      if(argv[i][0] == '-' && argv[i][1] == 'a'){
	switched = 1;
	if(i == 1){
	  month = atoi(argv[2]);
	  day = atoi(argv[3]);
	  century = atoi(argv[4]);
	  break;
	}
	if(i == 2){
	  month = atoi(argv[1]);
	  day = atoi(argv[3]);
	  century = atoi(argv[4]);
	  break;
	}
	if(i == 3){
	  month = atoi(argv[1]);
	  day = atoi(argv[2]);
	  century = atoi(argv[4]);
	  break;
	}
	if(i == 4){
	  month = atoi(argv[1]);
	  day = atoi(argv[2]);
	  century = atoi(argv[3]);
	  break;
	}
      }else{
	switched=0;
	month = atoi(argv[1]);
	day = atoi(argv[2]);
	century = atoi(argv[3]);
      }
    }
  }
} 
  
int main(int argc, char* argv[]){
  //this char array pointer holds all moon names
  char *a[] = {"new","new","waxing crescent","waxing crescent","waxing crescent","waxing crescent","waxing crescent","first quarter","first quarter","waxing gibbous","waxing gibbous","waxing gibbous","waxing gibbous","waxing gibbous","full","full","full","waning gibbous","waning gibbous","waning gibbous","waning gibbous","waning gibbbous","third quarter","third quarter","waning crescent","waning crescent","waning crescent","waning crescent","waning crescent","new"};

  parseArgs(argc,argv);
  
  //the final 30 is helpful to avoid negative modular arithmetic later
  int sum = day+month+30;

  //last 2 digits of the year
  int yy;

  //will be used to calculate the absolute value of yy
  int x;

  //if the century digits are 20, subtract 8, else subtract 4
  if(century>=2000){
    sum -= 8;
  }else{
    sum -= 4;
  }

  //determine if the year is in the form 0-99
  if(century>=2000){
    yy=century%2000;
  }else{
    yy=century%1900;
  }

  //computing distance to the closest multiple of 19 between -9 and 9
  if(yy % 19 < 10){
    yy %= 19;
  }else{
    yy = (yy%19) - 19;
  }

  //x=|yy|
  x=abs(yy);
  //x = |yy| mod 3
  x = yy%3;
  //find value to append to x
  x = x*10;

  //if yy is negative just subtract since negative-negative = negative, else add
  if(yy<0){
    yy=yy-x;
  }else{
    yy=yy+x;
  }

  //recalculate the sum
  sum = sum+yy;
  //finally mod sum with 30
  sum = sum%30;

  //if switch is thrown only print the moon age
  if(switched){
    printf("%d\n",sum);
  }else{
    //else print moon's name
    printf("%s\n",a[sum]);
  }
  return 0;
}
