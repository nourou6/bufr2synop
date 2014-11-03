/***************************************************************************
 *   Copyright (C) 2004-2014 by Guillermo Ballester Valor                  *
 *   gbv@ogimet.com                                                        *
 *                                                                         *
 *   This file is part of bufr2synop                                       *
 *                                                                         *
 *   Ogimet is free software; you can redistribute it and/or modify        *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   Ogimet is distributed in the hope that it will be useful,             *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/
/*! 
   \file mettemp.h
   \brief Main header file for temp report related tasks 
*/
#ifndef METTEMP_H
#define METTEMP_H

/*!
  \def TEMP_PART_A 
  \brief mask bit meaning part A of TEMP report is solicited to or parsed with success
*/
#define TEMP_PART_A 1

/*!
  \def TEMP_PART_B 
  \brief mask bit meaning part B of TEMP report is solicited to or parsed with success
*/
#define TEMP_PART_B 2

/*!
  \def TEMP_PART_C 
  \brief mask bit meaning part C of TEMP report is solicited to or parsed with success
*/
#define TEMP_PART_C 4

/*!
  \def TEMP_PART_D 
  \brief mask bit meaning part D of TEMP report is solicited to or parsed with success
*/

#define TEMP_PART_D 8

/*!
  \def TEMP_SEC_1 
  \brief mask bit meaning sec 1 of a part of TEMP report parsed with success
*/
#define TEMP_SEC_1  (1)

/*!
  \def TEMP_SEC_2 
  \brief mask bit meaning sec 2 of a part of TEMP report parsed with success
*/
#define TEMP_SEC_2  (2)

/*!
  \def TEMP_SEC_3 
  \brief mask bit meaning sec 3 of a part of TEMP report parsed with success
*/
#define TEMP_SEC_3  (4)

/*!
  \def TEMP_SEC_4 
  \brief mask bit meaning sec 4 of a part of TEMP report parsed with success
*/
#define TEMP_SEC_4  (8)

/*!
  \def TEMP_SEC_5 
  \brief mask bit meaning sec 5 of a part of TEMP report parsed with success
*/
#define TEMP_SEC_5  (16)

/*!
  \def TEMP_SEC_6 
  \brief mask bit meaning sec 6 of a part of TEMP report parsed with success
*/
#define TEMP_SEC_6  (32)

/*!
  \def TEMP_SEC_7 
  \brief mask bit meaning sec 7 of a part of TEMP report parsed with success
*/
#define TEMP_SEC_7  (64)

/*!
  \def TEMP_SEC_8 
  \brief mask bit meaning sec 8 of a part of TEMP report parsed with success
*/
#define TEMP_SEC_8  (128)

/*!
  \def TEMP_SEC_9 
  \brief mask bit meaning sec 9 of a part of TEMP report parsed with success
*/
#define TEMP_SEC_9  (256)

/*!
  \def TEMP_SEC_10 
  \brief mask bit meaning sec 1 of a part of TEMP report parsed with success
*/
#define TEMP_SEC_10  (512)

/*!
  \def TEMP_NSTAND_MAX
  \brief Maximum number of standard levels in any part of a TEMP report
*/
#define TEMP_NSTAND_MAX (16)

/*!
  \def TEMP_NMAXWIND_MAX
  \brief Maximum number of mwx wind level in any part of a TEMP report
*/
#define TEMP_NMAXWIND_MAX (4)

/*!
  \def TEMP_NMAX_POINTS
  \brief maximum number of significant points 
*/
#define TEMP_NMAX_POINTS (64)

struct temp_main_level_data {
   char PnPnPn[4]; /*!< Pressure in hPa at evel omiting thousand unit */
   char TnTn[4]; /*!< Temperature . Whole degrees */
   char Tan[2]; /*!< tenth and sign of temperature (Code Table 3931) */
   char DnDn[4]; /*!< Dewpoint depression . (Code table 0777) */
   char dndn[4]; /*!< true wind direction in tens of degree */
   char fnfnfn[4]; /*!< Wind speed */
}; /*!< Detailed data at a main level (surface, tropopause ...)*/

struct temp_std_level_data {
   char PnPn[4]; /*!< Pressure in hPa at standard level int tens of hPa. 1000 = '00' , 925 = '92' */
   char hnhnhn[4]; /*!< Altitude (in mgp) of standard levels */
   char TnTn[4]; /*!< Temperature . Whole degrees */
   char Tan[2]; /*!< tenth and sign of temperature (Code Table 3931) */
   char DnDn[4]; /*!< Dewpoint depression . (Code table 0777) */
   char dndn[4]; /*!< true wind direction in tens of degree */
   char fnfnfn[4]; /*!< Wind speed */
}; 


struct temp_max_wind_data {
   char PmPmPm[4]; /*!< Pressure in hPa of wind maximum level */
   char dmdm[4]; /*!< true wind direction in tens of degree */
   char fmfmfm[4]; /*!< Wind speed */
   char vbvb[4]; /*!< Diference of winds . 1 km below */
   char vava[4]; /*!< Diference of winds . 1 km above */
};

struct temp_th_point {
   char PnPnPn[4]; /*!< Pressure in hPa at evel omiting thousand unit */
   char TnTn[4]; /*!< Temperature . Whole degrees */
   char Tan[2]; /*!< tenth and sign of temperature (Code Table 3931) */
   char DnDn[4]; /*!< Dewpoint depression . (Code table 0777) */
};

struct temp_wind_point {
   char PnPnPn[4]; /*!< Pressure in hPa at evel omiting thousand unit */
   char dndn[4]; /*!< true wind direction in tens of degree */
   char fnfnfn[4]; /*!< Wind speed */
};

struct temp_acd_sec1 {
   char MiMi[4]; /*!< MiMi item. (Code table 2582) */
   char MjMj[4]; /*!< MjMj item. (Code table 2582) */
   char A1[2]; /*!< A1 item. WMO region */
   char bw[2]; /*!< bw item. WMO subregion */
   char D_D[10]; /*!< Ship signal or mobile land station indentifier*/
   char YY[4]; /*!< Day (UTC) of observation . If wind units are in knots, add 50 to day */
   char GG[4]; /*!< Hour (UTC) of observation */
   char id[2]; /*!< Indicator for standard isobaric levels included for wind */
   char II[4]; /*!< Regional indicator for a synop station index */
   char iii[4]; /*!< Station index  */
   char Reg[4]; /*!< WMO IIiii region 'I','II','III', 'IV', 'V', ... */
   char IIIII[10]; /*!< Ship index name */
   char LaLaLa[4]; /*!< Latitude in degree tenths */
   char Qc[2]; /*!< Quadrant of the globe. (Code table 3333) */
   char LoLoLoLo[6]; /*!< Longitude in degree tenths */
   char MMM[4]; /*!< Number of Marsden square (Code table 2590) */
   char Ula[2]; /*!< Unit digit in the reported latitude. */
   char Ulo[2]; /*!< Units digit in the reported longitude. */
   char h0h0h0h0[6]; /*!< Elevation of a mobile land station  */
   char im[2]; /*!< Indicator for units of elevation, and confidence factor for accuracy of elevation. (Code table 1845) */
}; /*!< Section 1 for a part A, C or D of a TEMP report */

struct temp_b_sec1 {
   char MiMi[4]; /*!< MiMi item. (Code table 2582) */
   char MjMj[4]; /*!< MjMj item. (Code table 2582) */
   char A1[2]; /*!< A1 item. WMO region */
   char bw[2]; /*!< bw item. WMO subregion */
   char D_D[10]; /*!< Ship signal or mobile land station indentifier*/
   char YY[4]; /*!< Day (UTC) of observation . If wind units are in knots, add 50 to day */
   char GG[4]; /*!< Hour (UTC) of observation */
   char a4[2]; /*!< Type of measuring equipment used. (Code table 0265) */
   char II[4]; /*!< Regional indicator for a synop station index */
   char iii[4]; /*!< Station index  */
   char Reg[4]; /*!< WMO IIiii region 'I','II','III', 'IV', 'V', ... */
   char IIIII[10]; /*!< Ship index name */
   char LaLaLa[4]; /*!< Latitude in degree tenths */
   char Qc[2]; /*!< Quadrant of the globe. (Code table 3333) */
   char LoLoLoLo[6]; /*!< Longitude in degree tenths */
   char MMM[4]; /*!< Number of Marsden square (Code table 2590) */
   char Ula[2]; /*!< Unit digit in the reported latitude. */
   char Ulo[2]; /*!< Units digit in the reported longitude. */
   char h0h0h0h0[6]; /*!< Elevation of a mobile land station  */
   char im[2]; /*!< Indicator for units of elevation, and confidence factor for accuracy of elevation. (Code table 1845) */
}; /*!< Section 1 for a part A of a TEMP report */


struct temp_a_sec2 {
   int n; /*!< current number of standard levels */
   struct temp_main_level_data lev0; /*!< data at starting point */
   struct temp_std_level_data std[TEMP_NSTAND_MAX]; /*!< Array with data at standard levels */
}; /*!< Section 2 for a part A of a TEMP report */

struct temp_c_sec2 {
   int n; /*!< current number of standard levels */
   struct temp_std_level_data std[TEMP_NSTAND_MAX]; /*!< Array with data at standard levels */
}; /*!< Section 2 for a part A of a TEMP report */

struct temp_ac_sec3 {
   struct temp_main_level_data trop; /*!< data at starting tropopause */
}; /*!< Section 3 for a part A and C of a TEMP report */

struct temp_ac_sec4 {
   struct temp_max_wind_data windx[TEMP_NMAXWIND_MAX];
}; /*!< Section 4 for a part A and C of TEMP report */

struct temp_sec7 {
   char sr[2]; /*!< Solar radiation correction (code table 3849)*/
   char rara[4]; /*!< Radiosonde/sounding system used. (Code table 3685) */
   char sasa[4]; /*!< Tracking technique/status of system used. (Code table 3872) */
   char GG[4]; /*!< actual time of launching the radiosonde, Hour */
   char gg[4]; /*!< actual time of launching the radiosonde, minute */
   char sn[2];  /*!< Sign of temperature (Code table 3845) */
   char TwTwTw[4]; /*!< Sea-surface temperature, in tenths of a degree Celsius, its sign being given by sn.*/
}; /*!< Section 7 for a part of TEMP report */

struct temp_bd_sec5 {
  int n; /*!< current number of points */
  struct temp_th_point th[TEMP_NMAX_POINTS]; /*!< Significant th points for sec 5 for a part B */
};/*!< Section 5 for a part B or D of TEMP report */

struct temp_bd_sec6 {
  int n; /*!< current number of points */
  struct temp_wind_point wd[TEMP_NMAX_POINTS]; /*!< Significant wind points for sec 6 for a part B */
};/*!< Section 6 for a part B or D of TEMP report */


struct temp_b_sec8 {
   char Nh[2]; /*!< Amount of all the CL cloud present or, if no CL cloud is present, the amount of all the CM cloud present. (Code table 2700) */
   char Cl[2]; /*!< Clouds of the genera Stratocumulus, Stratus, Cumulus and Cumulonimbus. (Code table 0513) */
   char h[2]; /*!< Height above surface of the base of the lowest cloud seen. (Code table 1600) */
   char Cm[2]; /*!< Clouds of the genera Altocumulus, Altostratus and Nimbostratus. (Code table 0515) */
   char Ch[2]; /*!< Clouds of the genera Cirrus, Cirrocumulus and Cirrostratus. (Code table 0509)  */
}; /*!< Section 8 for a part B of TEMP report */

struct temp_a {
  int mask; /*!< Bit mask about parsed sections */
  struct report_date_ext e; /*!< report extension date/time */
  struct temp_acd_sec1 s1; /*!< section 1 for part A */
  struct temp_a_sec2 s2; /*!< section 2 for part A */
  struct temp_ac_sec3 s3; /*!< section 3 for part A */
  struct temp_ac_sec4 s4; /*!< section 4 for part A */
  struct temp_sec7 s7; /*!< section 7 for part A */
}; /*!< Contains part A of a TEMP REPORT */

struct temp_b {
  int mask; /*!< Bit mask about parsed sections */
  struct report_date_ext e; /*!< report extension date/time */
  struct temp_b_sec1 s1; /*!< section 1 for part B */
  struct temp_bd_sec5 s5; /*!< section 5 for part B */
  struct temp_bd_sec6 s6; /*!< section 6 for part B */
  struct temp_sec7 s7; /*!< section 7 for part B */
  struct temp_b_sec8 s8; /*!< section 8 for part B */
}; /*!< Contains part B of a TEMP REPORT */

struct temp_c {
  int mask; /*!< Bit mask about parsed sections */
  struct report_date_ext e; /*!< report extension date/time */
  struct temp_acd_sec1 s1; /*!< section 1 for part C */
  struct temp_c_sec2 s2; /*!< section 2 for part C */
  struct temp_ac_sec3 s3; /*!< section 3 for part C */
  struct temp_ac_sec4 s4; /*!< section 4 for part C */
  struct temp_sec7 s7; /*!< section 7 for part C */
}; /*!< Contains part C of a TEMP REPORT */

struct temp_d {
  int mask; /*!< Bit mask about parsed sections */
  struct report_date_ext e; /*!< report extension date/time */
  struct temp_acd_sec1 s1; /*!< section 1 for part D */
  struct temp_bd_sec5 s5; /*!< section 5 for part D */
  struct temp_bd_sec6 s6; /*!< section 6 for part D */
  struct temp_sec7 s7; /*!< section 7 for part D */
}; /*!< Contains part D of a TEMP REPORT */

struct temp_chunks {
  int mask; /*!< bit mask with parsed parts info */
  struct temp_a a; /*!< Part A */
  struct temp_b b; /*!< Part B */
  struct temp_c c; /*!< Part C */
  struct temp_d d; /*!< Part D */
};

#endif