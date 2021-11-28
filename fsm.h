#ifndef FSM_H_
#define FSM_H_

/**
  * These are te input/output types, you can
  * replace them with any type you want.
  */
typedef char fsm_input_t;
typedef void* fsm_output_t;

#define FSM_INPUT_DEFAULT_VALUE '\0'
#define FSM_OUTPUT_DEFAULT_VALUE NULL

/**
  * Error codes
*/
#define FSM_ERROR_MUX_NOT_DEFINED -3
#define FSM_ERROR_INPUT_NOT_DEFINED -2
#define FSM_ERROR_STATE_OUT_OF_BOUND -1

/**
 * State Function Type
 * - fsm_input_t input;
 * - fsm_output_t output;
 * - int previous_state;
 */
typedef fsm_output_t (*state_callable)(fsm_input_t, fsm_output_t, int);

/**
  * State Multiplexer Type
  * - fsm_input_t input;
  * - int previous_state;
  */
typedef int (*mux_callable)(fsm_input_t, int);

/**
 * Finite State Machine
 * - Default state;
 * - Array of the states;
 * - Array of the multiplexers;
 * - Maximum states.
 */
int fsm(int def, fsm_input_t (*input)(int), state_callable *S, mux_callable *M, int DIM);

#endif // FSM_H_
