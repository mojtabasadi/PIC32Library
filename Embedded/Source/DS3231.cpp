#include "DS3231.h"
RTCC::RTCC(unsigned long PBFrequency,double freq){RTCC::DS3231Init(PBFrequency,freq);}

uint8_t RTCC::DS3231Init(unsigned long PBFrequency,double freq)
{
    // Initialise I2C1 at 375kHz
    I2C1_init(PBFrequency,freq);
}
unsigned char RTCC::DS3231Read(unsigned char reg_address, unsigned char *value)
{   
    I2C1_start();                        /* Send start condition */  
    I2C1_write(DS3231_ADDRESS << 1, 1); /* Send MPU9250's address, read/write bit not set (AD + R) */  
    I2C1_write(reg_address, 1);          /* Send the register address (RA) */  
    I2C1_restart();                      /* Send repeated start condition */  
    I2C1_write(DS3231_ADDRESS << 1 | 1, 1); /* Send MPU9250's address, read/write bit set (AD + W) */  
    I2C1_read(value, 1);                 /* Read value from the I2C bus */  
    I2C1_stop();                         /* Send stop condition */  
}
void RTCC::DS3231Write(unsigned char reg_address, unsigned char value)
{
    unsigned char i2cbyte;
    I2C1_start();                        /* Send start condition */     
    i2cbyte=((value / 10) << 4) + (value % 10);
    I2C1_write(DS3231_ADDRESS << 1, 1); /* Send MPU9250's address, read/write bit not set (AD + R) */  
    I2C1_write(reg_address, 1);          /* Send the register address (RA) */  
    I2C1_write(i2cbyte, 1);                /* Send the value to set it to */  
    I2C1_stop();                         /* Send stop condition */  
}

unsigned char* RTCC::getRTCC(unsigned char time[])
{
    unsigned char ss,mm,hh;
    DS3231Read(SecAddress, &ss);
    time[0]=(ss >> 4) * 10 + (ss & 0x0F);
    DS3231Read(MinAddress, &mm);
    time[1]=(mm >> 4) * 10 + (mm & 0x0F);
    DS3231Read(HourAddress, &hh);
    time[2]=(hh >> 4) * 10 + (hh & 0x0F);
    return time;
}
unsigned char* RTCC::getDate(unsigned char date[])
{
    unsigned char yy,mm,dd;
    DS3231Read(YearAddress, &yy);
    date[0]=(yy >> 4) * 10 + (yy & 0x0F);
    DS3231Read(MonthAddress, &mm);
    date[1]=(mm >> 4) * 10 + (mm & 0x0F);
    DS3231Read(DateAddress, &dd);
    date[2]=(dd >> 4) * 10 + (dd & 0x0F);
    return date;
}
void RTCC::setRTCC(unsigned char h,unsigned char m,unsigned char s)
{
    DS3231Write(MinAddress,m);
    DS3231Write(HourAddress,h);
    DS3231Write(SecAddress,s);
}
void RTCC::setDate(unsigned char yy,unsigned char mm,unsigned char dd)
{
    DS3231Write(YearAddress,yy);
    DS3231Write(MonthAddress,mm);
    DS3231Write(DateAddress,dd);
}
/** Gregorian & Jalali (Hijri_Shamsi,Solar) Date Converter Functions
Author: JDF.SCR.IR =>> Download Full Version : http://jdf.scr.ir/jdf
License: GNU/LGPL _ Open Source & Free _ Version: 2.72 : [2017=1396]
--------------------------------------------------------------------
1461 = 365*4 + 4/4   &  146097 = 365*400 + 400/4 - 400/100 + 400/400
12053 = 365*33 + 32/4    &    36524 = 365*100 + 100/4 - 100/100   */
long* RTCC::gregorianTOjalali(long gy,long gm,long gd,long out[])
{
 long gy2,days,jy,jm,jd, g_d_m[12]={0,31,59,90,120,151,181,212,243,273,304,334};
 if(gy>1600){
  jy=979;
  gy-=1600;
 }else{
  jy=0;
  gy-=621;
 }
 gy2=(gm>2)?(gy+1):gy;
 days=(365*gy) +((int)((gy2+3)/4)) -((int)((gy2+99)/100)) +((int)((gy2+399)/400)) -80 +gd +g_d_m[gm-1];
 jy+=33*((int)(days/12053)); 
 days%=12053;
 jy+=4*((int)(days/1461));
 days%=1461;
 if(days > 365){
  jy+=(int)((days-1)/365);
  days=(days-1)%365;
 }
 jm=(days < 186)?1+(int)(days/31):7+(int)((days-186)/30);
 jd=1+((days < 186)?(days%31):((days-186)%30));
 out[0]=jy;
 out[1]=jm;
 out[2]=jd;
 return out;
}


long* RTCC::jalaliTOgregorian(long jy,long jm,long jd,long out[])
{
 long days,gy,gm,gd, sal_a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 if(jy>979){
  gy=1600;
  jy-=979;
 }else{
  gy=621;
 }
 days=(365*jy) +(((int)(jy/33))*8) +((int)(((jy%33)+3)/4)) +78 +jd +((jm<7)?(jm-1)*31:((jm-7)*30)+186);
 gy+=400*((int)(days/146097));
 days%=146097;
 if(days > 36524){
  gy+=100*((int)(--days/36524));
  days%=36524;
  if(days >= 365)days++;
 }
 gy+=4*((int)(days/1461));
 days%=1461;
 if(days > 365){
  gy+=(int)((days-1)/365);
  days=(days-1)%365;
 }
 gd=days+1;
 if((gy%4==0 && gy%100!=0) || (gy%400==0))sal_a[2]=29;
 for(gm=0;gm<13;gm++){
  long v=sal_a[gm];
  if(gd <= v)break;
  gd-=v;
 }
 out[0]=gy;
 out[1]=gm;
 out[2]=gd;
 return out;
}
