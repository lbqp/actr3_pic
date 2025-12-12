
#ifndef ACTR_H
#define	ACTR_H

static unsigned short response=100001; 

void initACTR(void);


void initACTR(void);
void energize();
void deenergize();
void selectWell(unsigned char well);
void selectSignal(unsigned char signal);
void holdSample();
void releaseSample();
void makeADConversion();
void selectSource(unsigned char source);
    

#define ENERGIZE              0x00
#define DEENERGIZE            0x01
#define SELECT_WELL           0X02
#define SELECT_SIGNAL         0X03
#define HOLD_SAMPLE           0X04
#define RELEASE_SAMPLE        0X05
#define MAKE_AD_CONVERSION    0X06
#define SELECT_SOURCE         0x07

#define SOURCE_WELL           0x00
#define SOURCE_CAL            0x01



#endif	/* ACTR_H */

