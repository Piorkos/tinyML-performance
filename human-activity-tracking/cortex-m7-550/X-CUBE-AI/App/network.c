/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Mon May  3 18:19:43 2021
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
#define AI_NETWORK_MODEL_SIGNATURE     "14688e363602ed20660f1101e6dde684"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Mon May  3 18:19:43 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array input_0_output_array;   /* Array #0 */
AI_STATIC ai_array conv1d_35_output_array;   /* Array #1 */
AI_STATIC ai_array conv1d_36_output_array;   /* Array #2 */
AI_STATIC ai_array dense_40_output_array;   /* Array #3 */
AI_STATIC ai_array dense_40_nl_output_array;   /* Array #4 */
AI_STATIC ai_array dense_41_output_array;   /* Array #5 */
AI_STATIC ai_array dense_41_nl_output_array;   /* Array #6 */
AI_STATIC ai_array conv1d_35_weights_array;   /* Array #7 */
AI_STATIC ai_array conv1d_35_bias_array;   /* Array #8 */
AI_STATIC ai_array conv1d_36_weights_array;   /* Array #9 */
AI_STATIC ai_array conv1d_36_bias_array;   /* Array #10 */
AI_STATIC ai_array dense_40_weights_array;   /* Array #11 */
AI_STATIC ai_array dense_40_bias_array;   /* Array #12 */
AI_STATIC ai_array dense_41_weights_array;   /* Array #13 */
AI_STATIC ai_array dense_41_bias_array;   /* Array #14 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor input_0_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv1d_35_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv1d_36_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv1d_36_output0;   /* Tensor #3 */
AI_STATIC ai_tensor dense_40_output;   /* Tensor #4 */
AI_STATIC ai_tensor dense_40_nl_output;   /* Tensor #5 */
AI_STATIC ai_tensor dense_41_output;   /* Tensor #6 */
AI_STATIC ai_tensor dense_41_nl_output;   /* Tensor #7 */
AI_STATIC ai_tensor conv1d_35_weights;   /* Tensor #8 */
AI_STATIC ai_tensor conv1d_35_bias;   /* Tensor #9 */
AI_STATIC ai_tensor conv1d_36_weights;   /* Tensor #10 */
AI_STATIC ai_tensor conv1d_36_bias;   /* Tensor #11 */
AI_STATIC ai_tensor dense_40_weights;   /* Tensor #12 */
AI_STATIC ai_tensor dense_40_bias;   /* Tensor #13 */
AI_STATIC ai_tensor dense_41_weights;   /* Tensor #14 */
AI_STATIC ai_tensor dense_41_bias;   /* Tensor #15 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv1d_35_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv1d_36_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain dense_40_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain dense_40_nl_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain dense_41_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain dense_41_nl_chain;   /* Chain #5 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv1d_35_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv1d_36_layer; /* Layer #1 */
AI_STATIC ai_layer_dense dense_40_layer; /* Layer #2 */
AI_STATIC ai_layer_nl dense_40_nl_layer; /* Layer #3 */
AI_STATIC ai_layer_dense dense_41_layer; /* Layer #4 */
AI_STATIC ai_layer_nl dense_41_nl_layer; /* Layer #5 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 78, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_35_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_36_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 176, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  dense_40_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  dense_40_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  dense_41_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  dense_41_nl_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_35_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_35_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_36_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_36_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  dense_40_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 11264, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  dense_40_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  dense_41_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  dense_41_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 26), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &input_0_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_35_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 24), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv1d_35_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_36_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 22), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv1d_36_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_36_output0, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 176, 1, 1), AI_STRIDE_INIT(4, 4, 4, 704, 704),
  1, &conv1d_36_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  dense_40_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_40_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  dense_40_nl_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_40_nl_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  dense_41_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_41_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  dense_41_nl_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_41_nl_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_35_weights, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 3, 1, 3, 16), AI_STRIDE_INIT(4, 4, 12, 12, 36),
  1, &conv1d_35_weights_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_35_bias, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv1d_35_bias_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_36_weights, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 3, 8), AI_STRIDE_INIT(4, 4, 64, 64, 192),
  1, &conv1d_36_weights_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_36_bias, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv1d_36_bias_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  dense_40_weights, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 176, 64, 1, 1), AI_STRIDE_INIT(4, 4, 704, 45056, 45056),
  1, &dense_40_weights_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  dense_40_bias, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_40_bias_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  dense_41_weights, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 1, 1), AI_STRIDE_INIT(4, 4, 256, 768, 768),
  1, &dense_41_weights_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  dense_41_bias, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_41_bias_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1d_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1d_35_weights, &conv1d_35_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1d_35_layer, 0,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv1d_35_chain,
  &AI_NET_OBJ_INSTANCE, &conv1d_36_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1d_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1d_36_weights, &conv1d_36_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1d_36_layer, 1,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv1d_36_chain,
  &AI_NET_OBJ_INSTANCE, &dense_40_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_40_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_36_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_40_weights, &dense_40_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_40_layer, 4,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_40_chain,
  &AI_NET_OBJ_INSTANCE, &dense_40_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_40_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_40_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_40_nl_layer, 4,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_40_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_41_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_40_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_41_weights, &dense_41_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_41_layer, 5,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_41_chain,
  &AI_NET_OBJ_INSTANCE, &dense_41_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_41_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_41_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_41_nl_layer, 5,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &dense_41_nl_chain,
  &AI_NET_OBJ_INSTANCE, &dense_41_nl_layer, AI_STATIC, 
  .nl_params = NULL, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 48300, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 1600, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &dense_41_nl_output),
  &conv1d_35_layer, 0, NULL)



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
    conv1d_35_output_array.data = AI_PTR(activations + 64);
    conv1d_35_output_array.data_start = AI_PTR(activations + 64);
    conv1d_36_output_array.data = AI_PTR(activations + 0);
    conv1d_36_output_array.data_start = AI_PTR(activations + 0);
    dense_40_output_array.data = AI_PTR(activations + 704);
    dense_40_output_array.data_start = AI_PTR(activations + 704);
    dense_40_nl_output_array.data = AI_PTR(activations + 0);
    dense_40_nl_output_array.data_start = AI_PTR(activations + 0);
    dense_41_output_array.data = AI_PTR(activations + 256);
    dense_41_output_array.data_start = AI_PTR(activations + 256);
    dense_41_nl_output_array.data = AI_PTR(NULL);
    dense_41_nl_output_array.data_start = AI_PTR(NULL);
    
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
    
    conv1d_35_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1d_35_weights_array.data = AI_PTR(weights + 0);
    conv1d_35_weights_array.data_start = AI_PTR(weights + 0);
    conv1d_35_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1d_35_bias_array.data = AI_PTR(weights + 576);
    conv1d_35_bias_array.data_start = AI_PTR(weights + 576);
    conv1d_36_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1d_36_weights_array.data = AI_PTR(weights + 640);
    conv1d_36_weights_array.data_start = AI_PTR(weights + 640);
    conv1d_36_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1d_36_bias_array.data = AI_PTR(weights + 2176);
    conv1d_36_bias_array.data_start = AI_PTR(weights + 2176);
    dense_40_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_40_weights_array.data = AI_PTR(weights + 2208);
    dense_40_weights_array.data_start = AI_PTR(weights + 2208);
    dense_40_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_40_bias_array.data = AI_PTR(weights + 47264);
    dense_40_bias_array.data_start = AI_PTR(weights + 47264);
    dense_41_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_41_weights_array.data = AI_PTR(weights + 47520);
    dense_41_weights_array.data_start = AI_PTR(weights + 47520);
    dense_41_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_41_bias_array.data = AI_PTR(weights + 48288);
    dense_41_bias_array.data_start = AI_PTR(weights + 48288);
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
      
      .n_macc            = 24120,
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

