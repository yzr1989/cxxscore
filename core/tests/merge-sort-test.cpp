#include <core/tests/merge-sort-test.h>
#include <vector>
#include <iostream>

using namespace Test;

std::vector<int> merge(std::vector<int> &vec, const std::vector<int> &left, const std::vector<int> &right) {
	std::vector<int> result;
	unsigned left_it = 0, right_it = 0;

	while (left_it < left.size() && right_it < right.size()) {
		if (left[left_it] < right[right_it]) {
			result.push_back(left[left_it]);
			left_it++;
		} else {
			result.push_back(right[right_it]);
			right_it++;
		}
	}

	while (left_it < left.size()) {
		result.push_back(left[left_it]);
		left_it++;
	}

	while (right_it < right.size()) {
		result.push_back(right[right_it]);
		right_it++;
	}

	vec = result;
	return vec;
}

std::vector<int> merge_sort(std::vector<int> &vec) {
	if (vec.size() == 1)
		return vec;

	std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);
	std::vector<int> left(vec.begin(), middle);
	std::vector<int> right(middle, vec.end());
	left = merge_sort(left);
	right = merge_sort(right);
	return merge(vec, left, right);
}

Enum::TestType MergeSortTest::type() const {
	return Enum::TestType::MergeSort;
}

uint64_t MergeSortTest::execute() {
	std::vector<int> data = { 11, 34, 1, 23, 24, 22, 22, 44, 85, 12, 334, 5, 2, 32, 64, 7 };
	return merge_sort(data).size();
}
