#include <adf.h>
using namespace adf;

//Layer1
std::vector<uint32_t> ifm_dim_1 = {4, 224, 1, 224};
std::vector<uint32_t> ifm_bound_1 = {4, 224, 1, 224};
std::vector<uint32_t> ifmsv_dim_1 = {4, 232, 1, 12};
uint32_t ifmsv_size_1 = 11136;
uint32_t kernel_iter_1 = 14;
std::vector<access_pattern> ifm_pattern_1[] = {
{
  tiling({.buffer_dimension = {4, 224, 1, 224}, .tiling_dimension = {4, 232, 1, 12}, .offset = {0, -5, 0, -5}, .tile_traversal = { {.dimension = 3, .stride = 16, .wrap = 14} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {4, 224, 1, 224}})
},
{
  tiling({.buffer_dimension = {4, 224, 1, 224}, .tiling_dimension = {4, 232, 1, 12}, .offset = {0, -5, 0, -1}, .tile_traversal = { {.dimension = 3, .stride = 16, .wrap = 14} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {4, 224, 1, 224}})
},
{
  tiling({.buffer_dimension = {4, 224, 1, 224}, .tiling_dimension = {4, 232, 1, 12}, .offset = {0, -5, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 16, .wrap = 14} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {4, 224, 1, 224}})
},
{
  tiling({.buffer_dimension = {4, 224, 1, 224}, .tiling_dimension = {4, 232, 1, 12}, .offset = {0, -5, 0, 7}, .tile_traversal = { {.dimension = 3, .stride = 16, .wrap = 14} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {4, 224, 1, 224}})
}};


std::vector<uint32_t> wts_dim_1 = {15104};
std::vector<uint32_t> wts_ddr_dim_1 = {15104};
std::vector<uint32_t> wtssv_dim_1 = {3776};
uint32_t wtssv_size_1 = 3776;
uint32_t wts_repetition_1 = 1;
std::vector<access_pattern> wts_pattern_1[] = {
{
  tiling({.buffer_dimension = {15104}, .tiling_dimension = {3776}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {15104}, .tiling_dimension = {3776}, .offset = {3776}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {15104}, .tiling_dimension = {3776}, .offset = {7552}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {15104}, .tiling_dimension = {3776}, .offset = {11328}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_1 = tiling({.buffer_dimension = {15104}, .tiling_dimension = {15104}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_1 = tiling({.buffer_dimension = {15104}, .tiling_dimension = {15104}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_1 = {8, 56, 8, 56};
std::vector<uint32_t> ofm_bound_1 = {8, 56, 8, 56};
std::vector<uint32_t> ofmsv_dim_1 = {8, 56, 2, 1};
uint32_t ofmsv_size_1 = 896;
uint32_t ofm_repetition_1 = 1;
std::vector<access_pattern> ofm_pattern_1[] = {
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 2, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 4, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 6, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 2, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 6, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 2, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 4, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 56, 2, 1}, .offset = {0, 0, 6, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer2
std::vector<uint32_t> ifm_dim_2 = {8, 56, 8, 56};
std::vector<uint32_t> ifm_bound_2 = {8, 56, 8, 56};
std::vector<uint32_t> ifmsv_dim_2 = {8, 16, 4, 7};
uint32_t ifmsv_size_2 = 3584;
uint32_t kernel_iter_2 = 16;
std::vector<access_pattern> ifm_pattern_2[] = {
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
}};


std::vector<uint32_t> wts_dim_2 = {5632};
std::vector<uint32_t> wts_ddr_dim_2 = {5632};
std::vector<uint32_t> wtssv_dim_2 = {704};
uint32_t wtssv_size_2 = 704;
uint32_t wts_repetition_2 = 1;
std::vector<access_pattern> wts_pattern_2[] = {
{
  tiling({.buffer_dimension = {5632}, .tiling_dimension = {704}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {5632}, .tiling_dimension = {704}, .offset = {1408}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {5632}, .tiling_dimension = {704}, .offset = {2816}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {5632}, .tiling_dimension = {704}, .offset = {4224}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_2 = tiling({.buffer_dimension = {5632}, .tiling_dimension = {5632}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_2 = tiling({.buffer_dimension = {5632}, .tiling_dimension = {5632}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_2 = {8, 64, 8, 56};
std::vector<uint32_t> ofm_bound_2 = {8, 56, 8, 56};
std::vector<uint32_t> ofmsv_dim_2 = {8, 16, 2, 7};
uint32_t ofmsv_size_2 = 1792;
uint32_t ofm_repetition_2 = 2;
std::vector<access_pattern> ofm_pattern_2[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer3
std::vector<uint32_t> ifm_dim_3 = {8, 64, 8, 56};
std::vector<uint32_t> ifm_bound_3 = {8, 56, 8, 56};
std::vector<uint32_t> ifmsv_dim_3 = {8, 20, 4, 9};
uint32_t ifmsv_size_3 = 5760;
uint32_t kernel_iter_3 = 16;
std::vector<access_pattern> ifm_pattern_3[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 27}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 34}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 13}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 41}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 20}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 48}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
}};


std::vector<uint32_t> wts_dim_3 = {38400};
std::vector<uint32_t> wts_ddr_dim_3 = {38400};
std::vector<uint32_t> wtssv_dim_3 = {4800};
uint32_t wtssv_size_3 = 4800;
uint32_t wts_repetition_3 = 1;
std::vector<access_pattern> wts_pattern_3[] = {
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {9600}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {19200}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {28800}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_3 = tiling({.buffer_dimension = {38400}, .tiling_dimension = {38400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_3 = tiling({.buffer_dimension = {38400}, .tiling_dimension = {38400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_3 = {8, 64, 8, 56};
std::vector<uint32_t> ofm_bound_3 = {8, 56, 8, 56};
std::vector<uint32_t> ofmsv_dim_3 = {8, 16, 2, 7};
uint32_t ofmsv_size_3 = 1792;
uint32_t ofm_repetition_3 = 2;
std::vector<access_pattern> ofm_pattern_3[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
}};


//Layer4
std::vector<uint32_t> ifm_dim_4 = {8, 56, 8, 56};
std::vector<uint32_t> ifm_bound_4 = {8, 56, 8, 56};
std::vector<uint32_t> ifmsv_dim_4 = {8, 16, 8, 4};
uint32_t ifmsv_size_4 = 4096;
uint32_t kernel_iter_4 = 14;
std::vector<access_pattern> ifm_pattern_4[] = {
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 56, 8, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
}};


std::vector<uint32_t> wts_dim_4 = {18688};
std::vector<uint32_t> wts_ddr_dim_4 = {18688};
std::vector<uint32_t> wtssv_dim_4 = {4672};
uint32_t wtssv_size_4 = 4672;
uint32_t wts_repetition_4 = 1;
std::vector<access_pattern> wts_pattern_4[] = {
{
  tiling({.buffer_dimension = {18688}, .tiling_dimension = {4672}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {18688}, .tiling_dimension = {4672}, .offset = {4672}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {18688}, .tiling_dimension = {4672}, .offset = {9344}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {18688}, .tiling_dimension = {4672}, .offset = {14016}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_4 = tiling({.buffer_dimension = {18688}, .tiling_dimension = {18688}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_4 = tiling({.buffer_dimension = {18688}, .tiling_dimension = {18688}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_4 = {8, 64, 32, 56};
std::vector<uint32_t> ofm_bound_4 = {8, 56, 32, 56};
std::vector<uint32_t> ofmsv_dim_4 = {8, 16, 8, 4};
uint32_t ofmsv_size_4 = 4096;
uint32_t ofm_repetition_4 = 1;
std::vector<access_pattern> ofm_pattern_4[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 16, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 16, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 16, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 32, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 32, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 32, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 48, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 48, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 48, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 14} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer5
std::vector<uint32_t> ifm_dim_5 = {8, 64, 8, 56};
std::vector<uint32_t> ifm_bound_5 = {8, 56, 8, 56};
std::vector<uint32_t> ifmsv_dim_5 = {8, 16, 4, 2};
uint32_t ifmsv_size_5 = 1024;
uint32_t kernel_iter_5 = 56;
std::vector<access_pattern> ifm_pattern_5[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
}};


std::vector<uint32_t> ifm2_dim_5 = {8, 64, 32, 56};
std::vector<uint32_t> ifm2_bound_5 = {8, 56, 32, 56};
std::vector<uint32_t> ifm2sv_dim_5 = {8, 16, 32, 2};
uint32_t ifm2sv_size_5 = 8192;
std::vector<access_pattern> ifm2_pattern_5[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_5 = {20992};
std::vector<uint32_t> wts_ddr_dim_5 = {20992};
std::vector<uint32_t> wtssv_dim_5 = {2624};
uint32_t wtssv_size_5 = 2624;
uint32_t wts_repetition_5 = 1;
std::vector<access_pattern> wts_pattern_5[] = {
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {5248}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {10496}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {15744}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_5 = tiling({.buffer_dimension = {20992}, .tiling_dimension = {20992}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_5 = tiling({.buffer_dimension = {20992}, .tiling_dimension = {20992}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_5 = {8, 64, 32, 56};
std::vector<uint32_t> ofm_bound_5 = {8, 56, 32, 56};
std::vector<uint32_t> ofmsv_dim_5 = {8, 16, 8, 2};
uint32_t ofmsv_size_5 = 2048;
uint32_t ofm_repetition_5 = 2;
std::vector<access_pattern> ofm_pattern_5[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer6
std::vector<uint32_t> ifm_dim_6 = {8, 64, 32, 56};
std::vector<uint32_t> ifm_bound_6 = {8, 56, 32, 56};
std::vector<uint32_t> ifmsv_dim_6 = {8, 16, 4, 7};
uint32_t ifmsv_size_6 = 3584;
uint32_t kernel_iter_6 = 64;
std::vector<access_pattern> ifm_pattern_6[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
}};


std::vector<uint32_t> wts_dim_6 = {22528};
std::vector<uint32_t> wts_ddr_dim_6 = {22528};
std::vector<uint32_t> wtssv_dim_6 = {704};
uint32_t wtssv_size_6 = 704;
uint32_t wts_repetition_6 = 1;
std::vector<access_pattern> wts_pattern_6[] = {
{
  tiling({.buffer_dimension = {22528}, .tiling_dimension = {704}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 8} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {22528}, .tiling_dimension = {704}, .offset = {5632}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 8} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {22528}, .tiling_dimension = {704}, .offset = {11264}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 8} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {22528}, .tiling_dimension = {704}, .offset = {16896}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 8} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_6 = tiling({.buffer_dimension = {22528}, .tiling_dimension = {22528}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_6 = tiling({.buffer_dimension = {22528}, .tiling_dimension = {22528}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_6 = {8, 64, 8, 56};
std::vector<uint32_t> ofm_bound_6 = {8, 56, 8, 56};
std::vector<uint32_t> ofmsv_dim_6 = {8, 16, 2, 7};
uint32_t ofmsv_size_6 = 1792;
uint32_t ofm_repetition_6 = 8;
std::vector<access_pattern> ofm_pattern_6[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer7
std::vector<uint32_t> ifm_dim_7 = {8, 64, 8, 56};
std::vector<uint32_t> ifm_bound_7 = {8, 56, 8, 56};
std::vector<uint32_t> ifmsv_dim_7 = {8, 20, 4, 9};
uint32_t ifmsv_size_7 = 5760;
uint32_t kernel_iter_7 = 16;
std::vector<access_pattern> ifm_pattern_7[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 27}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 34}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 13}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 41}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 20}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 48}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
}};


std::vector<uint32_t> wts_dim_7 = {38400};
std::vector<uint32_t> wts_ddr_dim_7 = {38400};
std::vector<uint32_t> wtssv_dim_7 = {4800};
uint32_t wtssv_size_7 = 4800;
uint32_t wts_repetition_7 = 1;
std::vector<access_pattern> wts_pattern_7[] = {
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {9600}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {19200}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {28800}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_7 = tiling({.buffer_dimension = {38400}, .tiling_dimension = {38400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_7 = tiling({.buffer_dimension = {38400}, .tiling_dimension = {38400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_7 = {8, 64, 8, 56};
std::vector<uint32_t> ofm_bound_7 = {8, 56, 8, 56};
std::vector<uint32_t> ofmsv_dim_7 = {8, 16, 2, 7};
uint32_t ofmsv_size_7 = 1792;
uint32_t ofm_repetition_7 = 2;
std::vector<access_pattern> ofm_pattern_7[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
}};


//Layer8
std::vector<uint32_t> ifm_dim_8 = {8, 64, 8, 56};
std::vector<uint32_t> ifm_bound_8 = {8, 56, 8, 56};
std::vector<uint32_t> ifmsv_dim_8 = {8, 16, 4, 2};
uint32_t ifmsv_size_8 = 1024;
uint32_t kernel_iter_8 = 56;
std::vector<access_pattern> ifm_pattern_8[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
}};


std::vector<uint32_t> ifm2_dim_8 = {8, 64, 32, 56};
std::vector<uint32_t> ifm2_bound_8 = {8, 56, 32, 56};
std::vector<uint32_t> ifm2sv_dim_8 = {8, 16, 32, 2};
uint32_t ifm2sv_size_8 = 8192;
std::vector<access_pattern> ifm2_pattern_8[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_8 = {20992};
std::vector<uint32_t> wts_ddr_dim_8 = {20992};
std::vector<uint32_t> wtssv_dim_8 = {2624};
uint32_t wtssv_size_8 = 2624;
uint32_t wts_repetition_8 = 1;
std::vector<access_pattern> wts_pattern_8[] = {
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {5248}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {10496}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {15744}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_8 = tiling({.buffer_dimension = {20992}, .tiling_dimension = {20992}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_8 = tiling({.buffer_dimension = {20992}, .tiling_dimension = {20992}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_8 = {8, 64, 32, 56};
std::vector<uint32_t> ofm_bound_8 = {8, 56, 32, 56};
std::vector<uint32_t> ofmsv_dim_8 = {8, 16, 8, 2};
uint32_t ofmsv_size_8 = 2048;
uint32_t ofm_repetition_8 = 2;
std::vector<access_pattern> ofm_pattern_8[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer9
std::vector<uint32_t> ifm_dim_9 = {8, 64, 32, 56};
std::vector<uint32_t> ifm_bound_9 = {8, 56, 32, 56};
std::vector<uint32_t> ifmsv_dim_9 = {8, 16, 4, 7};
uint32_t ifmsv_size_9 = 3584;
uint32_t kernel_iter_9 = 64;
std::vector<access_pattern> ifm_pattern_9[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 4, 7}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
}};


std::vector<uint32_t> wts_dim_9 = {22528};
std::vector<uint32_t> wts_ddr_dim_9 = {22528};
std::vector<uint32_t> wtssv_dim_9 = {704};
uint32_t wtssv_size_9 = 704;
uint32_t wts_repetition_9 = 1;
std::vector<access_pattern> wts_pattern_9[] = {
{
  tiling({.buffer_dimension = {22528}, .tiling_dimension = {704}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 8} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {22528}, .tiling_dimension = {704}, .offset = {5632}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 8} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {22528}, .tiling_dimension = {704}, .offset = {11264}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 8} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {22528}, .tiling_dimension = {704}, .offset = {16896}, .tile_traversal = { {.dimension = 0, .stride = 704, .wrap = 8} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_9 = tiling({.buffer_dimension = {22528}, .tiling_dimension = {22528}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_9 = tiling({.buffer_dimension = {22528}, .tiling_dimension = {22528}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_9 = {8, 64, 8, 56};
std::vector<uint32_t> ofm_bound_9 = {8, 56, 8, 56};
std::vector<uint32_t> ofmsv_dim_9 = {8, 16, 2, 7};
uint32_t ofmsv_size_9 = 1792;
uint32_t ofm_repetition_9 = 8;
std::vector<access_pattern> ofm_pattern_9[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 32, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 2, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 48, 6, 0}, .tile_traversal = { {.dimension = 3, .stride = 7, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer10
std::vector<uint32_t> ifm_dim_10 = {8, 64, 8, 56};
std::vector<uint32_t> ifm_bound_10 = {8, 56, 8, 56};
std::vector<uint32_t> ifmsv_dim_10 = {8, 20, 4, 9};
uint32_t ifmsv_size_10 = 5760;
uint32_t kernel_iter_10 = 16;
std::vector<access_pattern> ifm_pattern_10[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 27}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 34}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 13}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 41}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 20}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 48}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 1}, {.dimension = 1, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 28, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 1, .boundary_dimension = {8, 56, 8, 56}})
}};


std::vector<uint32_t> wts_dim_10 = {38400};
std::vector<uint32_t> wts_ddr_dim_10 = {38400};
std::vector<uint32_t> wtssv_dim_10 = {4800};
uint32_t wtssv_size_10 = 4800;
uint32_t wts_repetition_10 = 1;
std::vector<access_pattern> wts_pattern_10[] = {
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {9600}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {19200}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400}, .tiling_dimension = {4800}, .offset = {28800}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 2} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_10 = tiling({.buffer_dimension = {38400}, .tiling_dimension = {38400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_10 = tiling({.buffer_dimension = {38400}, .tiling_dimension = {38400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_10 = {8, 64, 8, 56};
std::vector<uint32_t> ofm_bound_10 = {8, 56, 8, 56};
std::vector<uint32_t> ofmsv_dim_10 = {8, 16, 2, 7};
uint32_t ofmsv_size_10 = 1792;
uint32_t ofm_repetition_10 = 2;
std::vector<access_pattern> ofm_pattern_10[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 28}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 7}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 35}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 14}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 42}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 21}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 49}, .tile_traversal = { {.dimension = 1, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
}};


//Layer11
std::vector<uint32_t> ifm_dim_11 = {8, 64, 8, 56};
std::vector<uint32_t> ifm_bound_11 = {8, 56, 8, 56};
std::vector<uint32_t> ifmsv_dim_11 = {8, 16, 4, 2};
uint32_t ifmsv_size_11 = 1024;
uint32_t kernel_iter_11 = 56;
std::vector<access_pattern> ifm_pattern_11[] = {
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 8, 56}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 2}, {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 8, 56}})
}};


std::vector<uint32_t> ifm2_dim_11 = {8, 64, 32, 56};
std::vector<uint32_t> ifm2_bound_11 = {8, 56, 32, 56};
std::vector<uint32_t> ifm2sv_dim_11 = {8, 16, 32, 2};
uint32_t ifm2sv_size_11 = 8192;
std::vector<access_pattern> ifm2_pattern_11[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_11 = {20992};
std::vector<uint32_t> wts_ddr_dim_11 = {20992};
std::vector<uint32_t> wtssv_dim_11 = {2624};
uint32_t wtssv_size_11 = 2624;
uint32_t wts_repetition_11 = 1;
std::vector<access_pattern> wts_pattern_11[] = {
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {5248}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {10496}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {20992}, .tiling_dimension = {2624}, .offset = {15744}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 2} }, .packet_port_id = -1, .repetition = 28, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_11 = tiling({.buffer_dimension = {20992}, .tiling_dimension = {20992}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_11 = tiling({.buffer_dimension = {20992}, .tiling_dimension = {20992}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_11 = {8, 64, 32, 56};
std::vector<uint32_t> ofm_bound_11 = {8, 56, 32, 56};
std::vector<uint32_t> ofmsv_dim_11 = {8, 16, 8, 2};
uint32_t ofmsv_size_11 = 2048;
uint32_t ofm_repetition_11 = 2;
std::vector<access_pattern> ofm_pattern_11[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 16, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 32, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 48, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 2, .wrap = 28} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer12
std::vector<uint32_t> ifm_dim_12 = {8, 64, 32, 56};
std::vector<uint32_t> ifm_bound_12 = {8, 56, 32, 56};
std::vector<uint32_t> ifmsv_dim_12 = {8, 16, 16, 3};
uint32_t ifmsv_size_12 = 6144;
uint32_t kernel_iter_12 = 38;
std::vector<access_pattern> ifm_pattern_12[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 16, 3}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2}, {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 16, 3}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2}, {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 16, 3}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2}, {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 16, 16, 3}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2}, {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
}};


std::vector<uint32_t> wts_dim_12 = {35328};
std::vector<uint32_t> wts_ddr_dim_12 = {35328};
std::vector<uint32_t> wtssv_dim_12 = {4416};
uint32_t wtssv_size_12 = 4416;
uint32_t wts_repetition_12 = 1;
std::vector<access_pattern> wts_pattern_12[] = {
{
  tiling({.buffer_dimension = {35328}, .tiling_dimension = {4416}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 2} }, .packet_port_id = -1, .repetition = 19, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {35328}, .tiling_dimension = {4416}, .offset = {8832}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 2} }, .packet_port_id = -1, .repetition = 19, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {35328}, .tiling_dimension = {4416}, .offset = {17664}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 2} }, .packet_port_id = -1, .repetition = 19, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {35328}, .tiling_dimension = {4416}, .offset = {26496}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 2} }, .packet_port_id = -1, .repetition = 19, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_12 = tiling({.buffer_dimension = {35328}, .tiling_dimension = {35328}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_12 = tiling({.buffer_dimension = {35328}, .tiling_dimension = {35328}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_12 = {8, 64, 16, 57};
std::vector<uint32_t> ofm_bound_12 = {8, 56, 16, 56};
std::vector<uint32_t> ofmsv_dim_12 = {8, 16, 4, 3};
uint32_t ofmsv_size_12 = 1536;
uint32_t ofm_repetition_12 = 2;
std::vector<access_pattern> ofm_pattern_12[] = {
{
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 16, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 16, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 16, 12, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 32, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 32, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 32, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 32, 12, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 48, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 48, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 48, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 16, 4, 3}, .offset = {0, 48, 12, 0}, .tile_traversal = { {.dimension = 3, .stride = 3, .wrap = 19} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer13
std::vector<uint32_t> ifm_dim_13 = {8, 64, 16, 57};
std::vector<uint32_t> ifm_bound_13 = {8, 56, 16, 56};
std::vector<uint32_t> ifmsv_dim_13 = {8, 68, 2, 4};
uint32_t ifmsv_size_13 = 4352;
uint32_t kernel_iter_13 = 56;
std::vector<access_pattern> ifm_pattern_13[] = {
{
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 68, 2, 4}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 8}, {.dimension = 3, .stride = 8, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 16, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 68, 2, 4}, .offset = {0, -1, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 8}, {.dimension = 3, .stride = 8, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 16, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 68, 2, 4}, .offset = {0, -1, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 8}, {.dimension = 3, .stride = 8, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 16, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 16, 57}, .tiling_dimension = {8, 68, 2, 4}, .offset = {0, -1, 0, 5}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 8}, {.dimension = 3, .stride = 8, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 56, 16, 56}})
}};


std::vector<uint32_t> wts_dim_13 = {157696};
std::vector<uint32_t> wts_ddr_dim_13 = {157696};
std::vector<uint32_t> wtssv_dim_13 = {4928};
uint32_t wtssv_size_13 = 4928;
uint32_t wts_repetition_13 = 1;
std::vector<access_pattern> wts_pattern_13[] = {
{
  tiling({.buffer_dimension = {157696}, .tiling_dimension = {4928}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4928, .wrap = 8} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {157696}, .tiling_dimension = {4928}, .offset = {39424}, .tile_traversal = { {.dimension = 0, .stride = 4928, .wrap = 8} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {157696}, .tiling_dimension = {4928}, .offset = {78848}, .tile_traversal = { {.dimension = 0, .stride = 4928, .wrap = 8} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {157696}, .tiling_dimension = {4928}, .offset = {118272}, .tile_traversal = { {.dimension = 0, .stride = 4928, .wrap = 8} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_13 = tiling({.buffer_dimension = {157696}, .tiling_dimension = {157696}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_13 = tiling({.buffer_dimension = {157696}, .tiling_dimension = {157696}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_13 = {8, 32, 16, 28};
std::vector<uint32_t> ofm_bound_13 = {8, 28, 16, 28};
std::vector<uint32_t> ofmsv_dim_13 = {8, 32, 4, 1};
uint32_t ofmsv_size_13 = 1024;
uint32_t ofm_repetition_13 = 8;
std::vector<access_pattern> ofm_pattern_13[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer14
std::vector<uint32_t> ifm_dim_14 = {8, 64, 32, 56};
std::vector<uint32_t> ifm_bound_14 = {8, 56, 32, 56};
std::vector<uint32_t> ifmsv_dim_14 = {8, 32, 8, 2};
uint32_t ifmsv_size_14 = 4096;
uint32_t kernel_iter_14 = 112;
std::vector<access_pattern> ifm_pattern_14[] = {
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4}, {.dimension = 1, .stride = 32, .wrap = 2}, {.dimension = 3, .stride = 8, .wrap = 7} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4}, {.dimension = 1, .stride = 32, .wrap = 2}, {.dimension = 3, .stride = 8, .wrap = 7} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4}, {.dimension = 1, .stride = 32, .wrap = 2}, {.dimension = 3, .stride = 8, .wrap = 7} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
},
{
  tiling({.buffer_dimension = {8, 64, 32, 56}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4}, {.dimension = 1, .stride = 32, .wrap = 2}, {.dimension = 3, .stride = 8, .wrap = 7} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 56, 32, 56}})
}};


std::vector<uint32_t> wts_dim_14 = {149504};
std::vector<uint32_t> wts_ddr_dim_14 = {149504};
std::vector<uint32_t> wtssv_dim_14 = {4672};
uint32_t wtssv_size_14 = 4672;
uint32_t wts_repetition_14 = 1;
std::vector<access_pattern> wts_pattern_14[] = {
{
  tiling({.buffer_dimension = {149504}, .tiling_dimension = {4672}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 4} }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {149504}, .tiling_dimension = {4672}, .offset = {74752}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 4} }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {149504}, .tiling_dimension = {4672}, .offset = {18688}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 4} }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {149504}, .tiling_dimension = {4672}, .offset = {93440}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 4} }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {149504}, .tiling_dimension = {4672}, .offset = {37376}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 4} }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {149504}, .tiling_dimension = {4672}, .offset = {112128}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 4} }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {149504}, .tiling_dimension = {4672}, .offset = {56064}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 4} }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {149504}, .tiling_dimension = {4672}, .offset = {130816}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 4} }, .packet_port_id = -1, .repetition = 14, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_14 = tiling({.buffer_dimension = {149504}, .tiling_dimension = {149504}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_14 = tiling({.buffer_dimension = {149504}, .tiling_dimension = {149504}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_14 = {8, 32, 64, 28};
std::vector<uint32_t> ofm_bound_14 = {8, 28, 64, 28};
std::vector<uint32_t> ofmsv_dim_14 = {8, 16, 8, 1};
uint32_t ofmsv_size_14 = 1024;
uint32_t ofm_repetition_14 = 4;
std::vector<access_pattern> ofm_pattern_14[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 32, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 40, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 48, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 56, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 32, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 40, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 48, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 56, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 32, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 40, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 48, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 56, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 16, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 24, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 32, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 40, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 48, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 56, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 32, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 40, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 48, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 56, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 16, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 24, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 32, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 40, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 48, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 56, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 32, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 40, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 48, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 56, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 16, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 24, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 32, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 40, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 48, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 16, 56, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer15
std::vector<uint32_t> ifm_dim_15 = {8, 32, 16, 28};
std::vector<uint32_t> ifm_bound_15 = {8, 28, 16, 28};
std::vector<uint32_t> ifmsv_dim_15 = {8, 32, 4, 1};
uint32_t ifmsv_size_15 = 1024;
uint32_t kernel_iter_15 = 56;
std::vector<access_pattern> ifm_pattern_15[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
}};


std::vector<uint32_t> ifm2_dim_15 = {8, 32, 64, 28};
std::vector<uint32_t> ifm2_bound_15 = {8, 28, 64, 28};
std::vector<uint32_t> ifm2sv_dim_15 = {8, 32, 32, 1};
uint32_t ifm2sv_size_15 = 8192;
std::vector<access_pattern> ifm2_pattern_15[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_15 = {83968};
std::vector<uint32_t> wts_ddr_dim_15 = {83968};
std::vector<uint32_t> wtssv_dim_15 = {2624};
uint32_t wtssv_size_15 = 2624;
uint32_t wts_repetition_15 = 1;
std::vector<access_pattern> wts_pattern_15[] = {
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {41984}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {10496}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {52480}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {20992}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {62976}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {31488}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {73472}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_15 = tiling({.buffer_dimension = {83968}, .tiling_dimension = {83968}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_15 = tiling({.buffer_dimension = {83968}, .tiling_dimension = {83968}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_15 = {8, 32, 64, 28};
std::vector<uint32_t> ofm_bound_15 = {8, 28, 64, 28};
std::vector<uint32_t> ofmsv_dim_15 = {8, 32, 8, 1};
uint32_t ofmsv_size_15 = 2048;
uint32_t ofm_repetition_15 = 4;
std::vector<access_pattern> ofm_pattern_15[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer16
std::vector<uint32_t> ifm_dim_16 = {8, 32, 64, 28};
std::vector<uint32_t> ifm_bound_16 = {8, 28, 64, 28};
std::vector<uint32_t> ifmsv_dim_16 = {8, 32, 16, 1};
uint32_t ifmsv_size_16 = 4096;
uint32_t kernel_iter_16 = 28;
std::vector<access_pattern> ifm_pattern_16[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
}};


std::vector<uint32_t> wts_dim_16 = {70656};
std::vector<uint32_t> wts_ddr_dim_16 = {70656};
std::vector<uint32_t> wtssv_dim_16 = {4416};
uint32_t wtssv_size_16 = 4416;
uint32_t wts_repetition_16 = 1;
std::vector<access_pattern> wts_pattern_16[] = {
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {17664}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {35328}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {52992}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_16 = tiling({.buffer_dimension = {70656}, .tiling_dimension = {70656}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_16 = tiling({.buffer_dimension = {70656}, .tiling_dimension = {70656}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_16 = {8, 32, 16, 28};
std::vector<uint32_t> ofm_bound_16 = {8, 28, 16, 28};
std::vector<uint32_t> ofmsv_dim_16 = {8, 32, 4, 1};
uint32_t ofmsv_size_16 = 1024;
uint32_t ofm_repetition_16 = 4;
std::vector<access_pattern> ofm_pattern_16[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer17
std::vector<uint32_t> ifm_dim_17 = {8, 32, 16, 28};
std::vector<uint32_t> ifm_bound_17 = {8, 28, 16, 28};
std::vector<uint32_t> ifmsv_dim_17 = {8, 20, 4, 9};
uint32_t ifmsv_size_17 = 5760;
uint32_t kernel_iter_17 = 16;
std::vector<access_pattern> ifm_pattern_17[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 13}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 20}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
}};


std::vector<uint32_t> wts_dim_17 = {153600};
std::vector<uint32_t> wts_ddr_dim_17 = {153600};
std::vector<uint32_t> wtssv_dim_17 = {4800};
uint32_t wtssv_size_17 = 4800;
uint32_t wts_repetition_17 = 1;
std::vector<access_pattern> wts_pattern_17[] = {
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {76800}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {19200}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {96000}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {38400}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {115200}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {57600}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {134400}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_17 = tiling({.buffer_dimension = {153600}, .tiling_dimension = {153600}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_17 = tiling({.buffer_dimension = {153600}, .tiling_dimension = {153600}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_17 = {8, 32, 16, 28};
std::vector<uint32_t> ofm_bound_17 = {8, 28, 16, 28};
std::vector<uint32_t> ofmsv_dim_17 = {8, 16, 2, 7};
uint32_t ofmsv_size_17 = 1792;
uint32_t ofm_repetition_17 = 4;
std::vector<access_pattern> ofm_pattern_17[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer18
std::vector<uint32_t> ifm_dim_18 = {8, 32, 16, 28};
std::vector<uint32_t> ifm_bound_18 = {8, 28, 16, 28};
std::vector<uint32_t> ifmsv_dim_18 = {8, 32, 4, 1};
uint32_t ifmsv_size_18 = 1024;
uint32_t kernel_iter_18 = 56;
std::vector<access_pattern> ifm_pattern_18[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
}};


std::vector<uint32_t> ifm2_dim_18 = {8, 32, 64, 28};
std::vector<uint32_t> ifm2_bound_18 = {8, 28, 64, 28};
std::vector<uint32_t> ifm2sv_dim_18 = {8, 32, 32, 1};
uint32_t ifm2sv_size_18 = 8192;
std::vector<access_pattern> ifm2_pattern_18[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_18 = {83968};
std::vector<uint32_t> wts_ddr_dim_18 = {83968};
std::vector<uint32_t> wtssv_dim_18 = {2624};
uint32_t wtssv_size_18 = 2624;
uint32_t wts_repetition_18 = 1;
std::vector<access_pattern> wts_pattern_18[] = {
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {41984}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {10496}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {52480}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {20992}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {62976}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {31488}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {73472}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_18 = tiling({.buffer_dimension = {83968}, .tiling_dimension = {83968}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_18 = tiling({.buffer_dimension = {83968}, .tiling_dimension = {83968}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_18 = {8, 32, 64, 28};
std::vector<uint32_t> ofm_bound_18 = {8, 28, 64, 28};
std::vector<uint32_t> ofmsv_dim_18 = {8, 32, 8, 1};
uint32_t ofmsv_size_18 = 2048;
uint32_t ofm_repetition_18 = 4;
std::vector<access_pattern> ofm_pattern_18[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer19
std::vector<uint32_t> ifm_dim_19 = {8, 32, 64, 28};
std::vector<uint32_t> ifm_bound_19 = {8, 28, 64, 28};
std::vector<uint32_t> ifmsv_dim_19 = {8, 32, 16, 1};
uint32_t ifmsv_size_19 = 4096;
uint32_t kernel_iter_19 = 28;
std::vector<access_pattern> ifm_pattern_19[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
}};


std::vector<uint32_t> wts_dim_19 = {70656};
std::vector<uint32_t> wts_ddr_dim_19 = {70656};
std::vector<uint32_t> wtssv_dim_19 = {4416};
uint32_t wtssv_size_19 = 4416;
uint32_t wts_repetition_19 = 1;
std::vector<access_pattern> wts_pattern_19[] = {
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {17664}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {35328}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {52992}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_19 = tiling({.buffer_dimension = {70656}, .tiling_dimension = {70656}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_19 = tiling({.buffer_dimension = {70656}, .tiling_dimension = {70656}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_19 = {8, 32, 16, 28};
std::vector<uint32_t> ofm_bound_19 = {8, 28, 16, 28};
std::vector<uint32_t> ofmsv_dim_19 = {8, 32, 4, 1};
uint32_t ofmsv_size_19 = 1024;
uint32_t ofm_repetition_19 = 4;
std::vector<access_pattern> ofm_pattern_19[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer20
std::vector<uint32_t> ifm_dim_20 = {8, 32, 16, 28};
std::vector<uint32_t> ifm_bound_20 = {8, 28, 16, 28};
std::vector<uint32_t> ifmsv_dim_20 = {8, 20, 4, 9};
uint32_t ifmsv_size_20 = 5760;
uint32_t kernel_iter_20 = 16;
std::vector<access_pattern> ifm_pattern_20[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 13}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 20}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
}};


std::vector<uint32_t> wts_dim_20 = {153600};
std::vector<uint32_t> wts_ddr_dim_20 = {153600};
std::vector<uint32_t> wtssv_dim_20 = {4800};
uint32_t wtssv_size_20 = 4800;
uint32_t wts_repetition_20 = 1;
std::vector<access_pattern> wts_pattern_20[] = {
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {76800}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {19200}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {96000}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {38400}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {115200}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {57600}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {134400}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_20 = tiling({.buffer_dimension = {153600}, .tiling_dimension = {153600}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_20 = tiling({.buffer_dimension = {153600}, .tiling_dimension = {153600}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_20 = {8, 32, 16, 28};
std::vector<uint32_t> ofm_bound_20 = {8, 28, 16, 28};
std::vector<uint32_t> ofmsv_dim_20 = {8, 16, 2, 7};
uint32_t ofmsv_size_20 = 1792;
uint32_t ofm_repetition_20 = 4;
std::vector<access_pattern> ofm_pattern_20[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer21
std::vector<uint32_t> ifm_dim_21 = {8, 32, 16, 28};
std::vector<uint32_t> ifm_bound_21 = {8, 28, 16, 28};
std::vector<uint32_t> ifmsv_dim_21 = {8, 32, 4, 1};
uint32_t ifmsv_size_21 = 1024;
uint32_t kernel_iter_21 = 56;
std::vector<access_pattern> ifm_pattern_21[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
}};


std::vector<uint32_t> ifm2_dim_21 = {8, 32, 64, 28};
std::vector<uint32_t> ifm2_bound_21 = {8, 28, 64, 28};
std::vector<uint32_t> ifm2sv_dim_21 = {8, 32, 32, 1};
uint32_t ifm2sv_size_21 = 8192;
std::vector<access_pattern> ifm2_pattern_21[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_21 = {83968};
std::vector<uint32_t> wts_ddr_dim_21 = {83968};
std::vector<uint32_t> wtssv_dim_21 = {2624};
uint32_t wtssv_size_21 = 2624;
uint32_t wts_repetition_21 = 1;
std::vector<access_pattern> wts_pattern_21[] = {
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {41984}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {10496}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {52480}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {20992}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {62976}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {31488}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {73472}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_21 = tiling({.buffer_dimension = {83968}, .tiling_dimension = {83968}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_21 = tiling({.buffer_dimension = {83968}, .tiling_dimension = {83968}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_21 = {8, 32, 64, 28};
std::vector<uint32_t> ofm_bound_21 = {8, 28, 64, 28};
std::vector<uint32_t> ofmsv_dim_21 = {8, 32, 8, 1};
uint32_t ofmsv_size_21 = 2048;
uint32_t ofm_repetition_21 = 4;
std::vector<access_pattern> ofm_pattern_21[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer22
std::vector<uint32_t> ifm_dim_22 = {8, 32, 64, 28};
std::vector<uint32_t> ifm_bound_22 = {8, 28, 64, 28};
std::vector<uint32_t> ifmsv_dim_22 = {8, 32, 16, 1};
uint32_t ifmsv_size_22 = 4096;
uint32_t kernel_iter_22 = 28;
std::vector<access_pattern> ifm_pattern_22[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
}};


std::vector<uint32_t> wts_dim_22 = {70656};
std::vector<uint32_t> wts_ddr_dim_22 = {70656};
std::vector<uint32_t> wtssv_dim_22 = {4416};
uint32_t wtssv_size_22 = 4416;
uint32_t wts_repetition_22 = 1;
std::vector<access_pattern> wts_pattern_22[] = {
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {17664}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {35328}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656}, .tiling_dimension = {4416}, .offset = {52992}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_22 = tiling({.buffer_dimension = {70656}, .tiling_dimension = {70656}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_22 = tiling({.buffer_dimension = {70656}, .tiling_dimension = {70656}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_22 = {8, 32, 16, 28};
std::vector<uint32_t> ofm_bound_22 = {8, 28, 16, 28};
std::vector<uint32_t> ofmsv_dim_22 = {8, 32, 4, 1};
uint32_t ofmsv_size_22 = 1024;
uint32_t ofm_repetition_22 = 4;
std::vector<access_pattern> ofm_pattern_22[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer23
std::vector<uint32_t> ifm_dim_23 = {8, 32, 16, 28};
std::vector<uint32_t> ifm_bound_23 = {8, 28, 16, 28};
std::vector<uint32_t> ifmsv_dim_23 = {8, 20, 4, 9};
uint32_t ifmsv_size_23 = 5760;
uint32_t kernel_iter_23 = 16;
std::vector<access_pattern> ifm_pattern_23[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 13}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 20, 4, 9}, .offset = {0, -1, 0, 20}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 1, .stride = 16, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
}};


std::vector<uint32_t> wts_dim_23 = {153600};
std::vector<uint32_t> wts_ddr_dim_23 = {153600};
std::vector<uint32_t> wtssv_dim_23 = {4800};
uint32_t wtssv_size_23 = 4800;
uint32_t wts_repetition_23 = 1;
std::vector<access_pattern> wts_pattern_23[] = {
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {76800}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {19200}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {96000}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {38400}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {115200}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {57600}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {153600}, .tiling_dimension = {4800}, .offset = {134400}, .tile_traversal = { {.dimension = 0, .stride = 4800, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_23 = tiling({.buffer_dimension = {153600}, .tiling_dimension = {153600}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_23 = tiling({.buffer_dimension = {153600}, .tiling_dimension = {153600}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_23 = {8, 32, 16, 28};
std::vector<uint32_t> ofm_bound_23 = {8, 28, 16, 28};
std::vector<uint32_t> ofmsv_dim_23 = {8, 16, 2, 7};
uint32_t ofmsv_size_23 = 1792;
uint32_t ofm_repetition_23 = 4;
std::vector<access_pattern> ofm_pattern_23[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 7}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 0, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 2, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 4, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 0, 6, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 0, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 2, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 4, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 16, 2, 7}, .offset = {0, 16, 6, 21}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer24
std::vector<uint32_t> ifm_dim_24 = {8, 32, 16, 28};
std::vector<uint32_t> ifm_bound_24 = {8, 28, 16, 28};
std::vector<uint32_t> ifmsv_dim_24 = {8, 32, 4, 1};
uint32_t ifmsv_size_24 = 1024;
uint32_t kernel_iter_24 = 56;
std::vector<access_pattern> ifm_pattern_24[] = {
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 16, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7}, {.dimension = 1, .stride = 0, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 28, 16, 28}})
}};


std::vector<uint32_t> ifm2_dim_24 = {8, 32, 64, 28};
std::vector<uint32_t> ifm2_bound_24 = {8, 28, 64, 28};
std::vector<uint32_t> ifm2sv_dim_24 = {8, 32, 32, 1};
uint32_t ifm2sv_size_24 = 8192;
std::vector<access_pattern> ifm2_pattern_24[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 32, 1}, .offset = {0, 0, 128, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_24 = {83968};
std::vector<uint32_t> wts_ddr_dim_24 = {83968};
std::vector<uint32_t> wtssv_dim_24 = {2624};
uint32_t wtssv_size_24 = 2624;
uint32_t wts_repetition_24 = 1;
std::vector<access_pattern> wts_pattern_24[] = {
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {41984}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {10496}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {52480}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {20992}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {62976}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {31488}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {83968}, .tiling_dimension = {2624}, .offset = {73472}, .tile_traversal = { {.dimension = 0, .stride = 2624, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_24 = tiling({.buffer_dimension = {83968}, .tiling_dimension = {83968}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_24 = tiling({.buffer_dimension = {83968}, .tiling_dimension = {83968}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_24 = {8, 32, 64, 28};
std::vector<uint32_t> ofm_bound_24 = {8, 28, 64, 28};
std::vector<uint32_t> ofmsv_dim_24 = {8, 32, 8, 1};
uint32_t ofmsv_size_24 = 2048;
uint32_t ofm_repetition_24 = 4;
std::vector<access_pattern> ofm_pattern_24[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 16, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 24, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 32, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 40, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 48, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 1}, .offset = {0, 0, 56, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer25
std::vector<uint32_t> ifm_dim_25 = {8, 32, 64, 28};
std::vector<uint32_t> ifm_bound_25 = {8, 28, 64, 28};
std::vector<uint32_t> ifmsv_dim_25 = {8, 32, 16, 1};
uint32_t ifmsv_size_25 = 4096;
uint32_t kernel_iter_25 = 56;
std::vector<access_pattern> ifm_pattern_25[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 16, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4}, {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}})
}};


std::vector<uint32_t> wts_dim_25 = {141312};
std::vector<uint32_t> wts_ddr_dim_25 = {141312};
std::vector<uint32_t> wtssv_dim_25 = {4416};
uint32_t wtssv_size_25 = 4416;
uint32_t wts_repetition_25 = 1;
std::vector<access_pattern> wts_pattern_25[] = {
{
  tiling({.buffer_dimension = {141312}, .tiling_dimension = {4416}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {141312}, .tiling_dimension = {4416}, .offset = {70656}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {141312}, .tiling_dimension = {4416}, .offset = {17664}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {141312}, .tiling_dimension = {4416}, .offset = {88320}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {141312}, .tiling_dimension = {4416}, .offset = {35328}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {141312}, .tiling_dimension = {4416}, .offset = {105984}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {141312}, .tiling_dimension = {4416}, .offset = {52992}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {141312}, .tiling_dimension = {4416}, .offset = {123648}, .tile_traversal = { {.dimension = 0, .stride = 4416, .wrap = 4} }, .packet_port_id = -1, .repetition = 7, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_25 = tiling({.buffer_dimension = {141312}, .tiling_dimension = {141312}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_25 = tiling({.buffer_dimension = {141312}, .tiling_dimension = {141312}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_25 = {8, 32, 32, 28};
std::vector<uint32_t> ofm_bound_25 = {8, 28, 32, 28};
std::vector<uint32_t> ofmsv_dim_25 = {8, 32, 4, 1};
uint32_t ofmsv_size_25 = 1024;
uint32_t ofm_repetition_25 = 4;
std::vector<access_pattern> ofm_pattern_25[] = {
{
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 20, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 28, 0}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 16, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 20, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 24, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 28, 1}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 20, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 28, 2}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 4, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 12, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 16, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 20, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 24, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 32, 4, 1}, .offset = {0, 0, 28, 3}, .tile_traversal = { {.dimension = 3, .stride = 4, .wrap = 7} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer26
std::vector<uint32_t> ifm_dim_26 = {8, 32, 32, 28};
std::vector<uint32_t> ifm_bound_26 = {8, 28, 32, 28};
std::vector<uint32_t> ifmsv_dim_26 = {8, 36, 2, 10};
uint32_t ifmsv_size_26 = 5760;
uint32_t kernel_iter_26 = 32;
std::vector<access_pattern> ifm_pattern_26[] = {
{
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 36, 2, 10}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 16} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 32, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 36, 2, 10}, .offset = {0, -1, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 16} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 32, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 36, 2, 10}, .offset = {0, -1, 0, 15}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 16} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 32, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 32, 28}, .tiling_dimension = {8, 36, 2, 10}, .offset = {0, -1, 0, 23}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 16} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 32, 28}})
}};


std::vector<uint32_t> wts_dim_26 = {630784};
std::vector<uint32_t> wts_ddr_dim_26 = {630784};
std::vector<uint32_t> wtssv_dim_26 = {4928};
uint32_t wtssv_size_26 = 4928;
uint32_t wts_repetition_26 = 1;
std::vector<access_pattern> wts_pattern_26[] = {
{
  tiling({.buffer_dimension = {78848, 8}, .tiling_dimension = {78848, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {78848, 8}, .tiling_dimension = {78848, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {78848, 8}, .tiling_dimension = {78848, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {78848, 8}, .tiling_dimension = {78848, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_26 = tiling({.buffer_dimension = {630784}, .tiling_dimension = {630784}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_26 = tiling({.buffer_dimension = {630784}, .tiling_dimension = {630784}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_26 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_26 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_26 = {8, 16, 4, 4};
uint32_t ofmsv_size_26 = 2048;
uint32_t ofm_repetition_26 = 16;
std::vector<access_pattern> ofm_pattern_26[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 12, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 4, 8}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 8, 8}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 12, 8}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 4, 12}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 8, 12}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 4}, .offset = {0, 0, 12, 12}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer27
std::vector<uint32_t> ifm_dim_27 = {8, 32, 64, 28};
std::vector<uint32_t> ifm_bound_27 = {8, 28, 64, 28};
std::vector<uint32_t> ifmsv_dim_27 = {8, 32, 8, 2};
uint32_t ifmsv_size_27 = 4096;
uint32_t kernel_iter_27 = 128;
std::vector<access_pattern> ifm_pattern_27[] = {
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 16}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 1, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 24}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 1, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 18}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 1, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 26}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 1, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 20}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 1, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 28}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 1, .boundary_dimension = {8, 28, 64, 28}})
},
{
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 22}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 1, .boundary_dimension = {8, 28, 64, 28}}),
  tiling({.buffer_dimension = {8, 32, 64, 28}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 28}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = -1, .repetition = 2, .phase = 1, .boundary_dimension = {8, 28, 64, 28}})
}};


std::vector<uint32_t> wts_dim_27 = {598016};
std::vector<uint32_t> wts_ddr_dim_27 = {598016};
std::vector<uint32_t> wtssv_dim_27 = {4672};
uint32_t wtssv_size_27 = 4672;
uint32_t wts_repetition_27 = 1;
std::vector<access_pattern> wts_pattern_27[] = {
{
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {149504}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {299008}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {448512}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {37376}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {186880}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {336384}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {485888}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {74752}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {224256}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {373760}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {523264}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {112128}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {261632}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {411136}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {598016}, .tiling_dimension = {4672}, .offset = {560640}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_27 = tiling({.buffer_dimension = {598016}, .tiling_dimension = {598016}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_27 = tiling({.buffer_dimension = {598016}, .tiling_dimension = {598016}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_27 = {8, 16, 128, 16};
std::vector<uint32_t> ofm_bound_27 = {8, 14, 128, 14};
std::vector<uint32_t> ofmsv_dim_27 = {8, 16, 8, 1};
uint32_t ofmsv_size_27 = 1024;
uint32_t ofm_repetition_27 = 8;
std::vector<access_pattern> ofm_pattern_27[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 1}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 1}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 5}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 5}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 5}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 5}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 9}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 9}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 9}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 9}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 13}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 13}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 13}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 13}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 10}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 10}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 10}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 14}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 14}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 14}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 3}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 3}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 7}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 7}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 7}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 11}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 11}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 11}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 11}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 15}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 15}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 15}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 1, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 15}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 1, .boundary_dimension = {}})
}};


//Layer28
std::vector<uint32_t> ifm_dim_28 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_28 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_28 = {8, 16, 4, 2};
uint32_t ifmsv_size_28 = 1024;
uint32_t kernel_iter_28 = 48;
std::vector<access_pattern> ifm_pattern_28[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> ifm2_dim_28 = {8, 16, 128, 16};
std::vector<uint32_t> ifm2_bound_28 = {8, 14, 128, 14};
std::vector<uint32_t> ifm2sv_dim_28 = {8, 16, 48, 2};
uint32_t ifm2sv_size_28 = 12288;
std::vector<access_pattern> ifm2_pattern_28[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_28 = {343552};
std::vector<uint32_t> wts_ddr_dim_28 = {343552};
std::vector<uint32_t> wtssv_dim_28 = {3904};
uint32_t wtssv_size_28 = 3904;
uint32_t wts_repetition_28 = 1;
std::vector<access_pattern> wts_pattern_28[] = {
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_28 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_28 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_28 = {8, 16, 128, 16};
std::vector<uint32_t> ofm_bound_28 = {8, 14, 128, 14};
std::vector<uint32_t> ofmsv_dim_28 = {8, 16, 12, 2};
uint32_t ofmsv_size_28 = 3072;
uint32_t ofm_repetition_28 = 8;
std::vector<access_pattern> ofm_pattern_28[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer29
std::vector<uint32_t> ifm_dim_29 = {8, 16, 128, 16};
std::vector<uint32_t> ifm_bound_29 = {8, 14, 128, 14};
std::vector<uint32_t> ifmsv_dim_29 = {8, 16, 8, 4};
uint32_t ifmsv_size_29 = 4096;
uint32_t kernel_iter_29 = 16;
std::vector<access_pattern> ifm_pattern_29[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
}};


std::vector<uint32_t> wts_dim_29 = {299008};
std::vector<uint32_t> wts_ddr_dim_29 = {299008};
std::vector<uint32_t> wtssv_dim_29 = {4672};
uint32_t wtssv_size_29 = 4672;
uint32_t wts_repetition_29 = 1;
std::vector<access_pattern> wts_pattern_29[] = {
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {74752}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {149504}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {224256}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_29 = tiling({.buffer_dimension = {299008}, .tiling_dimension = {299008}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_29 = tiling({.buffer_dimension = {299008}, .tiling_dimension = {299008}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_29 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_29 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_29 = {8, 16, 8, 4};
uint32_t ofmsv_size_29 = 4096;
uint32_t ofm_repetition_29 = 16;
std::vector<access_pattern> ofm_pattern_29[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer30
std::vector<uint32_t> ifm_dim_30 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_30 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_30 = {8, 20, 4, 6};
uint32_t ifmsv_size_30 = 3840;
uint32_t kernel_iter_30 = 32;
std::vector<access_pattern> ifm_pattern_30[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 11}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> wts_dim_30 = {614400};
std::vector<uint32_t> wts_ddr_dim_30 = {614400};
std::vector<uint32_t> wtssv_dim_30 = {4800};
uint32_t wtssv_size_30 = 4800;
uint32_t wts_repetition_30 = 1;
std::vector<access_pattern> wts_pattern_30[] = {
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_30 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_30 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_30 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_30 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_30 = {8, 16, 2, 4};
uint32_t ofmsv_size_30 = 1024;
uint32_t ofm_repetition_30 = 8;
std::vector<access_pattern> ofm_pattern_30[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer31
std::vector<uint32_t> ifm_dim_31 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_31 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_31 = {8, 16, 4, 2};
uint32_t ifmsv_size_31 = 1024;
uint32_t kernel_iter_31 = 48;
std::vector<access_pattern> ifm_pattern_31[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> ifm2_dim_31 = {8, 16, 128, 16};
std::vector<uint32_t> ifm2_bound_31 = {8, 14, 128, 14};
std::vector<uint32_t> ifm2sv_dim_31 = {8, 16, 48, 2};
uint32_t ifm2sv_size_31 = 12288;
std::vector<access_pattern> ifm2_pattern_31[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_31 = {343552};
std::vector<uint32_t> wts_ddr_dim_31 = {343552};
std::vector<uint32_t> wtssv_dim_31 = {3904};
uint32_t wtssv_size_31 = 3904;
uint32_t wts_repetition_31 = 1;
std::vector<access_pattern> wts_pattern_31[] = {
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_31 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_31 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_31 = {8, 16, 128, 16};
std::vector<uint32_t> ofm_bound_31 = {8, 14, 128, 14};
std::vector<uint32_t> ofmsv_dim_31 = {8, 16, 12, 2};
uint32_t ofmsv_size_31 = 3072;
uint32_t ofm_repetition_31 = 8;
std::vector<access_pattern> ofm_pattern_31[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer32
std::vector<uint32_t> ifm_dim_32 = {8, 16, 128, 16};
std::vector<uint32_t> ifm_bound_32 = {8, 14, 128, 14};
std::vector<uint32_t> ifmsv_dim_32 = {8, 16, 8, 4};
uint32_t ifmsv_size_32 = 4096;
uint32_t kernel_iter_32 = 16;
std::vector<access_pattern> ifm_pattern_32[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
}};


std::vector<uint32_t> wts_dim_32 = {299008};
std::vector<uint32_t> wts_ddr_dim_32 = {299008};
std::vector<uint32_t> wtssv_dim_32 = {4672};
uint32_t wtssv_size_32 = 4672;
uint32_t wts_repetition_32 = 1;
std::vector<access_pattern> wts_pattern_32[] = {
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {74752}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {149504}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {224256}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_32 = tiling({.buffer_dimension = {299008}, .tiling_dimension = {299008}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_32 = tiling({.buffer_dimension = {299008}, .tiling_dimension = {299008}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_32 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_32 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_32 = {8, 16, 8, 4};
uint32_t ofmsv_size_32 = 4096;
uint32_t ofm_repetition_32 = 16;
std::vector<access_pattern> ofm_pattern_32[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer33
std::vector<uint32_t> ifm_dim_33 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_33 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_33 = {8, 20, 4, 6};
uint32_t ifmsv_size_33 = 3840;
uint32_t kernel_iter_33 = 32;
std::vector<access_pattern> ifm_pattern_33[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 11}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> wts_dim_33 = {614400};
std::vector<uint32_t> wts_ddr_dim_33 = {614400};
std::vector<uint32_t> wtssv_dim_33 = {4800};
uint32_t wtssv_size_33 = 4800;
uint32_t wts_repetition_33 = 1;
std::vector<access_pattern> wts_pattern_33[] = {
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_33 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_33 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_33 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_33 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_33 = {8, 16, 2, 4};
uint32_t ofmsv_size_33 = 1024;
uint32_t ofm_repetition_33 = 8;
std::vector<access_pattern> ofm_pattern_33[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer34
std::vector<uint32_t> ifm_dim_34 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_34 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_34 = {8, 16, 4, 2};
uint32_t ifmsv_size_34 = 1024;
uint32_t kernel_iter_34 = 48;
std::vector<access_pattern> ifm_pattern_34[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> ifm2_dim_34 = {8, 16, 128, 16};
std::vector<uint32_t> ifm2_bound_34 = {8, 14, 128, 14};
std::vector<uint32_t> ifm2sv_dim_34 = {8, 16, 48, 2};
uint32_t ifm2sv_size_34 = 12288;
std::vector<access_pattern> ifm2_pattern_34[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_34 = {343552};
std::vector<uint32_t> wts_ddr_dim_34 = {343552};
std::vector<uint32_t> wtssv_dim_34 = {3904};
uint32_t wtssv_size_34 = 3904;
uint32_t wts_repetition_34 = 1;
std::vector<access_pattern> wts_pattern_34[] = {
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_34 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_34 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_34 = {8, 16, 128, 16};
std::vector<uint32_t> ofm_bound_34 = {8, 14, 128, 14};
std::vector<uint32_t> ofmsv_dim_34 = {8, 16, 12, 2};
uint32_t ofmsv_size_34 = 3072;
uint32_t ofm_repetition_34 = 8;
std::vector<access_pattern> ofm_pattern_34[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer35
std::vector<uint32_t> ifm_dim_35 = {8, 16, 128, 16};
std::vector<uint32_t> ifm_bound_35 = {8, 14, 128, 14};
std::vector<uint32_t> ifmsv_dim_35 = {8, 16, 8, 4};
uint32_t ifmsv_size_35 = 4096;
uint32_t kernel_iter_35 = 16;
std::vector<access_pattern> ifm_pattern_35[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
}};


std::vector<uint32_t> wts_dim_35 = {299008};
std::vector<uint32_t> wts_ddr_dim_35 = {299008};
std::vector<uint32_t> wtssv_dim_35 = {4672};
uint32_t wtssv_size_35 = 4672;
uint32_t wts_repetition_35 = 1;
std::vector<access_pattern> wts_pattern_35[] = {
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {74752}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {149504}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {224256}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_35 = tiling({.buffer_dimension = {299008}, .tiling_dimension = {299008}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_35 = tiling({.buffer_dimension = {299008}, .tiling_dimension = {299008}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_35 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_35 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_35 = {8, 16, 8, 4};
uint32_t ofmsv_size_35 = 4096;
uint32_t ofm_repetition_35 = 16;
std::vector<access_pattern> ofm_pattern_35[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer36
std::vector<uint32_t> ifm_dim_36 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_36 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_36 = {8, 20, 4, 6};
uint32_t ifmsv_size_36 = 3840;
uint32_t kernel_iter_36 = 32;
std::vector<access_pattern> ifm_pattern_36[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 11}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> wts_dim_36 = {614400};
std::vector<uint32_t> wts_ddr_dim_36 = {614400};
std::vector<uint32_t> wtssv_dim_36 = {4800};
uint32_t wtssv_size_36 = 4800;
uint32_t wts_repetition_36 = 1;
std::vector<access_pattern> wts_pattern_36[] = {
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_36 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_36 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_36 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_36 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_36 = {8, 16, 2, 4};
uint32_t ofmsv_size_36 = 1024;
uint32_t ofm_repetition_36 = 8;
std::vector<access_pattern> ofm_pattern_36[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer37
std::vector<uint32_t> ifm_dim_37 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_37 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_37 = {8, 16, 4, 2};
uint32_t ifmsv_size_37 = 1024;
uint32_t kernel_iter_37 = 48;
std::vector<access_pattern> ifm_pattern_37[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> ifm2_dim_37 = {8, 16, 128, 16};
std::vector<uint32_t> ifm2_bound_37 = {8, 14, 128, 14};
std::vector<uint32_t> ifm2sv_dim_37 = {8, 16, 48, 2};
uint32_t ifm2sv_size_37 = 12288;
std::vector<access_pattern> ifm2_pattern_37[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_37 = {343552};
std::vector<uint32_t> wts_ddr_dim_37 = {343552};
std::vector<uint32_t> wtssv_dim_37 = {3904};
uint32_t wtssv_size_37 = 3904;
uint32_t wts_repetition_37 = 1;
std::vector<access_pattern> wts_pattern_37[] = {
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_37 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_37 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_37 = {8, 16, 128, 16};
std::vector<uint32_t> ofm_bound_37 = {8, 14, 128, 14};
std::vector<uint32_t> ofmsv_dim_37 = {8, 16, 12, 2};
uint32_t ofmsv_size_37 = 3072;
uint32_t ofm_repetition_37 = 8;
std::vector<access_pattern> ofm_pattern_37[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer38
std::vector<uint32_t> ifm_dim_38 = {8, 16, 128, 16};
std::vector<uint32_t> ifm_bound_38 = {8, 14, 128, 14};
std::vector<uint32_t> ifmsv_dim_38 = {8, 16, 8, 4};
uint32_t ifmsv_size_38 = 4096;
uint32_t kernel_iter_38 = 16;
std::vector<access_pattern> ifm_pattern_38[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
}};


std::vector<uint32_t> wts_dim_38 = {299008};
std::vector<uint32_t> wts_ddr_dim_38 = {299008};
std::vector<uint32_t> wtssv_dim_38 = {4672};
uint32_t wtssv_size_38 = 4672;
uint32_t wts_repetition_38 = 1;
std::vector<access_pattern> wts_pattern_38[] = {
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {74752}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {149504}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {224256}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_38 = tiling({.buffer_dimension = {299008}, .tiling_dimension = {299008}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_38 = tiling({.buffer_dimension = {299008}, .tiling_dimension = {299008}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_38 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_38 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_38 = {8, 16, 8, 4};
uint32_t ofmsv_size_38 = 4096;
uint32_t ofm_repetition_38 = 16;
std::vector<access_pattern> ofm_pattern_38[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer39
std::vector<uint32_t> ifm_dim_39 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_39 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_39 = {8, 20, 4, 6};
uint32_t ifmsv_size_39 = 3840;
uint32_t kernel_iter_39 = 32;
std::vector<access_pattern> ifm_pattern_39[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 11}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> wts_dim_39 = {614400};
std::vector<uint32_t> wts_ddr_dim_39 = {614400};
std::vector<uint32_t> wtssv_dim_39 = {4800};
uint32_t wtssv_size_39 = 4800;
uint32_t wts_repetition_39 = 1;
std::vector<access_pattern> wts_pattern_39[] = {
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_39 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_39 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_39 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_39 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_39 = {8, 16, 2, 4};
uint32_t ofmsv_size_39 = 1024;
uint32_t ofm_repetition_39 = 8;
std::vector<access_pattern> ofm_pattern_39[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer40
std::vector<uint32_t> ifm_dim_40 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_40 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_40 = {8, 16, 4, 2};
uint32_t ifmsv_size_40 = 1024;
uint32_t kernel_iter_40 = 48;
std::vector<access_pattern> ifm_pattern_40[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> ifm2_dim_40 = {8, 16, 128, 16};
std::vector<uint32_t> ifm2_bound_40 = {8, 14, 128, 14};
std::vector<uint32_t> ifm2sv_dim_40 = {8, 16, 48, 2};
uint32_t ifm2sv_size_40 = 12288;
std::vector<access_pattern> ifm2_pattern_40[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_40 = {343552};
std::vector<uint32_t> wts_ddr_dim_40 = {343552};
std::vector<uint32_t> wtssv_dim_40 = {3904};
uint32_t wtssv_size_40 = 3904;
uint32_t wts_repetition_40 = 1;
std::vector<access_pattern> wts_pattern_40[] = {
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_40 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_40 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_40 = {8, 16, 128, 16};
std::vector<uint32_t> ofm_bound_40 = {8, 14, 128, 14};
std::vector<uint32_t> ofmsv_dim_40 = {8, 16, 12, 2};
uint32_t ofmsv_size_40 = 3072;
uint32_t ofm_repetition_40 = 8;
std::vector<access_pattern> ofm_pattern_40[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer41
std::vector<uint32_t> ifm_dim_41 = {8, 16, 128, 16};
std::vector<uint32_t> ifm_bound_41 = {8, 14, 128, 14};
std::vector<uint32_t> ifmsv_dim_41 = {8, 16, 8, 4};
uint32_t ifmsv_size_41 = 4096;
uint32_t kernel_iter_41 = 16;
std::vector<access_pattern> ifm_pattern_41[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
}};


std::vector<uint32_t> wts_dim_41 = {299008};
std::vector<uint32_t> wts_ddr_dim_41 = {299008};
std::vector<uint32_t> wtssv_dim_41 = {4672};
uint32_t wtssv_size_41 = 4672;
uint32_t wts_repetition_41 = 1;
std::vector<access_pattern> wts_pattern_41[] = {
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {0}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {74752}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {149504}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {299008}, .tiling_dimension = {4672}, .offset = {224256}, .tile_traversal = { {.dimension = 0, .stride = 4672, .wrap = 16} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_41 = tiling({.buffer_dimension = {299008}, .tiling_dimension = {299008}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_41 = tiling({.buffer_dimension = {299008}, .tiling_dimension = {299008}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_41 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_41 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_41 = {8, 16, 8, 4};
uint32_t ofmsv_size_41 = 4096;
uint32_t ofm_repetition_41 = 16;
std::vector<access_pattern> ofm_pattern_41[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 1} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer42
std::vector<uint32_t> ifm_dim_42 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_42 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_42 = {8, 20, 4, 6};
uint32_t ifmsv_size_42 = 3840;
uint32_t kernel_iter_42 = 32;
std::vector<access_pattern> ifm_pattern_42[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 20, 4, 6}, .offset = {0, -1, 0, 11}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> wts_dim_42 = {614400};
std::vector<uint32_t> wts_ddr_dim_42 = {614400};
std::vector<uint32_t> wtssv_dim_42 = {4800};
uint32_t wtssv_size_42 = 4800;
uint32_t wts_repetition_42 = 1;
std::vector<access_pattern> wts_pattern_42[] = {
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {38400, 16}, .tiling_dimension = {38400, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_42 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_42 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_42 = {8, 16, 32, 16};
std::vector<uint32_t> ofm_bound_42 = {8, 14, 32, 14};
std::vector<uint32_t> ofmsv_dim_42 = {8, 16, 2, 4};
uint32_t ofmsv_size_42 = 1024;
uint32_t ofm_repetition_42 = 8;
std::vector<access_pattern> ofm_pattern_42[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 2, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 4, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 2, 4}, .offset = {0, 0, 6, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer43
std::vector<uint32_t> ifm_dim_43 = {8, 16, 32, 16};
std::vector<uint32_t> ifm_bound_43 = {8, 14, 32, 14};
std::vector<uint32_t> ifmsv_dim_43 = {8, 16, 4, 2};
uint32_t ifmsv_size_43 = 1024;
uint32_t kernel_iter_43 = 48;
std::vector<access_pattern> ifm_pattern_43[] = {
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}}),
  tiling({.buffer_dimension = {8, 16, 32, 16}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 8}, {.dimension = 1, .stride = 0, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 14, 32, 14}})
}};


std::vector<uint32_t> ifm2_dim_43 = {8, 16, 128, 16};
std::vector<uint32_t> ifm2_bound_43 = {8, 14, 128, 14};
std::vector<uint32_t> ifm2sv_dim_43 = {8, 16, 48, 2};
uint32_t ifm2sv_size_43 = 12288;
std::vector<access_pattern> ifm2_pattern_43[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 48, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_43 = {343552};
std::vector<uint32_t> wts_ddr_dim_43 = {343552};
std::vector<uint32_t> wtssv_dim_43 = {3904};
uint32_t wtssv_size_43 = 3904;
uint32_t wts_repetition_43 = 1;
std::vector<access_pattern> wts_pattern_43[] = {
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {28629, 12}, .tiling_dimension = {28629, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 3} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_43 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_43 = tiling({.buffer_dimension = {343552}, .tiling_dimension = {343552}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_43 = {8, 16, 128, 16};
std::vector<uint32_t> ofm_bound_43 = {8, 14, 128, 14};
std::vector<uint32_t> ofmsv_dim_43 = {8, 16, 12, 2};
uint32_t ofmsv_size_43 = 3072;
uint32_t ofm_repetition_43 = 8;
std::vector<access_pattern> ofm_pattern_43[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 0}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 8}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 2}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 10}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 4}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 12}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 6}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 12, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 24, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 12, 2}, .offset = {0, 0, 36, 14}, .tile_traversal = { {.dimension = 2, .stride = 48, .wrap = 3} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer44
std::vector<uint32_t> ifm_dim_44 = {8, 16, 128, 16};
std::vector<uint32_t> ifm_bound_44 = {8, 14, 128, 14};
std::vector<uint32_t> ifmsv_dim_44 = {8, 16, 8, 4};
uint32_t ifmsv_size_44 = 4096;
uint32_t kernel_iter_44 = 32;
std::vector<access_pattern> ifm_pattern_44[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
}};


std::vector<uint32_t> wts_dim_44 = {598016};
std::vector<uint32_t> wts_ddr_dim_44 = {598016};
std::vector<uint32_t> wtssv_dim_44 = {4672};
uint32_t wtssv_size_44 = 4672;
uint32_t wts_repetition_44 = 1;
std::vector<access_pattern> wts_pattern_44[] = {
{
  tiling({.buffer_dimension = {74752, 8}, .tiling_dimension = {74752, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {74752, 8}, .tiling_dimension = {74752, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {74752, 8}, .tiling_dimension = {74752, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {74752, 8}, .tiling_dimension = {74752, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_44 = tiling({.buffer_dimension = {598016}, .tiling_dimension = {598016}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_44 = tiling({.buffer_dimension = {598016}, .tiling_dimension = {598016}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_44 = {8, 16, 64, 16};
std::vector<uint32_t> ofm_bound_44 = {8, 14, 64, 14};
std::vector<uint32_t> ofmsv_dim_44 = {8, 16, 8, 4};
uint32_t ofmsv_size_44 = 4096;
uint32_t ofm_repetition_44 = 16;
std::vector<access_pattern> ofm_pattern_44[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 8}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 8, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 16, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 16, 8, 4}, .offset = {0, 0, 24, 12}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 2} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer45
std::vector<uint32_t> ifm_dim_45 = {8, 16, 64, 16};
std::vector<uint32_t> ifm_bound_45 = {8, 14, 64, 14};
std::vector<uint32_t> ifmsv_dim_45 = {8, 36, 2, 6};
uint32_t ifmsv_size_45 = 3456;
uint32_t kernel_iter_45 = 128;
std::vector<access_pattern> ifm_pattern_45[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 36, 2, 6}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 32} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 64, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 36, 2, 6}, .offset = {0, -1, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 32} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 64, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 36, 2, 6}, .offset = {0, -1, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 32} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 64, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 16}, .tiling_dimension = {8, 36, 2, 6}, .offset = {0, -1, 0, 11}, .tile_traversal = { {.dimension = 2, .stride = 2, .wrap = 32} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 14, 64, 14}})
}};


std::vector<uint32_t> wts_dim_45 = {630784};
std::vector<uint32_t> wts_ddr_dim_45 = {2523136};
std::vector<uint32_t> wtssv_dim_45 = {4928};
uint32_t wtssv_size_45 = 4928;
uint32_t wts_repetition_45 = 4;
std::vector<access_pattern> wts_pattern_45[] = {
{
  tiling({.buffer_dimension = {157696, 4}, .tiling_dimension = {157696, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {157696, 4}, .tiling_dimension = {157696, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {157696, 4}, .tiling_dimension = {157696, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {157696, 4}, .tiling_dimension = {157696, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 1} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_45 = tiling({.buffer_dimension = {2523136}, .tiling_dimension = {2523136}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_45 = tiling({.buffer_dimension = {630784}, .tiling_dimension = {630784}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_45 = {8, 16, 64, 8};
std::vector<uint32_t> ofm_bound_45 = {8, 7, 64, 7};
std::vector<uint32_t> ofmsv_dim_45 = {8, 16, 4, 2};
uint32_t ofmsv_size_45 = 1024;
uint32_t ofm_repetition_45 = 32;
std::vector<access_pattern> ofm_pattern_45[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer46
std::vector<uint32_t> ifm_dim_46 = {8, 16, 128, 16};
std::vector<uint32_t> ifm_bound_46 = {8, 14, 128, 14};
std::vector<uint32_t> ifmsv_dim_46 = {8, 32, 8, 2};
uint32_t ifmsv_size_46 = 4096;
uint32_t kernel_iter_46 = 256;
std::vector<access_pattern> ifm_pattern_46[] = {
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 14, 128, 14}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 8}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 14, 128, 14}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 10}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 14, 128, 14}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 12}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
},
{
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 14, 128, 14}}),
  tiling({.buffer_dimension = {8, 16, 128, 16}, .tiling_dimension = {8, 32, 8, 2}, .offset = {0, 0, 0, 14}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 14, 128, 14}})
}};


std::vector<uint32_t> wts_dim_46 = {598016};
std::vector<uint32_t> wts_ddr_dim_46 = {2392064};
std::vector<uint32_t> wtssv_dim_46 = {4672};
uint32_t wtssv_size_46 = 4672;
uint32_t wts_repetition_46 = 4;
std::vector<access_pattern> wts_pattern_46[] = {
{
  tiling({.buffer_dimension = {74752, 8}, .tiling_dimension = {74752, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {74752, 8}, .tiling_dimension = {74752, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {74752, 8}, .tiling_dimension = {74752, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {74752, 8}, .tiling_dimension = {74752, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 2, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_46 = tiling({.buffer_dimension = {2392064}, .tiling_dimension = {2392064}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_46 = tiling({.buffer_dimension = {598016}, .tiling_dimension = {598016}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_46 = {8, 16, 256, 8};
std::vector<uint32_t> ofm_bound_46 = {8, 7, 256, 7};
std::vector<uint32_t> ofmsv_dim_46 = {8, 16, 8, 1};
uint32_t ofmsv_size_46 = 1024;
uint32_t ofm_repetition_46 = 16;
std::vector<access_pattern> ofm_pattern_46[] = {
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 1}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 1}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 1}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 5}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 5}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 5}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 5}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 3}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 3}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 3}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 0, 7}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 8, 7}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 16, 7}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 1}, .offset = {0, 0, 24, 7}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer47
std::vector<uint32_t> ifm_dim_47 = {8, 16, 64, 8};
std::vector<uint32_t> ifm_bound_47 = {8, 7, 64, 7};
std::vector<uint32_t> ifmsv_dim_47 = {8, 16, 4, 2};
uint32_t ifmsv_size_47 = 1024;
uint32_t kernel_iter_47 = 128;
std::vector<access_pattern> ifm_pattern_47[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
}};


std::vector<uint32_t> ifm2_dim_47 = {8, 16, 256, 8};
std::vector<uint32_t> ifm2_bound_47 = {8, 7, 256, 7};
std::vector<uint32_t> ifm2sv_dim_47 = {8, 16, 32, 2};
uint32_t ifm2sv_size_47 = 8192;
std::vector<access_pattern> ifm2_pattern_47[] = {
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_47 = {671744};
std::vector<uint32_t> wts_ddr_dim_47 = {1343488};
std::vector<uint32_t> wtssv_dim_47 = {2624};
uint32_t wtssv_size_47 = 2624;
uint32_t wts_repetition_47 = 2;
std::vector<access_pattern> wts_pattern_47[] = {
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_47 = tiling({.buffer_dimension = {1343488}, .tiling_dimension = {1343488}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_47 = tiling({.buffer_dimension = {671744}, .tiling_dimension = {671744}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_47 = {8, 16, 256, 8};
std::vector<uint32_t> ofm_bound_47 = {8, 7, 256, 7};
std::vector<uint32_t> ofmsv_dim_47 = {8, 16, 8, 2};
uint32_t ofmsv_size_47 = 2048;
uint32_t ofm_repetition_47 = 16;
std::vector<access_pattern> ofm_pattern_47[] = {
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer48
std::vector<uint32_t> ifm_dim_48 = {8, 16, 256, 8};
std::vector<uint32_t> ifm_bound_48 = {8, 7, 256, 7};
std::vector<uint32_t> ifmsv_dim_48 = {8, 16, 16, 2};
uint32_t ifmsv_size_48 = 4096;
uint32_t kernel_iter_48 = 64;
std::vector<access_pattern> ifm_pattern_48[] = {
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 16, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 16} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 7, 256, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 16, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 16} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 7, 256, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 16, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 16} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 7, 256, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 16, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 16} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 7, 256, 7}})
}};


std::vector<uint32_t> wts_dim_48 = {565248};
std::vector<uint32_t> wts_ddr_dim_48 = {1130496};
std::vector<uint32_t> wtssv_dim_48 = {4416};
uint32_t wtssv_size_48 = 4416;
uint32_t wts_repetition_48 = 2;
std::vector<access_pattern> wts_pattern_48[] = {
{
  tiling({.buffer_dimension = {70656, 8}, .tiling_dimension = {70656, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656, 8}, .tiling_dimension = {70656, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656, 8}, .tiling_dimension = {70656, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656, 8}, .tiling_dimension = {70656, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_48 = tiling({.buffer_dimension = {1130496}, .tiling_dimension = {1130496}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_48 = tiling({.buffer_dimension = {565248}, .tiling_dimension = {565248}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_48 = {8, 16, 64, 8};
std::vector<uint32_t> ofm_bound_48 = {8, 7, 64, 7};
std::vector<uint32_t> ofmsv_dim_48 = {8, 16, 4, 2};
uint32_t ofmsv_size_48 = 1024;
uint32_t ofm_repetition_48 = 16;
std::vector<access_pattern> ofm_pattern_48[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer49
std::vector<uint32_t> ifm_dim_49 = {8, 16, 64, 8};
std::vector<uint32_t> ifm_bound_49 = {8, 7, 64, 7};
std::vector<uint32_t> ifmsv_dim_49 = {8, 20, 4, 4};
uint32_t ifmsv_size_49 = 2560;
uint32_t kernel_iter_49 = 128;
std::vector<access_pattern> ifm_pattern_49[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 20, 4, 4}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 20, 4, 4}, .offset = {0, -1, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 20, 4, 4}, .offset = {0, -1, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 20, 4, 4}, .offset = {0, -1, 0, 5}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
}};


std::vector<uint32_t> wts_dim_49 = {614400};
std::vector<uint32_t> wts_ddr_dim_49 = {2457600};
std::vector<uint32_t> wtssv_dim_49 = {4800};
uint32_t wtssv_size_49 = 4800;
uint32_t wts_repetition_49 = 4;
std::vector<access_pattern> wts_pattern_49[] = {
{
  tiling({.buffer_dimension = {76800, 8}, .tiling_dimension = {76800, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {76800, 8}, .tiling_dimension = {76800, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {76800, 8}, .tiling_dimension = {76800, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {76800, 8}, .tiling_dimension = {76800, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_49 = tiling({.buffer_dimension = {2457600}, .tiling_dimension = {2457600}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_49 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_49 = {8, 16, 64, 8};
std::vector<uint32_t> ofm_bound_49 = {8, 7, 64, 7};
std::vector<uint32_t> ofmsv_dim_49 = {8, 16, 2, 2};
uint32_t ofmsv_size_49 = 512;
uint32_t ofm_repetition_49 = 16;
std::vector<access_pattern> ofm_pattern_49[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 2, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 6, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 2, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 6, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 2, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 4, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 6, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer50
std::vector<uint32_t> ifm_dim_50 = {8, 16, 64, 8};
std::vector<uint32_t> ifm_bound_50 = {8, 7, 64, 7};
std::vector<uint32_t> ifmsv_dim_50 = {8, 16, 4, 2};
uint32_t ifmsv_size_50 = 1024;
uint32_t kernel_iter_50 = 128;
std::vector<access_pattern> ifm_pattern_50[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
}};


std::vector<uint32_t> ifm2_dim_50 = {8, 16, 256, 8};
std::vector<uint32_t> ifm2_bound_50 = {8, 7, 256, 7};
std::vector<uint32_t> ifm2sv_dim_50 = {8, 16, 32, 2};
uint32_t ifm2sv_size_50 = 8192;
std::vector<access_pattern> ifm2_pattern_50[] = {
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_50 = {671744};
std::vector<uint32_t> wts_ddr_dim_50 = {1343488};
std::vector<uint32_t> wtssv_dim_50 = {2624};
uint32_t wtssv_size_50 = 2624;
uint32_t wts_repetition_50 = 2;
std::vector<access_pattern> wts_pattern_50[] = {
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_50 = tiling({.buffer_dimension = {1343488}, .tiling_dimension = {1343488}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_50 = tiling({.buffer_dimension = {671744}, .tiling_dimension = {671744}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_50 = {8, 16, 256, 8};
std::vector<uint32_t> ofm_bound_50 = {8, 7, 256, 7};
std::vector<uint32_t> ofmsv_dim_50 = {8, 16, 8, 2};
uint32_t ofmsv_size_50 = 2048;
uint32_t ofm_repetition_50 = 16;
std::vector<access_pattern> ofm_pattern_50[] = {
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer51
std::vector<uint32_t> ifm_dim_51 = {8, 16, 256, 8};
std::vector<uint32_t> ifm_bound_51 = {8, 7, 256, 7};
std::vector<uint32_t> ifmsv_dim_51 = {8, 16, 16, 2};
uint32_t ifmsv_size_51 = 4096;
uint32_t kernel_iter_51 = 64;
std::vector<access_pattern> ifm_pattern_51[] = {
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 16, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 16} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 7, 256, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 16, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 16} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 7, 256, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 16, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 16} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 7, 256, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 16, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 16} }, .packet_port_id = -1, .repetition = 4, .phase = 0, .boundary_dimension = {8, 7, 256, 7}})
}};


std::vector<uint32_t> wts_dim_51 = {565248};
std::vector<uint32_t> wts_ddr_dim_51 = {1130496};
std::vector<uint32_t> wtssv_dim_51 = {4416};
uint32_t wtssv_size_51 = 4416;
uint32_t wts_repetition_51 = 2;
std::vector<access_pattern> wts_pattern_51[] = {
{
  tiling({.buffer_dimension = {70656, 8}, .tiling_dimension = {70656, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656, 8}, .tiling_dimension = {70656, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656, 8}, .tiling_dimension = {70656, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {70656, 8}, .tiling_dimension = {70656, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_51 = tiling({.buffer_dimension = {1130496}, .tiling_dimension = {1130496}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_51 = tiling({.buffer_dimension = {565248}, .tiling_dimension = {565248}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_51 = {8, 16, 64, 8};
std::vector<uint32_t> ofm_bound_51 = {8, 7, 64, 7};
std::vector<uint32_t> ofmsv_dim_51 = {8, 16, 4, 2};
uint32_t ofmsv_size_51 = 1024;
uint32_t ofm_repetition_51 = 16;
std::vector<access_pattern> ofm_pattern_51[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 0}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 2}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 4}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 4, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 8, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 12, 6}, .tile_traversal = { {.dimension = 2, .stride = 16, .wrap = 4} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer52
std::vector<uint32_t> ifm_dim_52 = {8, 16, 64, 8};
std::vector<uint32_t> ifm_bound_52 = {8, 7, 64, 7};
std::vector<uint32_t> ifmsv_dim_52 = {8, 20, 4, 4};
uint32_t ifmsv_size_52 = 2560;
uint32_t kernel_iter_52 = 128;
std::vector<access_pattern> ifm_pattern_52[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 20, 4, 4}, .offset = {0, -1, 0, -1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 20, 4, 4}, .offset = {0, -1, 0, 1}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 20, 4, 4}, .offset = {0, -1, 0, 3}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 20, 4, 4}, .offset = {0, -1, 0, 5}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16} }, .packet_port_id = -1, .repetition = 8, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
}};


std::vector<uint32_t> wts_dim_52 = {614400};
std::vector<uint32_t> wts_ddr_dim_52 = {2457600};
std::vector<uint32_t> wtssv_dim_52 = {4800};
uint32_t wtssv_size_52 = 4800;
uint32_t wts_repetition_52 = 4;
std::vector<access_pattern> wts_pattern_52[] = {
{
  tiling({.buffer_dimension = {76800, 8}, .tiling_dimension = {76800, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {76800, 8}, .tiling_dimension = {76800, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {76800, 8}, .tiling_dimension = {76800, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {76800, 8}, .tiling_dimension = {76800, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 2} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_52 = tiling({.buffer_dimension = {2457600}, .tiling_dimension = {2457600}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_52 = tiling({.buffer_dimension = {614400}, .tiling_dimension = {614400}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_52 = {8, 16, 64, 8};
std::vector<uint32_t> ofm_bound_52 = {8, 7, 64, 7};
std::vector<uint32_t> ofmsv_dim_52 = {8, 16, 2, 2};
uint32_t ofmsv_size_52 = 512;
uint32_t ofm_repetition_52 = 16;
std::vector<access_pattern> ofm_pattern_52[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 2, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 4, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 6, 0}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 2, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 4, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 6, 2}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 2, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 4, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 6, 4}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 2, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 4, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 2, 2}, .offset = {0, 0, 6, 6}, .tile_traversal = { {.dimension = 2, .stride = 8, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


//Layer53
std::vector<uint32_t> ifm_dim_53 = {8, 16, 64, 8};
std::vector<uint32_t> ifm_bound_53 = {8, 7, 64, 7};
std::vector<uint32_t> ifmsv_dim_53 = {8, 16, 4, 2};
uint32_t ifmsv_size_53 = 1024;
uint32_t kernel_iter_53 = 128;
std::vector<access_pattern> ifm_pattern_53[] = {
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
},
{
  tiling({.buffer_dimension = {8, 16, 64, 8}, .tiling_dimension = {8, 16, 4, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 4, .wrap = 16}, {.dimension = 1, .stride = 0, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {8, 7, 64, 7}})
}};


std::vector<uint32_t> ifm2_dim_53 = {8, 16, 256, 8};
std::vector<uint32_t> ifm2_bound_53 = {8, 7, 256, 7};
std::vector<uint32_t> ifm2sv_dim_53 = {8, 16, 32, 2};
uint32_t ifm2sv_size_53 = 8192;
std::vector<access_pattern> ifm2_pattern_53[] = {
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 32, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};


std::vector<uint32_t> wts_dim_53 = {671744};
std::vector<uint32_t> wts_ddr_dim_53 = {1343488};
std::vector<uint32_t> wtssv_dim_53 = {2624};
uint32_t wtssv_size_53 = 2624;
uint32_t wts_repetition_53 = 2;
std::vector<access_pattern> wts_pattern_53[] = {
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 0}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 1}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 2}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {41984, 16}, .tiling_dimension = {41984, 1}, .offset = {0, 3}, .tile_traversal = { {.dimension = 1, .stride = 4, .wrap = 4} }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

access_pattern wts_ddr_read_pattern_53 = tiling({.buffer_dimension = {1343488}, .tiling_dimension = {1343488}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});
access_pattern wts_ddr_write_pattern_53 = tiling({.buffer_dimension = {671744}, .tiling_dimension = {671744}, .offset = {0}, .tile_traversal = { }, .packet_port_id = -1, .repetition = 1, .phase = 0, .boundary_dimension = {}});


std::vector<uint32_t> ofm_dim_53 = {8, 16, 256, 8};
std::vector<uint32_t> ofm_bound_53 = {8, 7, 256, 7};
std::vector<uint32_t> ofmsv_dim_53 = {8, 16, 8, 2};
uint32_t ofmsv_size_53 = 2048;
uint32_t ofm_repetition_53 = 16;
std::vector<access_pattern> ofm_pattern_53[] = {
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 0}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 2}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 4}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
},
{
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 0, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 0, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 8, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 1, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 16, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 2, .repetition = 1, .phase = 0, .boundary_dimension = {}}),
  tiling({.buffer_dimension = {8, 16, 256, 8}, .tiling_dimension = {8, 16, 8, 2}, .offset = {0, 0, 24, 6}, .tile_traversal = { {.dimension = 2, .stride = 32, .wrap = 8} }, .packet_port_id = 3, .repetition = 1, .phase = 0, .boundary_dimension = {}})
}};

