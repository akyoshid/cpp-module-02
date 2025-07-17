/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:42:04 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/17 15:15:41 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static int total_tests = 0;
static int passed_tests = 0;

bool test_result(const char* test_name, bool expected, bool actual) {
    ++total_tests;
    std::cout << test_name << ": ";
    if (expected == actual) {
        std::cout << "✓ PASS" << std::endl;
        ++passed_tests;
        return true;
    } else {
        std::cout
            << "✗ FAIL (expected " << (expected ? "true" : "false")
            << ", got " << (actual ? "true" : "false") << ")" << std::endl;
        return false;
    }
}

void test_point_inside_triangle() {
    std::cout << "\n=== Testing points inside triangle ===" << std::endl;

    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);

    // Point clearly inside
    Point inside1(2.0f, 1.0f);
    test_result("Point (2,1) inside triangle", true, bsp(a, b, c, inside1));

    // Another point inside
    Point inside2(1.5f, 0.5f);
    test_result("Point (1.5,0.5) inside triangle", true, bsp(a, b, c, inside2));

    // Point near center
    Point inside3(2.0f, 2.0f);
    test_result("Point (2,2) inside triangle", true, bsp(a, b, c, inside3));
}

void test_point_outside_triangle() {
    std::cout << "\n=== Testing points outside triangle ===" << std::endl;

    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);

    // Points clearly outside
    Point outside1(-1.0f, 1.0f);
    test_result("Point (-1,1) outside triangle", false, bsp(a, b, c, outside1));

    Point outside2(5.0f, 1.0f);
    test_result("Point (5,1) outside triangle", false, bsp(a, b, c, outside2));

    Point outside3(2.0f, -1.0f);
    test_result("Point (2,-1) outside triangle", false, bsp(a, b, c, outside3));

    Point outside4(2.0f, 5.0f);
    test_result("Point (2,5) outside triangle", false, bsp(a, b, c, outside4));
}

void test_point_on_edge() {
    std::cout << "\n=== Testing points on triangle edges ===" << std::endl;

    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);

    // Points on edges (should return false)
    Point on_edge1(2.0f, 0.0f);  // On edge AB
    test_result("Point on edge AB", false, bsp(a, b, c, on_edge1));

    Point on_edge2(1.0f, 2.0f);  // On edge AC
    test_result("Point on edge AC", false, bsp(a, b, c, on_edge2));

    Point on_edge3(3.0f, 2.0f);  // On edge BC
    test_result("Point on edge BC", false, bsp(a, b, c, on_edge3));
}

void test_point_on_vertex() {
    std::cout << "\n=== Testing points on triangle vertices ===" << std::endl;

    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);

    // Points on vertices (should return false)
    test_result("Point on vertex A", false, bsp(a, b, c, a));
    test_result("Point on vertex B", false, bsp(a, b, c, b));
    test_result("Point on vertex C", false, bsp(a, b, c, c));
}

void test_different_orientations() {
    std::cout
        << "\n=== Testing different triangle orientations ===" << std::endl;

    // Clockwise triangle
    Point a1(0.0f, 0.0f);
    Point b1(0.0f, 4.0f);
    Point c1(4.0f, 0.0f);
    Point inside1(1.0f, 1.0f);
    test_result("Point inside clockwise triangle",
        true, bsp(a1, b1, c1, inside1));

    // Counter-clockwise triangle
    Point a2(0.0f, 0.0f);
    Point b2(4.0f, 0.0f);
    Point c2(0.0f, 4.0f);
    Point inside2(1.0f, 1.0f);
    test_result("Point inside counter-clockwise triangle",
        true, bsp(a2, b2, c2, inside2));
}

void test_degenerate_triangle() {
    std::cout << "\n=== Testing degenerate triangles ===" << std::endl;

    // Collinear points (degenerate triangle)
    Point a(0.0f, 0.0f);
    Point b(2.0f, 0.0f);
    Point c(4.0f, 0.0f);
    Point test_point(2.0f, 1.0f);

    // Should return false for degenerate triangle
    test_result("Point with degenerate triangle",
        false, bsp(a, b, c, test_point));
}

void test_negative_coordinates() {
    std::cout
        << "\n=== Testing triangles with negative coordinates ===" << std::endl;

    Point a(-2.0f, -2.0f);
    Point b(2.0f, -2.0f);
    Point c(0.0f, 2.0f);

    Point inside(0.0f, 0.0f);
    test_result("Point inside triangle with negative coords",
        true, bsp(a, b, c, inside));

    Point outside(0.0f, -3.0f);
    test_result("Point outside triangle with negative coords",
        false, bsp(a, b, c, outside));
}

void test_fixed_precision_limits() {
    std::cout << "\n=== Testing Fixed precision limits ===" << std::endl;

    // Since the fixed resolution is 1/256,
    // accuracy below 0.004 cannot be expected
    Point a(0.0f, 0.0f);
    Point b(1.0f, 0.0f);
    Point c(0.5f, 1.0f);

    // Point clearly inside
    Point inside(0.5f, 0.25f);
    test_result("Point clearly inside (precision safe)",
        true, bsp(a, b, c, inside));

    // Point clearly outside
    Point outside(0.5f, 1.5f);
    test_result("Point clearly outside (precision safe)",
        false, bsp(a, b, c, outside));
}

int main() {
    std::cout
        << "=== BSP Function Tests ===\n"
        << "Fixed resolution: 1/256 ≈ 0.0039" << std::endl;
    test_point_inside_triangle();
    test_point_outside_triangle();
    test_point_on_edge();
    test_point_on_vertex();
    test_different_orientations();
    test_degenerate_triangle();
    test_negative_coordinates();
    test_fixed_precision_limits();
    std::cout
        << "\n=== Test Summary ===\n"
        << "Tests passed: " << passed_tests << "/" << total_tests << std::endl;
    if (passed_tests == total_tests) {
        std::cout
            << "🎉 All tests PASSED!" << std::endl;
        return 0;
    } else {
        std::cout
            << "❌ " << (total_tests - passed_tests) << " test(s) FAILED!"
            << std::endl;
        return 1;
    }
}
