#pragma once

#include "tiling.h"
#include "superkernels.h"

#define NUM_LAYERS (53)

// Input
std::vector<uint32_t> input_dim = ifm_dim_1;
access_pattern input_ddr_pattern = tiling({.buffer_dimension = input_dim, .tiling_dimension = input_dim, .offset = { 0, 0, 0, 0 }});
// final output
std::vector<uint32_t> output_dim = ofm_dim_53;
access_pattern output_ddr_pattern = tiling({.buffer_dimension = output_dim, .tiling_dimension = output_dim, .offset = { 0, 0, 0, 0 }});
// WTS DDR Offsets
std::vector<uint32_t> wts_ddr_offset = {
0/4,//15104
15104/4,//5632
20736/4,//38400
59136/4,//18688
77824/4,//20992
98816/4,//22528
121344/4,//38400
159744/4,//20992
180736/4,//22528
203264/4,//38400
241664/4,//20992
262656/4,//35328
297984/4,//157696
455680/4,//149504
605184/4,//83968
689152/4,//70656
759808/4,//153600
913408/4,//83968
997376/4,//70656
1068032/4,//153600
1221632/4,//83968
1305600/4,//70656
1376256/4,//153600
1529856/4,//83968
1613824/4,//141312
1755136/4,//630784
2385920/4,//598016
2983936/4,//343552
3327488/4,//299008
3626496/4,//614400
4240896/4,//343552
4584448/4,//299008
4883456/4,//614400
5497856/4,//343552
5841408/4,//299008
6140416/4,//614400
6754816/4,//343552
7098368/4,//299008
7397376/4,//614400
8011776/4,//343552
8355328/4,//299008
8654336/4,//614400
9268736/4,//343552
9612288/4,//598016
10210304/4,//2523136
12733440/4,//2392064
15125504/4,//1343488
16468992/4,//1130496
17599488/4,//2457600
20057088/4,//1343488
21400576/4,//1130496
22531072/4,//2457600
24988672/4//1343488
};
#define IFM_DDR_MEM_SIZE (input_dim[0]*input_dim[1]*input_dim[2]*input_dim[3])
#define OFM_DDR_MEM_SIZE (output_dim[0]*output_dim[1]*output_dim[2]*output_dim[3])
#define WTS_DDR_MEM_SIZE (26332160)
std::vector<location_constraint> ifm_loc_1 = {address(0,0, 200704)};
std::vector<location_constraint> ofm_loc_1= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_2= {address(0,0, 430080)};
std::vector<location_constraint> ofm_loc_3= {address(0,0, 200704)};
std::vector<location_constraint> ofm_loc_4= {address(1,0, 131072)};
std::vector<location_constraint> ofm_loc_5= {address(1,0, 131072)};
std::vector<location_constraint> ofm_loc_6= {address(0,0, 229376)};
std::vector<location_constraint> ofm_loc_7= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_8= {address(1,0, 131072)};
std::vector<location_constraint> ofm_loc_9= {address(0,0, 229376)};
std::vector<location_constraint> ofm_loc_10= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_11= {address(1,0, 131072)};
std::vector<location_constraint> ofm_loc_12= {address(0,0, 114688)};
std::vector<location_constraint> ofm_loc_13= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_14= {address(0,0, 196608)};
std::vector<location_constraint> ofm_loc_15= {address(0,0, 196608)};
std::vector<location_constraint> ofm_loc_16= {address(1,0, 245760)};
std::vector<location_constraint> ofm_loc_17= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_18= {address(0,0, 196608)};
std::vector<location_constraint> ofm_loc_19= {address(1,0, 245760)};
std::vector<location_constraint> ofm_loc_20= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_21= {address(0,0, 196608)};
std::vector<location_constraint> ofm_loc_22= {address(1,0, 245760)};
std::vector<location_constraint> ofm_loc_23= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_24= {address(0,0, 196608)};
std::vector<location_constraint> ofm_loc_25= {address(1,0, 196608)};
std::vector<location_constraint> ofm_loc_26= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_27= {address(2,0, 262144)};
std::vector<location_constraint> ofm_loc_28= {address(2,0, 262144)};
std::vector<location_constraint> ofm_loc_29= {address(0,0, 65536)};
std::vector<location_constraint> ofm_loc_30= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_31= {address(2,0, 262144)};
std::vector<location_constraint> ofm_loc_32= {address(0,0, 65536)};
std::vector<location_constraint> ofm_loc_33= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_34= {address(2,0, 262144)};
std::vector<location_constraint> ofm_loc_35= {address(0,0, 65536)};
std::vector<location_constraint> ofm_loc_36= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_37= {address(2,0, 262144)};
std::vector<location_constraint> ofm_loc_38= {address(0,0, 65536)};
std::vector<location_constraint> ofm_loc_39= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_40= {address(2,0, 262144)};
std::vector<location_constraint> ofm_loc_41= {address(0,0, 65536)};
std::vector<location_constraint> ofm_loc_42= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_43= {address(2,0, 262144)};
std::vector<location_constraint> ofm_loc_44= {address(0,0, 65536)};
std::vector<location_constraint> ofm_loc_45= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_46= {address(2,0, 0)};
std::vector<location_constraint> ofm_loc_47= {address(2,0, 0)};
std::vector<location_constraint> ofm_loc_48= {address(0,0, 65536)};
std::vector<location_constraint> ofm_loc_49= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_50= {address(2,0, 0)};
std::vector<location_constraint> ofm_loc_51= {address(0,0, 65536)};
std::vector<location_constraint> ofm_loc_52= {address(0,0, 0)};
std::vector<location_constraint> ofm_loc_53= {address(2,0, 0)};

std::vector<location_constraint> wts_loc_1 = {address(3, 1, 509184)};
std::vector<location_constraint> wts_loc_2 = {address(3, 1, 518656)};
std::vector<location_constraint> wts_loc_3 = {address(3, 1, 485888)};
std::vector<location_constraint> wts_loc_4 = {address(3, 1, 505600)};
std::vector<location_constraint> wts_loc_5 = {address(3, 1, 503296)};
std::vector<location_constraint> wts_loc_6 = {address(3, 1, 501760)};
std::vector<location_constraint> wts_loc_7 = {address(3, 1, 485888)};
std::vector<location_constraint> wts_loc_8 = {address(3, 1, 503296)};
std::vector<location_constraint> wts_loc_9 = {address(3, 1, 501760)};
std::vector<location_constraint> wts_loc_10 = {address(3, 1, 485888)};
std::vector<location_constraint> wts_loc_11 = {address(3, 1, 503296)};
std::vector<location_constraint> wts_loc_12 = {address(3, 1, 488960)};
std::vector<location_constraint> wts_loc_13 = {address(3, 1, 366592)};
std::vector<location_constraint> wts_loc_14 = {address(3, 1, 374784)};
std::vector<location_constraint> wts_loc_15 = {address(3, 1, 440320)};
std::vector<location_constraint> wts_loc_16 = {address(3, 1, 453632)};
std::vector<location_constraint> wts_loc_17 = {address(3, 1, 370688)};
std::vector<location_constraint> wts_loc_18 = {address(3, 1, 440320)};
std::vector<location_constraint> wts_loc_19 = {address(3, 1, 453632)};
std::vector<location_constraint> wts_loc_20 = {address(3, 1, 370688)};
std::vector<location_constraint> wts_loc_21 = {address(3, 1, 440320)};
std::vector<location_constraint> wts_loc_22 = {address(3, 1, 453632)};
std::vector<location_constraint> wts_loc_23 = {address(3, 1, 370688)};
std::vector<location_constraint> wts_loc_24 = {address(3, 1, 440320)};
std::vector<location_constraint> wts_loc_25 = {address(3, 1, 382976)};
std::vector<location_constraint> wts_loc_26 = {address(2, 1, 417792)};
std::vector<location_constraint> wts_loc_27 = {address(2, 1, 450560)};
std::vector<location_constraint> wts_loc_28 = {address(3, 1, 180736)};
std::vector<location_constraint> wts_loc_29 = {address(3, 1, 225280)};
std::vector<location_constraint> wts_loc_30 = {address(2, 1, 434176)};
std::vector<location_constraint> wts_loc_31 = {address(3, 1, 180736)};
std::vector<location_constraint> wts_loc_32 = {address(3, 1, 225280)};
std::vector<location_constraint> wts_loc_33 = {address(2, 1, 434176)};
std::vector<location_constraint> wts_loc_34 = {address(3, 1, 180736)};
std::vector<location_constraint> wts_loc_35 = {address(3, 1, 225280)};
std::vector<location_constraint> wts_loc_36 = {address(2, 1, 434176)};
std::vector<location_constraint> wts_loc_37 = {address(3, 1, 180736)};
std::vector<location_constraint> wts_loc_38 = {address(3, 1, 225280)};
std::vector<location_constraint> wts_loc_39 = {address(2, 1, 434176)};
std::vector<location_constraint> wts_loc_40 = {address(3, 1, 180736)};
std::vector<location_constraint> wts_loc_41 = {address(3, 1, 225280)};
std::vector<location_constraint> wts_loc_42 = {address(2, 1, 434176)};
std::vector<location_constraint> wts_loc_43 = {address(3, 1, 180736)};
std::vector<location_constraint> wts_loc_44 = {address(2, 1, 450560)};
std::vector<location_constraint> wts_loc_45 = {address(1, 1, 311296), address(2,1, 417792)};
std::vector<location_constraint> wts_loc_46 = {address(1, 1, 376832), address(2,1, 450560)};
std::vector<location_constraint> wts_loc_47 = {address(1, 1, 229376), address(2,1, 376832)};
std::vector<location_constraint> wts_loc_48 = {address(1, 1, 442368), address(2,1, 483328)};
std::vector<location_constraint> wts_loc_49 = {address(1, 1, 344064), address(2,1, 434176)};
std::vector<location_constraint> wts_loc_50 = {address(1, 1, 229376), address(2,1, 376832)};
std::vector<location_constraint> wts_loc_51 = {address(1, 1, 442368), address(2,1, 483328)};
std::vector<location_constraint> wts_loc_52 = {address(1, 1, 344064), address(2,1, 434176)};
std::vector<location_constraint> wts_loc_53 = {address(1, 1, 229376), address(2,1, 376832)};

const uint32_t L1SIZE = 0x4000;

class single_layer_overlay : public graph{
public:
kernel compute_node[4][4];

shared_buffer<uint8_t> wts;
external_buffer<uint8_t> wts_ddr;

shared_buffer<uint8_t> ofm;
pktmerge<4> ofm_merge[4];

single_layer_overlay(
unsigned super_kernel_mode,
uint32_t num_ofm_out,
std::vector<access_pattern> ofm_pattern[],
std::vector<access_pattern> wts_pattern[],
const access_pattern &wts_ddr_read_pattern,
const access_pattern &wts_ddr_write_pattern,
const std::vector<uint32_t>& wts_ddr_dim,
uint32_t ofmsv_size,
uint32_t wtssv_size,
const std::vector<location_constraint>& ofm_loc,
const std::vector<location_constraint>& wts_loc,
uint32_t kernel_iter,
uint32_t ofm_repetition,
uint32_t wts_repetition,
uint32_t num_wts,
uint32_t in0_addr = 0x0,
uint32_t in1_addr = 0x0,
uint32_t in2_addr = 0x0)
{
ofm = shared_buffer<uint8_t>::create({512*1024},4,num_ofm_out);
location<buffer>(ofm) = ofm_loc;

wts = shared_buffer<uint8_t>::create({512*1024},1,4);
location<buffer>(wts) = wts_loc;
wts_ddr = external_buffer<uint8_t>::create(wts_ddr_dim, 0, 1);

num_buffers(wts) = num_wts;
repetition_count(wts) = wts_repetition;

for (int col = 0; col < 4; col++){
  ofm_merge[col] = pktmerge<4>::create();
  for (int row = 0; row < 4 ; row++){
    switch(super_kernel_mode){
    case 0:{
      compute_node[col][row] = kernel::create(conv2d_maxpool);
      location<buffer>(compute_node[col][row].in[0]) = {address(col+0,row,in0_addr), address(col+0,row,in0_addr+L1SIZE)};
      location<buffer>(compute_node[col][row].in[1]) = {address(col+0,row,in1_addr), address(col+0,row,in1_addr+L1SIZE)};
      location<dma>(compute_node[col][row].in[0]) = dma_channel(aie_tile,col+0,row,0);
      location<dma>(compute_node[col][row].in[1]) = dma_channel(aie_tile,col+0,row,1);
    }break;
    case 1:{
      if (col == 0){
        compute_node[col][row] = kernel::create(conv2d_elem_add_gav_cas_start);
      }else if (col == 4 - 1){
        compute_node[col][row] = kernel::create(conv2d_elem_add_gav_cas_end);
        connect<cascade>(compute_node[col-1][row].out[1], compute_node[col][row].in[3]);
      }else{
        compute_node[col][row] = kernel::create(conv2d_elem_add_gav_cas_mid);
        connect<cascade>(compute_node[col-1][row].out[1], compute_node[col][row].in[3]);
      }
      location<buffer>(compute_node[col][row].in[0]) = {address(col+0,row,in0_addr), address(col+0,row,in0_addr+L1SIZE)};
      location<buffer>(compute_node[col][row].in[1]) = {address(col+0,row,in1_addr), address(col+0,row,in1_addr+L1SIZE)};
      location<buffer>(compute_node[col][row].in[2]) = {address(col+0,row,in2_addr), address(col+0,row,in2_addr+L1SIZE)};
      location<dma>(compute_node[col][row].in[0]) = dma_channel(aie_tile,col+0,row,0);
      location<dma>(compute_node[col][row].in[1]) = dma_channel(aie_tile,col+0,row,1);
      location<dma>(compute_node[col][row].in[2]) = dma_channel(aie_tile,col+0,row,0);
      async_repetition(compute_node[col][row].in[2]) = ofm_repetition;
    }break;
    default:;
    }
    source(compute_node[col][row]) = "superkernels.cpp";
    initialization_function(compute_node[col][row]) = "node_init";
    repetition_count(compute_node[col][row]) = kernel_iter;
    runtime<ratio>(compute_node[col][row]) = 0.8;
    location<kernel>(compute_node[col][row]) = tile( col+0,row);
    location<buffer>(compute_node[col][row].out[0]) = {address(col+0,row,0x0), address(col+0,row, 0x4000)};
    location<dma>(compute_node[col][row].out[0]) = dma_channel(aie_tile,col+0,row,0);
    async_repetition(compute_node[col][row].out[0] ) = ofm_repetition;
    location<stack>(compute_node[col][row]) = {address(col+0,row,0xeb40)};
    connect(compute_node[col][row].out[0], ofm_merge[col].in[row]); dimensions(compute_node[col][row].out[0]) = {ofmsv_size};
    connect(wts.out[row], compute_node[col][row].in[1]); dimensions(compute_node[col][row].in[1]) = {wtssv_size};
  }
  connect<pktstream>(ofm_merge[col].out[0], ofm.in[col]); write_access(ofm.in[col]) = ofm_pattern[col];
}
location<dma>(ofm.in[0]) = dma_channel(memory_tile, 1,0,0);
location<dma>(ofm.in[1]) = dma_channel(memory_tile, 1,0,1);
location<dma>(ofm.in[2]) = dma_channel(memory_tile, 1,0,2);
location<dma>(ofm.in[3]) = dma_channel(memory_tile, 1,0,3);

location<dma>(wts.out[0]) = dma_channel(memory_tile, 2,1,0); read_access(wts.out[0]) = wts_pattern[0];
location<dma>(wts.out[1]) = dma_channel(memory_tile, 2,1,1); read_access(wts.out[1]) = wts_pattern[1];
location<dma>(wts.out[2]) = dma_channel(memory_tile, 2,1,2); read_access(wts.out[2]) = wts_pattern[2];
location<dma>(wts.out[3]) = dma_channel(memory_tile, 2,1,3); read_access(wts.out[3]) = wts_pattern[3];

location<dma>(wts_ddr.out[0]) = dma_channel(shim_tile, 2, 0, 0);
location<dma>(wts.in[0]) = dma_channel(memory_tile, 2,1,0);
connect(wts_ddr.out[0], wts.in[0]); read_access(wts_ddr.out[0]) = wts_ddr_read_pattern; write_access(wts.in[0]) = wts_ddr_write_pattern;
}

void connect_layer(
shared_buffer<uint8_t>& ifm, 
std::vector<access_pattern> ifm_pattern[], 
uint32_t ifmsv_size, 
unsigned src_offset, 
unsigned dst_port)
{
for (int col = 0; col < 4; col++){
  for(int row = 0; row < 4; row++){
    connect(ifm.out[col + src_offset], compute_node[col][row].in[dst_port]);
    dimensions(compute_node[col][row].in[dst_port]) = {ifmsv_size};
  }
  read_access(ifm.out[col + src_offset]) = ifm_pattern[col];
}
location<dma>(ifm.out[0+src_offset]) = dma_channel(memory_tile, 1,0,0);
location<dma>(ifm.out[1+src_offset]) = dma_channel(memory_tile, 1,0,1);
location<dma>(ifm.out[2+src_offset]) = dma_channel(memory_tile, 1,0,2);
location<dma>(ifm.out[3+src_offset]) = dma_channel(memory_tile, 1,0,3);
}
};

class FlexMLGraph : public graph{
public:
single_layer_overlay flexml_layers[NUM_LAYERS] = {
single_layer_overlay(0,8,ofm_pattern_1,wts_pattern_1,wts_ddr_read_pattern_1,wts_ddr_write_pattern_1,wts_ddr_dim_1,ofmsv_size_1,wtssv_size_1,ofm_loc_1,wts_loc_1,kernel_iter_1,ofm_repetition_1,1,1,0x8000,0x2000),
single_layer_overlay(0,4,ofm_pattern_2,wts_pattern_2,wts_ddr_read_pattern_2,wts_ddr_write_pattern_2,wts_ddr_dim_2,ofmsv_size_2,wtssv_size_2,ofm_loc_2,wts_loc_2,kernel_iter_2,ofm_repetition_2,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_3,wts_pattern_3,wts_ddr_read_pattern_3,wts_ddr_write_pattern_3,wts_ddr_dim_3,ofmsv_size_3,wtssv_size_3,ofm_loc_3,wts_loc_3,kernel_iter_3,ofm_repetition_3,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_4,wts_pattern_4,wts_ddr_read_pattern_4,wts_ddr_write_pattern_4,wts_ddr_dim_4,ofmsv_size_4,wtssv_size_4,ofm_loc_4,wts_loc_4,kernel_iter_4,ofm_repetition_4,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_5,wts_pattern_5,wts_ddr_read_pattern_5,wts_ddr_write_pattern_5,wts_ddr_dim_5,ofmsv_size_5,wtssv_size_5,ofm_loc_5,wts_loc_5,kernel_iter_5,ofm_repetition_5,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_6,wts_pattern_6,wts_ddr_read_pattern_6,wts_ddr_write_pattern_6,wts_ddr_dim_6,ofmsv_size_6,wtssv_size_6,ofm_loc_6,wts_loc_6,kernel_iter_6,ofm_repetition_6,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_7,wts_pattern_7,wts_ddr_read_pattern_7,wts_ddr_write_pattern_7,wts_ddr_dim_7,ofmsv_size_7,wtssv_size_7,ofm_loc_7,wts_loc_7,kernel_iter_7,ofm_repetition_7,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_8,wts_pattern_8,wts_ddr_read_pattern_8,wts_ddr_write_pattern_8,wts_ddr_dim_8,ofmsv_size_8,wtssv_size_8,ofm_loc_8,wts_loc_8,kernel_iter_8,ofm_repetition_8,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_9,wts_pattern_9,wts_ddr_read_pattern_9,wts_ddr_write_pattern_9,wts_ddr_dim_9,ofmsv_size_9,wtssv_size_9,ofm_loc_9,wts_loc_9,kernel_iter_9,ofm_repetition_9,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_10,wts_pattern_10,wts_ddr_read_pattern_10,wts_ddr_write_pattern_10,wts_ddr_dim_10,ofmsv_size_10,wtssv_size_10,ofm_loc_10,wts_loc_10,kernel_iter_10,ofm_repetition_10,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_11,wts_pattern_11,wts_ddr_read_pattern_11,wts_ddr_write_pattern_11,wts_ddr_dim_11,ofmsv_size_11,wtssv_size_11,ofm_loc_11,wts_loc_11,kernel_iter_11,ofm_repetition_11,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_12,wts_pattern_12,wts_ddr_read_pattern_12,wts_ddr_write_pattern_12,wts_ddr_dim_12,ofmsv_size_12,wtssv_size_12,ofm_loc_12,wts_loc_12,kernel_iter_12,ofm_repetition_12,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_13,wts_pattern_13,wts_ddr_read_pattern_13,wts_ddr_write_pattern_13,wts_ddr_dim_13,ofmsv_size_13,wtssv_size_13,ofm_loc_13,wts_loc_13,kernel_iter_13,ofm_repetition_13,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_14,wts_pattern_14,wts_ddr_read_pattern_14,wts_ddr_write_pattern_14,wts_ddr_dim_14,ofmsv_size_14,wtssv_size_14,ofm_loc_14,wts_loc_14,kernel_iter_14,ofm_repetition_14,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_15,wts_pattern_15,wts_ddr_read_pattern_15,wts_ddr_write_pattern_15,wts_ddr_dim_15,ofmsv_size_15,wtssv_size_15,ofm_loc_15,wts_loc_15,kernel_iter_15,ofm_repetition_15,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_16,wts_pattern_16,wts_ddr_read_pattern_16,wts_ddr_write_pattern_16,wts_ddr_dim_16,ofmsv_size_16,wtssv_size_16,ofm_loc_16,wts_loc_16,kernel_iter_16,ofm_repetition_16,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_17,wts_pattern_17,wts_ddr_read_pattern_17,wts_ddr_write_pattern_17,wts_ddr_dim_17,ofmsv_size_17,wtssv_size_17,ofm_loc_17,wts_loc_17,kernel_iter_17,ofm_repetition_17,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_18,wts_pattern_18,wts_ddr_read_pattern_18,wts_ddr_write_pattern_18,wts_ddr_dim_18,ofmsv_size_18,wtssv_size_18,ofm_loc_18,wts_loc_18,kernel_iter_18,ofm_repetition_18,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_19,wts_pattern_19,wts_ddr_read_pattern_19,wts_ddr_write_pattern_19,wts_ddr_dim_19,ofmsv_size_19,wtssv_size_19,ofm_loc_19,wts_loc_19,kernel_iter_19,ofm_repetition_19,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_20,wts_pattern_20,wts_ddr_read_pattern_20,wts_ddr_write_pattern_20,wts_ddr_dim_20,ofmsv_size_20,wtssv_size_20,ofm_loc_20,wts_loc_20,kernel_iter_20,ofm_repetition_20,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_21,wts_pattern_21,wts_ddr_read_pattern_21,wts_ddr_write_pattern_21,wts_ddr_dim_21,ofmsv_size_21,wtssv_size_21,ofm_loc_21,wts_loc_21,kernel_iter_21,ofm_repetition_21,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_22,wts_pattern_22,wts_ddr_read_pattern_22,wts_ddr_write_pattern_22,wts_ddr_dim_22,ofmsv_size_22,wtssv_size_22,ofm_loc_22,wts_loc_22,kernel_iter_22,ofm_repetition_22,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_23,wts_pattern_23,wts_ddr_read_pattern_23,wts_ddr_write_pattern_23,wts_ddr_dim_23,ofmsv_size_23,wtssv_size_23,ofm_loc_23,wts_loc_23,kernel_iter_23,ofm_repetition_23,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_24,wts_pattern_24,wts_ddr_read_pattern_24,wts_ddr_write_pattern_24,wts_ddr_dim_24,ofmsv_size_24,wtssv_size_24,ofm_loc_24,wts_loc_24,kernel_iter_24,ofm_repetition_24,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_25,wts_pattern_25,wts_ddr_read_pattern_25,wts_ddr_write_pattern_25,wts_ddr_dim_25,ofmsv_size_25,wtssv_size_25,ofm_loc_25,wts_loc_25,kernel_iter_25,ofm_repetition_25,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_26,wts_pattern_26,wts_ddr_read_pattern_26,wts_ddr_write_pattern_26,wts_ddr_dim_26,ofmsv_size_26,wtssv_size_26,ofm_loc_26,wts_loc_26,kernel_iter_26,ofm_repetition_26,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_27,wts_pattern_27,wts_ddr_read_pattern_27,wts_ddr_write_pattern_27,wts_ddr_dim_27,ofmsv_size_27,wtssv_size_27,ofm_loc_27,wts_loc_27,kernel_iter_27,ofm_repetition_27,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_28,wts_pattern_28,wts_ddr_read_pattern_28,wts_ddr_write_pattern_28,wts_ddr_dim_28,ofmsv_size_28,wtssv_size_28,ofm_loc_28,wts_loc_28,kernel_iter_28,ofm_repetition_28,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_29,wts_pattern_29,wts_ddr_read_pattern_29,wts_ddr_write_pattern_29,wts_ddr_dim_29,ofmsv_size_29,wtssv_size_29,ofm_loc_29,wts_loc_29,kernel_iter_29,ofm_repetition_29,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_30,wts_pattern_30,wts_ddr_read_pattern_30,wts_ddr_write_pattern_30,wts_ddr_dim_30,ofmsv_size_30,wtssv_size_30,ofm_loc_30,wts_loc_30,kernel_iter_30,ofm_repetition_30,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_31,wts_pattern_31,wts_ddr_read_pattern_31,wts_ddr_write_pattern_31,wts_ddr_dim_31,ofmsv_size_31,wtssv_size_31,ofm_loc_31,wts_loc_31,kernel_iter_31,ofm_repetition_31,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_32,wts_pattern_32,wts_ddr_read_pattern_32,wts_ddr_write_pattern_32,wts_ddr_dim_32,ofmsv_size_32,wtssv_size_32,ofm_loc_32,wts_loc_32,kernel_iter_32,ofm_repetition_32,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_33,wts_pattern_33,wts_ddr_read_pattern_33,wts_ddr_write_pattern_33,wts_ddr_dim_33,ofmsv_size_33,wtssv_size_33,ofm_loc_33,wts_loc_33,kernel_iter_33,ofm_repetition_33,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_34,wts_pattern_34,wts_ddr_read_pattern_34,wts_ddr_write_pattern_34,wts_ddr_dim_34,ofmsv_size_34,wtssv_size_34,ofm_loc_34,wts_loc_34,kernel_iter_34,ofm_repetition_34,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_35,wts_pattern_35,wts_ddr_read_pattern_35,wts_ddr_write_pattern_35,wts_ddr_dim_35,ofmsv_size_35,wtssv_size_35,ofm_loc_35,wts_loc_35,kernel_iter_35,ofm_repetition_35,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_36,wts_pattern_36,wts_ddr_read_pattern_36,wts_ddr_write_pattern_36,wts_ddr_dim_36,ofmsv_size_36,wtssv_size_36,ofm_loc_36,wts_loc_36,kernel_iter_36,ofm_repetition_36,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_37,wts_pattern_37,wts_ddr_read_pattern_37,wts_ddr_write_pattern_37,wts_ddr_dim_37,ofmsv_size_37,wtssv_size_37,ofm_loc_37,wts_loc_37,kernel_iter_37,ofm_repetition_37,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_38,wts_pattern_38,wts_ddr_read_pattern_38,wts_ddr_write_pattern_38,wts_ddr_dim_38,ofmsv_size_38,wtssv_size_38,ofm_loc_38,wts_loc_38,kernel_iter_38,ofm_repetition_38,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_39,wts_pattern_39,wts_ddr_read_pattern_39,wts_ddr_write_pattern_39,wts_ddr_dim_39,ofmsv_size_39,wtssv_size_39,ofm_loc_39,wts_loc_39,kernel_iter_39,ofm_repetition_39,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_40,wts_pattern_40,wts_ddr_read_pattern_40,wts_ddr_write_pattern_40,wts_ddr_dim_40,ofmsv_size_40,wtssv_size_40,ofm_loc_40,wts_loc_40,kernel_iter_40,ofm_repetition_40,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_41,wts_pattern_41,wts_ddr_read_pattern_41,wts_ddr_write_pattern_41,wts_ddr_dim_41,ofmsv_size_41,wtssv_size_41,ofm_loc_41,wts_loc_41,kernel_iter_41,ofm_repetition_41,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_42,wts_pattern_42,wts_ddr_read_pattern_42,wts_ddr_write_pattern_42,wts_ddr_dim_42,ofmsv_size_42,wtssv_size_42,ofm_loc_42,wts_loc_42,kernel_iter_42,ofm_repetition_42,1,1,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_43,wts_pattern_43,wts_ddr_read_pattern_43,wts_ddr_write_pattern_43,wts_ddr_dim_43,ofmsv_size_43,wtssv_size_43,ofm_loc_43,wts_loc_43,kernel_iter_43,ofm_repetition_43,1,1,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_44,wts_pattern_44,wts_ddr_read_pattern_44,wts_ddr_write_pattern_44,wts_ddr_dim_44,ofmsv_size_44,wtssv_size_44,ofm_loc_44,wts_loc_44,kernel_iter_44,ofm_repetition_44,1,1,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_45,wts_pattern_45,wts_ddr_read_pattern_45,wts_ddr_write_pattern_45,wts_ddr_dim_45,ofmsv_size_45,wtssv_size_45,ofm_loc_45,wts_loc_45,kernel_iter_45,ofm_repetition_45,4,2,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_46,wts_pattern_46,wts_ddr_read_pattern_46,wts_ddr_write_pattern_46,wts_ddr_dim_46,ofmsv_size_46,wtssv_size_46,ofm_loc_46,wts_loc_46,kernel_iter_46,ofm_repetition_46,4,2,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_47,wts_pattern_47,wts_ddr_read_pattern_47,wts_ddr_write_pattern_47,wts_ddr_dim_47,ofmsv_size_47,wtssv_size_47,ofm_loc_47,wts_loc_47,kernel_iter_47,ofm_repetition_47,2,2,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_48,wts_pattern_48,wts_ddr_read_pattern_48,wts_ddr_write_pattern_48,wts_ddr_dim_48,ofmsv_size_48,wtssv_size_48,ofm_loc_48,wts_loc_48,kernel_iter_48,ofm_repetition_48,2,2,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_49,wts_pattern_49,wts_ddr_read_pattern_49,wts_ddr_write_pattern_49,wts_ddr_dim_49,ofmsv_size_49,wtssv_size_49,ofm_loc_49,wts_loc_49,kernel_iter_49,ofm_repetition_49,4,2,0x8000,0x9800),
single_layer_overlay(1,8,ofm_pattern_50,wts_pattern_50,wts_ddr_read_pattern_50,wts_ddr_write_pattern_50,wts_ddr_dim_50,ofmsv_size_50,wtssv_size_50,ofm_loc_50,wts_loc_50,kernel_iter_50,ofm_repetition_50,2,2,0x8000,0x9800,0x2000),
single_layer_overlay(0,4,ofm_pattern_51,wts_pattern_51,wts_ddr_read_pattern_51,wts_ddr_write_pattern_51,wts_ddr_dim_51,ofmsv_size_51,wtssv_size_51,ofm_loc_51,wts_loc_51,kernel_iter_51,ofm_repetition_51,2,2,0x8000,0x9800),
single_layer_overlay(0,4,ofm_pattern_52,wts_pattern_52,wts_ddr_read_pattern_52,wts_ddr_write_pattern_52,wts_ddr_dim_52,ofmsv_size_52,wtssv_size_52,ofm_loc_52,wts_loc_52,kernel_iter_52,ofm_repetition_52,4,2,0x8000,0x9800),
single_layer_overlay(1,1,ofm_pattern_53,wts_pattern_53,wts_ddr_read_pattern_53,wts_ddr_write_pattern_53,wts_ddr_dim_53,ofmsv_size_53,wtssv_size_53,ofm_loc_53,wts_loc_53,kernel_iter_53,ofm_repetition_53,2,2,0x8000,0x9800,0x2000)
};
external_buffer<uint8_t> ifm_ddr;
external_buffer<uint8_t> ofm_ddr;
shared_buffer<uint8_t> ifm;
FlexMLGraph(){
ifm_ddr = external_buffer<uint8_t>::create(input_dim, 0, 1);
ofm_ddr = external_buffer<uint8_t>::create(output_dim, 1, 0);
ifm = shared_buffer<uint8_t>::create({512*1024},1,4);
location<buffer>(ifm) = ifm_loc_1;
connect(ifm_ddr.out[0], ifm.in[0]);read_access(ifm_ddr.out[0]) = input_ddr_pattern;write_access(ifm.in[0]) = input_ddr_pattern;
location<dma>(ifm_ddr.out[0]) = dma_channel(shim_tile, 3, 0, 0);
location<dma>(ifm.in[0]) = dma_channel(memory_tile,0, 0, 0);
connect(flexml_layers[NUM_LAYERS-1].ofm.out[0], ofm_ddr.in[0]);
read_access(flexml_layers[NUM_LAYERS-1].ofm.out[0]) = output_ddr_pattern;
write_access(ofm_ddr.in[0]) = output_ddr_pattern;
location<dma>(ofm_ddr.in[0]) = dma_channel(shim_tile, 6, 0, 0);
flexml_layers[0].connect_layer(ifm,ifm_pattern_1,ifmsv_size_1, 0, 0);
flexml_layers[1].connect_layer(flexml_layers[0].ofm,ifm_pattern_2,ifmsv_size_2, 0, 0);
flexml_layers[2].connect_layer(flexml_layers[1].ofm,ifm_pattern_3,ifmsv_size_3, 0, 0);
flexml_layers[3].connect_layer(flexml_layers[0].ofm,ifm_pattern_4,ifmsv_size_4, 4, 0);
flexml_layers[4].connect_layer(flexml_layers[2].ofm,ifm_pattern_5,ifmsv_size_5, 0, 0);
flexml_layers[4].connect_layer(flexml_layers[3].ofm,ifm2_pattern_5,ifm2sv_size_5, 0, 2);
flexml_layers[5].connect_layer(flexml_layers[4].ofm,ifm_pattern_6,ifmsv_size_6, 0, 0);
flexml_layers[6].connect_layer(flexml_layers[5].ofm,ifm_pattern_7,ifmsv_size_7, 0, 0);
flexml_layers[7].connect_layer(flexml_layers[6].ofm,ifm_pattern_8,ifmsv_size_8, 0, 0);
flexml_layers[7].connect_layer(flexml_layers[4].ofm,ifm2_pattern_8,ifm2sv_size_8, 4, 2);
flexml_layers[8].connect_layer(flexml_layers[7].ofm,ifm_pattern_9,ifmsv_size_9, 0, 0);
flexml_layers[9].connect_layer(flexml_layers[8].ofm,ifm_pattern_10,ifmsv_size_10, 0, 0);
flexml_layers[10].connect_layer(flexml_layers[9].ofm,ifm_pattern_11,ifmsv_size_11, 0, 0);
flexml_layers[10].connect_layer(flexml_layers[7].ofm,ifm2_pattern_11,ifm2sv_size_11, 4, 2);
flexml_layers[11].connect_layer(flexml_layers[10].ofm,ifm_pattern_12,ifmsv_size_12, 0, 0);
flexml_layers[12].connect_layer(flexml_layers[11].ofm,ifm_pattern_13,ifmsv_size_13, 0, 0);
flexml_layers[13].connect_layer(flexml_layers[10].ofm,ifm_pattern_14,ifmsv_size_14, 4, 0);
flexml_layers[14].connect_layer(flexml_layers[12].ofm,ifm_pattern_15,ifmsv_size_15, 0, 0);
flexml_layers[14].connect_layer(flexml_layers[13].ofm,ifm2_pattern_15,ifm2sv_size_15, 0, 2);
flexml_layers[15].connect_layer(flexml_layers[14].ofm,ifm_pattern_16,ifmsv_size_16, 0, 0);
flexml_layers[16].connect_layer(flexml_layers[15].ofm,ifm_pattern_17,ifmsv_size_17, 0, 0);
flexml_layers[17].connect_layer(flexml_layers[16].ofm,ifm_pattern_18,ifmsv_size_18, 0, 0);
flexml_layers[17].connect_layer(flexml_layers[14].ofm,ifm2_pattern_18,ifm2sv_size_18, 4, 2);
flexml_layers[18].connect_layer(flexml_layers[17].ofm,ifm_pattern_19,ifmsv_size_19, 0, 0);
flexml_layers[19].connect_layer(flexml_layers[18].ofm,ifm_pattern_20,ifmsv_size_20, 0, 0);
flexml_layers[20].connect_layer(flexml_layers[19].ofm,ifm_pattern_21,ifmsv_size_21, 0, 0);
flexml_layers[20].connect_layer(flexml_layers[17].ofm,ifm2_pattern_21,ifm2sv_size_21, 4, 2);
flexml_layers[21].connect_layer(flexml_layers[20].ofm,ifm_pattern_22,ifmsv_size_22, 0, 0);
flexml_layers[22].connect_layer(flexml_layers[21].ofm,ifm_pattern_23,ifmsv_size_23, 0, 0);
flexml_layers[23].connect_layer(flexml_layers[22].ofm,ifm_pattern_24,ifmsv_size_24, 0, 0);
flexml_layers[23].connect_layer(flexml_layers[20].ofm,ifm2_pattern_24,ifm2sv_size_24, 4, 2);
flexml_layers[24].connect_layer(flexml_layers[23].ofm,ifm_pattern_25,ifmsv_size_25, 0, 0);
flexml_layers[25].connect_layer(flexml_layers[24].ofm,ifm_pattern_26,ifmsv_size_26, 0, 0);
flexml_layers[26].connect_layer(flexml_layers[23].ofm,ifm_pattern_27,ifmsv_size_27, 4, 0);
flexml_layers[27].connect_layer(flexml_layers[25].ofm,ifm_pattern_28,ifmsv_size_28, 0, 0);
flexml_layers[27].connect_layer(flexml_layers[26].ofm,ifm2_pattern_28,ifm2sv_size_28, 0, 2);
flexml_layers[28].connect_layer(flexml_layers[27].ofm,ifm_pattern_29,ifmsv_size_29, 0, 0);
flexml_layers[29].connect_layer(flexml_layers[28].ofm,ifm_pattern_30,ifmsv_size_30, 0, 0);
flexml_layers[30].connect_layer(flexml_layers[29].ofm,ifm_pattern_31,ifmsv_size_31, 0, 0);
flexml_layers[30].connect_layer(flexml_layers[27].ofm,ifm2_pattern_31,ifm2sv_size_31, 4, 2);
flexml_layers[31].connect_layer(flexml_layers[30].ofm,ifm_pattern_32,ifmsv_size_32, 0, 0);
flexml_layers[32].connect_layer(flexml_layers[31].ofm,ifm_pattern_33,ifmsv_size_33, 0, 0);
flexml_layers[33].connect_layer(flexml_layers[32].ofm,ifm_pattern_34,ifmsv_size_34, 0, 0);
flexml_layers[33].connect_layer(flexml_layers[30].ofm,ifm2_pattern_34,ifm2sv_size_34, 4, 2);
flexml_layers[34].connect_layer(flexml_layers[33].ofm,ifm_pattern_35,ifmsv_size_35, 0, 0);
flexml_layers[35].connect_layer(flexml_layers[34].ofm,ifm_pattern_36,ifmsv_size_36, 0, 0);
flexml_layers[36].connect_layer(flexml_layers[35].ofm,ifm_pattern_37,ifmsv_size_37, 0, 0);
flexml_layers[36].connect_layer(flexml_layers[33].ofm,ifm2_pattern_37,ifm2sv_size_37, 4, 2);
flexml_layers[37].connect_layer(flexml_layers[36].ofm,ifm_pattern_38,ifmsv_size_38, 0, 0);
flexml_layers[38].connect_layer(flexml_layers[37].ofm,ifm_pattern_39,ifmsv_size_39, 0, 0);
flexml_layers[39].connect_layer(flexml_layers[38].ofm,ifm_pattern_40,ifmsv_size_40, 0, 0);
flexml_layers[39].connect_layer(flexml_layers[36].ofm,ifm2_pattern_40,ifm2sv_size_40, 4, 2);
flexml_layers[40].connect_layer(flexml_layers[39].ofm,ifm_pattern_41,ifmsv_size_41, 0, 0);
flexml_layers[41].connect_layer(flexml_layers[40].ofm,ifm_pattern_42,ifmsv_size_42, 0, 0);
flexml_layers[42].connect_layer(flexml_layers[41].ofm,ifm_pattern_43,ifmsv_size_43, 0, 0);
flexml_layers[42].connect_layer(flexml_layers[39].ofm,ifm2_pattern_43,ifm2sv_size_43, 4, 2);
flexml_layers[43].connect_layer(flexml_layers[42].ofm,ifm_pattern_44,ifmsv_size_44, 0, 0);
flexml_layers[44].connect_layer(flexml_layers[43].ofm,ifm_pattern_45,ifmsv_size_45, 0, 0);
flexml_layers[45].connect_layer(flexml_layers[42].ofm,ifm_pattern_46,ifmsv_size_46, 4, 0);
flexml_layers[46].connect_layer(flexml_layers[44].ofm,ifm_pattern_47,ifmsv_size_47, 0, 0);
flexml_layers[46].connect_layer(flexml_layers[45].ofm,ifm2_pattern_47,ifm2sv_size_47, 0, 2);
flexml_layers[47].connect_layer(flexml_layers[46].ofm,ifm_pattern_48,ifmsv_size_48, 0, 0);
flexml_layers[48].connect_layer(flexml_layers[47].ofm,ifm_pattern_49,ifmsv_size_49, 0, 0);
flexml_layers[49].connect_layer(flexml_layers[48].ofm,ifm_pattern_50,ifmsv_size_50, 0, 0);
flexml_layers[49].connect_layer(flexml_layers[46].ofm,ifm2_pattern_50,ifm2sv_size_50, 4, 2);
flexml_layers[50].connect_layer(flexml_layers[49].ofm,ifm_pattern_51,ifmsv_size_51, 0, 0);
flexml_layers[51].connect_layer(flexml_layers[50].ofm,ifm_pattern_52,ifmsv_size_52, 0, 0);
flexml_layers[52].connect_layer(flexml_layers[51].ofm,ifm_pattern_53,ifmsv_size_53, 0, 0);
flexml_layers[52].connect_layer(flexml_layers[49].ofm,ifm2_pattern_53,ifm2sv_size_53, 4, 2);
for(int col = 0; col < 4; col++){
  for(int row = 0; row < 4; row++){
    execution_order(flexml_layers[1].compute_node[col][row],flexml_layers[3].compute_node[col][row]);
    execution_order(flexml_layers[2].compute_node[col][row],flexml_layers[3].compute_node[col][row]);
    execution_order(flexml_layers[11].compute_node[col][row],flexml_layers[13].compute_node[col][row]);
    execution_order(flexml_layers[12].compute_node[col][row],flexml_layers[13].compute_node[col][row]);
    execution_order(flexml_layers[24].compute_node[col][row],flexml_layers[26].compute_node[col][row]);
    execution_order(flexml_layers[25].compute_node[col][row],flexml_layers[26].compute_node[col][row]);
    execution_order(flexml_layers[43].compute_node[col][row],flexml_layers[45].compute_node[col][row]);
    execution_order(flexml_layers[44].compute_node[col][row],flexml_layers[45].compute_node[col][row]);
}}
location<dma>(flexml_layers[NUM_LAYERS-1].ofm.out[0]) = dma_channel(memory_tile, 0, 0, 0);
}
};
