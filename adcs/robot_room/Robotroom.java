/*
 * Robot Coordination Problem
 *
 * Note that each robot is defined as the Robot class below.
 * Please modify the marked area for your assignment.
 *
 * Ver. 0.5 by hxt@sfc.keio.ac.jp
 */

import java.applet.*;
import java.awt.*;

  class Robot {
    private int id;
    private int x;
    private int y;
    private int state;

    public Robot(int myid, int xpos, int ypos, int mystate) {
      id = myid;
      x  = xpos;
      y  = ypos;
      state = mystate;
    }

    public void move(int xnew, int ynew, int count) {
      x = xnew;
      y = ynew;
      state += count;
    }
    public int getid() {
      return id;
    }    
    public int getx() {
      return x;
    }    
    public int gety() {
      return y;
    }    
    public int getstate() {
      return state;
    }    
  }  

/*
 * We assume 512x512 space for this robot room
 * and all robots move synchronously.
 */

public class Robotroom extends Applet
implements Runnable {
  Thread th1;
  int sleepTime;
  Robot[] robots;
  int d, dx, dy;
  int num_robot;
  double pair_dist;

  public void init( ) {
    Graphics g;
    num_robot = 8;
    robots = new Robot[num_robot];

    robotinit( );
    sleepTime = 1000;
    d = 200;
    dx = dy = 256;
    // dist0 = d * Math.sqrt(Math.pow(1 - Math.cos(Math.PI / 4), 2) + Math.pow(Math.sin(Math.PI / 4), 2));
    pair_dist = 2 * d * Math.sin(Math.PI / num_robot);
    resize(512,512);
    th1 = new Thread(this);
    th1.start();
  }

  public void robotinit(){
    for (int i=0; i < num_robot; i++) { 
        robots[i] = new Robot(i, 0, 0, 0);
        robots[i].move(i*50, i*1, 1);
    }
  }  
 
  public void robotnextmove(Graphics g) {
    int xold, yold;
    int xnew, ynew;
    int powdist, dist;

    for (int i=0; i < num_robot; i++) {
      /*
      * Here you have to compute a new location for each robot
      */
      xold = robots[i].getx();
      yold = robots[i].gety();
      xnew = xold;
      ynew = yold;

      /* hint1 */
      powdist = (int)Math.pow(xold - dx, 2) + (int)Math.pow(yold - dy, 2);
      dist = (int)Math.sqrt(powdist);

      /* hint1 change xnew and ynew using xlod and yold here */
      double x_diff = (double) xnew - dx;
      double y_diff = (double) ynew - dy;

      x_diff = x_diff / dist * d;
      y_diff = y_diff / dist * d;

      xnew = dx + (int) x_diff;
      ynew = dy + (int) y_diff;

      double close_1_dist = 1024.0, close_2_dist = 1024.0;
      int close_1_idx = i, close_2_idx = i;
      for (int j = 0; j < num_robot; j++) {
        if (i == j) continue;
        int x = robots[j].getx();
        int y = robots[j].gety();

        /* hint2 you need to update xnew and ynew  using dist1*/
        double dist1 = Math.sqrt(Math.pow(x - xnew, 2) + Math.pow(y - ynew, 2));

        xnew -= ((x - xnew) / dist1 * 10);
        ynew -= ((y - ynew) / dist1 * 10);
      }

      if (xnew < 0) xnew = Math.abs(xnew);
      if (xnew > 512) xnew = (xnew % 512);
      if (ynew < 10) ynew = Math.abs(ynew)+10;
      if (ynew > 512) ynew = (ynew % 512);

      /*
      * erase the old mark and move to a new location
      */
      paint(g, i, xold, yold, xnew, ynew);
      robots[i].move(xnew, ynew, 1);
      
    }
  }

  public void run( ) {
    try {
      while (true) {
        repaint();
        Thread.sleep(sleepTime);

      }
    } catch (Exception e) {
    
    }
  }

  public void update(Graphics g){
    robotnextmove(g);
  }

  public void paint(Graphics g, int i, int oldx, int oldy, int newx, int newy) {
      //g.drawRect(oldx, oldy-10, 10, 10);
    g.clearRect(oldx, oldy-10, 10, 10);
    g.setColor(Color.red);
    g.drawString(Integer.toHexString(i), newx, newy);
    /*
    * for your debugging
    * g.drawString(Integer.toHexString(newx) + ":" +
    * Integer.toHexString(newy), newx, newy);
    */

  } 
}
