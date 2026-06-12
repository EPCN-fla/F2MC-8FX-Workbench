/*
 F2MC-8L family CPU definition file V30L08
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU LIMITED 1998
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU LIMITED
*/

/******************/
/* MB891xx Series */
/******************/
#if   defined(__CPU_MB89120__) || defined(__CPU_MB89120A__) || \
      defined(__CPU_MB89121__) || defined(__CPU_MB89123A__) || \
      defined(__CPU_MB89125__) || defined(__CPU_MB89125A__)
#define __CPU_MB89120_SERIES

#elif defined(__CPU_MB89130__)  || defined(__CPU_MB89130A__)  || \
      defined(__CPU_MB89131__)  || defined(__CPU_MB89P131__)  || \
      defined(__CPU_MB89133A__) || defined(__CPU_MB89P133A__) || \
      defined(__CPU_MB89135A__) || defined(__CPU_MB89P135A__) || \
      defined(__CPU_MB89135L__) || defined(__CPU_MB89PV130A__)
#define __CPU_MB89130_SERIES

#elif defined(__CPU_MB89140__)  || defined(__CPU_MB89145__)  || \
      defined(__CPU_MB89146__)  || defined(__CPU_MB89P147__) || \
      defined(__CPU_MB89PV140__)
#define __CPU_MB89140_SERIES

#elif defined(__CPU_MB89143A__) || defined(__CPU_MB89144A__)
#define __CPU_MB89143A_SERIES

#elif defined(__CPU_MB89150__)  || defined(__CPU_MB89150A__)  || \
      defined(__CPU_MB89151__)  || defined(__CPU_MB89151A__)  || \
      defined(__CPU_MB89152__)  || defined(__CPU_MB89152A__)  || \
      defined(__CPU_MB89153__)  || defined(__CPU_MB89153A__)  || \
      defined(__CPU_MB89154__)  || defined(__CPU_MB89154A__)  || \
      defined(__CPU_MB89155__)  || defined(__CPU_MB89155A__)  || \
      defined(__CPU_MB89P155__) || defined(__CPU_MB89P155A__) || \
      defined(__CPU_MB89PV150__)
#define __CPU_MB89150_SERIES

#elif defined(__CPU_MB89160__)  || defined(__CPU_MB89160A__) || \
      defined(__CPU_MB89161__)  || defined(__CPU_MB89161A__) || \
      defined(__CPU_MB89163__)  || defined(__CPU_MB89163A__) || \
      defined(__CPU_MB89165__)  || defined(__CPU_MB89165A__) || \
      defined(__CPU_MB89P165__) || defined(__CPU_MB89W165__) || \
      defined(__CPU_MB89PV160__)
#define __CPU_MB89160_SERIES

#elif defined(__CPU_MB89170__)    || defined(__CPU_MB89170A__)  || \
      defined(__CPU_MB89173__)    || defined(__CPU_MB89P173__)  || \
      defined(__CPU_MB89174A__)   || defined(__CPU_MB89P175A__) || \
      defined(__CPU_MB89PV170A__) || defined(__CPU_MB89170L__)  || \
      defined(__CPU_MB89173L__)   || defined(__CPU_MB89174L__)
#define __CPU_MB89170_SERIES

#elif defined(__CPU_MB89180__) || \
      defined(__CPU_MB89181__) || defined(__CPU_MB89182__)  || \
      defined(__CPU_MB89183__) || defined(__CPU_MB89184__)  || \
      defined(__CPU_MB89185__) || defined(__CPU_MB89P185__) || \
      defined(__CPU_MB89PV180__)
#define __CPU_MB89180_SERIES

#elif defined(__CPU_MB89190__)   || defined(__CPU_MB89190A__)  || \
      defined(__CPU_MB89191__)   || defined(__CPU_MB89191A__)  || \
      defined(__CPU_MB89193__)   || defined(__CPU_MB89193A__)  || \
      defined(__CPU_MB89195__)   || defined(__CPU_MB89195A__)  || \
      defined(__CPU_MB89P195__)  || defined(__CPU_MB89P195A__) || \
      defined(__CPU_MB89PV190__) || defined(__CPU_MB89PV190A__)
#define __CPU_MB89190_SERIES

/******************/
/* MB895xx Series */
/******************/
#elif defined(__CPU_MB89530__)   || defined(__CPU_MB89537__)  || \
      defined(__CPU_MB89537C__)  || defined(__CPU_MB89537H__) || \
      defined(__CPU_MB89537HC__) || \
      defined(__CPU_MB89538__)   || defined(__CPU_MB89P538__) || \
      defined(__CPU_MB89538C__)  || defined(__CPU_MB89538H__) || \
      defined(__CPU_MB89538HC__) || \
      defined(__CPU_MB89PV530__)
#define __CPU_MB89530_SERIES

#elif defined(__CPU_MB89550A__)   || defined(__CPU_MB89557A__)  || \
      defined(__CPU_MB89558A__)   || defined(__CPU_MB89P558A__) || \
      defined(__CPU_MB89PV550A__)
#define __CPU_MB89550_SERIES

#elif defined(__CPU_MB89560__)  || defined(__CPU_MB89567__)   || \
      defined(__CPU_MB89P568__) || defined(__CPU_MB89PV560__) || \
      defined(__CPU_MB89567H__) || defined(__CPU_MB89567C__)  || \
      defined(__CPU_MB89567HC__)
#define __CPU_MB89560_SERIES

#elif defined(__CPU_MB89570__)  || defined(__CPU_MB89PV570__) || \
      defined(__CPU_MB89P578__) || defined(__CPU_MB89577__)
#define __CPU_MB89570_SERIES

#elif defined(__CPU_MB89580__) || defined(__CPU_MB89583__)  || \
      defined(__CPU_MB89585__) || defined(__CPU_MB89P585__)
#define __CPU_MB89580_SERIES

#elif defined(__CPU_MB89590__) || defined(__CPU_MB89593__)  || \
      defined(__CPU_MB89595__) || defined(__CPU_MB89P595__)
#define __CPU_MB89590_SERIES

/*******************/
/* MB896xxx Series */
/*******************/
#elif defined(__CPU_MB89601R__) || defined(__CPU_MB89P601__) || \
      defined(__CPU_MB89603R__) || defined(__CPU_MB89603__)  || \
      defined(__CPU_MB89601__)
#define __CPU_MB89601_SERIES

#elif defined(__CPU_MB89610__) || defined(__CPU_MB89610R__) || \
      defined(__CPU_MB89613__) || defined(__CPU_MB89613R__) || \
      defined(__CPU_MB89615__) || defined(__CPU_MB89615R__)
#define __CPU_MB89610_SERIES

#elif defined(__CPU_MB89620__)   || defined(__CPU_MB89620R__)  || \
      defined(__CPU_MB89623__)   || defined(__CPU_MB89623R__)  || \
      defined(__CPU_MB89T623R__) || \
      defined(__CPU_MB89T623__)  || defined(__CPU_MB89V623__)  || \
      defined(__CPU_MB89625__)   || defined(__CPU_MB89625R__)  || \
      defined(__CPU_MB89W625__)  || defined(__CPU_MB89P625__)  || \
      defined(__CPU_MB89T625__)  || defined(__CPU_MB89V625__)  || \
      defined(__CPU_MB89T625R__) || \
      defined(__CPU_MB89626__)   || defined(__CPU_MB89626R__)  || \
      defined(__CPU_MB89627__)   || defined(__CPU_MB89627R__)  || \
      defined(__CPU_MB89W627__)  || defined(__CPU_MB89P627__)  || \
      defined(__CPU_MB89T627__)  || defined(__CPU_MB89T627R__) || \
      defined(__CPU_MB89628R__)  || defined(__CPU_MB89629R__)  || \
      defined(__CPU_MB89W629__)  || defined(__CPU_MB89P629__)  || \
      defined(__CPU_MB89PV620__)
#define __CPU_MB89620_SERIES

#elif defined(__CPU_MB89630__)  || defined(__CPU_MB89630R__)  || \
      defined(__CPU_MB89635__)  || defined(__CPU_MB89635R__)  || \
      defined(__CPU_MB89T635__) || defined(__CPU_MB89T635R__) || \
      defined(__CPU_MB89636__)  || defined(__CPU_MB89636R__)  || \
      defined(__CPU_MB89637__)  || defined(__CPU_MB89637R__)  || \
      defined(__CPU_MB89W637__) || defined(__CPU_MB89P637__)  || \
      defined(__CPU_MB89T637__) || defined(__CPU_MB89T637R__) || \
      defined(__CPU_MB89PV630__)
#define __CPU_MB89630_SERIES

#elif defined(__CPU_MB89640__)  || defined(__CPU_MB89643__)  || \
      defined(__CPU_MB89645__)  || defined(__CPU_MB89646__)  || \
      defined(__CPU_MB89647__)  || defined(__CPU_MB89P647__) || \
      defined(__CPU_MB89PV640__)
#define __CPU_MB89640_SERIES

#elif defined(__CPU_MB89650A__)   || defined(__CPU_MB89653A__)  || \
      defined(__CPU_MB89653AR__)  || defined(__CPU_MB89655A__)  || \
      defined(__CPU_MB89655AR__)  || defined(__CPU_MB89656A__)  || \
      defined(__CPU_MB89656AR__)  || defined(__CPU_MB89657A__)  || \
      defined(__CPU_MB89657AR__)  || defined(__CPU_MB89P657__)  || \
      defined(__CPU_MB89PV650A__) || defined(__CPU_MB89P657A__)
#define __CPU_MB89650_SERIES

#elif defined(__CPU_MB89660__)  || defined(__CPU_MB89660R__) || \
      defined(__CPU_MB89663__)  || defined(__CPU_MB89663R__) || \
      defined(__CPU_MB89665__)  || defined(__CPU_MB89665R__) || \
      defined(__CPU_MB89W665__) || defined(__CPU_MB89P665__)
#define __CPU_MB89660_SERIES

#elif defined(__CPU_MB89670__)   || defined(__CPU_MB89673__)    || \
      defined(__CPU_MB89673R__)  || defined(__CPU_MB89673AR__)  || \
      defined(__CPU_MB89675R__)  || defined(__CPU_MB89675AR__)  || \
      defined(__CPU_MB89677__)   || \
      defined(__CPU_MB89677A__)  || defined(__CPU_MB89677AR__)  || \
      defined(__CPU_MB89P677A__) || defined(__CPU_MB89PV670A__)
#define __CPU_MB89670_SERIES
#if defined(__CPU_MB89PV670A__) || defined(__CPU_MB89673AR__) || \
    defined(__CPU_MB89675AR__)  || defined(__CPU_MB89677A__)  || \
    defined(__CPU_MB89677AR__)  || defined(__CPU_MB89P677A__)
#define __CPU_MB89670A_SERIES
#endif

#elif defined(__CPU_MB89680__)   || defined(__CPU_MB89689__)  || \
      defined(__CPU_MB89P689__)  || defined(__CPU_MB89W689__) || \
      defined(__CPU_MB89PV680__)
#define __CPU_MB89680_SERIES

#elif defined(__CPU_MB89690A__)   || defined(__CPU_MB89695A__)  || \
      defined(__CPU_MB89697A__)  || defined(__CPU_MB89P698A__)
#define __CPU_MB89690_SERIES

/******************/
/* MB898xx Series */
/******************/
#elif defined(__CPU_MB89800__) || defined(__CPU_MB89803__)  || \
      defined(__CPU_MB89805__) || defined(__CPU_MB89P808__) || \
      defined(__CPU_MB89PV800__)
#define __CPU_MB89800_SERIES

#elif defined(__CPU_MB89810A__)  || defined(__CPU_MB89816A__) || \
      defined(__CPU_MB89P817A__)
#define __CPU_MB89810A_SERIES

#elif defined(__CPU_MB89820__) || defined(__CPU_MB89821__)  || \
      defined(__CPU_MB89823__) || defined(__CPU_MB89P825__) || \
      defined(__CPU_MB89PV820__)
#define __CPU_MB89820_SERIES

#elif defined(__CPU_MB89830__) || defined(__CPU_MB89836__)  || \
      defined(__CPU_MB89837__) || defined(__CPU_MB89P837__) || \
      defined(__CPU_MB89PV830__)
#define __CPU_MB89830_SERIES

#elif defined(__CPU_MB89850__)  || defined(__CPU_MB89855__) || \
      defined(__CPU_MB89855R__) || \
      defined(__CPU_MB89T855__) || defined(__CPU_MB89857__) || \
      defined(__CPU_MB89P857__) || defined(__CPU_MB89W857__)
#define __CPU_MB89850_SERIES

#elif defined(__CPU_MB89860__)  || defined(__CPU_MB89865__)  || \
      defined(__CPU_MB89867__)  || defined(__CPU_MB89P867__) || \
      defined(__CPU_MB89W867__)
#define __CPU_MB89860_SERIES

#elif defined(__CPU_MB89863__)
#define __CPU_MB89863_SERIES

#elif defined(__CPU_MB89870__)  || defined(__CPU_MB89875__)  || \
      defined(__CPU_MB89P875__) || defined(__CPU_MB89PV870__)
#define __CPU_MB89870_SERIES

#elif defined(__CPU_MB89880__)  || defined(__CPU_MB89888__)  || \
      defined(__CPU_MB89P888__) || defined(__CPU_MB89PV880__)
#define __CPU_MB89880_SERIES

#elif defined(__CPU_MB89890__) || defined(__CPU_MB89898__)  || \
      defined(__CPU_MB89899__) || defined(__CPU_MB89P899__) || \
      defined(__CPU_MB89PV890__)
#define __CPU_MB89890_SERIES

/******************/
/* MB899xx Series */
/******************/
#elif defined(__CPU_MB89910__)  || defined(__CPU_MB89915__)   || \
      defined(__CPU_MB89P915__) || defined(__CPU_MB89PV910__) || \
      defined(__CPU_MB89P913__) || defined(__CPU_MB89913__)
#define __CPU_MB89910_SERIES

#elif defined(__CPU_MB89920__) || defined(__CPU_MB89923__)  || \
      defined(__CPU_MB89925__) || defined(__CPU_MB89P928__) || \
      defined(__CPU_MB89PV920__)
#define __CPU_MB89920_SERIES

#elif defined(__CPU_MB89930A__)  || defined(__CPU_MB89935A__) || \
      defined(__CPU_MB89P935A__) || defined(__CPU_MB89PV930A__)
#define __CPU_MB89930_SERIES

#elif defined(__CPU_MB89940__)  || defined(__CPU_MB89943__) || \
      defined(__CPU_MB89P945__) || defined(__CPU_MB89PV940__)
#define __CPU_MB89940_SERIES

#elif defined(__CPU_MB89950__) || defined(__CPU_MB89951__)  || \
      defined(__CPU_MB89953__) || defined(__CPU_MB89P955__) || \
      defined(__CPU_MB89PV950__)
#define __CPU_MB89950_SERIES

#elif defined(__CPU_MB89960__)  || defined(__CPU_MB89965__)   || \
      defined(__CPU_MB89P965__) || defined(__CPU_MB89PV960__) || \
      defined(__CPU_MB89P965A__)
#define __CPU_MB89960_SERIES

#elif defined(__CPU_MB89980__)  || defined(__CPU_MB89983__)   || \
      defined(__CPU_MB89P985__) || defined(__CPU_MB89PV980__)
#define __CPU_MB89980_SERIES

#elif defined(__CPU_MB89990__) || defined(__CPU_MB89995__) || \
      defined(__CPU_MB89997__)
#define __CPU_MB89990_SERIES

/**********/
/* Others */
/**********/
#else
#error "The I/O register file of the specified CPU option does not exist"

#endif
