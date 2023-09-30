//
// Created by fluque1995 on 8/9/21.
//

#include <string>
#include <vector>
#include <utility>
#include <set>
#include "dictionary_ed.h"
#include <cmath>

///////////////////////////////////////////////////////////////////////////////
//                             Private functions                             //
///////////////////////////////////////////////////////////////////////////////

Dictionary::node Dictionary::findLowerBoundChildNode(char character, Dictionary::node current_node) {
  node prev_child, curr_child = current_node.left_child();

  for (; !curr_child.is_null() && (*curr_child).character <= character; curr_child = curr_child.right_sibling()){
    prev_child = curr_child;
    if ((*curr_child).character == character) {
      return curr_child;
    }
  }
  if (!prev_child.is_null()) {
    return prev_child;
  }
  return current_node;
}

Dictionary::node Dictionary::insertCharacter(char character, Dictionary::node current_node) {
  node insertion_position = findLowerBoundChildNode(character, current_node);
  if (insertion_position == current_node){
    this->words.insert_left_child(current_node, char_info(character));
    return insertion_position.left_child();
  } else if ((*insertion_position).character != character){
    this->words.insert_right_sibling(insertion_position, char_info(character));
    return insertion_position.right_sibling();
  } else {
    return insertion_position;
  }
}

int Dictionary::getOccurrences(node curr_node, char c){
  int cnt = 0;

  if (!(curr_node.right_sibling().is_null()))
    cnt += getOccurrences(curr_node.right_sibling(), c);

  if (!(curr_node.left_child().is_null()))
    cnt += getOccurrences(curr_node.left_child(), c);

  if (toupper((*curr_node).character) == toupper(c))
    cnt++;

  return cnt;
}

std::pair<int, int> Dictionary::getTotalUsages(node curr_node, char c){
  std::pair<int, int> pair_hdcha(0, 0), pair_hizqa(0, 0);

  if (!curr_node.right_sibling().is_null())
    pair_hdcha = getTotalUsages(curr_node.right_sibling(), c);

  if (!curr_node.left_child().is_null())
    pair_hizqa = getTotalUsages(curr_node.left_child(), c);

  int curr_usos = pair_hdcha.first + pair_hizqa.first;

  if (toupper((*curr_node).character) == toupper(c)) {
    curr_usos += pair_hizqa.second;
    if ((*curr_node).valid_word)
      curr_usos++;
  }

  int curr_words = pair_hdcha.second + pair_hizqa.second;

  if ((*curr_node).valid_word)
    curr_words++;

  return std::pair<int, int>(curr_usos, curr_words);
}

///////////////////////////////////////////////////////////////////////////////
//                              Public functions                             //
///////////////////////////////////////////////////////////////////////////////

Dictionary::Dictionary() {
  this->words.set_root(char_info());
  this->total_words = 0;
}

Dictionary::Dictionary(const Dictionary &other) {
  this->words = other.words;
  this->total_words = other.total_words;
}

Dictionary::~Dictionary() {
  this->words.clear();
}

bool Dictionary::exists(const std::string & word) {
  node current_node = this->words.get_root();
  for (int i = 0; i < word.size(); ++i){
    current_node = this->findLowerBoundChildNode(word[i], current_node);
    if ((*current_node).character != word[i]) {
      return false;
    }
  }

  return (*current_node).valid_word;
}

bool Dictionary::insert(const std::string &word) {
  node current_node = this->words.get_root();
  for (int i = 0; i < word.size(); ++i){
    current_node = this->insertCharacter(word[i], current_node);
  }

  if (!(*current_node).valid_word) {
    (*current_node).valid_word = true;
    this->total_words++;
    return true;
  }

  return false;
}

bool Dictionary::erase(const std::string & val){
  node current_node = this->words.get_root();
  for (int i = 0; i < val.size(); ++i){
    current_node = this->findLowerBoundChildNode(val[i], current_node);
    if ((*current_node).character != val[i]) {
      return false;
    }
  }
  if ((*current_node).valid_word){
    (*current_node).valid_word = false;
    this->total_words--;
    return true;
  }
  return false;
}

Dictionary &Dictionary::operator=(const Dictionary &dic){
  if (this != &dic){
    this->words.clear();
    this->words = dic.words;
    this->total_words = dic.total_words;
  }
  return *this;
}

///////////////////////////////////////////////////////////////////////////////
//                               I/O overload                                //
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream &os, const Dictionary &dict){
  for(Dictionary::iterator it = dict.begin();it != dict.end(); ++it){
    os << *it << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream &is, Dictionary &dict){
  std::string curr_word;
  while (getline(is, curr_word)){
    dict.insert(curr_word);
  }
  return is;
}

///////////////////////////////////////////////////////////////////////////////
//                            Recursive counters                             //
///////////////////////////////////////////////////////////////////////////////

int Dictionary::getOccurrences(const char c){
  return getOccurrences(words.get_root(), c);
}

int Dictionary::getTotalUsages(const char c){
  return getTotalUsages(words.get_root(), c).first;
}

///////////////////////////////////////////////////////////////////////////////
//                                 Iterator                                  //
///////////////////////////////////////////////////////////////////////////////

Dictionary::iterator::iterator() {
  curr_word = "";
  iter = tree<char_info>::const_preorder_iterator();
}

Dictionary::iterator::iterator(tree<char_info>::const_preorder_iterator iter) {
  curr_word = "";
  this->iter = iter;
}

std::string Dictionary::iterator::operator*() {
  return curr_word;
}

Dictionary::iterator &Dictionary::iterator::operator++() {
  int level = iter.get_level();

  do {
    ++iter;
    if (iter.get_level() > level){
      curr_word += (*iter).character;
    }
    else if (iter.get_level() == level){
      curr_word.pop_back();
      curr_word += (*iter).character;
    }
    else {
      while (level >= iter.get_level()){
        curr_word.pop_back();
        level--;
      }
      if (level >= 0)
        curr_word += (*iter).character;
    }

    level = iter.get_level();
  } while (level && !(*iter).valid_word);

  return (*this);
}

bool Dictionary::iterator::operator==(const iterator &other) {
  return (this->iter == other.iter);
}

bool Dictionary::iterator::operator!=(const iterator &other) {
  return (this->iter != other.iter);
}

Dictionary::iterator Dictionary::begin() const {
  return ++Dictionary::iterator(words.cbegin_preorder());
}

Dictionary::iterator Dictionary::end() const {
  return Dictionary::iterator(words.cend_preorder());
}

///////////////////////////////////////////////////////////////////////////////
//                            Letters Iterator                               //
///////////////////////////////////////////////////////////////////////////////


Dictionary::possible_words_iterator Dictionary::possible_words_begin(vector<char> available_characters) const {
  Dictionary::possible_words_iterator iter(words.get_root(), available_characters);
  cout << "BEGIN antes del ++ " << (*iter) << "\n";
  ++iter;
  cout << "BEGIN después del ++ " << (*iter) << "\n";
  return iter;
  // return ++Dictionary::possible_words_iterator(words.get_root(), available_characters);
}

Dictionary::possible_words_iterator Dictionary::possible_words_end() const {
  return Dictionary::possible_words_iterator();
}

Dictionary::possible_words_iterator::possible_words_iterator() {
  current_word = "";
  level = 0;
  current_node = node();
}

Dictionary::possible_words_iterator::possible_words_iterator(node current_node, vector<char> available_letters){
  current_word = "";
  level = 0;
  this->current_node = current_node;
  multiset<char> tmp (available_letters.begin(), available_letters.end());
  this->available_letters = tmp;
}

Dictionary::possible_words_iterator::possible_words_iterator(const possible_words_iterator &other){
  this->current_word = other.current_word;
  this->level = other.level;
  this->current_node = other.current_node;
  this->available_letters = other.available_letters;
}

Dictionary::possible_words_iterator &Dictionary::possible_words_iterator::operator=(const Dictionary::possible_words_iterator &other) {
  this->current_word = other.current_word;
  this->level = other.level;
  this->current_node = other.current_node;
  this->available_letters = other.available_letters;
  return (*this);
}

bool Dictionary::possible_words_iterator::operator==(const Dictionary::possible_words_iterator &other) const {
  return (current_node == other.current_node);
}

bool Dictionary::possible_words_iterator::operator!=(const Dictionary::possible_words_iterator &other) const {
  return (current_node != other.current_node);
}

Dictionary::possible_words_iterator &Dictionary::possible_words_iterator::operator++() {
  do {
    if (!current_node.left_child().is_null() &&
        available_letters.find((*current_node.left_child()).character) != available_letters.end()) {
      current_node = current_node.left_child();
      level++;
      current_word += (*current_node).character;
      available_letters.erase(available_letters.find((*current_node).character));
    }
    else if (!current_node.right_sibling().is_null() &&
              available_letters.find((*current_node.right_sibling()).character) != available_letters.end()) {
      available_letters.insert((*current_node).character);
      current_node = current_node.right_sibling();
      current_word.pop_back();
      current_word += (*current_node).character;
      available_letters.erase(available_letters.find((*current_node).character));
    }
    else {
      while (!current_node.parent().is_null() &&
            (current_node.parent().right_sibling().is_null() ||
            current_node.parent().right_sibling() == current_node ||
            available_letters.find((*current_node.parent().right_sibling()).character) == available_letters.end())){

        available_letters.insert((*current_node).character);
        current_node = current_node.parent();
        current_word.pop_back();
        level--;
      }
      if (current_node.parent().is_null()){
	      current_node = node();
      }
      else {
        available_letters.insert((*current_node).character);
        available_letters.insert((*current_node.parent()).character);
        current_node = current_node.parent().right_sibling();
        level--;
        current_word.pop_back();
        current_word.pop_back();
        current_word += (*current_node).character;
        available_letters.erase(available_letters.find((*current_node).character));
      }
    }
  } while (level && !(*current_node).valid_word);
  
  return (*this);
}

std::string Dictionary::possible_words_iterator::operator*() const {
  return current_word;
}
