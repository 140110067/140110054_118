#include<simplecpp>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
main_program{
    initCanvas("JETMAN",500,500);    //opens canvas of name jetman having height and width 500 pixels
    Text t1(250,250,"START GAME");    //outputs start game
    Rectangle r1(250,250,100,50);     //creates a rectangle around text start game

    Rectangle r2(250,325,120,50);     //creates a rectangle around text instructions

    Text t2(250,325,"INSTRUCTIONS");
    //outputs instructions

    int score=0;

    int start=getClick();

    int x=start/65536,y=start%65536;

    if (x>190 && x<310 && y<350 && y>300){

        Text t4(250,100,"INSTRUCTIONS");
        t2.setColor(COLOR("white"));
        r2.setColor(COLOR("white"));
        t1.setColor(COLOR("white"));
        r1.setColor(COLOR("white"));
        Text t3 (250,200,"1. Press spacebar to make jetman go up.");
        Text t5 (250,230,"2. Press B to make jetman go down.");
        Text t6 (250,260,"3. Avoid touching the obstacles, spikes.");
        Text t7 (250,290,"4. Try to score as many points as you can.");
        getClick();

    }

    if (x>200 && x<300 && y<275 && y>225){

        t2.setColor(COLOR("white"));
        r2.setColor(COLOR("white"));
        t1.setColor(COLOR("white"));
        r1.setColor(COLOR("white"));
        int spike1=4;

        for(int i=0;i<501;i=i+8){

            Line l1(i,0,spike1,10);
            Line l2(spike1,10,spike1+4,0);
            l2.imprint();
            l1.imprint();
            spike1+=8;

        }

        int spike2=4;
         //creating spikes

            //spikes on the top of screen

        for(int i=0;i<501;i=i+8){

         //break each spike in two lines l1 and l2
                    //each new l1 begin where previous l2 end
                    //each l2 begin where previous l1 end


            Line l1(i,500,spike2,490);
            Line l2(spike2,490,spike2+4,500);
            l2.imprint();
            l1.imprint();
            spike2+=8;
            //updating final x co-ord of new l1

        }

        int a;
        //variable to store random value.
        double vx=1;

        Circle jetman(50,250,5);
        Rectangle jetman1(50,265,10,20);
        Line jetman2(47.5,275,50,285);
        Line jetman3(50,285,47.5,295);
        Line jetman4(52.5,275,55,285);
        Line jetman5(55,285,52.5,295);
        Line jetman6(55,255,60,265);
        Line jetman7(60,265,65,255);
        Line jetman8(45,255,50,265);
        Line jetman9(50,265,55,255);
        Rectangle jetman10(42.5,265,5,15);

        Text t10 (20 , 30 , "score");

        char b;

        void srand (unsigned int seed);    //define and initialize random func. seed
        srand (time(0));

        repeat(100){

            vx=0;

            a=rand() %300 +100;    //variable to store random value.

            Rectangle p(525,a,30,180);

            repeat(200){

                b=getch();
                if (b==32){

                     //move all parts of jetman up when key spacebar is pressed

                    jetman.move(0,-5);
                    jetman1.move(0,-5);
                    jetman2.move(0,-5);
                    jetman3.move(0,-5);
                    jetman4.move(0,-5);
                    jetman5.move(0,-5);
                    jetman6.move(0,-5);
                    jetman7.move(0,-5);
                    jetman8.move(0,-5);
                    jetman9.move(0,-5);
                    jetman10.move(0,-5);

                }

                else if (b==98){

                    //move all parts of jetman down when key b is pressed

                    jetman.move(0,5);
                    jetman1.move(0,5);
                    jetman2.move(0,5);
                    jetman3.move(0,5);
                    jetman4.move(0,5);
                    jetman5.move(0,5);
                    jetman6.move(0,5);
                    jetman7.move(0,5);
                    jetman8.move(0,5);
                    jetman9.move(0,5);
                    jetman10.move(0,5);

                }

                //move rectangle p that has been created before
                p.move(vx,0);
                vx-=0.1;
                wait (0.025);      //moving rectangles

                //set colour of rectangle to red
                //fill the inner of rectangle with the colour red

                p.setColor(COLOR("red"));
                p.setFill(true);

                //increment score

                 if(p.getX() < 20){
                    score = score + 100 ;
                    break ;
                }

                Text t11(20 , 45, score ) ;

                //collision with head

                if(p.getX()>25 && p.getX()<75 && jetman.getY()==a+95){

                    cout<<"GAME OVER"<<endl;

                     int rcgo=10;//rcgo-radius of circle on game over

                     //a circle appears on center of screen which starts growing in size and finally covers the whole screen

                    while(rcgo<=250*sqrt(2)){

                        Circle cgo(250,250,rcgo);//cgo-circle on game over
                        rcgo+=10;
                        cgo.setFill(true);
                        wait(0.005);
                    }

                    //displaying game over and score

                    Rectangle r3(250,250,500,500);
                    r3.setFill(true);
                    Text t8(250,150,"GAME OVER");
                    t8.setColor(COLOR("red"));
                    Text t9 (250, 180 , "Your Score");
                    Text t10 (250,200,score) ;
                    wait(1000);

                }

                //collision with leg1

                if(p.getX()>25 && p.getX()<75 && jetman5.getY()<a-90 && jetman5.getY()>a-100){

                    cout<<"GAME OVER"<<endl;

                     int rcgo=10;//rcgo-radius of circle on game over

                     //a circle appears on center of screen which starts growing in size and finally covers the whole screen

                    while(rcgo<=250*sqrt(2)){

                        Circle cgo(250,250,rcgo);//cgo-circle on game over
                        rcgo+=10;
                        cgo.setFill(true);
                        wait(0.005);
                    }

                    //displaying game over and score

                    Rectangle r3(250,250,500,500);
                    r3.setFill(true);
                    Text t8(250,150,"GAME OVER");
                    t8.setColor(COLOR("red"));
                    Text t9 (250, 180 , "Your Score");
                    Text t10 (250,200,score) ;
                    wait(1000);
                }

                //collision with leg2
                if(p.getX()>25 && p.getX()<75 && jetman3.getY()<a-90 && jetman3.getY()>a-100){

                    cout<<"GAME OVER"<<endl;
                     int rcgo=10;//rcgo-radius of circle on game over

                    while(rcgo<=250*sqrt(2)){

                     //a circle appears on center of screen which starts growing in size and finally covers the whole screen


                        Circle cgo(250,250,rcgo);//cgo-circle on game over
                        rcgo+=10;
                        cgo.setFill(true);
                        wait(0.005);
                    }

                    //displaying game over and score


                    Rectangle r3(250,250,500,500);
                    r3.setFill(true);
                    Text t8(250,150,"GAME OVER");
                    t8.setColor(COLOR("red"));
                    Text t9 (250, 180 , "Your Score");
                    Text t10 (250,200,score) ;
                    wait(1000);
                }

                // collision with hands
                if (p.getX()>75 && p.getX()<85 && jetman7.getY()<a+90 && jetman7.getY()>a-90){

                    cout<<"GAME OVER"<<endl;    //a circle appears on center of screen which starts growing in size and finally covers the whole screen

                     int rcgo=10;//rcgo-radius of circle on game over

                    while(rcgo<=250*sqrt(2)){

                     //a circle appears on center of screen which starts growing in size and finally covers the whole screen

                        Circle cgo(250,250,rcgo);//cgo-circle on game over
                        rcgo+=10;
                        cgo.setFill(true);
                        wait(0.005);
                    }

                    //displaying game over and score


                    Rectangle r3(250,250,500,500);
                    r3.setFill(true);
                    Text t8(250,150,"GAME OVER");
                    t8.setColor(COLOR("red"));
                    Text t9 (250, 180 , "Your Score");
                    Text t10 (250,200,score) ;
                    wait(1000);

                }

                // collision with spikes
                if(jetman.getY()==15 || jetman5.getY()==485){

                    cout<<"GAME OVER"<<endl;

                     int rcgo=10;//rcgo-radius of circle on game over

                    while(rcgo<=250*sqrt(2)){

                     //a circle appears on center of screen which starts growing in size and finally covers the whole screen

                        Circle cgo(250,250,rcgo);//cgo-circle on game over
                        rcgo+=10;
                        cgo.setFill(true);
                        wait(0.005);

                    }

                    //displaying game over and score


                    Rectangle r3(250,250,500,500);
                    r3.setFill(true);
                    Text t8(250,150,"GAME OVER");
                    t8.setColor(COLOR("red"));
                    Text t9 (250, 180 , "Your Score");
                    Text t10 (250,200,score);
                    wait(1000);

                }
            }
        }
    }
}
