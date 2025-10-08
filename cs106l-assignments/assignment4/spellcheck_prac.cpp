#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  auto whitespace = find_all(source.begin(), source.end(), [](unsigned char c) {return std::isspace(c);});
  Corpus tokens;
  std::transform(whitespace.begin(), whitespace.end() - 1, whitespace.begin() + 1, 
                std::inserter(tokens, tokens.end()), 
                [&source](auto it1, auto it2){return Token{source, it1, it2};}
  );
  std::erase_if(tokens, [](auto token){return token.content.empty();});
  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  namespace rv = std::ranges::views;
  auto view = source 
              | rv::filter([&dictionary](const Token& token){
                  return !dictionary.contains(token.content);
                })
              | rv::transform([&dictionary](const Token& token) -> Misspelling {
                  auto dict_view = dictionary 
                              | rv::filter([&token](const std::string& dictionary_word){
                                  return levenshtein(token.content, dictionary_word) == 1;
                                });
                  std::set<std::string> suggestions(dict_view.begin(), dict_view.end());
                  return Misspelling{token, suggestions};
                })
              | rv::filter([](const Misspelling &element){
                  return !element.suggestions.empty();
                });

  return std::set<Misspelling>(view.begin(), view.end());
};

/* Helper methods */

#include "utils.cpp"