#ifndef _VECTOR_FUNCS_TPT_H
#define _VECTOR_FUNCS_TPT_H
#include <vector>
#include <stdexcept>

// Lab 7 (Data Structures)
// Abdul Wahab

using std::vector;

// TO-DO: implement recursive versions of following functions and modify provided wrapper functions to call recursive functions:
// MAX, MIN, SUM, FIND, CONTAINS, VEC_UNION, INTERSECTION, DIFFERENCE
// Notice I'm giving you the 'normal' interfaces (i.e. the 'wrapper' functions)
// the recursive ones you write may take extra parameters (and then you make the wrappers call them)
// wrapper function
// returns the largest element in the vector, throws a domain_error exception if vector is empty
template <typename T> T max(const vector<T>&v){
if(v.empty())
		throw std::domain_error("Empty vector");
return max(v, 0);		
}

//fcn that finds the largest elem in the vector v recursively

template <typename T> T max(const vector<T>&v, unsigned int i){
//base case looks to see if the last index of the vecto v has been reached
if (v.size() - 1 == i) {
	return v[i];
}else {
T temP = max(v, v[i]);
return v[i] > temP ? v[i] : temP;
}
}
// returns the smallest element in the vector, throws a domain_error exception if vector is empty.
template <typename T> T min(const vector<T>&v) {
if (v.empty()) {
throw std::domain_error("ERROR: Vector is empty");
}
return min(v, 0);
}

//fcn that recursively returns the smallest elem in vector v
template <typename T> T min(const vector<T>&v, unsigned int i) {
if (v.size() - 1 == i) { // Base Case
return v[i];
}
else {
T tTemp = min(v, ++i);
return v[i] < tTemp ? v[i] : tTemp;
}
}
// wrapper fcn.
// returns sum of all elems in the vector ( returns 0 if empty)
// DO NOT THROW EXCEPTION IF EMPTY, returns 0
template <typename T> T sum(const vector<T>&v){
if (v.empty()) {
return 0;
}else {
return sum(v, 0);
}
}

// a fcn. that returns sum of all elems in vector v recursively
template <typename T> T sum(const vector<T>&v, unsigned int i) {
if (v.size() - 1 == i) { // Base Case:
return v[i];
}else {
  T vector_elems_sum = sum(v, ++i);
  return vector_elems_sum += v[i];
}
}
// returns index of first element with that value, -1 if not found
// DO NOT THROW EXCEPTION IF EMPTY, returns -1
template <typename T> int find(const vector<T>&v, unsigned int value){
if (v.empty()) { // Base Case:
return -1;
}else{
return find(v, value, 0);
}
}
// fcn. that returns index of 1st elem recursively
template <typename T> int find(const vector<T>&v, unsigned int value, unsigned int index_to_find) {
if (value == v[index_to_find]) {
return index_to_find;
}else {
if ((v.size() - 1 == index_to_find && value != v[index_to_find])) { // Base Case:
return -1;
}else{
return find(v, value, ++index_to_find);
}
}
}
// returns true if vector contains that element, 0 otherwise
// DO NOT THROW EXCEPTION IF EMPTY
template <typename T> bool contains(const vector<T>&v, T value) {
if (v.empty()) {
return false;
}else {
return contains(v, value, 0);
}
}
// fcn. that returns either true or false depending n the value that is stored in the vector v. (Recursively)
template <typename T> bool contains(const vector<T>&v, T value, unsigned int vector_stores) {
if (value == v[vector_stores]) {
return true;
}else {
if ((v.size() - 1 == vector_stores && value != v[vector_stores])) { // Base case:
return false;
}else{
return contains(v, value, ++vector_stores);
}
}
}
// returns a new vector; every element in v1 and every element in v2 are also in this new vector
// if an element appears in both v1 and v2, it is only added once to the new vector
// Think about this from a Discrete Math point of view -- I will go over this in lab //


template <typename T> vector<T> vec_union(vector<T> &v1, vector<T> &v2){
if (v1.empty() && v2.empty()) {
vector<T> v3 = v1;
return v3;
}
else if (v1.empty()) {
vector<T> v3 = v2;
return v3;
}
else if (v2.empty()) {
vector<T> v3 = v1;
return v3;
}
vector<T> v3 = v1;
if (v1.size() >= v2.size()) {
return vec_union(v1, v2, v3, 0);
}else{
return vec_union(v2, v1, v3, 0);
}
}
// fcn. that finds union of 2 vectors using recursion
template <typename T> vector<T> vec_union(vector<T> &v1, vector<T> &v2, vector<T> &v3, unsigned int i) {
if (v1.size() == i) {
return v3;
}else{
if (find(v1, v2[i]) == -1) { 
v3.push_back(v2[i]);
}
return vec_union(v1, v2, v3, ++i);
}
}
// returns a new vector; every element that is in both v1 and v2 are also in this new vector
// there are no duplicates in v1 and v2
//Think about this from a Discrete Math point of view -- I will go over this in lab
template <typename T> vector<T> intersection(vector<T> v1, vector<T> v2){
vector<T> both_vecs;
if (v1.empty() || v2.empty()) {
return both_vecs;
}
if (v1.size() >= v2.size()) {
return intersection(v1, v2, both_vecs, 0);


}else{
return intersection(v2, v1, both_vecs, 0);
}
}







//fcn. that returns intersection of two vectors recursively
template <typename T> vector<T> intersection(vector<T> v1, vector<T> v2, vector<T> intersection_of_vec, unsigned int i) {
if (v1.size() == i) {
return intersection_of_vec;
}else{
if ((contains(v2, v1[i]) || contains(v1, v2[i]) && !contains(intersecion_of_vec, v1[i]))) {
intersection_of_vec.push_back(v2[i]);
}
return intersection(v1, v2, intersect, ++i);
}
}



template <typename T> vector<T> difference(vector<T> v1, vector<T> v2)
{
vector<T> diff_in_vecs;
if (v1.size()) {
if (v1.size() >= v2.size()) {
return difference(v1, v2, diff_in_vecs, 0);
}else{
return difference(v2, v1, diff_in_vecs, 0);
}
}else{
return diff_in_vecs;
}
}

// fcn. to return the diff of v2 from v1 (Recursively)
template <typename T> vector<T> difference(vector<T> v1, vector<T> v2, vector<T> v3, unsigned int i) {
if (v1.size() == i) {
return v3;
}else{
if (v2.empty()) {
return v1;
		
}
if (v1.empty()) {
return v1;
}
if (!contains(v2, v1[i])) {
v3.push_back(v1[i]);
}
if (!contains(v1, v2[i])) {
v3.push_back(v2[i]);
}
return difference(v1, v2, v3, ++i);
}
}

// END OF TO-DO
#endif
