#include "vec.hpp"

#include <benchmark/benchmark.h>
#include <fmt/core.h>
#include <range/v3/all.hpp>

#include <iostream>
#include <utility>
#include <vector>

static void BM_v_add_s(benchmark::State& state)
{
    auto v2 = RangeImpl::Vec<long long>::iota(1LL, 1001LL);
    for (auto _ : state) {
        auto v3 = v2 + 2LL;
        benchmark::DoNotOptimize(v3);
    }
}
BENCHMARK(BM_v_add_s);

static void BM_v_add_2s(benchmark::State& state)
{
    auto v2 = RangeImpl::Vec<long long>::iota(1LL, 1001LL);
    for (auto _ : state) {
        auto v3 = v2 + 2LL + 3LL;
        benchmark::DoNotOptimize(v3);
    }
}
BENCHMARK(BM_v_add_2s);

static void BM_v_add_v(benchmark::State& state)
{
    auto v2 = RangeImpl::Vec<long long>::iota(1LL, 1001LL);
    auto v3 = RangeImpl::Vec<long long>::iota(1LL, 1001LL);
    for (auto _ : state) {
        auto v4 = v2 + v3;
        benchmark::DoNotOptimize(v4);
    }
}
BENCHMARK(BM_v_add_v);

static void BM_v2(benchmark::State& state)
{
    auto v2 = RangeImpl::Vec<long long>::iota(1LL, 1001LL);
    for (auto _ : state) {
        auto sum_value = v2.sum();
        benchmark::DoNotOptimize(sum_value);
    }
}
BENCHMARK(BM_v2);

BENCHMARK_MAIN();