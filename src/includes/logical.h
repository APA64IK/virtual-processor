#ifndef LOGICAL_H
#define LOGICAL_H
  #define GATE_NOT(A) (!(A) ? 1 : 0)

  #define GATE_AND(A, B) ((A) == (B) ? 1 : 0)
  #define GATE_OR(A, B) ((A) || (B) ? 1 : 0)
  #define GATE_XOR(A, B) ((A) != (B) ? 1 : 0)

  #define GATE_NAND(A, B) (!(GATE_AND(A, B)) ? 1 : 0)
  #define GATE_NOR(A, B) (!(GATE_OR(A, B)) ? 1 : 0)
  #define GATE_XNOR(A, B) (!(GATE_XOR(A, B)) ? 1 : 0)

  #define FULL_ADDER(A, B, Cin, Sum, Cout) \
    do { \
        Sum = GATE_XOR(GATE_XOR(A, B), Cin); \
        Cout = GATE_OR(GATE_AND(A, B), GATE_OR(GATE_AND(GATE_XOR(A, B), Cin), GATE_AND(A, Cin))); \
    } while(0)
  
  #define D_FLIP_FLOP(D, Clock, Q, Qn) \
    do { \
        if (Clock) { \
            Q = D; \
            Qn = GATE_NOT(D); \
        } \
    } while(0)
    
  #define EIGHT_BIT_REGISTER(D0, D1, D2, D3, D4, D5, D6, D7, Clock, Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7) \
    do { \
        D_FLIP_FLOP(D0, Clock, Q0, GATE_NOT(Q0)); \
        D_FLIP_FLOP(D1, Clock, Q1, GATE_NOT(Q1)); \
        D_FLIP_FLOP(D2, Clock, Q2, GATE_NOT(Q2)); \
        D_FLIP_FLOP(D3, Clock, Q3, GATE_NOT(Q3)); \
        D_FLIP_FLOP(D4, Clock, Q4, GATE_NOT(Q4)); \
        D_FLIP_FLOP(D5, Clock, Q5, GATE_NOT(Q5)); \
        D_FLIP_FLOP(D6, Clock, Q6, GATE_NOT(Q6)); \
        D_FLIP_FLOP(D7, Clock, Q7, GATE_NOT(Q7)); \
    } while(0)

#endif