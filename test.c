#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int sad(void);
int happy(void);
int neutral(void);
int mislead=0;

int main(void)
{

  char feeling[10000];
  int i=0, j=0, c=0;
  int rate;
  int negative(char feeling[]);
  int positive(char feeling[]);
  char check1, check2;
  char repeat;
  printf("\n----------------------------------------------------------------------------------------------------------------------------");
  printf("\n\t\t\t\t\t\t\t\"WHAT'S YOUR MOOD\"\n");
  printf("----------------------------------------------------------------------------------------------------------------------------");
  printf("\nThis software will help you recognise your mood and give some suggestions accordingly.\n");
  printf("Please keep in mind that the results may not be completely true, but there will be a good chance for correct deductions\n");
  printf("\nThe test consists of two parts,");
  printf("\nIn the first part, you will be asked to write how you are feeling right now, how was your day, etc,"
                        "\nIn the other part, based on your written input, questions will be asked and you need to answer them in the form of codes");
  again:
  mislead=0;                                                       //To check for any misleading entries of changing nature of response



  printf("\n\nPress Enter to continue...");
  scanf("%c", &check1);
  if(check1=='\n')
  {
    printf("\nEnter your feelings, describe your day, write  anything you wish."
              "\nNOTE: Avoid using indirect terms(for eg.\"not good\" instead of \"bad\", etc"
              "\n\nEnter you input here:");
    gets( feeling);                                              //Get the input for evaluating the mood type from 3 main mood types and analysis
    again1:
    printf("\nDo rate your day on a scale of 5 ('0' for worst, '5' for the best): ");
    scanf("%d", &rate);                                          //For more accurate mood analysis

    switch(rate)
    {
      case 0:
      i+=3;
      break;

      case 1:
      i+=2;
      break;

      case 2:
      i+=1;
      break;

      case 3:
      j+=1;
      break;

      case 4:
      j+=2;
      break;

      case 5:
      j+=3;
      break;

      default:
      printf("\nUnvalid Code...please try again...");
      goto again1;
      break;
    }



  i=i+negative(feeling);                                                //For evaluating the negative aspect based on the keywords entered, i.e i
  j=j+positive(feeling);                                                //For evaluating the  positive aspect based on the keywords entered, i.e j

  while((c = getchar()) != '\n' && c != EOF);                         //For clearing keyboard buffer.


  printf("\nYour words and day's score are saved,\nPress Enter to continue with the questionnaire part...");
  scanf("%c", &check2);                                               //To go ahead on entering 'Enter'.
  if(check2=='\n')
  {
    printf("\nDo answer the following questions honestly based on which your mood will be evaluated.\n");

    if((i>j)&&(i>2)&&((i-j)>2||(j-i)>2))                             //Based on the score of i and j and checking for 'sad' main mood.
    {
     sad1:
     c=sad();
     if(c==0)                                                        //Check for any change needed by the nature of answers
     goto exit;                                                      //If no change in nature of answer encounntered, exit the program
     else if(c==10)
     goto mislead1;                                                  //If change in nature of the answer is misleading, end the program
     else
     goto neutral1;                                                   //If change in nature of answer is towards neutral, go to 'neutral' main mood
   }

  else if((i<j)&&(j>2)&&((i-j)>2||(j-i)>2))                              //Based on the score of i and j and checking for 'happy' main mood.
    {
      happy1:
      c=happy();
      if(c==0)                                                        //Check for any change needed by the nature of answers
      goto exit;                                                      //If no change in nature of answer encounntered, exit the program
      else if(c==10)                                                  //If change in nature of the answer is misleading, end the program
      goto mislead1;
      else                                                            //If change in nature of answer is towards neutral, go to 'neutral' main mood
      goto neutral1;
    }

    else                                                       //Based on the score of i and j and checking for 'neutral' main mood.
    {
      neutral1:
      c=neutral();                                                     //Check for any change needed by the nature of answers
      if(c==1)
      goto happy1;
      else if(c==2)
      goto sad1;
      else if(c==10)
      goto mislead1;
      else
      goto exit;
    }
    mislead1:                                                         //If the user has tried to play with the nature of the aanswers, this will run
    printf("\nYou either are very moody or you are entering wrong inputs. Please enter correct inputs next time.\nIf you entered correct inputs, then you should surely visit a psychiatrist as this may be serious.\n");

    exit:
    printf("\nDo you want to take the test again?(Y/n):");
    scanf(" %c", &repeat);
    if(repeat=='y'||repeat=='Y')
    {
      i=0; j=0;
      while((c = getchar()) != '\n' && c != EOF);                     //Clearing the buffer of the keyboard for the next new turn.
      goto again;
    }
    printf("\nThanks for your time!\nProgram developed by Parthesh Soni.\n\n");
  }
 }


    return 0;
}

int sad(void)
{
  int result[6];

  int i=0;
  int p=0, q=0, r=0, s=0, t=0, c=0;;
  int depressed(void);
  int bored(void);
  int fatigue(void);
  int nervous(void);
  int angry(void);

  printf("\n(S-1) Your best friend teases you for no reason, what would you do?\n1. Do nothing and feel myself stupid\n2. Try to shoo him, as he makes no sense\n3. Curse the world for nothing\n4. Give him a fake smile\n5. Punch him hard on face\nCode: ");
  scanf(" %d", &result[i++]);
  printf("\n(S-2) Suppose your neighbours are playing your favourite intense song(beats, jazz, etc.), what would you do?\n1. Lock yourself in a room\n2. Go and talk to them to slow down the volume\n3. Burn with anger but cannot do anything\n4. Go and try to enjoy with the neighbours\n5. Call the police and make them arrested\nCode: ");
  scanf(" %d", &result[i++]);
  printf("\n(S-3) Which movie would you prefer right now?\n1. Roy\n2. All the best\n3. An old movie having some personal nostalgia\n4. Mr. Bean\n5. G.I.Joe\nCode: ");
  scanf(" %d", &result[i++]);
  printf("\n(S-4) Your brother plays a prank on you, what would be your reaction?\n1. Nothing\n2. Try to understand the prank\n3. Shoo him away\n4. Motivate him to play more\n5. Play a hard prank on him by which he may get hurt\nCode: ");
  scanf(" %d", &result[i++]);
  printf("\n(S-5) Can you meditate on one thing easily right now?\n1. Hell, No because my own thoughts may harass me\n2. Ya, may be I can\n3. Yes, but my body is not feeling good\n4. Would love to!\n5. No way, I am burning with anger right now!\nCode: ");
  scanf(" %d", &result[i++]);
  printf("\n(S-6) If you are given a chocolate, what would you do?\n1. Crave for it\n2. Would accept it if offered for free!\n3. I can't say\n4. Ya, it may prove beneficial right now\n5. No\nCode: ");
  scanf(" %d", &result[i++]);

  for(i=0; i<6; i++)                      //to grade the answers for best selection of submood.
  {
    if(result[i]==1)
    p++;

    if(result[i]==2)
    q++;

    if(result[i]==3)
    r++;

    if(result[i]==4)
    s++;

    if(result[i]==5)
    t++;

    else if(result[i]>5||result[i]<1)                     //check for any incorrect code
    {
      printf("\nYou have entered an invalid code for the question (S-%d). Please enter its valid code:\n",i+1);
      scanf(" %d", &result[i]);
      i--;
    }

  }

  if((p>=q)&&(p>=r)&&(p>=s)&&(p>=t))                          //If p is greater than any other, this mood will be selected first, and then the other ones.
  {
   c=depressed();
   if(c==0)
   return 0;
   c=bored();                                                  //if the first one is not the case, then selecting the other submoods.
   if(c==0)
   return 0;
   c=fatigue();
   if(c==0)
   return 0;
   c=nervous();
   if(c==0)
   return 0;
   c=angry();
   if(c==0)
   return 0;
  }
  else if((q>=p)&&(q>=r)&&(q>=s)&&(q>=t))                     //same logic as above
  {
    c=bored();
    if(c==0)
    return 0;
    c=depressed();
    if(c==0)
    return 0;
    c=fatigue();
    if(c==0)
    return 0;
    c=nervous();
    if(c==0)
    return 0;
    c=angry();
    if(c==0)
    return 0;
  }
  else if((r>=p)&&(r>=q)&&(r>=s)&&(r>=t))
  {
    c=fatigue();
    if(c==0)
    return 0;
    c=bored();
    if(c==0)
    return 0;
    c=depressed();
    if(c==0)
    return 0;
    c=nervous();
    if(c==0)
    return 0;
    c=angry();
    if(c==0)
    return 0;
  }
  else if((s>=p)&&(s>=q)&&(s>=r)&&(s>=t))
  {
    c=nervous();
    if(c==0)
    return 0;
    c=fatigue();
    if(c==0)
    return 0;
    c=bored();
    if(c==0)
    return 0;
    c=depressed();
    if(c==0)
    return 0;
    c=angry();
    if(c==0)
    return 0;
  }
  else if((t>=p)&&(t>=q)&&(t>=r)&&(t>=s))
  {
    c=angry();
    if(c==0)
    return 0;
    c=nervous();
    if(c==0)
    return 0;
    c=fatigue();
    if(c==0)
    return 0;
    c=bored();
    if(c==0)
    return 0;
    c=depressed();
    if(c==0)
    return 0;
  }
  if(mislead!=0)
  {
    return 10;                                                    //if mislead is more than 0, then change in the nature of mood is seen, hence it is fake input entered
  }                                                                //as no one can enter first as bad mood  one, and then enter answers of good mood.
  mislead++;
  return 1;

}






int depressed(void)
{
  int ans=0;
  printf("\nIs your feeling feels like your life is turned upside down and you have made a mess with it?\n1.Hell, Yes\n2. Nope\nCode: ");
  again:
  scanf(" %d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nIt is detected that you are sad and depressed. Do talk to your parents or friends if the depression is mild, otherwise do visit a family psychiatrist\n");
    return 0;
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}

int bored(void)
{
  int ans=0;
  printf("\nDo you enjoy the things you are doing right now?\n1. Yup\n2. No\nCode: ");
  again:
  scanf(" %d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nYou seem to be bored right now. Go on, do somthing interesting, have fun!\n");
    return 0;
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}

int fatigue(void)
{
  int ans=0;
  printf("\nYour mind is a mess, your thoughts are doped, your body pains and stomach aches.\n1. Yes\n2. No\nCode: ");
  again:
  scanf(" %d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nIt is inferred that you are fatigue right now. Destress yourself and visit a doctor. Plan a holiday to relax!\n");
    return 0;
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}

int nervous(void)
{
  int ans=0;
  printf("\nYou wish to bite your nails, your legs shiver and you feel something's gonna go wrong.\n1. Yes\n2. No\nCode: ");
  again:
  scanf(" %d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nHmm...You are feeling nervous. Talk to your colleague, or friend who can give you comfort.\n");
    return 0;
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}

int angry(void)
{
  int ans=0;
  printf("\nDo you feel you can punch the person in front of you and bang your TV screen with your phone?\n1. Yes\n2. No\nCode: ");
  again:
  scanf(" %d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nWhy so angry dude! Relax, everything will come to it's proper place. Hope for the best.\n");
    return 0;
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}



int happy(void)
{

  int result[7];

  int i=0;
  int p=0, q=0, r=0, c=0;
  int alert(void);
  int excited(void);
  int elated(void);
  printf("\n(H-1) How is your body feeling at this moment?\n1. Feeling normal and light\n2. Very light and stomach bubbling\n3. Feels strong and confident\nCode: ");
  scanf(" %d", &result[i++]);
  printf("\n(H-2) If you encounter a salesman, how would you respond?\n1. Would try to make out how good is the deal\n2. Would buy his product if useful without a second thought\n3. Would try to comfort him by offering water and then start business talk\nCode: ");
  scanf(" %d",  &result[i++]);
  printf("\n(H-3) If your brother asks you for $20, what would you do?\n1. Ask him what he wants to buy, and give him if necessary\n2. Give him without inspection\n3. Give him $30!\nCode: ");
  scanf(" %d",  &result[i++]);
  printf("\n(H-4) Your social group is planning for an outting, what would you do?\n1. Join if you have nothing to else to do\n2. Join them obviously\n3. Join them if they are gonna help someone (volunteachering, etc)\nCode: ");
  scanf(" %d",  &result[i++]);
  printf("\n(H-5) Suppose you get a news that you topped your University exams, what would be your reaction?\n1. Make sure if it's true, and then Party!\n2. Party Hard and celebrate with friends\n3. Celebrate a bit and then help the friend scoring less\nCode: ");
  scanf(" %d",  &result[i++]);
  printf("\n(H-6) Would you be able to meditate on something right now?\n1. Ofcourse, very easily\n2. No, how can I?\n3. Ya, but don't have time or mood\nCode: ");
  scanf(" %d",  &result[i++]);
  printf("\n(H-7) Would you be able to read a novel, at this instant?\n1. Yes\n2. Hell, No\n3. Yes, if I wish to\nCode: ");
  scanf(" %d",  &result[i++]);

  for(i=0; i<7; i++)
  {
    if(result[i]==1)
    p++;

    if(result[i]==2)
    q++;

    if(result[i]==3)
    r++;


    else if(result[i]>3||result[i]<1)
    {
      printf("\nYou have entered an invalid code for the question (H-%d). Please enter its correct code:\n",1+i);
      scanf("%d", &result[i]);
      i--;
    }


  }



  if((p>=q)&&(p>=r))
  {
    c=alert();
    if(c==0)
    return 0;
    c=excited();
    if(c==0)
    return 0;
    c=elated();
    if(c==0)
    return 0;
  }
  if((q>=p)&&(q>=r))
  {
    c=excited();
    if(c==0)
    return 0;
    c=alert();
    if(c==0)
    return 0;
    c=elated();
    if(c==0)
    return 0;

  }
  if((r>=p)&&(r>=q))
  {
    c=elated();
    if(c==0)
    return 0;
    c=excited();
    if(c==0)
    return 0;
    c=alert();
    if(c==0)
    return 0;
  }
  if(mislead!=0)
  {
    return 10;
  }
  mislead++;
  return 1;

}




int alert(void)
{
  int ans=0;
  printf("\nAre you fully conscious about the things happening around you?\n1. Yo\n2. Nope\nCode: ");
  again:
  scanf("%d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nYou are Happy and alert! This is a good state of mind! Try to be in this state always!\n");
    return (0);
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}
int excited(void)
{
  int ans=0;
  printf("\nDo you feel hyper and happy as if you have got what you want?\n1. Yes\n2. No\nCode: ");
  again:
  scanf("%d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nExcitement is taking hold of you! Relax! Try to bring down your excitment and enjoy the moment.\n");
    return 0;
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}
int elated(void)
{
  int ans=0;
  printf("\nDo you feel the instinct to make people around you happy and blessed?\n1. Yes\n2. No\nCode: ");
  again:
  scanf("%d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nElated you are! Very good feeling. Remain happy by making others happy. Just take care no one takes benefit of you for his own selfishness.\n");
    return 0;
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}



int neutral(void)
{
  static int result[5];

  int i=0;
  int p=0, q=0, r=0, s=0, c=0;
  int calm(void);
  int content(void);
  int dreamy(void);
  int relaxed(void);

  printf("\n(N-1) You are given a surprise party, what would be your reaction?\n1. Thank them\n2. Express gratitude to them\n3. Bang the party, without offence\n4. Have a good time with them, enjoying every moment\nCode: ");
  scanf(" %d", &result[i++]);
  printf("\n(N-2) You are on a holiday with your family, and suddenly your boss calls you, what would you do?\n1. Answer him and let him know you are holidaying\n2. Won't answer the call as you have already told him about your outing\n3. Laugh at his stupidity for calling you at this time\n4. Message him that you are on leave and driving right now\nCode: ");
  scanf("%d", &result[i++]);
  printf("\n(N-3) Which is the best option which feels right to you right now?\n1. Life is so peaceful\n2. You have everything you wish to have in your life\n3. You are the supreme hero of your game called life\n4. I want to enjoy the mother nature!\nCode: ");
  scanf("%d", &result[i++]);
  printf("\n(N-4) You are given a Windows Surface Pro for free without any conditions, what would you do?\n1. No one can give me that\n2. I would rather not take it.\n3. Hell, yes, I would love it\n4. Relax, no one can afford to give such an expensive thing for free\nCode: ");
  scanf("%d", &result[i++]);
  printf("\n(N-5) Suppose there is a state of emergency in your area, how would you feel?\n1. Breath deeply and try to analyse the problem\n2. Would keep in mind government is always there for me\n3. Everything is alright, there is no emergency!\n4. Relax, everything gonna go good!\nCode: ");
  scanf("%d", &result[i++]);
  for(i=0; i<5; i++)
  {
    if(result[i]==1)
    p++;

    if(result[i]==2)
    q++;

    if(result[i]==3)
    r++;

    if(result[i]==4)
    s++;

    else if(result[i]>4||result[i]<1)
    {
      printf("\nYou have entered an invalid code for the question (N-%d). Please enter its correct code:\n",1+i);
      scanf("%d", &result[i]);
      i--;
    }
  }

  if((p>=q)&&(p>=r)&&(p>=s))
  {
    c=calm();
    if(c==0)
    return 0;
    c=content();
    if(c==0)
    return 0;
    c=dreamy();
    if(c==0)
    return 0;
    c=relaxed();
    if(c==0)
    return 0;
  }
  if((q>=p)&&(q>=r)&&(q>=s))
  {
    c=content();
    if(c==0)
    return 0;
    c=calm();
    if(c==0)
    return 0;
    c=dreamy();
    if(c==0)
    return 0;
    c=relaxed();
    if(c==0)
    return 0;
  }
  if((r>=p)&&(r>=q)&&(r>=s))
  {
    c=dreamy();
    if(c==0)
    return 0;
    c=content();
    if(c==0)
    return 0;
    c=calm();
    if(c==0)
    return 0;
    c=relaxed();
    if(c==0)
    return 0;
  }
  if((s>=p)&&(s>=q)&&(s>=r))
  {
    c=relaxed();
    if(c==0)
    return 0;
    c=dreamy();
    if(c==0)
    return 0;
    c=content();
    if(c==0)
    return 0;
    c=calm();
    if(c==0)
    return 0;
  }
  if(mislead!=0)
  {
    return 10;
  }
 int bonus=0;                                     //for transfering the control to happy or sad.
 printf("\nIs your feeling a bit on happier side?\n1. Yes\n2. No\nCode: ");
 scanf("%d", &bonus);
 mislead++;
 if(bonus==1)
 return 1;
 else
 return 2;
 }




int calm(void)
{
  int ans=0;
  printf("\nDo you feel that everything going around you is proper and fine?\n1. Yes\n2. No\nCode: ");
  again:
  scanf("%d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nGood! You are feeling calm and should continue feeling it! Enjoy the calmness ;)\n");
    return 0;
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}
int content(void)
{
  int ans=0;
  printf("\nIs there a feeling in you that everything you wish to have is with you and in proper order?\n1. Yes\n2. No\nCode: ");
  again:
  scanf("%d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nYou are satisfied and happy with what you have! Be content with the things you own always!\n");
    return 0;
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}
int dreamy(void)
{
  int ans=0;
  printf("\nDo you have slight dizziness in you?\n1. Yes\n2. No\nCode: ");
  again:
  scanf("%d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nYou are day-dreaming! Wake up, be alert. Live in the moment.\n");
    return 0;
  }
  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}
int relaxed(void)
{
  int ans=0;
  printf("\nIs your breath, heartbeat, and bloodflow normal?\n1. Yes\n2. No\nCode: ");
  again:
  scanf("%d", &ans);
  if(ans==1)
  {
    printf("\nRESULT:\nRelaxed! Good. You should always be in this state. Relaxed state is good for your health!\n");
    return 0;
  }

  else if(ans==2)
  return 1;
  else
  {
    printf("\nEnter valid code:");
    goto again;
  }
}



int negative(char feeling[])
{
  int i=0;
  char word[100];

  if((strcpy(word,"gloomy"))&&(strcasestr(feeling, word)))                       //check the keywords and based on it, increment the i.
  i++;
  if((strcpy(word,"gloom"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"tired"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"sad"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"sadly"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"sadness"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"miserable"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"unhappy"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"unhappiness"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"bad"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"badly"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"dejected"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"detached"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"depressed"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"depressing"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"low"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"disheartened"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"disheartening"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"tragic"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"tragedy"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"traumatic"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"trauma"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"distressing"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"distress"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"unfortunate"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"unfortunately"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"mournful"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"regret"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"regreting"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"uncomfort"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"uncomfortable"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"painfull"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"pain"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"unbearable"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"nervous"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"restless"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"tense"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"trouble"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"troubled"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"disturbed"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"disturb"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"disturbing"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"embarass"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"embarassing"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"embarassed"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"upset"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"upsetting"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"anxious"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"uneasy"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"uneasiness"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"irritate"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"irritating"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"poor"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"difficult"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"unpleasent"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"unlucky"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"hard luck"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"terrible"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"guilty"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"guilt"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"negative"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"sick"))&&(strcasestr(feeling, word)))
  i++;
  if((strcpy(word,"ill"))&&(strcasestr(feeling, word)))
  i++;

  return (i);                                                         //return the value of i, as negative aspect
}


int positive(char feeling[])
{
  int j=0;
  char word[100];
  if((strcpy(word,"happy"))&&(strcasestr(feeling, word)))                   //same logic as the one in the above ones
  j++;
  if((strcpy(word,"happiness"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"happily"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"joyous"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"blessed"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"blessings"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"bliss"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"radiant"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"sunny"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"good"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"better"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"accomplished"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"healthy"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"fun"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"funny"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"nice"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"nicely"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"hilarious"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"comedy"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"comic"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"enjoyable"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"delight"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"delightful"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"satisfied"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"amusing"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"amuse"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"marvellous"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"charming"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"entertaining"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"entertain"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"entertainment"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"entertained"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"high"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"mindful"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"joy"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"joyful"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"merry"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"superb"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"strong"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"alert"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"glad"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"fantastic"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"fabulous"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"exciting"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"excited"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"helpful"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"elated"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"calm"))&&(strcasestr(feeling, word)))
  j++;
  if((strcpy(word,"relaxed"))&&(strcasestr(feeling, word)))
  j++;


  return (j);
}
