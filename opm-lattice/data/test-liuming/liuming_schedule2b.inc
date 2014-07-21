RPTSCHED
'PRES' 'SOIL' 'SWAT' 'RESTART=2' 'FIP=1' 'WELLS=1' 'SUMMARY=1' /
  
RPTSCHED
'RESTART=2' 'FIP=2' 'WELLS=2' 'VFPPROD=1' 'CPU=2' 'WELSPECS' 'FIPTR=2' 
/
  
WELSPECS
--Well specification data
 'INJE1 '  'G'   5  10  12000  'WATER' /
 'PROD1 '  'G'   1   1  12000  'OIL' /
 'PROD2 '  'G'   1  20  12000  'OIL' /
 'PROD3 '  'G'  10   1  12000  'OIL' /
 'PROD4 '  'G'  10  20  12000  'OIL' /
/

COMPDAT
--Define connection data
 'INJE1 '  2*   1   1  'OPEN'  2*  1.0  1*  /
 'PROD1 '  2*   1   1  'OPEN'  2*  1.0  1*  /
 'PROD2 '  2*   1   1  'OPEN'  2*  1.0  1*  /
 'PROD3 '  2*   1   1  'OPEN'  2*  1.0  1*  /
 'PROD4 '  2*   1   1  'OPEN'  2*  1.0  1*  /
/

WCONPROD
 'PROD1 '  OPEN  ORAT  1.5  1*  1*  1*  1*  1*   /
 'PROD2 '  OPEN  ORAT  1.5  1*  1*  1*  1*  1*   /
 'PROD3 '  OPEN  ORAT  1.5  1*  1*  1*  1*  1*   /
 'PROD4 '  OPEN  ORAT  1.5  1*  1*  1*  1*  1*   /
/

WCONINJE
--                              Max        BHP
--                              Rate       limit
 'INJE1' 'WATER' 'OPEN' 'RATE'  6   1*    10000  /
/

TUNING
0.1 5 8* / 
11* / 
2* 80 30 6* /

TSTEP
 50 50 50 50          -- to day 200
 50 50 50 50 50 50
 50 50 50 50 50 50
 50 50 50 50 50 50
 50 50 50 50 50 50
 50 50 50 50 50 50
 50 50 50 50 50 50 /  -- to day 2000
 