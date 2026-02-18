# Code Review — RoboCup Junior 3GigaHZ

## Overall Rating
**7.0 / 10**

The project contains practical, competition-oriented logic and clear domain knowledge. Runtime safety improved with loop timeouts in OUT routines, but maintainability risks remain (duplication across mirrored trees, large monolithic control flow, and limited automated verification).

---

## Scope Reviewed
- `code/forward/*.ino`
- `code/goalkeeper/*.ino`
- Mirrored files under `RCJ1/forward/*.ino` and `RCJ1/goalkeeper/*.ino`
- `README.md`

---


## Progress Since Last Review
- Added timeout guards to OUT behavior loops in forward and goalkeeper sketches (and RCJ1 mirrors) to reduce lock-up risk when sensors stall or become noisy.
- This directly addresses the prior P0 reliability concern around unbounded `while` loops.

---

## What is Good
1. **Clear hardware intent**
   - Pin mappings and core sensor/motor variables are explicit, making it easy to map firmware to physical wiring.
2. **Role separation at file level**
   - The split into `forward` and `goalkeeper` folders reflects robot-role behavior clearly.
3. **Useful runtime debug helpers**
   - Functions like `SHOWSENSOR`, `SHOW_KAF`, and compass helpers are useful during field tuning.

---

## Main Risks / Defects

### 1) High logic duplication across mirrored trees
- The repository keeps very similar logic under both `code/` and `RCJ1/`, and they have already diverged.
- This increases the risk of partial fixes and inconsistent behavior between builds.

**Impact:** Medium-High (maintenance errors, inconsistent tournament firmware)

### 2) Blocking loops without robust exits/timeouts
- Many control paths in `Out.ino` use `while (...)` loops that depend on sensor transitions to exit.
- If a sensor is noisy/stuck, the robot can remain in a loop too long.

**Impact:** High (runtime lock-in / delayed response during matches)

### 3) Large monolithic behavior logic
- Movement, out-of-bounds recovery, and sensor arbitration are implemented in long conditional chains.
- This makes regression risk high when changing one branch.

**Impact:** Medium (hard to test and evolve)

### 4) Limited automated verification
- No build/test automation for firmware in repository currently.
- Syntax/runtime issues can slip in and only appear on hardware.

**Impact:** Medium

---

## Recommended Improvements (Priority Order)

### P0 (Do next)
1. **Add timeout guards** to safety-critical `while` loops in `Out.ino`/movement logic.
2. **Pick one source of truth** (`code/` or `RCJ1/`) and generate/sync the mirror from scripts to prevent manual drift.

### P1
3. **Extract repeated movement patterns** into parameterized helper functions.
4. **Centralize constants** (noise thresholds, distances, offsets) into one config section per role.

### P2
5. Add a lightweight **local build check script** (if toolchain present) and document it.
6. Add a short architecture note describing state transitions (ball tracking, boundary handling, goal recovery).

---

## Notes on Recent Fixes
- The recent update correctly addressed:
  - buffer sizing for `%03d` debug formatting,
  - boolean-operator correctness in goalkeeper decision logic,
  - ADC reading correctness for forward battery voltage sampling.

These were good, targeted fixes. The next quality jump now depends on reducing duplication and hardening runtime loop behavior.
