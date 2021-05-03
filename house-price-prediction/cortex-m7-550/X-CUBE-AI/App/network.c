/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Mon May  3 13:55:14 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



/*
#define AI_TOOLS_VERSION_MAJOR 6
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0
#define AI_TOOLS_VERSION_EXTRA "RC6"

*/

/*
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 4
#define AI_TOOLS_API_VERSION_MICRO 0
*/

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "2898a30cc251382a106a23233abbb204"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Mon May  3 13:55:14 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array input_0_output_array;   /* Array #0 */
AI_STATIC ai_array dense_73_output_array;   /* Array #1 */
AI_STATIC ai_array dense_73_nl_output_array;   /* Array #2 */
AI_STATIC ai_array dense_74_output_array;   /* Array #3 */
AI_STATIC ai_array dense_74_nl_output_array;   /* Array #4 */
AI_STATIC ai_array dense_75_output_array;   /* Array #5 */
AI_STATIC ai_array dense_75_nl_output_array;   /* Array #6 */
AI_STATIC ai_array dense_76_output_array;   /* Array #7 */
AI_STATIC ai_array dense_76_nl_output_array;   /* Array #8 */
AI_STATIC ai_array dense_77_output_array;   /* Array #9 */
AI_STATIC ai_array dense_77_nl_output_array;   /* Array #10 */
AI_STATIC ai_array dense_78_output_array;   /* Array #11 */
AI_STATIC ai_array dense_78_nl_output_array;   /* Array #12 */
AI_STATIC ai_array dense_79_output_array;   /* Array #13 */
AI_STATIC ai_array dense_79_nl_output_array;   /* Array #14 */
AI_STATIC ai_array dense_80_output_array;   /* Array #15 */
AI_STATIC ai_array dense_80_nl_output_array;   /* Array #16 */
AI_STATIC ai_array dense_81_output_array;   /* Array #17 */
AI_STATIC ai_array dense_81_nl_output_array;   /* Array #18 */
AI_STATIC ai_array dense_82_output_array;   /* Array #19 */
AI_STATIC ai_array dense_82_nl_output_array;   /* Array #20 */
AI_STATIC ai_array dense_83_output_array;   /* Array #21 */
AI_STATIC ai_array dense_83_nl_output_array;   /* Array #22 */
AI_STATIC ai_array dense_73_weights_array;   /* Array #23 */
AI_STATIC ai_array dense_73_bias_array;   /* Array #24 */
AI_STATIC ai_array dense_74_weights_array;   /* Array #25 */
AI_STATIC ai_array dense_74_bias_array;   /* Array #26 */
AI_STATIC ai_array dense_75_weights_array;   /* Array #27 */
AI_STATIC ai_array dense_75_bias_array;   /* Array #28 */
AI_STATIC ai_array dense_76_weights_array;   /* Array #29 */
AI_STATIC ai_array dense_76_bias_array;   /* Array #30 */
AI_STATIC ai_array dense_77_weights_array;   /* Array #31 */
AI_STATIC ai_array dense_77_bias_array;   /* Array #32 */
AI_STATIC ai_array dense_78_weights_array;   /* Array #33 */
AI_STATIC ai_array dense_78_bias_array;   /* Array #34 */
AI_STATIC ai_array dense_79_weights_array;   /* Array #35 */
AI_STATIC ai_array dense_79_bias_array;   /* Array #36 */
AI_STATIC ai_array dense_80_weights_array;   /* Array #37 */
AI_STATIC ai_array dense_80_bias_array;   /* Array #38 */
AI_STATIC ai_array dense_81_weights_array;   /* Array #39 */
AI_STATIC ai_array dense_81_bias_array;   /* Array #40 */
AI_STATIC ai_array dense_82_weights_array;   /* Array #41 */
AI_STATIC ai_array dense_82_bias_array;   /* Array #42 */
AI_STATIC ai_array dense_83_weights_array;   /* Array #43 */
AI_STATIC ai_array dense_83_bias_array;   /* Array #44 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor input_0_output;   /* Tensor #0 */
AI_STATIC ai_tensor dense_73_output;   /* Tensor #1 */
AI_STATIC ai_tensor dense_73_nl_output;   /* Tensor #2 */
AI_STATIC ai_tensor dense_74_output;   /* Tensor #3 */
AI_STATIC ai_tensor dense_74_nl_output;   /* Tensor #4 */
AI_STATIC ai_tensor dense_75_output;   /* Tensor #5 */
AI_STATIC ai_tensor dense_75_nl_output;   /* Tensor #6 */
AI_STATIC ai_tensor dense_76_output;   /* Tensor #7 */
AI_STATIC ai_tensor dense_76_nl_output;   /* Tensor #8 */
AI_STATIC ai_tensor dense_77_output;   /* Tensor #9 */
AI_STATIC ai_tensor dense_77_nl_output;   /* Tensor #10 */
AI_STATIC ai_tensor dense_78_output;   /* Tensor #11 */
AI_STATIC ai_tensor dense_78_nl_output;   /* Tensor #12 */
AI_STATIC ai_tensor dense_79_output;   /* Tensor #13 */
AI_STATIC ai_tensor dense_79_nl_output;   /* Tensor #14 */
AI_STATIC ai_tensor dense_80_output;   /* Tensor #15 */
AI_STATIC ai_tensor dense_80_nl_output;   /* Tensor #16 */
AI_STATIC ai_tensor dense_81_output;   /* Tensor #17 */
AI_STATIC ai_tensor dense_81_nl_output;   /* Tensor #18 */
AI_STATIC ai_tensor dense_82_output;   /* Tensor #19 */
AI_STATIC ai_tensor dense_82_nl_output;   /* Tensor #20 */
AI_STATIC ai_tensor dense_83_output;   /* Tensor #21 */
AI_STATIC ai_tensor dense_83_nl_output;   /* Tensor #22 */
AI_STATIC ai_tensor dense_73_weights;   /* Tensor #23 */
AI_STATIC ai_tensor dense_73_bias;   /* Tensor #24 */
AI_STATIC ai_tensor dense_74_weights;   /* Tensor #25 */
AI_STATIC ai_tensor dense_74_bias;   /* Tensor #26 */
AI_STATIC ai_tensor dense_75_weights;   /* Tensor #27 */
AI_STATIC ai_tensor dense_75_bias;   /* Tensor #28 */
AI_STATIC ai_tensor dense_76_weights;   /* Tensor #29 */
AI_STATIC ai_tensor dense_76_bias;   /* Tensor #30 */
AI_STATIC ai_tensor dense_77_weights;   /* Tensor #31 */
AI_STATIC ai_tensor dense_77_bias;   /* Tensor #32 */
AI_STATIC ai_tensor dense_78_weights;   /* Tensor #33 */
AI_STATIC ai_tensor dense_78_bias;   /* Tensor #34 */
AI_STATIC ai_tensor dense_79_weights;   /* Tensor #35 */
AI_STATIC ai_tensor dense_79_bias;   /* Tensor #36 */
AI_STATIC ai_tensor dense_80_weights;   /* Tensor #37 */
AI_STATIC ai_tensor dense_80_bias;   /* Tensor #38 */
AI_STATIC ai_tensor dense_81_weights;   /* Tensor #39 */
AI_STATIC ai_tensor dense_81_bias;   /* Tensor #40 */
AI_STATIC ai_tensor dense_82_weights;   /* Tensor #41 */
AI_STATIC ai_tensor dense_82_bias;   /* Tensor #42 */
AI_STATIC ai_tensor dense_83_weights;   /* Tensor #43 */
AI_STATIC ai_tensor dense_83_bias;   /* Tensor #44 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain dense_73_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain dense_73_nl_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain dense_74_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain dense_74_nl_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain dense_75_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain dense_75_nl_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain dense_76_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain dense_76_nl_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain dense_77_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain dense_77_nl_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain dense_78_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain dense_78_nl_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain dense_79_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain dense_79_nl_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain dense_80_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain dense_80_nl_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain dense_81_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain dense_81_nl_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain dense_82_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain dense_82_nl_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain dense_83_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain dense_83_nl_chain;   /* Chain #21 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_dense dense_73_layer; /* Layer #0 */
AI_STATIC ai_layer_nl dense_73_nl_layer; /* Layer #1 */
AI_STATIC ai_layer_dense dense_74_layer; /* Layer #2 */
AI_STATIC ai_layer_nl dense_74_nl_layer; /* Layer #3 */
AI_STATIC ai_layer_dense dense_75_layer; /* Layer #4 */
AI_STATIC ai_layer_nl dense_75_nl_layer; /* Layer #5 */
AI_STATIC ai_layer_dense dense_76_layer; /* Layer #6 */
AI_STATIC ai_layer_nl dense_76_nl_layer; /* Layer #7 */
AI_STATIC ai_layer_dense dense_77_layer; /* Layer #8 */
AI_STATIC ai_layer_nl dense_77_nl_layer; /* Layer #9 */
AI_STATIC ai_layer_dense dense_78_layer; /* Layer #10 */
AI_STATIC ai_layer_nl dense_78_nl_layer; /* Layer #11 */
AI_STATIC ai_layer_dense dense_79_layer; /* Layer #12 */
AI_STATIC ai_layer_nl dense_79_nl_layer; /* Layer #13 */
AI_STATIC ai_layer_dense dense_80_layer; /* Layer #14 */
AI_STATIC ai_layer_nl dense_80_nl_layer; /* Layer #15 */
AI_STATIC ai_layer_dense dense_81_layer; /* Layer #16 */
AI_STATIC ai_layer_nl dense_81_nl_layer; /* Layer #17 */
AI_STATIC ai_layer_dense dense_82_layer; /* Layer #18 */
AI_STATIC ai_layer_nl dense_82_nl_layer; /* Layer #19 */
AI_STATIC ai_layer_dense dense_83_layer; /* Layer #20 */
AI_STATIC ai_layer_nl dense_83_nl_layer; /* Layer #21 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 19, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  dense_73_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  dense_73_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  dense_74_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  dense_74_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  dense_75_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 38, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  dense_75_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 38, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  dense_76_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 38, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  dense_76_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 38, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  dense_77_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 38, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  dense_77_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 38, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  dense_78_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  dense_78_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  dense_79_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  dense_79_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  dense_80_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  dense_80_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  dense_81_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  dense_81_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  dense_82_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  dense_82_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  dense_83_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  dense_83_nl_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  dense_73_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 361, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  dense_73_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  dense_74_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 361, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  dense_74_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  dense_75_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 722, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  dense_75_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 38, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  dense_76_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1444, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  dense_76_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 38, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  dense_77_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1444, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  dense_77_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 38, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  dense_78_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 722, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  dense_78_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  dense_79_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 361, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  dense_79_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  dense_80_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 361, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  dense_80_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  dense_81_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 361, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  dense_81_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 19, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  dense_82_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 152, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  dense_82_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  dense_83_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  dense_83_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &input_0_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  dense_73_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_73_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  dense_73_nl_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_73_nl_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  dense_74_output, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_74_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  dense_74_nl_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_74_nl_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  dense_75_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 38, 1, 1), AI_STRIDE_INIT(4, 4, 4, 152, 152),
  1, &dense_75_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  dense_75_nl_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 38, 1, 1), AI_STRIDE_INIT(4, 4, 4, 152, 152),
  1, &dense_75_nl_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  dense_76_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 38, 1, 1), AI_STRIDE_INIT(4, 4, 4, 152, 152),
  1, &dense_76_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  dense_76_nl_output, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 38, 1, 1), AI_STRIDE_INIT(4, 4, 4, 152, 152),
  1, &dense_76_nl_output_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  dense_77_output, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 38, 1, 1), AI_STRIDE_INIT(4, 4, 4, 152, 152),
  1, &dense_77_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  dense_77_nl_output, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 38, 1, 1), AI_STRIDE_INIT(4, 4, 4, 152, 152),
  1, &dense_77_nl_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  dense_78_output, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_78_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  dense_78_nl_output, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_78_nl_output_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  dense_79_output, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_79_output_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  dense_79_nl_output, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_79_nl_output_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  dense_80_output, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_80_output_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  dense_80_nl_output, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_80_nl_output_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  dense_81_output, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_81_output_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  dense_81_nl_output, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_81_nl_output_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  dense_82_output, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &dense_82_output_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  dense_82_nl_output, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &dense_82_nl_output_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  dense_83_output, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &dense_83_output_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  dense_83_nl_output, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &dense_83_nl_output_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  dense_73_weights, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 19, 19, 1, 1), AI_STRIDE_INIT(4, 4, 76, 1444, 1444),
  1, &dense_73_weights_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  dense_73_bias, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_73_bias_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  dense_74_weights, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 19, 19, 1, 1), AI_STRIDE_INIT(4, 4, 76, 1444, 1444),
  1, &dense_74_weights_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  dense_74_bias, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_74_bias_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  dense_75_weights, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 19, 38, 1, 1), AI_STRIDE_INIT(4, 4, 76, 2888, 2888),
  1, &dense_75_weights_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  dense_75_bias, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 38, 1, 1), AI_STRIDE_INIT(4, 4, 4, 152, 152),
  1, &dense_75_bias_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  dense_76_weights, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 38, 38, 1, 1), AI_STRIDE_INIT(4, 4, 152, 5776, 5776),
  1, &dense_76_weights_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  dense_76_bias, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 38, 1, 1), AI_STRIDE_INIT(4, 4, 4, 152, 152),
  1, &dense_76_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  dense_77_weights, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 38, 38, 1, 1), AI_STRIDE_INIT(4, 4, 152, 5776, 5776),
  1, &dense_77_weights_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  dense_77_bias, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 38, 1, 1), AI_STRIDE_INIT(4, 4, 4, 152, 152),
  1, &dense_77_bias_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  dense_78_weights, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 38, 19, 1, 1), AI_STRIDE_INIT(4, 4, 152, 2888, 2888),
  1, &dense_78_weights_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  dense_78_bias, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_78_bias_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  dense_79_weights, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 19, 19, 1, 1), AI_STRIDE_INIT(4, 4, 76, 1444, 1444),
  1, &dense_79_weights_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  dense_79_bias, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_79_bias_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  dense_80_weights, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 19, 19, 1, 1), AI_STRIDE_INIT(4, 4, 76, 1444, 1444),
  1, &dense_80_weights_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  dense_80_bias, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_80_bias_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  dense_81_weights, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 19, 19, 1, 1), AI_STRIDE_INIT(4, 4, 76, 1444, 1444),
  1, &dense_81_weights_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  dense_81_bias, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 19, 1, 1), AI_STRIDE_INIT(4, 4, 4, 76, 76),
  1, &dense_81_bias_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  dense_82_weights, AI_STATIC,
  41, 0x0,
  AI_SHAPE_INIT(4, 19, 8, 1, 1), AI_STRIDE_INIT(4, 4, 76, 608, 608),
  1, &dense_82_weights_array, NULL)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  dense_82_bias, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &dense_82_bias_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  dense_83_weights, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 1), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &dense_83_weights_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  dense_83_bias, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &dense_83_bias_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_73_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_73_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_73_weights, &dense_73_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_73_layer, 0,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_73_chain,
  &AI_NET_OBJ_INSTANCE, &dense_73_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_73_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_73_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_73_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_73_nl_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_73_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_74_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_74_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_73_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_74_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_74_weights, &dense_74_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_74_layer, 1,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_74_chain,
  &AI_NET_OBJ_INSTANCE, &dense_74_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_74_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_74_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_74_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_74_nl_layer, 1,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_74_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_75_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_75_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_74_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_75_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_75_weights, &dense_75_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_75_layer, 2,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_75_chain,
  &AI_NET_OBJ_INSTANCE, &dense_75_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_75_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_75_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_75_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_75_nl_layer, 2,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_75_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_76_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_76_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_75_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_76_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_76_weights, &dense_76_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_76_layer, 3,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_76_chain,
  &AI_NET_OBJ_INSTANCE, &dense_76_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_76_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_76_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_76_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_76_nl_layer, 3,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_76_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_77_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_77_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_76_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_77_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_77_weights, &dense_77_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_77_layer, 4,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_77_chain,
  &AI_NET_OBJ_INSTANCE, &dense_77_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_77_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_77_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_77_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_77_nl_layer, 4,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_77_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_78_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_78_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_77_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_78_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_78_weights, &dense_78_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_78_layer, 5,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_78_chain,
  &AI_NET_OBJ_INSTANCE, &dense_78_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_78_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_78_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_78_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_78_nl_layer, 5,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_78_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_79_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_79_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_78_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_79_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_79_weights, &dense_79_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_79_layer, 6,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_79_chain,
  &AI_NET_OBJ_INSTANCE, &dense_79_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_79_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_79_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_79_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_79_nl_layer, 6,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_79_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_80_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_80_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_79_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_80_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_80_weights, &dense_80_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_80_layer, 7,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_80_chain,
  &AI_NET_OBJ_INSTANCE, &dense_80_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_80_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_80_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_80_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_80_nl_layer, 7,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_80_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_81_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_81_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_80_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_81_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_81_weights, &dense_81_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_81_layer, 8,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_81_chain,
  &AI_NET_OBJ_INSTANCE, &dense_81_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_81_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_81_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_81_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_81_nl_layer, 8,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_81_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_82_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_82_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_81_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_82_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_82_weights, &dense_82_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_82_layer, 9,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_82_chain,
  &AI_NET_OBJ_INSTANCE, &dense_82_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_82_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_82_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_82_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_82_nl_layer, 9,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_82_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_83_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_83_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_82_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_83_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_83_weights, &dense_83_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_83_layer, 10,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_83_chain,
  &AI_NET_OBJ_INSTANCE, &dense_83_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_83_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_83_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_83_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_83_nl_layer, 10,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_83_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_83_nl_layer, AI_STATIC, 
  .nl_params = NULL, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 26136, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 304, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &dense_83_nl_output),
  &dense_73_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    input_0_output_array.data = AI_PTR(NULL);
    input_0_output_array.data_start = AI_PTR(NULL);
    dense_73_output_array.data = AI_PTR(activations + 76);
    dense_73_output_array.data_start = AI_PTR(activations + 76);
    dense_73_nl_output_array.data = AI_PTR(activations + 76);
    dense_73_nl_output_array.data_start = AI_PTR(activations + 76);
    dense_74_output_array.data = AI_PTR(activations + 152);
    dense_74_output_array.data_start = AI_PTR(activations + 152);
    dense_74_nl_output_array.data = AI_PTR(activations + 76);
    dense_74_nl_output_array.data_start = AI_PTR(activations + 76);
    dense_75_output_array.data = AI_PTR(activations + 152);
    dense_75_output_array.data_start = AI_PTR(activations + 152);
    dense_75_nl_output_array.data = AI_PTR(activations + 152);
    dense_75_nl_output_array.data_start = AI_PTR(activations + 152);
    dense_76_output_array.data = AI_PTR(activations + 0);
    dense_76_output_array.data_start = AI_PTR(activations + 0);
    dense_76_nl_output_array.data = AI_PTR(activations + 152);
    dense_76_nl_output_array.data_start = AI_PTR(activations + 152);
    dense_77_output_array.data = AI_PTR(activations + 0);
    dense_77_output_array.data_start = AI_PTR(activations + 0);
    dense_77_nl_output_array.data = AI_PTR(activations + 152);
    dense_77_nl_output_array.data_start = AI_PTR(activations + 152);
    dense_78_output_array.data = AI_PTR(activations + 0);
    dense_78_output_array.data_start = AI_PTR(activations + 0);
    dense_78_nl_output_array.data = AI_PTR(activations + 76);
    dense_78_nl_output_array.data_start = AI_PTR(activations + 76);
    dense_79_output_array.data = AI_PTR(activations + 0);
    dense_79_output_array.data_start = AI_PTR(activations + 0);
    dense_79_nl_output_array.data = AI_PTR(activations + 76);
    dense_79_nl_output_array.data_start = AI_PTR(activations + 76);
    dense_80_output_array.data = AI_PTR(activations + 0);
    dense_80_output_array.data_start = AI_PTR(activations + 0);
    dense_80_nl_output_array.data = AI_PTR(activations + 76);
    dense_80_nl_output_array.data_start = AI_PTR(activations + 76);
    dense_81_output_array.data = AI_PTR(activations + 0);
    dense_81_output_array.data_start = AI_PTR(activations + 0);
    dense_81_nl_output_array.data = AI_PTR(activations + 76);
    dense_81_nl_output_array.data_start = AI_PTR(activations + 76);
    dense_82_output_array.data = AI_PTR(activations + 0);
    dense_82_output_array.data_start = AI_PTR(activations + 0);
    dense_82_nl_output_array.data = AI_PTR(activations + 32);
    dense_82_nl_output_array.data_start = AI_PTR(activations + 32);
    dense_83_output_array.data = AI_PTR(activations + 0);
    dense_83_output_array.data_start = AI_PTR(activations + 0);
    dense_83_nl_output_array.data = AI_PTR(NULL);
    dense_83_nl_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_73_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_73_weights_array.data = AI_PTR(weights + 0);
    dense_73_weights_array.data_start = AI_PTR(weights + 0);
    dense_73_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_73_bias_array.data = AI_PTR(weights + 1444);
    dense_73_bias_array.data_start = AI_PTR(weights + 1444);
    dense_74_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_74_weights_array.data = AI_PTR(weights + 1520);
    dense_74_weights_array.data_start = AI_PTR(weights + 1520);
    dense_74_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_74_bias_array.data = AI_PTR(weights + 2964);
    dense_74_bias_array.data_start = AI_PTR(weights + 2964);
    dense_75_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_75_weights_array.data = AI_PTR(weights + 3040);
    dense_75_weights_array.data_start = AI_PTR(weights + 3040);
    dense_75_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_75_bias_array.data = AI_PTR(weights + 5928);
    dense_75_bias_array.data_start = AI_PTR(weights + 5928);
    dense_76_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_76_weights_array.data = AI_PTR(weights + 6080);
    dense_76_weights_array.data_start = AI_PTR(weights + 6080);
    dense_76_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_76_bias_array.data = AI_PTR(weights + 11856);
    dense_76_bias_array.data_start = AI_PTR(weights + 11856);
    dense_77_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_77_weights_array.data = AI_PTR(weights + 12008);
    dense_77_weights_array.data_start = AI_PTR(weights + 12008);
    dense_77_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_77_bias_array.data = AI_PTR(weights + 17784);
    dense_77_bias_array.data_start = AI_PTR(weights + 17784);
    dense_78_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_78_weights_array.data = AI_PTR(weights + 17936);
    dense_78_weights_array.data_start = AI_PTR(weights + 17936);
    dense_78_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_78_bias_array.data = AI_PTR(weights + 20824);
    dense_78_bias_array.data_start = AI_PTR(weights + 20824);
    dense_79_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_79_weights_array.data = AI_PTR(weights + 20900);
    dense_79_weights_array.data_start = AI_PTR(weights + 20900);
    dense_79_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_79_bias_array.data = AI_PTR(weights + 22344);
    dense_79_bias_array.data_start = AI_PTR(weights + 22344);
    dense_80_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_80_weights_array.data = AI_PTR(weights + 22420);
    dense_80_weights_array.data_start = AI_PTR(weights + 22420);
    dense_80_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_80_bias_array.data = AI_PTR(weights + 23864);
    dense_80_bias_array.data_start = AI_PTR(weights + 23864);
    dense_81_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_81_weights_array.data = AI_PTR(weights + 23940);
    dense_81_weights_array.data_start = AI_PTR(weights + 23940);
    dense_81_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_81_bias_array.data = AI_PTR(weights + 25384);
    dense_81_bias_array.data_start = AI_PTR(weights + 25384);
    dense_82_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_82_weights_array.data = AI_PTR(weights + 25460);
    dense_82_weights_array.data_start = AI_PTR(weights + 25460);
    dense_82_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_82_bias_array.data = AI_PTR(weights + 26068);
    dense_82_bias_array.data_start = AI_PTR(weights + 26068);
    dense_83_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_83_weights_array.data = AI_PTR(weights + 26100);
    dense_83_weights_array.data_start = AI_PTR(weights + 26100);
    dense_83_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_83_bias_array.data = AI_PTR(weights + 26132);
    dense_83_bias_array.data_start = AI_PTR(weights + 26132);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 6771,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, &params->params);
  ok &= network_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

