/* -*- c++ -*- */
/* 
 * Copyright 2014 Institute for Theoretical Information Technology,
 *                RWTH Aachen University
 *                www.ti.rwth-aachen.de
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_OFDM_REFERENCE_DATA_SOURCE_MIMO_IB_IMPL_H
#define INCLUDED_OFDM_REFERENCE_DATA_SOURCE_MIMO_IB_IMPL_H

#include <ofdm/reference_data_source_mimo_ib.h>

#include <vector>

namespace gr {
  namespace ofdm {

    class reference_data_source_mimo_ib_impl : public reference_data_source_mimo_ib
    {
     private:
        std::vector<char> d_ref_data;
        std::vector<char>::const_iterator d_bpos;
        std::vector<char>::size_type d_produced;

     public:
      reference_data_source_mimo_ib_impl(const std::vector<int> &ref_data);
      ~reference_data_source_mimo_ib_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);
    };

  } // namespace ofdm
} // namespace gr

#endif /* INCLUDED_OFDM_REFERENCE_DATA_SOURCE_MIMO_IB_IMPL_H */

