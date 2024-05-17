// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: compute_body_vel_innov_innov_var_and_h
 *
 * Args:
 *     state: Matrix24_1
 *     P: Matrix23_23
 *     meas: Matrix31
 *     omega: Matrix31
 *     R: Matrix31
 *
 * Outputs:
 *     innov: Matrix31
 *     innov_var: Matrix31
 *     H: Matrix3_23
 */
template <typename Scalar>
void ComputeBodyVelInnovInnovVarAndH(const matrix::Matrix<Scalar, 24, 1>& state,
                                     const matrix::Matrix<Scalar, 23, 23>& P,
                                     const matrix::Matrix<Scalar, 3, 1>& meas,
                                     const matrix::Matrix<Scalar, 3, 1>& omega,
                                     const matrix::Matrix<Scalar, 3, 1>& R,
                                     matrix::Matrix<Scalar, 3, 1>* const innov = nullptr,
                                     matrix::Matrix<Scalar, 3, 1>* const innov_var = nullptr,
                                     matrix::Matrix<Scalar, 3, 23>* const H = nullptr) {
  // Total ops: 618

  // Input arrays

  // Intermediate terms (69)
  const Scalar _tmp0 = 2 * state(0, 0);
  const Scalar _tmp1 = _tmp0 * state(2, 0);
  const Scalar _tmp2 = 2 * state(1, 0);
  const Scalar _tmp3 = _tmp2 * state(3, 0);
  const Scalar _tmp4 = -_tmp1 + _tmp3;
  const Scalar _tmp5 = _tmp0 * state(3, 0);
  const Scalar _tmp6 = _tmp2 * state(2, 0);
  const Scalar _tmp7 = _tmp5 + _tmp6;
  const Scalar _tmp8 = -2 * std::pow(state(3, 0), Scalar(2));
  const Scalar _tmp9 = 1 - 2 * std::pow(state(2, 0), Scalar(2));
  const Scalar _tmp10 = _tmp8 + _tmp9;
  const Scalar _tmp11 = omega(1, 0) - state(11, 0);
  const Scalar _tmp12 = omega(2, 0) - state(12, 0);
  const Scalar _tmp13 = -_tmp5 + _tmp6;
  const Scalar _tmp14 = 2 * state(2, 0);
  const Scalar _tmp15 = _tmp14 * state(3, 0);
  const Scalar _tmp16 = _tmp0 * state(1, 0);
  const Scalar _tmp17 = _tmp15 + _tmp16;
  const Scalar _tmp18 = -2 * std::pow(state(1, 0), Scalar(2));
  const Scalar _tmp19 = _tmp18 + _tmp8 + 1;
  const Scalar _tmp20 = omega(0, 0) - state(10, 0);
  const Scalar _tmp21 = _tmp1 + _tmp3;
  const Scalar _tmp22 = _tmp15 - _tmp16;
  const Scalar _tmp23 = _tmp18 + _tmp9;
  const Scalar _tmp24 = state(3, 0) * state(5, 0);
  const Scalar _tmp25 = 2 * _tmp24;
  const Scalar _tmp26 = _tmp14 * state(6, 0);
  const Scalar _tmp27 = _tmp25 - _tmp26;
  const Scalar _tmp28 = (Scalar(1) / Scalar(2)) * state(3, 0);
  const Scalar _tmp29 = 2 * state(5, 0);
  const Scalar _tmp30 = _tmp29 * state(2, 0);
  const Scalar _tmp31 = 2 * state(3, 0) * state(6, 0);
  const Scalar _tmp32 = _tmp30 + _tmp31;
  const Scalar _tmp33 = (Scalar(1) / Scalar(2)) * state(2, 0);
  const Scalar _tmp34 = 4 * state(4, 0);
  const Scalar _tmp35 = _tmp0 * state(5, 0);
  const Scalar _tmp36 = _tmp2 * state(6, 0);
  const Scalar _tmp37 = -Scalar(1) / Scalar(2) * _tmp34 * state(3, 0) +
                        (Scalar(1) / Scalar(2)) * _tmp35 + (Scalar(1) / Scalar(2)) * _tmp36;
  const Scalar _tmp38 = _tmp29 * state(1, 0);
  const Scalar _tmp39 = _tmp0 * state(6, 0);
  const Scalar _tmp40 = -_tmp34 * state(2, 0) + _tmp38 - _tmp39;
  const Scalar _tmp41 = (Scalar(1) / Scalar(2)) * _tmp40;
  const Scalar _tmp42 =
      -_tmp27 * _tmp28 - _tmp32 * _tmp33 + _tmp37 * state(0, 0) + _tmp41 * state(1, 0);
  const Scalar _tmp43 =
      -_tmp27 * _tmp33 + _tmp28 * _tmp32 - _tmp37 * state(1, 0) + _tmp41 * state(0, 0);
  const Scalar _tmp44 = (Scalar(1) / Scalar(2)) * state(1, 0);
  const Scalar _tmp45 = (Scalar(1) / Scalar(2)) * state(0, 0);
  const Scalar _tmp46 = -_tmp27 * _tmp44 - _tmp28 * _tmp40 + _tmp32 * _tmp45 + _tmp37 * state(2, 0);
  const Scalar _tmp47 = 2 * state(4, 0);
  const Scalar _tmp48 = _tmp47 * state(3, 0);
  const Scalar _tmp49 = _tmp36 - _tmp48;
  const Scalar _tmp50 = _tmp47 * state(1, 0);
  const Scalar _tmp51 = _tmp31 + _tmp50;
  const Scalar _tmp52 = _tmp47 * state(0, 0);
  const Scalar _tmp53 = -4 * _tmp24 + _tmp26 - _tmp52;
  const Scalar _tmp54 = (Scalar(1) / Scalar(2)) * _tmp53;
  const Scalar _tmp55 = _tmp47 * state(2, 0);
  const Scalar _tmp56 = _tmp39 + _tmp55 - 4 * state(1, 0) * state(5, 0);
  const Scalar _tmp57 = (Scalar(1) / Scalar(2)) * _tmp56;
  const Scalar _tmp58 =
      -_tmp28 * _tmp51 - _tmp44 * _tmp49 + _tmp54 * state(2, 0) + _tmp57 * state(0, 0);
  const Scalar _tmp59 =
      -_tmp28 * _tmp49 + _tmp44 * _tmp51 + _tmp54 * state(0, 0) - _tmp57 * state(2, 0);
  const Scalar _tmp60 = _tmp28 * _tmp56 - _tmp33 * _tmp49 - _tmp44 * _tmp53 + _tmp45 * _tmp51;
  const Scalar _tmp61 = _tmp30 + _tmp50;
  const Scalar _tmp62 = -_tmp38 + _tmp55;
  const Scalar _tmp63 = 4 * state(6, 0);
  const Scalar _tmp64 = _tmp25 + _tmp52 - _tmp63 * state(2, 0);
  const Scalar _tmp65 = -Scalar(1) / Scalar(2) * _tmp35 + (Scalar(1) / Scalar(2)) * _tmp48 -
                        Scalar(1) / Scalar(2) * _tmp63 * state(1, 0);
  const Scalar _tmp66 = -_tmp33 * _tmp62 - _tmp44 * _tmp61 + _tmp45 * _tmp64 + _tmp65 * state(3, 0);
  const Scalar _tmp67 = -_tmp28 * _tmp64 + _tmp33 * _tmp61 - _tmp44 * _tmp62 + _tmp65 * state(0, 0);
  const Scalar _tmp68 = -_tmp28 * _tmp62 + _tmp44 * _tmp64 + _tmp45 * _tmp61 - _tmp65 * state(2, 0);

  // Output terms (3)
  if (innov != nullptr) {
    matrix::Matrix<Scalar, 3, 1>& _innov = (*innov);

    _innov(0, 0) = _tmp10 * state(4, 0) + Scalar(0.029999999999999999) * _tmp11 -
                   Scalar(0.02) * _tmp12 + _tmp4 * state(6, 0) + _tmp7 * state(5, 0) - meas(0, 0);
    _innov(1, 0) = Scalar(0.01) * _tmp12 + _tmp13 * state(4, 0) + _tmp17 * state(6, 0) +
                   _tmp19 * state(5, 0) - Scalar(0.029999999999999999) * _tmp20 - meas(1, 0);
    _innov(2, 0) = -Scalar(0.01) * _tmp11 + Scalar(0.02) * _tmp20 + _tmp21 * state(4, 0) +
                   _tmp22 * state(5, 0) + _tmp23 * state(6, 0) - meas(2, 0);
  }

  if (innov_var != nullptr) {
    matrix::Matrix<Scalar, 3, 1>& _innov_var = (*innov_var);

    _innov_var(0, 0) =
        -Scalar(0.029999999999999999) * P(0, 10) * _tmp46 + Scalar(0.02) * P(0, 11) * _tmp46 -
        Scalar(0.029999999999999999) * P(1, 10) * _tmp43 + Scalar(0.02) * P(1, 11) * _tmp43 +
        Scalar(0.00089999999999999998) * P(10, 10) - Scalar(0.00059999999999999995) * P(10, 11) -
        Scalar(0.00059999999999999995) * P(11, 10) + Scalar(0.00040000000000000002) * P(11, 11) -
        Scalar(0.029999999999999999) * P(2, 10) * _tmp42 + Scalar(0.02) * P(2, 11) * _tmp42 -
        Scalar(0.029999999999999999) * P(3, 10) * _tmp10 + Scalar(0.02) * P(3, 11) * _tmp10 -
        Scalar(0.029999999999999999) * P(4, 10) * _tmp7 + Scalar(0.02) * P(4, 11) * _tmp7 -
        Scalar(0.029999999999999999) * P(5, 10) * _tmp4 + Scalar(0.02) * P(5, 11) * _tmp4 +
        R(0, 0) +
        _tmp10 * (P(0, 3) * _tmp46 + P(1, 3) * _tmp43 - Scalar(0.029999999999999999) * P(10, 3) +
                  Scalar(0.02) * P(11, 3) + P(2, 3) * _tmp42 + P(3, 3) * _tmp10 + P(4, 3) * _tmp7 +
                  P(5, 3) * _tmp4) +
        _tmp4 * (P(0, 5) * _tmp46 + P(1, 5) * _tmp43 - Scalar(0.029999999999999999) * P(10, 5) +
                 Scalar(0.02) * P(11, 5) + P(2, 5) * _tmp42 + P(3, 5) * _tmp10 + P(4, 5) * _tmp7 +
                 P(5, 5) * _tmp4) +
        _tmp42 * (P(0, 2) * _tmp46 + P(1, 2) * _tmp43 - Scalar(0.029999999999999999) * P(10, 2) +
                  Scalar(0.02) * P(11, 2) + P(2, 2) * _tmp42 + P(3, 2) * _tmp10 + P(4, 2) * _tmp7 +
                  P(5, 2) * _tmp4) +
        _tmp43 * (P(0, 1) * _tmp46 + P(1, 1) * _tmp43 - Scalar(0.029999999999999999) * P(10, 1) +
                  Scalar(0.02) * P(11, 1) + P(2, 1) * _tmp42 + P(3, 1) * _tmp10 + P(4, 1) * _tmp7 +
                  P(5, 1) * _tmp4) +
        _tmp46 * (P(0, 0) * _tmp46 + P(1, 0) * _tmp43 - Scalar(0.029999999999999999) * P(10, 0) +
                  Scalar(0.02) * P(11, 0) + P(2, 0) * _tmp42 + P(3, 0) * _tmp10 + P(4, 0) * _tmp7 +
                  P(5, 0) * _tmp4) +
        _tmp7 * (P(0, 4) * _tmp46 + P(1, 4) * _tmp43 - Scalar(0.029999999999999999) * P(10, 4) +
                 Scalar(0.02) * P(11, 4) + P(2, 4) * _tmp42 + P(3, 4) * _tmp10 + P(4, 4) * _tmp7 +
                 P(5, 4) * _tmp4);
    _innov_var(1, 0) =
        -Scalar(0.01) * P(0, 11) * _tmp58 + Scalar(0.029999999999999999) * P(0, 9) * _tmp58 -
        Scalar(0.01) * P(1, 11) * _tmp60 + Scalar(0.029999999999999999) * P(1, 9) * _tmp60 +
        Scalar(0.0001) * P(11, 11) - Scalar(0.00029999999999999997) * P(11, 9) -
        Scalar(0.01) * P(2, 11) * _tmp59 + Scalar(0.029999999999999999) * P(2, 9) * _tmp59 -
        Scalar(0.01) * P(3, 11) * _tmp13 + Scalar(0.029999999999999999) * P(3, 9) * _tmp13 -
        Scalar(0.01) * P(4, 11) * _tmp19 + Scalar(0.029999999999999999) * P(4, 9) * _tmp19 -
        Scalar(0.01) * P(5, 11) * _tmp17 + Scalar(0.029999999999999999) * P(5, 9) * _tmp17 -
        Scalar(0.00029999999999999997) * P(9, 11) + Scalar(0.00089999999999999998) * P(9, 9) +
        R(1, 0) +
        _tmp13 * (P(0, 3) * _tmp58 + P(1, 3) * _tmp60 - Scalar(0.01) * P(11, 3) + P(2, 3) * _tmp59 +
                  P(3, 3) * _tmp13 + P(4, 3) * _tmp19 + P(5, 3) * _tmp17 +
                  Scalar(0.029999999999999999) * P(9, 3)) +
        _tmp17 * (P(0, 5) * _tmp58 + P(1, 5) * _tmp60 - Scalar(0.01) * P(11, 5) + P(2, 5) * _tmp59 +
                  P(3, 5) * _tmp13 + P(4, 5) * _tmp19 + P(5, 5) * _tmp17 +
                  Scalar(0.029999999999999999) * P(9, 5)) +
        _tmp19 * (P(0, 4) * _tmp58 + P(1, 4) * _tmp60 - Scalar(0.01) * P(11, 4) + P(2, 4) * _tmp59 +
                  P(3, 4) * _tmp13 + P(4, 4) * _tmp19 + P(5, 4) * _tmp17 +
                  Scalar(0.029999999999999999) * P(9, 4)) +
        _tmp58 * (P(0, 0) * _tmp58 + P(1, 0) * _tmp60 - Scalar(0.01) * P(11, 0) + P(2, 0) * _tmp59 +
                  P(3, 0) * _tmp13 + P(4, 0) * _tmp19 + P(5, 0) * _tmp17 +
                  Scalar(0.029999999999999999) * P(9, 0)) +
        _tmp59 * (P(0, 2) * _tmp58 + P(1, 2) * _tmp60 - Scalar(0.01) * P(11, 2) + P(2, 2) * _tmp59 +
                  P(3, 2) * _tmp13 + P(4, 2) * _tmp19 + P(5, 2) * _tmp17 +
                  Scalar(0.029999999999999999) * P(9, 2)) +
        _tmp60 * (P(0, 1) * _tmp58 + P(1, 1) * _tmp60 - Scalar(0.01) * P(11, 1) + P(2, 1) * _tmp59 +
                  P(3, 1) * _tmp13 + P(4, 1) * _tmp19 + P(5, 1) * _tmp17 +
                  Scalar(0.029999999999999999) * P(9, 1));
    _innov_var(2, 0) =
        Scalar(0.01) * P(0, 10) * _tmp67 - Scalar(0.02) * P(0, 9) * _tmp67 +
        Scalar(0.01) * P(1, 10) * _tmp66 - Scalar(0.02) * P(1, 9) * _tmp66 +
        Scalar(0.0001) * P(10, 10) - Scalar(0.00020000000000000001) * P(10, 9) +
        Scalar(0.01) * P(2, 10) * _tmp68 - Scalar(0.02) * P(2, 9) * _tmp68 +
        Scalar(0.01) * P(3, 10) * _tmp21 - Scalar(0.02) * P(3, 9) * _tmp21 +
        Scalar(0.01) * P(4, 10) * _tmp22 - Scalar(0.02) * P(4, 9) * _tmp22 +
        Scalar(0.01) * P(5, 10) * _tmp23 - Scalar(0.02) * P(5, 9) * _tmp23 -
        Scalar(0.00020000000000000001) * P(9, 10) + Scalar(0.00040000000000000002) * P(9, 9) +
        R(2, 0) +
        _tmp21 * (P(0, 3) * _tmp67 + P(1, 3) * _tmp66 + Scalar(0.01) * P(10, 3) + P(2, 3) * _tmp68 +
                  P(3, 3) * _tmp21 + P(4, 3) * _tmp22 + P(5, 3) * _tmp23 - Scalar(0.02) * P(9, 3)) +
        _tmp22 * (P(0, 4) * _tmp67 + P(1, 4) * _tmp66 + Scalar(0.01) * P(10, 4) + P(2, 4) * _tmp68 +
                  P(3, 4) * _tmp21 + P(4, 4) * _tmp22 + P(5, 4) * _tmp23 - Scalar(0.02) * P(9, 4)) +
        _tmp23 * (P(0, 5) * _tmp67 + P(1, 5) * _tmp66 + Scalar(0.01) * P(10, 5) + P(2, 5) * _tmp68 +
                  P(3, 5) * _tmp21 + P(4, 5) * _tmp22 + P(5, 5) * _tmp23 - Scalar(0.02) * P(9, 5)) +
        _tmp66 * (P(0, 1) * _tmp67 + P(1, 1) * _tmp66 + Scalar(0.01) * P(10, 1) + P(2, 1) * _tmp68 +
                  P(3, 1) * _tmp21 + P(4, 1) * _tmp22 + P(5, 1) * _tmp23 - Scalar(0.02) * P(9, 1)) +
        _tmp67 * (P(0, 0) * _tmp67 + P(1, 0) * _tmp66 + Scalar(0.01) * P(10, 0) + P(2, 0) * _tmp68 +
                  P(3, 0) * _tmp21 + P(4, 0) * _tmp22 + P(5, 0) * _tmp23 - Scalar(0.02) * P(9, 0)) +
        _tmp68 * (P(0, 2) * _tmp67 + P(1, 2) * _tmp66 + Scalar(0.01) * P(10, 2) + P(2, 2) * _tmp68 +
                  P(3, 2) * _tmp21 + P(4, 2) * _tmp22 + P(5, 2) * _tmp23 - Scalar(0.02) * P(9, 2));
  }

  if (H != nullptr) {
    matrix::Matrix<Scalar, 3, 23>& _h = (*H);

    _h.setZero();

    _h(0, 0) = _tmp46;
    _h(1, 0) = _tmp58;
    _h(2, 0) = _tmp67;
    _h(0, 1) = _tmp43;
    _h(1, 1) = _tmp60;
    _h(2, 1) = _tmp66;
    _h(0, 2) = _tmp42;
    _h(1, 2) = _tmp59;
    _h(2, 2) = _tmp68;
    _h(0, 3) = _tmp10;
    _h(1, 3) = _tmp13;
    _h(2, 3) = _tmp21;
    _h(0, 4) = _tmp7;
    _h(1, 4) = _tmp19;
    _h(2, 4) = _tmp22;
    _h(0, 5) = _tmp4;
    _h(1, 5) = _tmp17;
    _h(2, 5) = _tmp23;
    _h(1, 9) = Scalar(0.029999999999999999);
    _h(2, 9) = Scalar(-0.02);
    _h(0, 10) = Scalar(-0.029999999999999999);
    _h(2, 10) = Scalar(0.01);
    _h(0, 11) = Scalar(0.02);
    _h(1, 11) = Scalar(-0.01);
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
