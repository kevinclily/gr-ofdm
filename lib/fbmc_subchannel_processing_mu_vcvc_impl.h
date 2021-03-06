/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
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

#ifndef INCLUDED_OFDM_FBMC_SUBCHANNEL_PROCESSING_MU_VCVC_IMPL_H
#define INCLUDED_OFDM_FBMC_SUBCHANNEL_PROCESSING_MU_VCVC_IMPL_H

#include <ofdm/fbmc_subchannel_processing_mu_vcvc.h>

namespace gr {
  namespace ofdm {

    class fbmc_subchannel_processing_mu_vcvc_impl : public fbmc_subchannel_processing_mu_vcvc
    {
     private:
      // Nothing to declare in this block.
      unsigned int d_M;
      unsigned int d_syms_per_frame;
      std::vector<gr_complex> d_preamble;
      std::vector<int> d_indices;
      std::vector<int> d_mask;
      int d_users;
      int d_sel_eq;
      int d_allocation;
      unsigned int d_preamble_length;
      unsigned int d_frame_length;
      std::vector<gr_complex> d_estimation;
      std::vector<gr_complex> d_eq_coef;
      int ii;
      int fr;
      int estimation_point;
      gr_complex normalization_factor;
      int d_sel_preamble;
      int d_zero_pads;
      bool d_extra_pad;

     public:
      fbmc_subchannel_processing_mu_vcvc_impl(unsigned int M, unsigned int syms_per_frame, std::vector<int> indices, int sel_preamble, int zero_pads, bool extra_pad, int sel_eq);
      ~fbmc_subchannel_processing_mu_vcvc_impl();

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
      void get_estimation(const gr_complex * start);
      void get_equalizer_coefficients(int order);
      // std::ofstream estimation_data;
      // std::ofstream equalizer_data;
      // std::ofstream output_data;
    };

  } // namespace ofdm
} // namespace gr

#endif /* INCLUDED_OFDM_FBMC_SUBCHANNEL_PROCESSING_MU_VCVC_IMPL_H */

