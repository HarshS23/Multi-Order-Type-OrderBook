<!-- # Multi-Order-Type-OrderBook
An order book used by hedge funds to place, manage, and execute buy and sell orders for equities.


# What is an OrderBook? 
An orderbook is a storing of buy and sell orders for a specific asset, financial instrument, securtiy, etc. -->

# Multi-Order-Type Order Book (C++)

A high-performance **C++ implementation of a financial order book** supporting multiple order types (e.g., market, limit, cancel, modify).
Designed for correctness, clarity, and extensibility rather than exchange-specific behavior.

This project models the **core matching engine logic** used in electronic trading systems.

---

## Features

* Supports multiple order types:

  * Limit orders
  * Market orders
  * Order cancellation
  * Order modification
* Price–time priority matching
* Bid / ask book separation
* Deterministic matching behavior
* Written in modern C++ (no external dependencies)
* Easy to extend with new order types or matching rules

---

## Design Overview

### Core Concepts

| Concept         | Description                                                       |
| --------------- | ----------------------------------------------------------------- |
| Order           | Represents a client instruction (side, price, quantity, id, type) |
| OrderBook       | Manages bids and asks and performs matching                       |
| Matching Engine | Applies price–time priority to execute trades                     |
| Trade           | Result of matching compatible buy/sell orders                     |

---

### Matching Rules

1. Orders are matched **only if prices are compatible**:

   * Buy price ≥ Sell price
2. Higher price bids have priority.
3. Lower price asks have priority.
4. FIFO within the same price level.

---

## Build Instructions

### Requirements

* C++17 or later
* GCC / Clang / MSVC

### Compile

```bash
g++ -std=c++17 -O2 -Wall main.cpp -o orderbook
```

(Adjust filename(s) as needed.)

---

## Running

```bash
./orderbook
```

The program runs a demonstration of order submission, matching, and execution based on the input logic defined in `main.cpp`.

---

## Example Flow

1. Submit buy/sell orders
2. Order book inserts them into bid/ask sides
3. Matching engine attempts execution
4. Trades are generated and printed/logged

---

## Future Improvements for the Trading Engine

You can add:

* New order types (iceberg, stop, IOC, FOK)
* Different priority models (pro-rata, size-based)
* Persistence or logging
* Multi-instrument support
* Thread safety for concurrent order flow

---

## Disclaimer

This is a **simulation / educational matching engine**.
It is **not** production-grade trading software and lacks:

* Latency optimization
* Risk checks
* Regulatory controls
* Persistence
* Fault tolerance

Disclamier : Do not use in live trading environments!
# Multi-Order-Type-OrderBook
An order book used to simulate how hedge funds place, manage, and execute buy and sell orders for equities.
