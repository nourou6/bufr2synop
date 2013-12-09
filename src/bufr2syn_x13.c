/***************************************************************************
 *   Copyright (C) 2012 by Guillermo Ballester Valor                       *
 *   gbv@ogimet.com                                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
/*!
 \file bufr2syn_x13.c
 \brief decodes the descriptors with X = 13 . Precipitation and hidrology
 */
#include "bufr2synop.h"

char * prec_to_RRR ( char *target, double r )
{
  if ( r == 0.0 )
    strcpy ( target,"000" );
  else if ( r < 0.1 )
    strcpy ( target,"990" );
  else if ( r < 1.0 )
    sprintf ( target, "99%d", ( int ) ( r * 10.0 ) );
  else
    sprintf ( target, "%03d", ( int ) ( r ) );
  return target;

}

char * prec_to_RRRR ( char *target, double r )
{
  if ( r < 0.0||(r > 0.0 && r < 0.1))
    strcpy ( target,"9999" );
  else if ( r <= 999.8 )
    sprintf ( target,"%04d", ( int ) ( r * 10.0 ) );
  else
    strcpy ( target,"9998" );
  return target;
}

char * prec_to_RRRR24 ( char *target, double r )
{
  if ( r < 0.0 || (r > 0.0 && r < 0.1))
    strcpy ( target,"9999" );
  else if ( r <= 999.8 )
    sprintf ( target,"%04d", ( int ) ( r * 10.0 ) );
  else
    strcpy ( target,"9998" );
  return target;
}


int syn_parse_x13 ( struct synop_chunks *syn, struct bufr_subset_state *s, char *err )
{
  switch ( s->a->desc.y )
    {
    case 11: // 0 13 011
      if ( s->itval ==  -3600 )
        {
          if (syn->s3.RRR[0] == 0)
            {
              syn->s3.tr[0] = '5'; // 1 hour
              prec_to_RRR ( syn->s3.RRR, s->val );
              syn->mask |= SYNOP_SEC3;
            }
        }
      else if ( s->itval == -7200 )
        {
          if (syn->s1.RRR[0] == 0)
            {
              syn->s1.tr[0] = '6'; // 2 hour
              prec_to_RRR ( syn->s1.RRR, s->val );
            }
        }
      else if ( s->itval == -10800 )
        {
          if (syn->s3.RRR[0] == 0)
            {
              syn->s3.tr[0] = '7'; // 3 hour
              prec_to_RRR ( syn->s3.RRR, s->val );
              syn->mask |= SYNOP_SEC3;
            }
        }
      else if ( s->itval == - ( 6 * 3600 ) )
        {
          if (syn->s1.RRR[0] == 0)
            {
              syn->s1.tr[0] = '1'; // 6 hour
              prec_to_RRR ( syn->s1.RRR, s->val );
            }
        }
      else if ( s->itval == - ( 9 * 3600 ) )
        {
          if (syn->s3.RRR[0] == 0)
            {
              syn->s3.tr[0] = '8'; // 9 hour
              prec_to_RRR ( syn->s3.RRR, s->val );
              syn->mask |= SYNOP_SEC3;
            }
        }
      else if ( s->itval == - ( 12 * 3600 ) )
        {
          if (syn->s1.RRR[0] == 0 || syn->s1.tr[0] == '4')
            {
              syn->s1.tr[0] = '2'; // 12 hour
              prec_to_RRR ( syn->s1.RRR, s->val );
            }
        }
      else if ( s->itval == - ( 15 * 3600 ) )
        {
          if (syn->s3.RRR[0] == 0)
            {
              syn->s3.tr[0] = '9'; // 15 hour
              prec_to_RRR ( syn->s3.RRR, s->val );
              syn->mask |= SYNOP_SEC3;
            }
        }
      else if ( s->itval == - ( 18 * 3600 ) )
        {
          if (syn->s1.RRR[0] == 0)
            {
              syn->s1.tr[0] = '3'; // 12 hour
              prec_to_RRR ( syn->s1.RRR, s->val );
            }
        }
      else if ( s->itval == - ( 24 * 3600 ) )
        {
          if (syn->s3.RRR[0] == 0)
            {
              syn->s3.tr[0] = '4'; // 24 hour
              prec_to_RRR ( syn->s3.RRR, s->val );
            }
          if (syn->s3.RRRR24[0] == 0)
            {
              prec_to_RRRR24 ( syn->s3.RRRR24, s->val );
              syn->mask |= SYNOP_SEC3;
            }
        }
      break;
    case 19: // 0 13 019
      if (syn->s3.RRR[0] == 0)
        {
          syn->s3.tr[0] = '5'; // 1 hour
          prec_to_RRR ( syn->s3.RRR, s->val );
          syn->mask |= SYNOP_SEC3;
        }
      break;
    case 20: // 0 13 020
      if (syn->s3.RRR[0] == 0)
        {
          syn->s3.tr[0] = '7'; // 3 hour
          prec_to_RRR ( syn->s3.RRR, s->val );
          syn->mask |= SYNOP_SEC3;
        }
      break;
    case 21: // 0 13 021
      if (syn->s1.RRR[0] == 0)
        {
          syn->s1.tr[0] = '1'; // 6 hour
          prec_to_RRR ( syn->s1.RRR, s->val );
        }
      break;
    case 22: // 0 13 022
      if (syn->s1.RRR[0] == 0 || syn->s1.tr[0] == '4')
        {
          syn->s1.tr[0] = '2'; // 12 hour
          prec_to_RRR ( syn->s1.RRR, s->val );
        }
      break;
    case 23: // 0 13 023
      if (syn->s1.RRR[0] == 0)
        {
          syn->s1.tr[0] = '4'; // 24 hour
          prec_to_RRR ( syn->s1.RRR, s->val );
        }
      if (syn->s3.RRRR24[0] == 0)
        {
          prec_to_RRRR24 ( syn->s3.RRRR24, s->val );
          syn->mask |= SYNOP_SEC3;
        }
      break;
    default:
      break;
    }
  return 0;
}
