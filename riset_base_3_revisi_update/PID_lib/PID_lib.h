/*
a library used for easyly when we want control omnidirectional robot
there three params that you must change to matching with your system, the parameter is kp ki kd
the derivative parameter has been filtered with low pas filter butterworth orde 1 with cut-off frequency 25Khz

example: 
#include "PID_lib.h"

//            dir1   dir2   pwm
PID_lib pid1(PE_11, PF_14, PE_13);
Timer t;

int main(){
    t.reset();
    t.start();

    while(1){
        float rpm = rpm.readRPM();
        pid1.pid_pwm(250 , 1.0 , 0.001 , 0.0003, rpm , t.read_high_resolution());
        wait(5);
        pid1.stop();
    }
}

*/

#ifndef PID_lib_H
#define PID_lib_H

#include "mbed.h"

class PID_lib {

public:

    PID_lib(PinName direction1, PinName direction2, PinName pulseWidth);
  
    void pid_speed(double target_, double kp_, double ki_, double kd_, double rpm, double t_);
    void stop();
    void manualPwm(double speed_);
    // double record_data(int dir_,double speed_,double freq, double t_r);
    // void useParams1();
    // void printParams();
    // void pos(double target_, double kp_, double ki_, double kd_, double angle_, double t_);
    float compute(double target_, double kp_ , double ki_ , double kd_, double sensor_);
    void reset_timer();

private:
       Timer tr;
       Timer t_pid;
       DigitalOut dir1;
       DigitalOut dir2;
       PwmOut pwm;
       double freq_rec;
       double rpm_rec;
       double rpm;
       double freq;
       double ppr;
    //    double angNow;
    //    double lastAng;
    //    double errAngle;
       double e;
       double laste;
       double eI;   
       double eD;
       double dt;
       double tim;
       double lastime;
       double pid;
       double pidSat;
       double pid_out;
       double pidPwm;
       double pwmLebih;
       double lastPid;
       double hP;
       double hI;
       double hD;
       double setI;
       
       double rpmFilt;
       double rpmFiltn1;
       double rpmn1;
};

#endif 
