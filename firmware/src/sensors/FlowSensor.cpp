#include "sensors/FlowSensor.h"

#include <Arduino.h>

#include "pins/BoardPins.h"

namespace owg {

namespace {

constexpr float kPulsesPerLiter = 75.0f;
constexpr float kLowFlowLitersPerMinute = 1.0f;
constexpr std::uint32_t kSampleIntervalMs = 1000;

volatile std::uint32_t g_flow_pulse_count = 0;

}  // namespace

void FlowSensor::begin() {
  pinMode(pins::kFlowPulse, INPUT_PULLUP);
  last_sample_ms_ = millis();
  last_pulse_count_ = 0;
  attachInterrupt(
      digitalPinToInterrupt(pins::kFlowPulse), FlowSensor::handlePulseInterrupt, RISING);
}

void FlowSensor::poll() {
  const std::uint32_t now_ms = millis();
  const std::uint32_t elapsed_ms = now_ms - last_sample_ms_;

  if (elapsed_ms < kSampleIntervalMs) {
    return;
  }

  noInterrupts();
  const std::uint32_t pulse_count = g_flow_pulse_count;
  interrupts();

  const std::uint32_t delta_pulses = pulse_count - last_pulse_count_;
  const float liters = static_cast<float>(delta_pulses) / kPulsesPerLiter;
  const float minutes = static_cast<float>(elapsed_ms) / 60000.0f;

  summary_.online = true;
  summary_.liters_per_minute = minutes > 0.0f ? liters / minutes : 0.0f;
  summary_.flow_present = delta_pulses > 0;
  summary_.low_flow_present =
      summary_.flow_present && summary_.liters_per_minute < kLowFlowLitersPerMinute;

  last_pulse_count_ = pulse_count;
  last_sample_ms_ = now_ms;
}

FlowSensorSummary FlowSensor::summary() const {
  return summary_;
}

void FlowSensor::handlePulseInterrupt() {
  ++g_flow_pulse_count;
}

}  // namespace owg
