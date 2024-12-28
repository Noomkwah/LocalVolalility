#include <iostream>
#include <cmath>
using namespace std;

// Function to compute the CDF of a normal distribution
float normal_cdf(float x) {
    return 0.5f * (1.0f + std::erf(x / std::sqrt(2.0f)));
}

// Function to calculate d_plus
float d_plus(float S, float K, float T, float sigma, float r, float q) {
    return (std::log(S / K) + ((r - q) + sigma * sigma / 2) * T) / (sigma * std::sqrt(T));
}

// Function to calculate d_minus
float d_minus(float S, float K, float T, float sigma, float r, float q) {
    return (std::log(S / K) + ((r - q) - sigma * sigma / 2) * T) / (sigma * std::sqrt(T));
}

// Function to calculate the price of a call option using the Black-Scholes formula
float BS_Call(float S, float K, float T, float sigma, float r, float q) {
    float d_plus_ = d_plus(S, K, T, sigma, r, q);
    float d_minus_ = d_minus(S, K, T, sigma, r, q);
    return S * std::exp(-q * T) * normal_cdf(d_plus_) - K * std::exp(-r * T) * normal_cdf(d_minus_);
}

int main() {
    // Parameters for the option
    float S = 100.0f;       // Spot price
    float K = 105.0f;       // Strike price
    float T = 0.5f;         // Time to maturity (in years)
    float sigma = 0.2f;     // Volatility
    float r = 0.05f;        // Risk-free rate
    float q = 0.00f;        // Dividend yield

    // Calculate the call price
    float call_price = BS_Call(S, K, T, sigma, r, q);
    cout << "The price of the call option is: " << call_price << endl;

    return 0;
}
