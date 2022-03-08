// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop___024root.h"
#include "Vtop__Syms.h"

//==========

VL_INLINE_OPT void Vtop___024root___combo__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__3\n"); );
    // Body
    vlSelf->VGA_CLK = vlSelf->clk;
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__4(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__4\n"); );
    // Variables
    CData/*0:0*/ top__DOT__my_vga_ctrl__DOT__h_valid;
    CData/*0:0*/ top__DOT__my_vga_ctrl__DOT__v_valid;
    CData/*7:0*/ __Vdly__top__DOT__led1__DOT__led;
    CData/*2:0*/ __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync;
    CData/*3:0*/ __Vdly__top__DOT__my_keyboard__DOT__count;
    CData/*2:0*/ __Vdly__top__DOT__mu_seg__DOT__offset;
    SData/*9:0*/ __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt;
    SData/*9:0*/ __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt;
    IData/*23:0*/ top__DOT__vga_data;
    IData/*31:0*/ __Vdly__top__DOT__led1__DOT__count;
    IData/*31:0*/ __Vdly__top__DOT__mu_seg__DOT__count;
    // Body
    __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync;
    __Vdly__top__DOT__my_keyboard__DOT__count = vlSelf->top__DOT__my_keyboard__DOT__count;
    __Vdly__top__DOT__led1__DOT__count = vlSelf->top__DOT__led1__DOT__count;
    __Vdly__top__DOT__led1__DOT__led = vlSelf->top__DOT__led1__DOT__led;
    __Vdly__top__DOT__mu_seg__DOT__count = vlSelf->top__DOT__mu_seg__DOT__count;
    __Vdly__top__DOT__mu_seg__DOT__offset = vlSelf->top__DOT__mu_seg__DOT__offset;
    __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt;
    __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt;
    __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = ((6U & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->ps2_clk));
    if (vlSelf->rst) {
        __Vdly__top__DOT__my_keyboard__DOT__count = 0U;
    } else if ((IData)((4U == (6U & (IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync))))) {
        if ((0xaU == (IData)(vlSelf->top__DOT__my_keyboard__DOT__count))) {
            if (VL_UNLIKELY((((~ (IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer)) 
                              & (IData)(vlSelf->ps2_data)) 
                             & VL_REDXOR_32((0x1ffU 
                                             & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer) 
                                                >> 1U)))))) {
                VL_WRITEF("recieve %x\n",8,(0xffU & 
                                            ((IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer) 
                                             >> 1U)));
            }
            __Vdly__top__DOT__my_keyboard__DOT__count = 0U;
        } else {
            vlSelf->top__DOT__my_keyboard__DOT____Vlvbound1 
                = vlSelf->ps2_data;
            if (VL_LIKELY((9U >= (IData)(vlSelf->top__DOT__my_keyboard__DOT__count)))) {
                vlSelf->top__DOT__my_keyboard__DOT__buffer 
                    = (((~ ((IData)(1U) << (IData)(vlSelf->top__DOT__my_keyboard__DOT__count))) 
                        & (IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer)) 
                       | (0x3ffU & ((IData)(vlSelf->top__DOT__my_keyboard__DOT____Vlvbound1) 
                                    << (IData)(vlSelf->top__DOT__my_keyboard__DOT__count))));
            }
            __Vdly__top__DOT__my_keyboard__DOT__count 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_keyboard__DOT__count)));
        }
    }
    if (vlSelf->rst) {
        __Vdly__top__DOT__led1__DOT__led = 1U;
        __Vdly__top__DOT__led1__DOT__count = 0U;
    } else {
        if ((0U == vlSelf->top__DOT__led1__DOT__count)) {
            __Vdly__top__DOT__led1__DOT__led = ((0xfeU 
                                                 & ((IData)(vlSelf->top__DOT__led1__DOT__led) 
                                                    << 1U)) 
                                                | (1U 
                                                   & ((IData)(vlSelf->top__DOT__led1__DOT__led) 
                                                      >> 7U)));
        }
        __Vdly__top__DOT__led1__DOT__count = ((0x4c4b40U 
                                               <= vlSelf->top__DOT__led1__DOT__count)
                                               ? 0U
                                               : ((IData)(1U) 
                                                  + vlSelf->top__DOT__led1__DOT__count));
    }
    if (vlSelf->rst) {
        __Vdly__top__DOT__mu_seg__DOT__count = 0U;
        __Vdly__top__DOT__mu_seg__DOT__offset = 0U;
    } else {
        if ((0x4c4b40U == vlSelf->top__DOT__mu_seg__DOT__count)) {
            __Vdly__top__DOT__mu_seg__DOT__offset = 
                (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)));
        }
        __Vdly__top__DOT__mu_seg__DOT__count = ((0x4c4b40U 
                                                 == vlSelf->top__DOT__mu_seg__DOT__count)
                                                 ? 0U
                                                 : 
                                                ((IData)(1U) 
                                                 + vlSelf->top__DOT__mu_seg__DOT__count));
    }
    if (vlSelf->rst) {
        __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 1U;
        __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = 1U;
    } else if ((0x320U == (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt))) {
        __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt = 
            ((0x20dU == (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt))
              ? 1U : (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt))));
        __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 1U;
    } else {
        __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt = 
            (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)));
    }
    vlSelf->top__DOT__my_keyboard__DOT__count = __Vdly__top__DOT__my_keyboard__DOT__count;
    vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync;
    vlSelf->top__DOT__led1__DOT__count = __Vdly__top__DOT__led1__DOT__count;
    vlSelf->top__DOT__led1__DOT__led = __Vdly__top__DOT__led1__DOT__led;
    vlSelf->top__DOT__mu_seg__DOT__count = __Vdly__top__DOT__mu_seg__DOT__count;
    vlSelf->top__DOT__mu_seg__DOT__offset = __Vdly__top__DOT__mu_seg__DOT__offset;
    vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt = __Vdly__top__DOT__my_vga_ctrl__DOT__x_cnt;
    vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt = __Vdly__top__DOT__my_vga_ctrl__DOT__y_cnt;
    vlSelf->seg0 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [vlSelf->top__DOT__mu_seg__DOT__offset]));
    vlSelf->seg1 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg2 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(2U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg3 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(3U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg4 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(4U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg5 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(5U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg6 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(6U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg7 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(7U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->VGA_HSYNC = (0x60U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt));
    top__DOT__my_vga_ctrl__DOT__h_valid = ((0x90U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)) 
                                           & (0x310U 
                                              >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)));
    vlSelf->VGA_VSYNC = (2U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt));
    top__DOT__my_vga_ctrl__DOT__v_valid = ((0x23U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)) 
                                           & (0x203U 
                                              >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)));
    vlSelf->VGA_BLANK_N = ((IData)(top__DOT__my_vga_ctrl__DOT__h_valid) 
                           & (IData)(top__DOT__my_vga_ctrl__DOT__v_valid));
    top__DOT__vga_data = vlSelf->top__DOT__my_vmem__DOT__vga_mem
        [((((IData)(top__DOT__my_vga_ctrl__DOT__h_valid)
             ? (0x3ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt) 
                          - (IData)(0x91U))) : 0U) 
           << 9U) | ((IData)(top__DOT__my_vga_ctrl__DOT__v_valid)
                      ? (0x1ffU & ((IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt) 
                                   - (IData)(0x24U)))
                      : 0U))];
    vlSelf->VGA_R = (0xffU & (top__DOT__vga_data >> 0x10U));
    vlSelf->VGA_G = (0xffU & (top__DOT__vga_data >> 8U));
    vlSelf->VGA_B = (0xffU & top__DOT__vga_data);
}

VL_INLINE_OPT void Vtop___024root___combo__TOP__5(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__5\n"); );
    // Body
    vlSelf->ledr = (((IData)(vlSelf->top__DOT__led1__DOT__led) 
                     << 8U) | (IData)(vlSelf->sw));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    Vtop___024root___combo__TOP__3(vlSelf);
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__4(vlSelf);
    }
    Vtop___024root___combo__TOP__5(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData Vtop___024root___change_request_1(Vtop___024root* vlSelf);

VL_INLINE_OPT QData Vtop___024root___change_request(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request\n"); );
    // Body
    return (Vtop___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vtop___024root___change_request_1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
}
#endif  // VL_DEBUG
